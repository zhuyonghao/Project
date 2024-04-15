#ifndef LINESTYLE_H
#define LINESTYLE_H

class LineStyle
{
public:
    LineStyle(int width = 1, int dotGap = 0)
        : width(width), dotGap(dotGap) {}

private:
    int width;
    int dotGap;
};

#endif