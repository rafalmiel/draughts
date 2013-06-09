#include "DraughtsField.h"

namespace bg {
namespace model {
namespace draughts {

Field::Field(QObject *parent) :
    bg::model::Field(parent),
    m_fieldId(0),
    m_checker(nullptr)
{
}

void Field::setFieldId(qint32 id)
{
    m_fieldId = id;
}

qint32 Field::fieldId() const
{
    return m_fieldId;
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
