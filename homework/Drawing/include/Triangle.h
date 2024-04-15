#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "Point.h"

class Triangle : public Shape
{
public:
    Triangle(const Point &p1, const Point &p2, const Point &p3,
             const Color &color = Color(), bool fill = false)
        : Shape(color, fill), p1(p1), p2(p2), p3(p3)
    {
    }
    void setP1(const Point &p);
    void setP2(const Point &p);
    void setP3(const Point &p);

    void draw() const override;
    void fill() const override;

private:
    Point p1, p2, p3;
};

#endif