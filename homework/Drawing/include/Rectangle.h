#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point.h"

class Rectangle : public Shape
{
public:
    Rectangle(const Point &p1, const Point &p2,
              const Point &p3, const Point &p4,
              const Color &color = Color(), bool fill = false)
        : Shape(color, fill), p1(p1), p2(p2), p3(p3), p4(p4)
    {
    }

    void setP1(const Point &p);
    void setP2(const Point &p);
    void setP3(const Point &p);
    void setP4(const Point &p);

    void draw() const override;
    void fill() const override;

private:
    Point p1, p2, p3, p4;
};

#endif