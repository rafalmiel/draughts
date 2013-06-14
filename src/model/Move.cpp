#include "Move.h"

namespace bg {
namespace model {

Move::Move(QObject *parent) :
    QObject(parent)
{
}

void Move::release()
{
    cleanup();
    emit released(this);
}

} // namespace model
} // namespace bg
