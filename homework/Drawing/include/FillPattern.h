#ifndef FILLPATTERN_H
#define FILLPATTERN_H

#include <string>

class FillPattern
{
public:
    FillPattern(const std::string &name, const std::string &pattern, int size)
        : name(name), pattern(pattern), size(size) {}

private:
    std::string name;
    std::string pattern;
    int size;
};

#endif
