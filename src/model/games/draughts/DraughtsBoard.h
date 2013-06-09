#ifndef BG_MODEL_DRAUGHTS_BOARD_H
#define BG_MODEL_DRAUGHTS_BOARD_H

#include <QVector>

#include <model/Board.h>

namespace bg {
namespace model {
namespace draughts {

class Field;
class Checker;

class Board : public ::bg::model::Board
{
    Q_OBJECT
public:
    explicit Board(qint32 fieldsNum, QObject *parent = 0);

    void initialise();

    QString toString() const;

    void setCheckerAt(qint32 fieldNum, Checker *checker);
    Checker *checkerAt(qint32 fieldNum) const;
    Field *fiendAt(qint32 fieldNum) const;
    
signals:
    
public slots:

protected:
    qint32 m_fieldsNum;
    QVector<Field *> m_fields;
    
};

} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BOARD_H
