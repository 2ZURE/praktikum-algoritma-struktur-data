#include "line.h"

double gradient(const Line *l, const Point *p) {
    return l->a * p->x + l->b * p->y + l->c;
}

std::string CheckPointPosition(double value) {
    if (value > EPSILON)
        return "Left";
    else if (value < -EPSILON)
        return "Right";
    else
        return "On Line";
}