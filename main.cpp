#include "mainwindow.h"
#include "shapearea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#define M_PI  3.14159265358979323846
#include <QApplication>

#define UNIT_TEST_ENABLED

#ifndef UNIT_TEST_ENABLED

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("CASE 1")
{
    REQUIRE(M_PI== 3.14159265358979323846);
}

TEST_CASE("CASE 2")
{
    REQUIRE(1==0);
}
#endif
