#include "DraughtsBoardScene.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QDebug>

#include "DraughtsBoardTypes.h"

namespace bg {
namespace ui {
namespace draughts {

DraughtsBoardScene::DraughtsBoardScene(QObject *parent) :
    QGraphicsScene(parent)
{

}

void DraughtsBoardScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem *> itms = items(event->scenePos());
    foreach (const QGraphicsItem *itm, itms) {
        if (itm->data(toInt(ItemKey::Type)).toInt() == toInt(ItemType::Field)) {
            emit fieldHovered(itm->data(toInt(ItemKey::FieldNum)).toInt());
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void DraughtsBoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem *> itms = items(event->scenePos());
    foreach (const QGraphicsItem *itm, itms) {
        if (itm->data(toInt(ItemKey::Type)).toInt() == toInt(ItemType::Field)) {
            emit fieldClicked(itm->data(toInt(ItemKey::FieldNum)).toInt());
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

} // namespace draughts
} // namespace ui
} // namespace bg
