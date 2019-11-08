#include "equationsarea.h"
#include "graphs.h"

EquationsArea::EquationsArea(QWidget *parent) : QWidget(parent),
    background_color(255,255,255),
    graph_color(0,0,0),
    Graph(Line)
{
      load_graph_change();
}

QPointF EquationsArea::drawGeneral(float t)
{
    ///break statements have been removed since each case returns a QPointF function
    switch (Graph)
    {
        case Line:
            return graph::drawLine(t);
        case Parabola:
            return graph::drawParabola(t);
        case Sqrt:
            return graph::drawSQRT(t);
        case XReciprical:
            return graph::drawXReciprical(t);
        default:
            return QPointF(0,0);
    }
}

void EquationsArea::load_graph_change()
{
    Scale = 50;
    length_of_Interval = 50;
    step_count_of_shape = 2500;
}

void EquationsArea::paintEvent(QPaintEvent *event)
{
    float step = length_of_Interval / step_count_of_shape;
    QPainter painter(this); ///calling "this"
    painter.setRenderHint(QPainter::Antialiasing, true); ///prevents liasing
    painter.setBrush(background_color);
    painter.setPen(graph_color);
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
        QPointF point = graph::drawXAxis(t);
        QPointF single_pixel;
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        painter.drawLine(single_pixel, previous_pixel);
        previous_pixel = single_pixel;
    }

    ///for loop algorithm that will draw y axis when the program draws the shape
    for(float t = -length_of_Interval; t < length_of_Interval; t+= step)
    {
        QPointF point = graph::drawYAxis(t);
        QPointF single_pixel;
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        painter.drawLine(single_pixel, previous_pixel);
        previous_pixel = single_pixel;
    }
}


