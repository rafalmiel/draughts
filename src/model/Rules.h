#ifndef BG_MODEL_RULES_H
#define BG_MODEL_RULES_H

#include <QObject>

namespace bg {
namespace model {

class Board;

class Rules : public QObject
{
    Q_OBJECT
public:
    explicit Rules(QObject *parent = 0);

    virtual void initialiseBoard(bg::model::Board *board) const = 0;
    
signals:
    
public slots:
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_RULES_H
