#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#include <QWidget>
#include <QColor>
#include <QSize>
#include "shapearea.h"

class shape_Factory : public QWidget,  public ShapeArea
{
     explicit shape_Factory(QWidget *parent = nullptr);
    QPointF drawGeneral(QPaintEvent *event);
    QColor background_color;
    ///set up the color of the shape
    QColor shape_color;

    QPen pen;
    shape_Factory Shape;
    shape_Factory shape() const {return Shape};
    void set_up_Shape(shape_type shape)
    {
        shape = shape;
    }

};

#endif // SHAPE_FACTORY_H
