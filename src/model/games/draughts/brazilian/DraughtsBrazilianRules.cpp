#include "DraughtsBrazilianRules.h"

#include <QDebug>

#include "DraughtsBrazilianBoard.h"
#include "DraughtsBrazilianMove.h"
#include <model/games/draughts/DraughtsTypes.h>
#include <model/games/draughts/DraughtsChecker.h>
#include <model/games/draughts/DraughtsGame.h>
#include <model/games/draughts/DraughtsField.h>

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

Rules::~Rules()
{
    for (int i = 0; i < 64; ++i) {
        if (m_board->checkerAt(i)) {
            delete m_board->checkerAt(i);
            m_board->setCheckerAt(i, nullptr);
        }
    }
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

bool Rules::applyMove(const bg::model::draughts::MovePtr &move)
{
    if (move->size() > 0) {
        Checker *checker = move->fieldAt(0)->checker();
        if (checker && checker->color() == m_whoseTurn) {
            if (move->size() > 1) {
                if (!move->fieldAt(1)->checker()) {
                    int colDir =
                            (m_whoseTurn == Player::BLACK) ?
                                1:-1;
                    qint32 f1 = move->fieldAt(0)->fieldId();
                    qint32 f2 = move->fieldAt(1)->fieldId();
                    qint32 r1 = f1 % 8;
                    qint32 c1 = f1 / 8;
                    qint32 r2 = f2 % 8;
                    qint32 c2 = f2 / 8;
                    if (c2 == c1 + colDir && (qAbs(r1 - r2) == 1)) {
                        move->fieldAt(1)->setChecker(checker);
                        move->fieldAt(0)->setChecker(nullptr);
                        m_whoseTurn = (m_whoseTurn == Player::BLACK)?Player::WHITE:Player::BLACK;
                        findAllLegalMoves();
                        return true;
                    }
                }
            }
        }
    }

    return false;
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
                        bg::model::draughts::MovePtr move =
                                m_board->createMove().staticCast<bg::model::draughts::Move>();
                        move->addField(m_board->fieldAt(row + col * 8));
                        move->addField(m_board->fieldAt(nrow + ncol * 8));
                        movesVec.push_back(move);
                    }
                if (nrow2 >= 0 && nrow2 < 8)
                    if (!m_board->checkerAt(nrow2 + ncol * 8)) {
                        bg::model::draughts::MovePtr move =
                                m_board->createMove().staticCast<bg::model::draughts::Move>();
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
