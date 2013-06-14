#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANMOVE_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANMOVE_H

#include <model/games/draughts/DraughtsMove.h>

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

class Move : public bg::model::draughts::Move
{
    Q_OBJECT
public:
    Move(QObject *parent = 0);

    QString toString() const;
};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANMOVE_H
