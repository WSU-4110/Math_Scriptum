#include "shapearea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#define M_PI  3.14159265358979323846

///using css to set up the backgrounf of the shaoe area
/// this is set to blue
ShapeArea::ShapeArea(QWidget *parent) : QWidget(parent),
    background_color(0,0,255),
    shape_color(255,255,255),
    Shape(Astroid)
{
    load_shape_change();
}

QSize ShapeArea::minimumSizeHint() const
{
    return QSize(500, 500);
}
QSize ShapeArea::sizeHint() const
{
    return QSize(399,399);
}
///when user hits a button this switch statemnt will execute and call
/// what the user chose
/// note** 2 shapes wont appear in the same time
/// unless function is changed
QPointF ShapeArea::drawGeneral(float t)
{
    switch (Shape)
    {
    case Astroid:
        return drawAstroid(t);
        break;
    case Cycloid:
        return drawCycloid(t);
        break;
    case Huygens:
        return drawHuygens(t);
        break;
    case Hype:
        return drawHypo(t);
        break;
    case Circle:
        return drawCircle(t);
        break;
    case Line:
        return drawLine(t);
        break;


    default:
        break;

    }
    return QPointF(0,0);
}

///this functoin will set the defualts for the shapes
/// using  C++ math library
void ShapeArea::load_shape_change()
{
    switch(Shape)
    {
    case Astroid:
            Scale = 50;
            length_of_Interval = 2 * M_PI;
            step_count_of_shape = 103; //mstepcount
        break;
    case Cycloid:
        Scale = 60;
        length_of_Interval = 6 * M_PI;
        step_count_of_shape = 128;
        break;
    case Huygens:
        Scale = 5;
        length_of_Interval = 4 * M_PI;
        step_count_of_shape = 255;
        break;
    case Hype:
        Scale = 16;
        length_of_Interval = 2 * M_PI;
        step_count_of_shape =  255;
        break;
   case Circle:
        Scale = 7;
        length_of_Interval = 3 * M_PI;
        step_count_of_shape = 255;
        break;
   case Line:
        Scale = 15;
        length_of_Interval = 1;
        step_count_of_shape = 129;
        break;


    default:
        break;

    }
}
///each shape will need to be coded in terms of sin and cos
/// please refer to calculus textsbooks or online for the equations of each shape
///standard x and y axis apply
QPointF ShapeArea::drawAstroid(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}

QPointF ShapeArea::drawHypo(float t)
{
    ///imnplemenmt
}

QPointF ShapeArea::drawLine(float t)
{
    ///implement
}

QPointF ShapeArea::drawCircle(float t)
{
    ///implement

}

QPointF ShapeArea::drawCycloid(float t)
{
    ///implement
    return QPointF(
                1.5 * (1-cos(t)), ///x
                1.5 * (1-sin(t)) ///y
                );

}

QPointF ShapeArea::drawHuygens(float t)
{
    ///implement

}

QPointF ShapeArea::drawLines(float t)
{
    ///implement

}


///main function of the shape area class
void ShapeArea::paintEvent(QPaintEvent *event)
{
    float step = length_of_Interval / step_count_of_shape;


    QPainter painter(this); ///calling "this"
    painter.setRenderHint(QPainter::Antialiasing, true); ///prevents liasing
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

    ///for loop algorithm that will set x and y axis when the program draws the shape
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
