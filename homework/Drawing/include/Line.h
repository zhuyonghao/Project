#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "Point.h"

class Line : public Shape
{
public:
    Line(const Point &p1, const Point &p2, const Color &color = Color(), bool fill = false)
        : Shape(color, fill), start(p1), end(p2) {}

    void draw() const override;
    void fill() const override;

    Point getStart() const { return start; }
    Point getEnd() const { return end; }

    void setStart(const Point &p) { start = p; }
    void setEnd(const Point &p) { end = p; }

private:
    Point start;
    Point end;
};

#endif