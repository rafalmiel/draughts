#ifndef BG_MODEL_BOARD_H
#define BG_MODEL_BOARD_H

#include <QObject>
#include <QString>

namespace bg {
namespace model {

class Piece;
class Field;

class Board : public QObject
{
    Q_OBJECT
public:
    explicit Board(QObject *parent = 0);

    virtual void initialise() = 0;
    virtual Piece *createPiece() const = 0;
    virtual Field *createField() const = 0;
    virtual QString toString() const = 0;
    
signals:
    
public slots:
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_BOARD_H
