#include "DraughtsBrazilianGame.h"

#include "DraughtsBrazilianBoard.h"
#include "DraughtsBrazilianRules.h"

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

Game::Game(QObject *parent) :
    bg::model::draughts::Game(parent),
    m_board(nullptr),
    m_rules(nullptr)
{
}

void Game::beginGame()
{
    if (m_board) delete m_board;
    if (m_rules) delete m_rules;

    m_board = static_cast<draughts::brazilian::Board *>(
                createBoard());
    m_rules = static_cast<draughts::brazilian::Rules *>(
                createRules());

    m_rules->setBoard(m_board);
    m_rules->beginGame();

    m_rules->findAllLegalMoves();
}

bg::model::draughts::brazilian::Board *Game::board() const
{
    return m_board;
}

bg::model::Board *Game::createBoard()
{
    bg::model::Board *board = new bg::model::draughts::brazilian::Board();
    board->initialise();
    return board;
}

bg::model::Rules *Game::createRules()
{
    return new bg::model::draughts::brazilian::Rules();
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
