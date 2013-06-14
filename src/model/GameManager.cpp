#include "GameManager.h"

#include "games/draughts/brazilian/DraughtsBrazilianGame.h"

namespace bg {
namespace model {

GameManager::GameManager(QObject *parent) :
    QObject(parent)
{
}

GameManager* GameManager::instance()
{
    static GameManager instance;
    return &instance;
}

Game *GameManager::createGame(const GameType type) const
{
    switch (type) {
    case GameType::DRAUGHTS_BRAZILIAN:
        return new draughts::brazilian::Game();
    }

    return nullptr;
}

} // namespace model
} // namespace bg
