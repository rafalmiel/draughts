#ifndef DRAUGHTSTYPES_H
#define DRAUGHTSTYPES_H

#include <QSharedPointer>

namespace bg {
namespace model {
namespace draughts {

class Move;

typedef QSharedPointer<Move> MovePtr;
typedef QVector<MovePtr> MovesVector;

enum class Player {
    WHITE,
    BLACK
};

enum class Type {
    NORMAL = 1,
    KING = 2
};

}
}
}

#endif // DRAUGHTSTYPES_H
