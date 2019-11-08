#include "graphs.h"


///The slope is negative to represent a line with positive slope. Not sure why but works
QPointF graph::drawLine(float t)
{
    float slope = -1.0;
    float yIntercept = 0;
    float x = t;
    float y = slope * x + yIntercept;
    return QPointF(x, y);
}

QPointF graph::drawParabola(float t)
{
    float x = t;
    float y = -x * x;
    return QPointF(x, y);
}

QPointF graph::drawSQRT(float t)
{
    float x = t;
    float y = -sqrt(x);
    return QPointF(x, y);
}

QPointF graph::drawXReciprical(float t)
{
    float x = t;
    float y = -1/x;
    return QPointF(x, y);
}

QPointF graph::drawXAxis(float t)
{
    float x = t;
    return QPointF(x, 0);
}

QPointF graph::drawYAxis(float t)
{
    float y = t;
    return QPointF(0, y);
}
