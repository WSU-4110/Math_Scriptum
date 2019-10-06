#include "shapearea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#define M_PI  3.14159265358979323846

ShapeArea::ShapeArea(QWidget *parent) : QWidget(parent),
    background_color(0,0,255),
    shape_color(255,255,255),
    Shape(Astroid)
{
    load_shape_change();
}

QSize ShapeArea::minimumSizeHint() const
{
    return QSize(399, 399);
}
QSize ShapeArea::sizeHint() const
{
    return QSize(399,399);
}

QPointF ShapeArea::drawGeneral(float t)
{
    switch (Shape)
    {
    case Astroid:
        return drawAstroid(t);
        break;


    default:
        break;

    }
    return QPointF(0,0);
}

void ShapeArea::load_shape_change()
{
    switch(Shape)
    {
    case Astroid:
            Scale = 50;
            length_of_Interval = 2 * M_PI;
            step_count_of_shape = 103; //mstepcount
        break;

    default:
        break;

    }
}

QPointF ShapeArea::drawAstroid(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}

void ShapeArea::paintEvent(QPaintEvent *event)
{
    float step = length_of_Interval / step_count_of_shape;


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(background_color);
    painter.setPen(shape_color);
    painter.drawRect(this->rect());
    QPoint center = this->rect().center();
    ///to adjust the dotted line and make it into smooth line
    QPointF previous_point = drawGeneral(0);
    QPoint previous_pixel;
    ///implicit conversion that will turn the floating numbers to a double
    previous_pixel.setX(previous_point.x() * Scale + center.x());
    previous_pixel.setY(previous_point.y() * Scale + center.y());

    for(float t = 0; t < length_of_Interval; t+= step)
    {
        QPointF point = drawGeneral(t);

        QPointF single_pixel;
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        painter.drawLine(single_pixel, previous_pixel);
        // previous_pixel = single_pixel;

    }

}
