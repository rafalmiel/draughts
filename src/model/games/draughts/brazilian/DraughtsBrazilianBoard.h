#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_BOARD_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_BOARD_H

#include <model/games/draughts/DraughtsBoard.h>

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

class Board : public ::bg::model::draughts::Board
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = 0);

    void initialise();

    bg::model::Piece *createPiece() const;
    bg::model::Field *createField() const;
    
signals:
    
public slots:
    
};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_BOARD_H
