#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"
#include "LineStyle.h"

class Shape
{
public:
    Shape(const Color &color = Color(), bool fill = false)
        : color(color), filled(fill) {}

    virtual ~Shape() {}

    void setFilled(bool fill) { filled = fill; }

    bool isFilled() const { return filled; }

    void setColor(const Color &color);

    const Color &getColor() const { return color; }

    virtual void draw() const = 0;
    virtual void fill() const = 0;

protected:
    Color color;
    bool filled;
};

#endif