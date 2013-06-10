#ifndef BG_MODEL_DRAUGHTS_MOVE_H
#define BG_MODEL_DRAUGHTS_MOVE_H

#include <QVector>

#include <model/Move.h>

namespace bg {
namespace model {
namespace draughts {

class Field;
class Move;

typedef QSharedPointer<Move> MovePtr;

class Move : public bg::model::Move
{
    Q_OBJECT
public:
    explicit Move(QObject *parent = 0);

    qint32 size() const;
    Field *fieldAt(qint32 ind);
    void addField(Field *field);
    
signals:
    
public slots:

protected:
    QVector<Field *> m_moves;
    
};

}
}
}

#endif // BG_MODEL_DRAUGHTS_MOVE_H
