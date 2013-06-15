#ifndef BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANGAME_H
#define BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANGAME_H

#include <model/games/draughts/DraughtsGame.h>

namespace bg {
namespace model {

class Board;
class Rules;

namespace draughts {
class Field;
namespace brazilian {

class Board;
class Rules;

class Game : public bg::model::draughts::Game
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    ~Game();

    void beginGame();

    bg::model::Board *createBoard();
    bg::model::Rules *createRules();

    bg::model::draughts::Board * board() const;

    bool applyMove(const draughts::MovePtr &move);
    MovesVector findAllLegalMoves() const;

    model::MovePtr createMove() const;
signals:
    
public slots:
    
private:
    bg::model::Move* createMove_impl() const;
    draughts::Field *stringToField(const QString &field) const;
    bg::model::draughts::brazilian::Board *m_board;
    bg::model::draughts::brazilian::Rules *m_rules;
};

} // namespace brazilian
} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_BRAZILIAN_DRAUGHTSBRAZILIANGAME_H
