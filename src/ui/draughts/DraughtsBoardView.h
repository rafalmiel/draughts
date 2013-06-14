#ifndef BG_UI_DRAUGHTS_DRAUGHTSBOARDVIEW_H
#define BG_UI_DRAUGHTS_DRAUGHTSBOARDVIEW_H

#include <QGraphicsView>

namespace bg {
namespace ui {
namespace draughts {

class DraughtsBoardView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit DraughtsBoardView(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

} // namespace draughts
} // namespace ui
} // namespace bg

#endif // BG_UI_DRAUGHTS_DRAUGHTSBOARDVIEW_H
