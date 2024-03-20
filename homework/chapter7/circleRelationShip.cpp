#include <iostream>
#include <cmath>
using namespace std;

enum CircleRelationShip
{
    intersect = 1,
    inscribe,
    circumscibe,
    include,
    concentricCircle,
    apart
};

class Point
{
public:
    Point(double x = 0.0, double y = 0.0);

    void setX(const double &x);

    void setY(const double &y);

    double getX() const;

    double getY() const;

private:
    double x;
    double y;
};

void Point::setX(const double &x)
{
    this->x = x;
}

void Point::setY(const double &y)
{
    this->y = y;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

class Circle
{
public:
    Circle(double pointX, double pointY, double circleR = 0) : center(pointX, pointY), r(circleR) {}

    Point getCenter() const;

    double getR() const;

private:
    Point center;
    double r;
};

Point Circle::getCenter() const
{
    return center;
}

double Circle::getR() const
{
    return r;
}

double distanceOfCircleCenter(Circle c1, Circle c2)
{
    double x = c1.getCenter().getX() - c2.getCenter().getX();
    double y = c1.getCenter().getY() - c2.getCenter().getY();
    return sqrt(pow(x, 2) + pow(y, 2));
}

int circleRelationShip(Circle c1, Circle c2)
{
    double d = distanceOfCircleCenter(c1, c2);

    if (c2.getCenter().getX() == c1.getCenter().getX() && c2.getCenter().getY() == c1.getCenter().getY())
        return concentricCircle;
    else if (d > c1.getR() + c2.getR())
        return apart;
    else if (d == c1.getR() + c2.getR())
        return circumscibe;
    else if (d > abs(c1.getR() - c2.getR()) && d < c1.getR() + c2.getR())
        return intersect;
    else if (d == abs(c1.getR() - c2.getR()))
        return inscribe;
    else if (d < abs(c1.getR() - c2.getR()) && (c2.getCenter().getX() != c1.getCenter().getX() || c2.getCenter().getY() != c1.getCenter().getY()))
        return include;
}

int main()
{
    while (true)
    {
        double x1, y1, r1, x2, y2, r2;

        cout << "enter the center and radius of two circles separately\n";
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        Circle c1(x1, y1, r1);
        Circle c2(x2, y2, r2);

        int CircleRelationShip = circleRelationShip(c1, c2);

        switch (CircleRelationShip)
        {
        case intersect:
            cout << "intersect\n";
            break;
        case inscribe:
            cout << "inscribe\n";
            break;
        case circumscibe:
            cout << "circumscibe\n";
            break;
        case include:
            cout << "include\n";
            break;
        case concentricCircle:
            cout << "concentricCircle\n";
            break;
        case apart:
            cout << "apart\n";
            break;
        }
    }
}