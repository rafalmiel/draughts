#include "DraughtsBrazilianGame.h"

#include "DraughtsBrazilianBoard.h"
#include "DraughtsBrazilianRules.h"

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

Game::Game(QObject *parent) :
    bg::model::draughts::Game(parent)
{
}

bg::model::Board *createBoard()
{
    return new bg::model::draughts::brazilian::Board();
}

bg::model::Rules *createRules()
{
    return new bg::model::draughts::brazilian::Rules();
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
