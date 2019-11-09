#include "print.h"

print::print(QWidget *parent) : QMainWindow(parent)
{

}

void print::printToPDF(QString text, QImage image)
{
    //QPrinter printer;
    QPdfWriter writer("/home/jack/Desktop/test.pdf");
    writer.setPageSize(QPageSize(QPageSize::Letter));
    QPainter painter(&writer);
    painter.drawText(0,0,text);
    writer.newPage();
    painter.drawImage(0,0, image);
    //todo
}





