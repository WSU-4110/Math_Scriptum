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

    void getFilename(QString name)
    {
        filename = name;
    }

    //void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    QString filename;
    //QPrinter printer;
    //QPdfWriter *writer = new QPdfWriter(filename);
    //QPainter *painter;

signals:

public slots:
};

#endif // PRINT_H
