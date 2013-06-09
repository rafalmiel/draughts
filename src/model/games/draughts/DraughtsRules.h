#ifndef BG_MODEL_DRAUGHTS_RULES_H
#define BG_MODEL_DRAUGHTS_RULES_H

#include <model/Rules.h>

namespace bg {
namespace model {
namespace draughts {

class Rules : public bg::model::Rules
{
    Q_OBJECT
public:
    explicit Rules(QObject *parent = 0);
    
signals:
    
public slots:
    
};

} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_RULES_H
