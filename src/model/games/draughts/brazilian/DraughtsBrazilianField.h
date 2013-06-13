#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANFIELD_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANFIELD_H

#include <model/games/draughts/DraughtsField.h>

namespace bg {
namespace model {
namespace draughts {
namespace brazilian {

class Field : public bg::model::draughts::Field
{
    Q_OBJECT
public:
    Field(QObject *parent = 0);

    QString toString() const;
};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANFIELD_H
