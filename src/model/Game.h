#ifndef BG_MODEL_GAME_H
#define BG_MODEL_GAME_H

#include <QObject>
#include <QList>
#include <QMutex>
#include "Types.h"

namespace bg {
namespace model {

class Board;
class Move;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);

    virtual MovePtr createMove() const = 0;
    

    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_GAME_H
