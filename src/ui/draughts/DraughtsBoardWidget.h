#ifndef BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H
#define BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QResizeEvent>
#include <QMap>

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

class BoardWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BoardWidget(model::draughts::Game *game, QWidget *parent = 0);
    ~BoardWidget();
    
    void setupBoard();
    void removeCheckerAt(int i);
private slots:
    void on_btnApplyMove_clicked();

private:
    model::draughts::Field *stringToField(const QString &field) const;
    bool isCheckerOnBoard(bg::model::draughts::Checker *checker, qint32 fieldNum);
    QString filenameByChecker(bg::model::draughts::Checker *checker);
    void setupCheckersItems();
    void resizeEvent(QResizeEvent *);
    Ui::BoardWidget *ui;

    QGraphicsScene *m_boardScene;

    QVector<QGraphicsSvgItem *> m_fields;
    QMap<qint32, QGraphicsSvgItem *> m_checkers;


    model::draughts::Game *m_game;

    const qint32 c_fieldsNum;
    const qint32 c_boardDim;

    static const qreal SVG_ITEM_WIDTH;
};


} // namespace draughts
} // namespace ui
} // namespace bg
#endif // BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H
