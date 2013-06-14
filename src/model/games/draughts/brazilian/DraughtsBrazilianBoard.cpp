#include "DraughtsBrazilianBoard.h"

#include <model/games/draughts/brazilian/DraughtsBrazilianChecker.h>
#include <model/games/draughts/brazilian/DraughtsBrazilianField.h>
#include <model/games/draughts/brazilian/DraughtsBrazilianMove.h>

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
	return new bg::model::draughts::brazilian::Checker();
}

bg::model::Field *Board::createField() const
{
	return new bg::model::draughts::brazilian::Field();
}

bg::model::Move *Board::createMove_impl() const
{
    return new bg::model::draughts::brazilian::Move();
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
