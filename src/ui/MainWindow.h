#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

namespace bg {

namespace model {
class GameManager;
class Game;
}

namespace ui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(model::GameManager *gameManager, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionGameDraughtsBrazilian_triggered();

private:
    Ui::MainWindow *ui;
    model::GameManager *m_gameManager;
    model::Game *m_game;

};

}
}


#endif // MAINWINDOW_H
