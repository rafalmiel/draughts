#ifndef BG_MODEL_BOARD_H
#define BG_MODEL_BOARD_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QVector>

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

private slots:
    void slotMoveReleased(Move *move);

private:
    virtual Move *createMove_impl() const = 0;
    mutable QMutex m_movesPoolMutex;
    mutable QVector<Move *> m_movesPool;
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_BOARD_H
