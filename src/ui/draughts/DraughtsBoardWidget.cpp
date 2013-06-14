#include "DraughtsBoardWidget.h"
#include "ui_DraughtsBoardWidget.h"

#include <QDebug>
#include <qmath.h>

#include "DraughtsBoardTypes.h"
#include "DraughtsBoardScene.h"
#include <model/games/draughts/Draughts.h>

namespace bg {
namespace ui {
namespace draughts {

const qreal BoardWidget::SVG_ITEM_WIDTH = 164;

BoardWidget::BoardWidget(model::draughts::Game *game, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoardWidget),
    m_boardScene(nullptr),
    m_game(game),
    c_fieldsNum(m_game->board()->fieldsNum()),
    c_boardDim(qSqrt(c_fieldsNum))
{
    ui->setupUi(this);

    m_game->createMove();

    m_boardScene = new DraughtsBoardScene();
    QGraphicsItem *itm = m_boardScene->addRect(-5, -5, SVG_ITEM_WIDTH * c_boardDim + 10, SVG_ITEM_WIDTH * c_boardDim + 10, QPen(Qt::white));
    itm->setData(toInt(SvgKeys::Type), toInt(ItemType::Selection));
    connect(m_boardScene, SIGNAL(fieldClicked(qint32)),
            this, SLOT(slotOnFieldClicked(qint32)));

    setupBoard();
    setupCheckersItems();

    ui->gvBoard->setScene(m_boardScene);
}

void BoardWidget::slotOnFieldClicked(qint32 num)
{
    if (m_clickedFields.contains(num)) {
        m_boardScene->removeItem(m_clickedFields[num]);
        delete m_clickedFields[num];
        m_clickedFields.remove(num);
    } else {
        qint32 row = num % c_boardDim;
        qint32 col = num / c_boardDim;

        QGraphicsRectItem *rect = new QGraphicsRectItem(
                    QRect(row * SVG_ITEM_WIDTH,
                          col * SVG_ITEM_WIDTH,
                          SVG_ITEM_WIDTH, SVG_ITEM_WIDTH));

        rect->setPen(QPen(QBrush(Qt::black), 5));
        rect->setData(toInt(SvgKeys::Type), toInt(ItemType::Selection));
        m_boardScene->addItem(rect);
        m_clickedFields.insert(num, rect);
    }
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
    model::draughts::Board *board = m_game->board();
    for (int i = 0; i < 64; ++i) {
        model::draughts::Checker *checker = board->checkerAt(i);
        if (checker && !isCheckerOnBoard(checker, i)) {
            QString filename = filenameByChecker(checker);



            QGraphicsSvgItem *svgChecker = new QGraphicsSvgItem(filename);
            qint32 row = i % c_boardDim;
            qint32 col = i / c_boardDim;
            svgChecker->setX(row * SVG_ITEM_WIDTH);
            svgChecker->setY(col * SVG_ITEM_WIDTH);
            svgChecker->setData(toInt(SvgKeys::Type), toInt(ItemType::Checker));
            svgChecker->setData(toInt(SvgKeys::CheckerColor), toInt(checker->color()));

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
    for (qint32 i = 0; i < c_boardDim*c_boardDim; ++i) {
        qint32 row = i % c_boardDim;
        qint32 col = i / c_boardDim;
        QString file =
                (((col % 2 == 0) && (row % 2 == 1)) ||
                ((col % 2 == 1) && (row % 2 == 0)))
                ?":/draughts/field_dark":":/draughts/field_white";
        QGraphicsSvgItem *item = new QGraphicsSvgItem(file);
        item->setX(row * SVG_ITEM_WIDTH);
        item->setY(col * SVG_ITEM_WIDTH);
        item->setData(toInt(SvgKeys::Type), toInt(ItemType::Field));
        item->setData(toInt(SvgKeys::FieldNum), i);
        m_fields.push_back(item);
        m_boardScene->addItem(item);
    }
}

void BoardWidget::resizeEvent(QResizeEvent *)
{
    qreal max_width = qMin(ui->gvBoard->width(), ui->gvBoard->height());
    qreal scale = (max_width / c_boardDim) / (SVG_ITEM_WIDTH + 5);
    ui->gvBoard->resetMatrix();
    ui->gvBoard->scale(scale, scale);
}

model::draughts::Field *BoardWidget::stringToField(const QString &field) const
{
    if (field.size() == 2) {
        qint32 row = field.toStdString().at(0) - 'a';
        qint32 col = 8 - (field.toStdString().at(1) - '0');
        return m_game->board()->fieldAt(col * 8 + row);
    }

    return nullptr;
}

void BoardWidget::on_btnApplyMove_clicked()
{
    //for testing purposes..
    QString strMove = ui->edMove->text();
    QStringList splitMove = strMove.split("-");
    bg::model::draughts::MovePtr mov(new bg::model::draughts::Move());
    foreach (const QString &str, splitMove) {
        mov->addField(stringToField(str));
    }
    if (m_game->applyMove(mov)) {
        setupCheckersItems();
    }
}

BoardWidget::~BoardWidget()
{
    ui->gvBoard->setScene(nullptr);
    delete m_boardScene;
    delete ui;
}

} // namespace draughts
} // namespace ui
} // namespace bg

