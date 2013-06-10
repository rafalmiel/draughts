#include "DraughtsBoard.h"

#include <model/games/draughts/DraughtsField.h>

namespace bg {
namespace model {
namespace draughts {

Board::Board(qint32 fieldsNum, QObject *parent) :
    ::bg::model::Board(parent),
    m_fieldsNum(fieldsNum)
{
}

void Board::initialise()
{
    m_fields.clear();

    /** board fields nums are counted from top left corner:
     *
     * 0 1 2
     * 3 4 5
     * 6 7 8
     */
    for (qint32 i = 0; i < m_fieldsNum; ++i) {
        m_fields.push_back(static_cast<bg::model::draughts::Field*>(createField()));
        m_fields.back()->setFieldId(i);
    }
}

void Board::setCheckerAt(qint32 fieldNum, Checker *checker)
{
    m_fields[fieldNum]->setChecker(checker);
}

Checker *Board::checkerAt(qint32 fieldNum) const
{
    return m_fields.at(fieldNum)->checker();
}

bg::model::draughts::Field *Board::fieldAt(qint32 fieldNum) const
{
    return m_fields.at(fieldNum);
}

QString Board::toString() const
{
    return "";
}

} // namespace draughts
} // namespace model
} // namespace bg
