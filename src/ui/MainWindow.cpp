#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "draughts/DraughtsBoardWidget.h"

namespace bg {
namespace ui {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::on_actionGameDraughtsBrazilian_triggered()
{
    draughts::BoardWidget *w = new draughts::BoardWidget();
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{
    delete ui;
}

}}


