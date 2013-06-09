#ifndef BG_MODEL_PIECE_H
#define BG_MODEL_PIECE_H

#include <QObject>

namespace bg {
namespace model {

class Piece : public QObject
{
    Q_OBJECT
public:
    explicit Piece(QObject *parent = 0);
    
signals:
    
public slots:
    
};

} // namespace model
} // namespace bg

#endif // BG_MODEL_PIECE_H
