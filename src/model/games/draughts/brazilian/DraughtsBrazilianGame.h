#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANGAME_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANGAME_H

#include <model/games/draughts/DraughtsGame.h>

namespace bg {
namespace model {

class Board;
class Rules;

namespace draughts {
namespace brazilian {

class Game : public bg::model::draughts::Game
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);

    bg::model::Board *createBoard();
    bg::model::Rules *createRules();
    
signals:
    
public slots:
    
};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANGAME_H
