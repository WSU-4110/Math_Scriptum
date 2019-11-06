#include "shapearea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#define M_PI  3.14159265358979323846

///using css to set up the backgrounf of the shaoe area
/// this is set to blue
ShapeArea::ShapeArea(QWidget *parent) : QWidget(parent),
    background_color(0,0,0),
    shape_color(255,255,255),
    pen(Qt::white),
    Shape(Astroid)
{
    load_shape_change();
}

QSize ShapeArea::minimumSizeHint() const
{
    return QSize(700, 700);
}
QSize ShapeArea::sizeHint() const
{
     return QSize(700,700);
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
    case Ellipse:
        return drawEllipse(t);
        break;
    case hexagon:
        return drawHexagon(t);
        break;
    case Lines:
        return drawLines(t);
        break;
    case General:
        return drawGeneral(t);
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
            Scale = 100;
            length_of_Interval = 2 * M_PI;
            step_count_of_shape = 255; //mstepcount
        break;
    case Cycloid:
        Scale = 30;
        length_of_Interval = 4 * M_PI;
        step_count_of_shape = 128;
        break;
    case Huygens:
        Scale = 5;
        length_of_Interval = 4 * M_PI;
        step_count_of_shape = 255;
        break;
    case Hype:
        Scale = 10;
        length_of_Interval = 4 * M_PI;
        step_count_of_shape =  255;
        break;
   case Circle:
        Scale = 165;
        length_of_Interval = 2 * M_PI;
        step_count_of_shape = 139;
        break;
   case Line:
        Scale = 15;
        length_of_Interval = 2;
        step_count_of_shape = 129;
        break;
   case Ellipse:
        Scale = 10;
        length_of_Interval = 3 * M_PI;
        step_count_of_shape = 225;
        break;
   case hexagon:
        Scale = 12;
        length_of_Interval = 5 * M_PI;
        step_count_of_shape = 234;
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
    return QPointF (1.5 * (2* cos(t) + cos(2*t)), 4 * (3*sin(t) - sin(3*t)));
}

QPointF ShapeArea::drawLine(float t)
{
    ///implement
}

QPointF ShapeArea::drawCircle(float t)
{
    ///implement
    return QPointF (cos(t),sin(t));

}

QPointF ShapeArea::drawCycloid(float t)
{
    ///implement
    return QPointF(
                1.5 * (1-cos(t)), ///x
                1.5 * (t-sin(t)) ///y
                );

}

QPointF ShapeArea::drawHuygens(float t)
{
    ///implement
    return QPointF (4*(3*cos(t)-cos(3*t)),4*(3*sin(t)-sin(3*t)));

}

QPointF ShapeArea::drawLines(float t)
{
    ///implement
    return QPointF ( 1-t,1-t);

}

QPointF ShapeArea::drawHexagon(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);

    float theta_t = 1.186822;

    float x = 2*cos(theta_t) * ((cos(M_PI/5)/cos((2*M_PI/5) * (theta_t/(2*theta_t/5) - (theta_t/(2*theta_t/5))) - M_PI)));
    float y = 2*sin(theta_t) * ((cos(M_PI/5)/cos((2*M_PI/5) * (theta_t/(2*theta_t/5) - (theta_t/(2*theta_t/5))) - M_PI)));

    return QPointF(x,y);


}

QPointF ShapeArea::drawEllipse(float t)
{
    float edge1 = 2;
    float edge2 = 1;
    return QPointF(edge1*cos(t), edge2*sin(t));

}



///main function of the shape area class
void ShapeArea::paintEvent(QPaintEvent *event)
{


}
