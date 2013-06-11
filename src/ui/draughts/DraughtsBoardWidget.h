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
namespace brazilian {
class Game;
}
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
    explicit BoardWidget(QWidget *parent = 0);
    ~BoardWidget();
    
    void setupBoard();
    void removeCheckerAt(int i);
private slots:
    void on_btnApplyMove_clicked();

private:
    bool isCheckerOnBoard(bg::model::draughts::Checker *checker, qint32 fieldNum);
    QString filenameByChecker(bg::model::draughts::Checker *checker);
    void setupCheckersItems();
    void resizeEvent(QResizeEvent *);
    Ui::BoardWidget *ui;

    QGraphicsScene *m_boardScene;

    QVector<QGraphicsSvgItem *> m_fields;
    QMap<qint32, QGraphicsSvgItem *> m_checkers;

    static const qreal SVG_ITEM_WIDTH;
    static const qint32 BOARD_FIELDS_DIM;

    model::draughts::brazilian::Game *m_game;
};


} // namespace draughts
} // namespace ui
} // namespace bg
#endif // BG_UI_DRAUGHTS_DRAUGHTSBOARDWIDGET_H
