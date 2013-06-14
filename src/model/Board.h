#ifndef BG_MODEL_BOARD_H
#define BG_MODEL_BOARD_H

#include <QObject>
#include <QString>
#include <QMutex>

#include "Types.h"

namespace bg {
namespace model {

class Piece;
class Field;
class Move;

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = 0);
    virtual ~Board();

    virtual void initialise() = 0;
    virtual Piece *createPiece() const = 0;
    virtual Field *createField() const = 0;
    virtual QString toString() const = 0;

    MovePtr createMove() const;
    
protected:
    virtual Move *createMove_impl() const = 0;

private slots:
    void slotMoveReleased(Move *move);
private:
    mutable QMutex m_movesPoolMutex;
    mutable QList<Move *> m_movesPool;
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_BOARD_H
