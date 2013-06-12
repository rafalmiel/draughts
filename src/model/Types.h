#ifndef TYPES_H
#define TYPES_H

#include <QSharedPointer>

namespace bg {
namespace model {

class Move;

typedef QSharedPointer<Move> MovePtr;

enum class GameType {
    DRAUGHTS_BRAZILIAN
};

}}

#endif // TYPES_H
