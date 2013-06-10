#include "DraughtsChecker.h"

#include "DraughtsTypes.h"

namespace bg {
namespace model {
namespace draughts {

Checker::Checker(QObject *parent) :
    bg::model::Piece(parent)
{
}

void Checker::setColor(Player color)
{
    m_color = color;
}

void Checker::setType(Type type)
{
    m_type = type;
}

Player Checker::color() const
{
    return m_color;
}

Type Checker::type() const
{
    return m_type;
}

} // namespace draughts
} // namespace model
} // namespace bg
