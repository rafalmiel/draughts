#ifndef BG_MODEL_DRAUGHTS_FIELD_H
#define BG_MODEL_DRAUGHTS_FIELD_H

#include <model/Field.h>

namespace bg {
namespace model {
namespace draughts {

class Checker;

class Field : public bg::model::Field
{
    Q_OBJECT
public:
    explicit Field(QObject *parent = 0);

    void setNum(qint32 id);
    qint32 num() const;

    void setChecker(Checker *checker);
    Checker *checker() const;
    
signals:
    
public slots:

protected:
    qint32 m_fieldNum;

    Checker *m_checker;
    
};

} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_FIELD_H
