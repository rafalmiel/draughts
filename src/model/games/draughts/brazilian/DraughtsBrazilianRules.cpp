#include "DraughtsBrazilianRules.h"

#include <QDebug>

#include <model/games/draughts/DraughtsTypes.h>
#include "DraughtsBrazilianBoard.h"
#include <model/games/draughts/brazilian/DraughtsBrazilianMove.h>
#include <model/games/draughts/DraughtsChecker.h>
#include <model/games/draughts/DraughtsGame.h>

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

Rules::Rules(QObject *parent) :
    bg::model::draughts::Rules(parent),
    m_board(nullptr),
    m_whoseTurn(Player::WHITE)
{
}

void Rules::setBoard(Board *board)
{
    m_board = board;
}

void Rules::beginGame()
{
    m_whoseTurn = Player::WHITE;
    for (int i = 0; i < 12; ++i) {
        Checker *checker = static_cast<Checker *>(m_board->createPiece());
        checker->setColor(Player::BLACK);
        checker->setType(Type::NORMAL);
        int ind = i*2;
        if (ind < 8 || ind >= 16) ind++;
        m_board->setCheckerAt(ind, checker);
    }

    for (int i = 0; i < 12; ++i) {
        Checker *checker = static_cast<Checker *>(m_board->createPiece());
        checker->setColor(Player::WHITE);
        checker->setType(Type::NORMAL);
        int ind = i*2;
        if (ind < 8 || ind >= 16) ind++;
        m_board->setCheckerAt(63 - ind, checker);
    }
}


QVector<bg::model::draughts::MovePtr> Rules::findAllLegalMoves()
{
    QVector<bg::model::draughts::MovePtr> movesVec;
    int colDir =
            (m_whoseTurn == Player::BLACK) ?
                1:-1;

    for (int i = 0; i < 64; ++i) {
        draughts::Checker *checker = m_board->checkerAt(i);
        if (checker && checker->color() == m_whoseTurn) {
            int row = i % 8;
            int col = i / 8;
            int nrow = row + 1;
            int nrow2 = row - 1;
            int ncol = col + colDir;
            if (ncol >= 0 && ncol < 8) {
                if (nrow >= 0 && nrow < 8)
                    if (!m_board->checkerAt(nrow + ncol * 8)) {
                        bg::model::draughts::MovePtr move(new bg::model::draughts::brazilian::Move());
                        move->addField(m_board->fieldAt(row + col * 8));
                        move->addField(m_board->fieldAt(nrow + ncol * 8));
                        movesVec.push_back(move);
                    }
                if (nrow2 >= 0 && nrow2 < 8)
                    if (!m_board->checkerAt(nrow2 + ncol * 8)) {
                        bg::model::draughts::MovePtr move(new bg::model::draughts::brazilian::Move());
                        move->addField(m_board->fieldAt(row + col * 8));
                        move->addField(m_board->fieldAt(nrow2 + ncol * 8));
                        movesVec.push_back(move);
                    }
            }
        }
    }

    foreach (bg::model::draughts::MovePtr ptr, movesVec) {
        qDebug() << ptr->toString();
    }

    return movesVec;
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
