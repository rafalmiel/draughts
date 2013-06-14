#ifndef BG_MODEL_MOVE_H
#define BG_MODEL_MOVE_H

#include <QObject>
#include <QSharedPointer>

#include "Types.h"

namespace bg {
namespace model {

class Move : public QObject
{
    Q_OBJECT
public:
    friend class Board;

    virtual QString toString() const = 0;
    virtual void cleanup() = 0;
    
signals:
    void released(Move *);
    
public slots:
    void release();

protected:
    explicit Move(QObject *parent = 0);
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_MOVE_H
