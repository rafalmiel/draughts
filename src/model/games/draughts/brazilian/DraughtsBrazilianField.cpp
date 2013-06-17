#include "DraughtsBrazilianField.h"

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

Field::Field(QObject *parent) : draughts::Field(parent)
{
}

QString Field::toString() const
{
    qint32 row = m_fieldNum % 8;
    qint32 col = m_fieldNum / 8;
    return QString(QChar('a' + row)) + QString::number(8 - col);
}

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg
