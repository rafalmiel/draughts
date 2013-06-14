#include "Board.h"

#include <QDebug>

#include "Types.h"
#include "Move.h"

namespace bg {
namespace model {

Board::Board(QObject *parent) :
    QObject(parent)
{
    m_movesPool.reserve(128);
}

Board::~Board()
{
    QMutexLocker l(&m_movesPoolMutex);
    foreach (Move *move, m_movesPool) {
        delete move;
    }
}

void Board::slotMoveReleased(Move *move)
{
    QMutexLocker l(&m_movesPoolMutex);
    m_movesPool.push_back(move);
}

MovePtr Board::createMove() const
{
    QMutexLocker l(&m_movesPoolMutex);
    if (m_movesPool.empty()) {
        MovePtr ptr(createMove_impl(), &model::Move::release);
        connect(ptr.data(), SIGNAL(released(Move*)), this, SLOT(slotMoveReleased(Move*)));
        return ptr;
    } else {
        MovePtr ptr(m_movesPool.back(), &model::Move::release);
        m_movesPool.pop_back();
        return ptr;
    }
}

} // namespace model
} // namespace bg
