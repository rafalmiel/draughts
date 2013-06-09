#ifndef BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H
#define BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QResizeEvent>

namespace bg {
namespace ui {
namespace draughts {

namespace Ui {
class BoardWidget;
}

class BoardWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BoardWidget(QWidget *parent = 0);
    ~BoardWidget();
    
private:
    void resizeEvent(QResizeEvent *);
    Ui::BoardWidget *ui;

    QGraphicsScene *m_boardScene;

    QVector<QGraphicsSvgItem *> m_fields;
    QVector<QGraphicsSvgItem *> m_whiteCheckers;
    QVector<QGraphicsSvgItem *> m_redCheckers;

    static const qreal SVG_ITEM_WIDTH;
    static const qint32 BOARD_FIELDS_DIM;
};


} // namespace draughts
} // namespace ui
} // namespace bg
#endif // BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H
