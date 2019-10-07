#ifndef SHAPEAREA_H
#define SHAPEAREA_H
#include <QPaintEvent>
#include <QPainter>
#include <math.h>
#include <QWidget>
#include <QColor>
#include <QSize>

/*
 * ALL VARIABLES SHOULD BE IN FLOATING POINT TO ENSURE CORRECT SHAPE ACCURACY
 * EXCEPT FOR STEP COUNT FUNCTIONS
 *
 *
*/

class ShapeArea : public QWidget
{


    Q_OBJECT
public:
    explicit ShapeArea(QWidget *parent = nullptr);
    ///override functions from base class needed to have the custom widget bhave accordingly
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;


     enum shape_type
     {
         Line,
         Astroid,
         Cycloid,
         Hype,
         Huygens,
         Circle
     };
     ///All setters anbd getters class functions to draw 2D shapes in the shape area window
    void set_up_Shape(shape_type shape)
    {
        Shape = shape;
        ///to load the different user values depeinding on  the shape displayed
         load_shape_change(); //on shape
    }

    ///function to allow rescaleing of the shape
    void set_scale_size(float scale)
    {
        Scale = scale;
        //repaint function here declare only no body
    }
    float scale () const
    {
        return Scale;
    }

    ///set step counter for the shape
    void set_step_counter(int count)
    {
        step_count_of_shape = count;
        //repaint functiuon here
    }
    int step_counter() const
    {
        return step_count_of_shape;
    }

    ///allow user to set custome lentghs of shape
    void set_length_of_shape(float length)
    {
        length_of_Interval = length;
        //painmt function
    }
    float length() const
    {
        return length_of_Interval;
    }


    ///overriding method form base class
    /// NOT using built in override method of paintEvent
    protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


signals:

public slots:
private:
    ///each function will have implementation to set up the shapes
    /// please add shapes as you see fit
   QPointF drawLine(float t);
   QPointF drawAstroid(float t);
   QPointF drawCycloid(float t);
   QPointF drawHypo(float t);
   QPointF drawHuygens(float t);
   QPointF drawCircle(float t);
   QPointF drawLines(float t);
   QPointF drawGeneral(float t);
   void load_shape_change();


private:
   ///use Qcolor class to allow the background color to be changed
   QColor background_color;
   ///set up the color of the shape
   QColor shape_color;
   shape_type Shape;
   float length_of_Interval;
   float Scale;
   int step_count_of_shape;
};

#endif // SHAPEAREA_H
