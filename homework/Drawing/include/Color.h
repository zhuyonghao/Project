#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0)
        : red(r), green(g), blue(b) {}

    unsigned char getRed() const { return red; }
    unsigned char getGreen() const { return green; }
    unsigned char getBlue() const { return blue; }

    void setRed(unsigned char r) { red = r; }
    void setGreen(unsigned char g) { green = g; }
    void setBlue(unsigned char b) { blue = b; }

private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

#endif