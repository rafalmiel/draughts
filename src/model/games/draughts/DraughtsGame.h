#ifndef BG_MODEL_DRAUGHTS_DRAUGHTSGAME_H
#define BG_MODEL_DRAUGHTS_DRAUGHTSGAME_H

#include <model/Game.h>
#include "DraughtsTypes.h"

namespace bg {
namespace model {
namespace draughts {

class Board;

class Game : public bg::model::Game
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);

    virtual void beginGame() = 0;
    virtual bg::model::draughts::Board * board() const = 0;
    virtual bool applyMove(const MovePtr &move) = 0;
    virtual MovesVector findAllLegalMoves() const = 0;
    
signals:
    
public slots:
    
};

} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_DRAUGHTSGAME_H
