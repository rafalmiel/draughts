#ifndef BG_MODEL_FIELD_H
#define BG_MODEL_FIELD_H

#include <QObject>

namespace bg {
namespace model {

class Field : public QObject
{
    Q_OBJECT
public:
    explicit Field(QObject *parent = 0);
    
signals:
    
public slots:
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_FIELD_H
