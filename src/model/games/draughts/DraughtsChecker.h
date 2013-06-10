#ifndef BG_MODEL_DRAUGHTS_CHECKER_H
#define BG_MODEL_DRAUGHTS_CHECKER_H

#include <model/Piece.h>

namespace bg {
namespace model {
namespace draughts {

enum class Player;
enum class Type;

class Checker : public bg::model::Piece
{
    Q_OBJECT
public:

    explicit Checker(QObject *parent = 0);

    void setColor(Player color);
    void setType(Type type);

    Player color() const;
    Type type() const;
    
signals:
    
public slots:

private:
    Player m_color;
    Type m_type;
    
};

} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_CHECKER_H
