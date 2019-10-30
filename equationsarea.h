#ifndef EQUATIONSAREA_H
#define EQUATIONSAREA_H
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#include <QWidget>
#include <QColor>
#include <QSize>


class EquationsArea : public QWidget
{
    Q_OBJECT
public:
    explicit EquationsArea(QWidget *parent = nullptr);
    ///override functions from base class needed to have the custom widget bhave accordingly
        //QSize minimumSizeHint() const Q_DECL_OVERRIDE;
        //QSize sizeHint() const Q_DECL_OVERRIDE;

        enum graph_type
        {
            Line,
            Parabola,
            Sqrt,
            XReciprical,
            xAxis,
            yAxis
        };

        void set_up_Graph(graph_type graph)
        {
            Graph = graph;
            ///to load the different user values depeinding on  the shape displayed
             load_graph_change(); //on shape
        }
    protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    private:
        ///each function will have implementation to set up the shapes
        /// please add shapes as you see fit
       QPointF drawLine(float t);
       QPointF drawParabola(float t);
       QPointF drawSQRT(float t);
       QPointF drawXReciprical(float t);
       QPointF drawXAxis(float t);
       QPointF drawYAxis(float t);
       QPointF drawGeneral(float t);

       void load_graph_change();

       ///use Qcolor class to allow the background color to be changed
       QColor background_color;
       ///set up the color of the shape
       QColor graph_color;
       graph_type Graph;
       float length_of_Interval;
       float Scale;
       int step_count_of_shape;
       ///Used to draw graph in Q1 and Q3 or Q1 and Q4
       bool degreeEven;

};

#endif // EQUATIONSAREA_H
