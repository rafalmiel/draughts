#include "DraughtsBrazilianBoard.h"

#include <model/games/draughts/DraughtsChecker.h>
#include <model/games/draughts/DraughtsField.h>

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

Board::Board(QObject *parent) :
    ::bg::model::draughts::Board(64, parent)
{
}

void Board::initialise()
{
    bg::model::draughts::Board::initialise();
}

bg::model::Piece *Board::createPiece() const
{
    return new bg::model::draughts::Checker();
}

bg::model::Field *Board::createField() const
{
    return new bg::model::draughts::Field();
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
