#ifndef BG_MODEL_GAMEMANAGER_H
#define BG_MODEL_GAMEMANAGER_H

#include <QObject>

#include "Types.h"

namespace bg {
namespace model {

class Game;

class GameManager : public QObject
{
    Q_OBJECT
public:

    static GameManager *instance();

    Game *createGame(GameType type) const;
    
signals:
    
public slots:

private:
    explicit GameManager(QObject *parent = 0);
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_GAMEMANAGER_H
