#ifndef BG_MODEL_DRAUGHTS_CHECKER_H
#define BG_MODEL_DRAUGHTS_CHECKER_H

#include <model/Piece.h>

namespace bg {
namespace model {
namespace draughts {

class Checker : public bg::model::Piece
{
    Q_OBJECT
public:
    enum class Type {
        NORMAL = 1,
        KING = 2
    };

    enum class Color {
        WHITE = 1,
        BLACK = 2
    };

    explicit Checker(QObject *parent = 0);

    void setColor(Color color);
    void setType(Type type);

    Color color() const;
    Type type() const;
    
signals:
    
public slots:

private:
    Color m_color;
    Type m_type;
    
};

} // namespace draughts
} // namespace model
} // namespace bg

#endif // BG_MODEL_DRAUGHTS_CHECKER_H
