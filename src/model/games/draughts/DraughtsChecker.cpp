#include "DraughtsChecker.h"

namespace bg {
namespace model {
namespace draughts {

Checker::Checker(QObject *parent) :
    bg::model::Piece(parent)
{
}

void Checker::setColor(Color color)
{
    m_color = color;
}

void Checker::setType(Type type)
{
    m_type = type;
}

Checker::Color Checker::color() const
{
    return m_color;
}

Checker::Type Checker::type() const
{
    return m_type;
}

} // namespace draughts
} // namespace model
} // namespace bg
