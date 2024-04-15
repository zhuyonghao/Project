#ifndef TEXT_H
#define TEXT_H

#include "Shape.h"
#include "Point.h"
#include <string>

class Text : public Shape
{
public:
    Text(const std::string &text, const Point &p, const Color &color = Color(), bool fill = false)
        : Shape(color, fill), text(text), p(p)
    {
    }

    void draw() const override;
    void fill() const override;

    void setText(const std::string &text);
    void setPoint(const Point &p);

    std::string getText() const;
    Point getPoint() const;

private:
    std::string text;
    Point p;
};

#endif