#include "DraughtsMove.h"

#include "DraughtsField.h"

namespace bg {
namespace model {
namespace draughts {

Move::Move(QObject *parent) :
    bg::model::Move(parent)
{
}

qint32 Move::size() const
{
    return m_moves.size();
}

Field *Move::fieldAt(qint32 ind)
{
    return m_moves.at(ind);
}

void Move::addField(Field *field)
{
    m_moves.push_back(field);
}

void Move::cleanup()
{
    m_moves.clear();
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

}}}
