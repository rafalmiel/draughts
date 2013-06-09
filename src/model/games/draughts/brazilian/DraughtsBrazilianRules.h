#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANRULES_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANRULES_H

#include <model/games/draughts/DraughtsMove.h>
#include <model/games/draughts/DraughtsRules.h>

namespace bg {
namespace model {
namespace draughts {

enum class PlayerTurn;

namespace brazilian {

class Board;

class Rules : public bg::model::draughts::Rules
{
    Q_OBJECT
public:
    explicit Rules(QObject *parent = 0);

    void initialiseBoard(bg::model::Board *board) const;
    QVector<bg::model::draughts::MovePtr> findAllLegalMoves(Board *board, PlayerTurn whoseTurn);
    
signals:
    
public slots:

};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANRULES_H
