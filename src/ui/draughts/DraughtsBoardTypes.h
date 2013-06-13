#ifndef DRAUGHTSBOARDTYPES_H
#define DRAUGHTSBOARDTYPES_H

#include <QObject>

namespace bg {
namespace ui {
namespace draughts {

enum class SvgKeys {
    Type = 0,
    FieldNum = 1,
    CheckerColor = 2
};

enum class ItemType {
    Field = 0,
    Checker = 1,
    Selection = 2
};

template<typename T>
qint32 toInt(const T &value)
{
    return static_cast<qint32>(value);
}

}
}
}

#endif // DRAUGHTSBOARDTYPES_H
