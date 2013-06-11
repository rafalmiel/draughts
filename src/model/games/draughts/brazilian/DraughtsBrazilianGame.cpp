#include "DraughtsBrazilianGame.h"

#include <QStringList>

#include "DraughtsBrazilianBoard.h"
#include "DraughtsBrazilianRules.h"
#include "DraughtsBrazilianMove.h"

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

bool Game::applyMove(const QString &move)
{
    QStringList splitMove = move.split("-");
    bg::model::draughts::MovePtr mov(new bg::model::draughts::brazilian::Move());
    foreach (const QString &str, splitMove) {
        mov->addField(stringToField(str));
    }
    return m_rules->applyMove(mov);
}

draughts::Field *Game::stringToField(const QString &field) const
{
    if (field.size() == 2) {
        qint32 row = field.toStdString().at(0) - 'a';
        qint32 col = 8 - (field.toStdString().at(1) - '0');
        return m_board->fieldAt(col * 8 + row);
    }

    return nullptr;
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
