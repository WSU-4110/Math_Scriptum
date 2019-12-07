#include "shapearea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
///define PI using C++ math library
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
    ///a decent size for a standard 15" laptop
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
    case shape10:
        return drawShape10(t);
        break;
    case shape11:
        return drawShape11(t);
        break;
    case shape12:
        return drawShape12(t);
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
        Scale = 5;
        length_of_Interval = 1;
        step_count_of_shape = 129;
        break;
   case Ellipse:
        Scale = 10;
        length_of_Interval = 3 * M_PI;
        step_count_of_shape = 225;
        break;
   case hexagon:
        Scale = 10;
        length_of_Interval = 11 * M_PI;
        step_count_of_shape = 534;
        break;
    case shape10:
         Scale = 25;
         length_of_Interval = 2 * M_PI;
         step_count_of_shape = 255;
        break;
    case shape11:
         Scale = 10;
         length_of_Interval = 12 * M_PI;
         step_count_of_shape = 555;
        break;
    case shape12:
         Scale = 15;
         length_of_Interval = 6.6666 * M_PI;
         step_count_of_shape = 339;
        break;



    default:
        break;

    }
}
///each shape will need to be coded in terms of sin and cos
/// please refer to calculus textsbooks or online for the equations of each shape
///standard x and y axis apply
/*
 * The following functions are for the base shapes in the application
 * the parametric equation is insterted manually in terms of sin and cos
 * flaoting point is used to ensure max accuracy
 * return as a QPointF
 * */
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
    return QPointF (1.5 * (2* cos(t) + cos(2*t)), 4 * (3*sin(t) - sin(3*t)));
}

QPointF ShapeArea::drawLine(float t)
{
    float t1 = 19;
    float t2 = 5;
    float t3 = 19;
    float x = (t1 - t2) * cos (t) + t3 * cos (t * ((t1 - t2) / t2));
    float y = (t1 - t2) * sin (t) - t3 * sin (t * ((t1 - t2) / t2));
    return QPointF (x, y);
}

QPointF ShapeArea::drawCircle(float t)
{
    return QPointF (cos(t),sin(t));
}

QPointF ShapeArea::drawCycloid(float t)
{
   return QPointF(
                1.5 * (1-cos(t)), ///x
                1.5 * (t-sin(t)) ///y
                );
}

QPointF ShapeArea::drawHuygens(float t)
{
    return QPointF (4*(3*cos(t)-cos(3*t)),4*(3*sin(t)-sin(3*t)));
}

QPointF ShapeArea::drawLines(float t)
{
    return QPointF ( 1-t,1-t);
}

QPointF ShapeArea::drawHexagon(float t)
{
    float vertex = 15;
    float secondVertex = 5.123987612132;

    float x = vertex * cos (t) - secondVertex * cos (vertex / secondVertex * t);
    float y = vertex * sin (t) - secondVertex * sin (vertex / secondVertex * t);
return QPointF (x,y);
}

QPointF ShapeArea::drawShape10(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 6 * cos_t * cos_t * cos_t * cos_t;
    float y = 6 * sin_t * sin_t * sin_t * sin_t;
    return QPointF(x, y);
}

QPointF ShapeArea::drawShape11(float t)
{
        float vertex = 15;
        float secondVertex = 4;

        float x = vertex * cos (t) - secondVertex * cos (vertex / secondVertex * t);
        float y = vertex * sin (t) - secondVertex * sin (vertex / secondVertex * t);
    return QPointF (x,y);
}

QPointF ShapeArea::drawShape12(float t)
{
      float t1 = 9;
      float t2 = 4;
      float t3 = 9;

      float x = (t1 - t2) * cos (t) + t3 * cos (t * ((t1 - t2) / t2));
      float y = (t1 - t2) * sin (t) - t3 * sin (t * ((t1 - t2) / t2));

      return QPointF (x, y);
}

QPointF ShapeArea::drawEllipse(float t)
{
    float edge1 = 2;
    float edge2 = 1;
    return QPointF(edge1*cos(t), edge2*sin(t));

}

///main paintEvent function of the shape area class
void ShapeArea::paintEvent(QPaintEvent *event)
{
    float step = length_of_Interval / step_count_of_shape;
    QPainter painter(this); ///calling "this"
    ///prevents liasing to create more smooth shapes (very good with MAC os)
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(background_color);
    painter.setPen(shape_color);
    ///use drawrct to call rect funtion and center it
    painter.drawRect(this->rect());
    QPoint center = this->rect().center();
    ///to adjust the dotted line and make it into smooth line
    QPointF previous_point = drawGeneral(0);
    QPointF previous_pixel;
    ///implicit conversion that will turn the floating numbers to a double
    previous_pixel.setX(previous_point.x() * Scale + center.x());
    previous_pixel.setY(previous_point.y() * Scale + center.y());

    ///for loop algorithm that will set x and y axis when the program draws the shape
    for(float t = 0; t < length_of_Interval; t+= step)
    {
        ///using qt QPointF to declare general empty shape with a floating point t
        QPointF point = drawGeneral(t);
        ///use QpointF to create a single pixel point
        QPointF single_pixel;
        ///give the single pixel an x and y and center them using built in qt functions
        single_pixel.setX(point.x() * Scale + center.x());
        single_pixel.setY(point.y() * Scale + center.y());
        ///once the pixels are scaled and made
        /// draw the basic points of the shape by connecting the pixels using qt drawLine
        painter.drawLine(single_pixel, previous_pixel);
        previous_pixel = single_pixel;
    }
}
