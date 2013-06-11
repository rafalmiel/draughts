#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANRULES_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANRULES_H

#include <model/games/draughts/DraughtsMove.h>
#include <model/games/draughts/DraughtsRules.h>

namespace bg {
namespace model {
namespace draughts {

enum class Player;

namespace brazilian {

class Board;

class Rules : public bg::model::draughts::Rules
{
    Q_OBJECT
public:
    explicit Rules(QObject *parent = 0);

    bool applyMove(const MovePtr &move);
    void setBoard(Board *board);
    void beginGame();
    QVector<bg::model::draughts::MovePtr> findAllLegalMoves();
    
signals:
    
public slots:

private:
    Board *m_board;
    Player m_whoseTurn;

};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANRULES_H
