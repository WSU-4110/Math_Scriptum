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

}

void ShapeArea::load_shape_change()
{

}
