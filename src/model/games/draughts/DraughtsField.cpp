#include "DraughtsField.h"

namespace bg {
namespace model {
namespace draughts {

Field::Field(QObject *parent) :
    bg::model::Field(parent),
    m_fieldNum(0),
    m_checker(nullptr)
{
}

void Field::setNum(qint32 id)
{
    m_fieldNum = id;
}

qint32 Field::num() const
{
    return m_fieldNum;
}

void Field::setChecker(Checker *checker)
{
    m_checker = checker;
}

Checker *Field::checker() const
{
    return m_checker;
}

} // namespace draughts
} // namespace model
} // namespace bg
