#ifndef PRINT_H
#define PRINT_H

#include <QMainWindow>
#include <QObject>
#include <QPdfWriter>
#include <QPageSize>
#include <QPainter>
#include "equationsarea.h"


class print : public EquationsArea
{
    Q_OBJECT
public:
    explicit print(QWidget *parent = nullptr);

    void printToPDF(QString text, QImage image);

signals:

public slots:
};

#endif // PRINT_H
