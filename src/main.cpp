#include "ui/MainWindow.h"
#include <QApplication>

#include <model/GameManager.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bg::ui::MainWindow w(::bg::model::GameManager::instance());
    w.show();

    return a.exec();
}
