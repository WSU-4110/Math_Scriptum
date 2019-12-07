#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ///create instance of the main application window
    MainWindow w;
    ///call show to load the application
    w.show();
    ///execute application
    return a.exec();
}
