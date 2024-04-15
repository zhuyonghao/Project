#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(double x = 0, double y = 0)
        : x(x), y(y) {}

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x;
    double y;
};

#endif