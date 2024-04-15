#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include "Point.h"

class Ellipse : public Shape
{
public:
    Ellipse(const Point &center, double radiusX, double radiusY,
            const Color &color = Color(), bool fill = false)
        : Shape(color, fill), center(center),
          radiusX(radiusX), radiusY(radiusY) {}

    void draw() const override;
    void fill() const override;

    void setCenter(const Point &p);
    void setX(double x);
    void setY(double y);

private:
    Point center;
    double radiusX;
    double radiusY;
};

#endif