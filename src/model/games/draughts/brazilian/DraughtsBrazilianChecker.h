#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANCHECKER_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANCHECKER_H

#include <model/games/draughts/DraughtsChecker.h>

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

class Checker : public bg::model::draughts::Checker
{
    Q_OBJECT
public:
    explicit Checker(QObject *parent = 0);
};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANCHECKER_H
