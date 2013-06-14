#include "Game.h"

#include <QMutexLocker>
#include <QDebug>

#include "Move.h"

namespace bg {
namespace model {

Game::Game(QObject *parent) :
    QObject(parent)
{
}

} // namespace model
} // namespace bg
