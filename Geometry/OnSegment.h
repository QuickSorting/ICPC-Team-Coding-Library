#pragma once
#include "Point.h"

template<class P> bool onSegment(P s, P e, P p) {
    return orient(p, s, e) == 0 && dot(s - p, e - p) <= 0;
}