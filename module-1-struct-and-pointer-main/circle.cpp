#include "circle.h"
#include <cmath>

double distance(const Circle *c, const Point *p) {
    return sqrt(
        (p->x - c->centre.x) * (p->x - c->centre.x) +
        (p->y - c->centre.y) * (p->y - c->centre.y)
    );
}

std::string CheckPointInCircle(double diff) {
    if (diff < -EPSILON)
        return "Inside";
    else if (diff > EPSILON)
        return "Outside";
    else
        return "On Circle";
}