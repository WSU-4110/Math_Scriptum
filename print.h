#ifndef PRINT_H
#define PRINT_H

#include <QMainWindow>
#include <QObject>
#include <QPdfWriter>
#include <QPageSize>
#include <QPainter>


class print : public QMainWindow
{
    Q_OBJECT
public:
    explicit print(QWidget *parent = nullptr);

    static void printToPDF(QString text, QImage image);

    void getFilename(QString name)
    {
        filename = name;
    }
private:
    QString filename;
    //QPrinter printer;
    //QPdfWriter *writer = new QPdfWriter(filename);
    //QPainter *painter;

signals:

public slots:
};

#endif // PRINT_H
