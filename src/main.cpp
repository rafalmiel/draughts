#include "ui/MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bg::ui::MainWindow w;
    w.show();

    return a.exec();
}
