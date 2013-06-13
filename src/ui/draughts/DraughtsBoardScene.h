#ifndef BG_UI_DRAUGHTS_DRAUGHTSBOARDSCENE_H
#define BG_UI_DRAUGHTS_DRAUGHTSBOARDSCENE_H

#include <QGraphicsScene>

namespace bg {
namespace ui {
namespace draughts {

class DraughtsBoardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DraughtsBoardScene(QObject *parent = 0);
    
signals:
    void fieldClicked(qint32 fieldNum);

public slots:

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    
};

} // namespace draughts
} // namespace ui
} // namespace bg

#endif // BG_UI_DRAUGHTS_DRAUGHTSBOARDSCENE_H
