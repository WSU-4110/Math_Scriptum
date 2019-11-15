#include "print.h"
#include "equationsarea.h"
#include <QPaintEvent>
#include <QPageLayout>
#include <QRect>
#include <QTextStream>
#include <QFileDialog>

print::print(QWidget *parent) : EquationsArea(parent)//, EquationsArea(parent)
{

}

void print::printToPDF(QString text, QImage image)
{
    int numOfChars =text.count();
    //reduce numOfChars during loop

    int index = 0;


    QString fileName = QFileDialog::getSaveFileName(this, tr("Create Save File"), "/home/jana/untitled.pdf", tr("Text (*.pdf)"));



    //QPrinter printer;
    //QPageLayout(const QPageSize &pageSize, Orientation orientation,
    //const QMarginsF &margins, Unit units = Point,
    //const QMarginsF &minMargins = QMarginsF(0, 0, 0, 0));
    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::Letter));

    writer.setPageMargins(QMarginsF(QMarginsF(50,50,2,2)));



    QPainter painter(&writer);
    painter.begin(&writer);

    painter.drawText(0,0,text);


    writer.newPage();


    float step = length_of_Interval / step_count_of_shape;
    Scale = Scale;
    //painter(this); ///calling "this"
    painter.setRenderHint(QPainter::Antialiasing, true); ///prevents liasing

    painter.setBrush(background_color);
    painter.setPen(graph_color);
    //QRect rect = QRect(290, 20, 70, 40);
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();

    ///to adjust the dotted line and make it into smooth line
    QPointF previous_point = drawGeneral(0);
    QPointF previous_pixel;

    ///implicit conversion that will turn the floating numbers to a double
    previous_pixel.setX(previous_point.x() * Scale + center.x());
    previous_pixel.setY(previous_point.y() * Scale + center.y());

    ///for loop algorithm that will set x and y axis when the program draws the shape
    for(float t = -length_of_Interval; t < length_of_Interval; t+= step)
    {
        ///Condition that will check if graph is for 1/x and if t is 0 continue past since 1 cannot be divide by 0
        if (Graph == XReciprical && t == 0.0)
            continue;

        QPointF point = drawGeneral(t);
        QPointF single_pixel;
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        painter.drawLine(single_pixel, previous_pixel);
        previous_pixel = single_pixel;
    }

    ///for loop algorithm that will draw x axis when the program draws the shape
    for(float t = -length_of_Interval; t < length_of_Interval; t+= step)
    {
        QPointF point = drawXAxis(t);
        QPointF single_pixel;
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        painter.drawLine(single_pixel, previous_pixel);
        previous_pixel = single_pixel;
    }

    ///for loop algorithm that will draw y axis when the program draws the shape
    for(float t = -length_of_Interval; t < length_of_Interval; t+= step)
    {
        QPointF point = drawYAxis(t);
        QPointF single_pixel;
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        painter.drawLine(single_pixel, previous_pixel);
        previous_pixel = single_pixel;
    }
/*
    //EquationsArea::paintEvent(writer);
    QRectF target(474, 351, 614, 331);
    QRectF source(474, 351, 614, 331);
    QPoint point(1000,1000);
    painter.drawImage(target, image, source);
    painter.end();
    //todo
    */
}





