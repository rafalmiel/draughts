#ifndef BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H
#define BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QResizeEvent>
#include <QMap>

#include <model/games/draughts/DraughtsTypes.h>

namespace bg {

namespace model {
namespace draughts {
class Checker;
class Game;
class Field;
}
}


namespace ui {
namespace draughts {

namespace Ui {
class BoardWidget;
}

class DraughtsBoardScene;

class BoardWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BoardWidget(model::draughts::Game *game, QWidget *parent = 0);
    ~BoardWidget();
    
    void setupBoard();
    void removeCheckerAt(int i);
private slots:
    void slotOnFieldClicked(qint32);
    void slotOnFieldHovered(qint32);

private:
    void selectField(qint32 num, bool select = true);

    model::draughts::Field *stringToField(const QString &field) const;
    bool isCheckerOnBoard(bg::model::draughts::Checker *checker, qint32 fieldNum);
    QString filenameByChecker(bg::model::draughts::Checker *checker);
    void setupCheckersItems();
    void resizeEvent(QResizeEvent *);
    Ui::BoardWidget *ui;


    DraughtsBoardScene *m_boardScene;

    QVector<QGraphicsSvgItem *> m_fields;
    QMap<qint32, QGraphicsSvgItem *> m_checkers;

    QMap<qint32, QGraphicsRectItem *> m_clickedFields;

    QVector<qint32> m_currentSelection;
    model::draughts::MovesVector m_legalMoves;
    model::draughts::MovesVector m_currentMoves;

    qint32 m_hoveredField;


    model::draughts::Game *m_game;

    const qint32 c_fieldsNum;
    const qint32 c_boardDim;

    static const qreal SVG_ITEM_WIDTH;
};


} // namespace draughts
} // namespace ui
} // namespace bg
#endif // BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H
