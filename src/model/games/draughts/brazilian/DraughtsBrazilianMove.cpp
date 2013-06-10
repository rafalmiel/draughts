#include "DraughtsBrazilianMove.h"

#include "DraughtsBrazilianField.h"

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

Move::Move()
{
}

QString Move::toString() const
{
    QString ret = "";
    bool first = true;
    foreach (const draughts::Field *field, m_moves) {
        if (!first) ret += "-";
        first = false;
        ret += field->toString();
    }
    return ret;
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
