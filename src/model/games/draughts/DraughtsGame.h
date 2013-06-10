#ifndef BG_MODEL_DRAUGHTS_DRAUGHTSGAME_H
#define BG_MODEL_DRAUGHTS_DRAUGHTSGAME_H

#include <model/Game.h>

namespace bg {
namespace model {
namespace draughts {

class Game : public bg::model::Game
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    
signals:
    
public slots:
    
};

} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_DRAUGHTSGAME_H
