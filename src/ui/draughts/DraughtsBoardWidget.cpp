#include "DraughtsBoardWidget.h"
#include "ui_DraughtsBoardWidget.h"

#include <model/games/draughts/DraughtsTypes.h>
#include <model/games/draughts/brazilian/DraughtsBrazilianGame.h>
#include <model/games/draughts/brazilian/DraughtsBrazilianBoard.h>
#include <model/games/draughts/DraughtsChecker.h>
#include <model/games/draughts/DraughtsField.h>

#include <QDebug>

namespace bg {
namespace ui {
namespace draughts {

const qreal BoardWidget::SVG_ITEM_WIDTH = 164;
const qint32 BoardWidget::BOARD_FIELDS_DIM = 8;

BoardWidget::BoardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoardWidget)
{
    ui->setupUi(this);

    m_game = new model::draughts::brazilian::Game();
    m_game->beginGame();

    m_boardScene = new QGraphicsScene();

    setupBoard();
    setupCheckersItems();

    ui->gvBoard->setScene(m_boardScene);
}

QString BoardWidget::filenameByChecker(model::draughts::Checker *checker)
{
    if (checker->color() == model::draughts::Player::BLACK) {
        return ":/draughts/checker_red";
    } else {
        return ":/draughts/checker_white";
    }
}

bool BoardWidget::isCheckerOnBoard(model::draughts::Checker *checker, qint32 fieldNum)
{
    return (m_checkers.contains(fieldNum) &&
            static_cast<model::draughts::Player>(
                m_checkers[fieldNum]->data(0).toInt()) == checker->color());

}

void BoardWidget::removeCheckerAt(int i)
{
    if (m_checkers.contains(i)) {
        m_boardScene->removeItem(m_checkers[i]);
        delete m_checkers[i];
        m_checkers.remove(i);
    }
}

void BoardWidget::setupCheckersItems()
{
    model::draughts::brazilian::Board *board = m_game->board();
    for (int i = 0; i < 64; ++i) {
        model::draughts::Checker *checker = board->checkerAt(i);
        if (checker && !isCheckerOnBoard(checker, i)) {
            QString filename = filenameByChecker(checker);

            QGraphicsSvgItem *svgChecker = new QGraphicsSvgItem(filename);
            qint32 row = i % BOARD_FIELDS_DIM;
            qint32 col = i / BOARD_FIELDS_DIM;
            svgChecker->setX(row * SVG_ITEM_WIDTH);
            svgChecker->setY(col * SVG_ITEM_WIDTH);
            svgChecker->setData(0, static_cast<int>(checker->color()));

            removeCheckerAt(i);

            m_checkers.insert(i, svgChecker);

            m_boardScene->addItem(svgChecker);
        } else if (!checker) {
            removeCheckerAt(i);
        }
    }
}

void BoardWidget::setupBoard()
{
    for (qint32 i = 0; i < BOARD_FIELDS_DIM*BOARD_FIELDS_DIM; ++i) {
        qint32 row = i % BOARD_FIELDS_DIM;
        qint32 col = i / BOARD_FIELDS_DIM;
        QString file =
                (((col % 2 == 0) && (row % 2 == 1)) ||
                ((col % 2 == 1) && (row % 2 == 0)))
                ?":/draughts/field_dark":":/draughts/field_white";
        QGraphicsSvgItem *item = new QGraphicsSvgItem(file);
        item->setX(row * SVG_ITEM_WIDTH);
        item->setY(col * SVG_ITEM_WIDTH);
        m_fields.push_back(item);
        m_boardScene->addItem(item);
    }
}

void BoardWidget::resizeEvent(QResizeEvent *)
{
    qreal max_width = qMin(ui->gvBoard->width(), ui->gvBoard->height());
    qreal scale = (max_width / BOARD_FIELDS_DIM) / (SVG_ITEM_WIDTH + 5);
    ui->gvBoard->resetMatrix();
    ui->gvBoard->scale(scale, scale);
}

void BoardWidget::on_btnApplyMove_clicked()
{
    if (m_game->applyMove(ui->edMove->text())) {
        setupCheckersItems();
    }
}

BoardWidget::~BoardWidget()
{
    delete ui;
}

} // namespace draughts
} // namespace ui
} // namespace bg

