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

    draughts::BoardWidget *w = new draughts::BoardWidget();
    w->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

}}
