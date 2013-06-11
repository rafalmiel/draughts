#ifndef BG_MODEL_GAME_H
#define BG_MODEL_GAME_H

#include <QObject>

namespace bg {
namespace model {

class Board;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    
signals:
    
public slots:
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_GAME_H
