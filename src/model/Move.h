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
    explicit Move(QObject *parent = 0);

    virtual QString toString() const = 0;
    
signals:
    
public slots:
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_MOVE_H
