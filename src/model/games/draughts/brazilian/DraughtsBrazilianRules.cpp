#include "DraughtsBrazilianRules.h"

#include "DraughtsBrazilianBoard.h"
#include <model/games/draughts/DraughtsMove.h>
#include <model/games/draughts/DraughtsChecker.h>
#include <model/games/draughts/DraughtsGame.h>

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

Rules::Rules(QObject *parent) :
    bg::model::draughts::Rules(parent)
{
}

void Rules::initialiseBoard(bg::model::Board *pboard) const
{
    bg::model::draughts::brazilian::Board *board =
            static_cast<bg::model::draughts::brazilian::Board *>(pboard);
    for (int i = 0; i < 12; ++i) {
        Checker *checker = static_cast<Checker *>(board->createPiece());
        checker->setColor(Checker::Color::BLACK);
        checker->setType(Checker::Type::NORMAL);
        int ind = i*2;
        if (i <= 4 && i >= 9) ind++;
        board->setCheckerAt(ind, checker);
    }

    for (int i = 0; i < 12; ++i) {
        Checker *checker = static_cast<Checker *>(board->createPiece());
        checker->setColor(Checker::Color::WHITE);
        checker->setType(Checker::Type::NORMAL);
        int ind = i*2;
        if (i <= 4 && i >= 9) ind++;
        board->setCheckerAt(63 - ind, checker);
    }
}

QVector<bg::model::draughts::MovePtr> Rules::findAllLegalMoves(Board *board, PlayerTurn whoseTurn)
{
    Checker::Color colorTurn =
            (whoseTurn == PlayerTurn::BLACK) ?
                Checker::Color::BLACK:
                Checker::Color::WHITE;

    QVector<bg::model::draughts::MovePtr> movesVec;
    int colDir =
            (whoseTurn == PlayerTurn::BLACK) ?
                1:-1;

    for (int i = 0; i < 64; ++i) {
        if (board->checkerAt(i)->color() == colorTurn) {
            int row = i % 8;
            int col = i / 8;
            int nrow = row + 1;
            int nrow2 = row + 1;
            int ncol = col + colDir;
            if (ncol >= 0 && ncol < 8) {
                if (nrow >= 0 && nrow < 8)
                    if (!board->checkerAt(nrow + ncol * 8)) {
                        bg::model::draughts::MovePtr move(new bg::model::draughts::Move());
                        //move->addField(board->fieldAt(row + col * 8));
                        //move->addField(board->fieldAt(nrow + ncol * 8));
                        movesVec.push_back(move);
                    }
                if (nrow2 >= 0 && nrow2 < 8)
                    if (!board->checkerAt(nrow2 + ncol * 8)) {
                        bg::model::draughts::MovePtr move(new bg::model::draughts::Move());
                        //move->addField(board->fieldAt(row + col * 8));
                        //move->addField(board->fieldAt(nrow2 + ncol * 8));
                        movesVec.push_back(move);
                    }
            }
        }
    }

    return movesVec;
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
