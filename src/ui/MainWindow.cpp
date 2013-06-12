#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <model/Types.h>
#include <model/GameManager.h>

#include <model/games/draughts/DraughtsGame.h>

#include "draughts/DraughtsBoardWidget.h"

namespace bg {
namespace ui {

MainWindow::MainWindow(model::GameManager *gameManager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_gameManager(gameManager),
    m_game(nullptr)
{
    ui->setupUi(this);

}

void MainWindow::on_actionGameDraughtsBrazilian_triggered()
{
    if (m_game) delete m_game;

    m_game = m_gameManager->createGame(model::GameType::DRAUGHTS_BRAZILIAN);
    static_cast<model::draughts::Game *>(m_game)->beginGame();
    draughts::BoardWidget *w = new draughts::BoardWidget(
                static_cast<model::draughts::Game *>(m_game));
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{
    if (m_game) delete m_game;
    delete ui;
}

}}


