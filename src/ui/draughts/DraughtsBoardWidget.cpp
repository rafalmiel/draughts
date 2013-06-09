#include "DraughtsBoardWidget.h"
#include "ui_DraughtsBoardWidget.h"

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

    m_boardScene = new QGraphicsScene();
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

    for (int i = 0; i < 12; ++i) {
        QGraphicsSvgItem *checker = new QGraphicsSvgItem(":/draughts/checker_red");
        int ind = i*2;
        if (ind < 8 || ind >= 16) ind++;
        qint32 row = ind % BOARD_FIELDS_DIM;
        qint32 col = ind / BOARD_FIELDS_DIM;
        checker->setX(row * SVG_ITEM_WIDTH);
        checker->setY(col * SVG_ITEM_WIDTH);
        m_redCheckers.push_back(checker);
        m_boardScene->addItem(checker);
    }

    for (int i = 0; i < 12; ++i) {
        QGraphicsSvgItem *checker = new QGraphicsSvgItem(":/draughts/checker_white");
        int ind = i*2;
        if (ind < 8 || ind >= 16) ind++;
        ind = 63 - ind;
        qint32 row = ind % BOARD_FIELDS_DIM;
        qint32 col = ind / BOARD_FIELDS_DIM;
        checker->setX(row * SVG_ITEM_WIDTH);
        checker->setY(col * SVG_ITEM_WIDTH);
        m_whiteCheckers.push_back(checker);
        m_boardScene->addItem(checker);
    }

    ui->gvBoard->setScene(m_boardScene);
}

void BoardWidget::resizeEvent(QResizeEvent *)
{
    qreal max_width = qMin(ui->gvBoard->width(), ui->gvBoard->height());
    qreal scale = (max_width / BOARD_FIELDS_DIM) / (SVG_ITEM_WIDTH + 5);
    ui->gvBoard->resetMatrix();
    ui->gvBoard->scale(scale, scale);
}

BoardWidget::~BoardWidget()
{
    delete ui;
}

} // namespace draughts
} // namespace ui
} // namespace bg
