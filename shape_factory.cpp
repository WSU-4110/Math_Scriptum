#include "shape_factory.h"
#include "shapearea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
shape_Factory::shape_Factory(QWidget *parent) : QWidget(parent),
    background_color(0,0,0),
    shape_color(255,255,255),
    pen(Qt::white)

{
    load_shape_change();
}

QPointF shape_Factory::drawGeneral(QPaintEvent *event)
{

    QPainter painter(this); ///calling "this"
    painter.setRenderHint(QPainter::Antialiasing, true); ///prevents liasing
    painter.setBrush(background_color);
    painter.setPen(shape_color);

    for(float t = 0; t < length_of_Interval; t+= step)
    {
        QPointF point = drawGeneral(t);

        QPointF single_pixel;
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        painter.drawLine(single_pixel, previous_pixel);
        // previous_pixel = single_pixel;
        previous_pixel = single_pixel;

    }


}

