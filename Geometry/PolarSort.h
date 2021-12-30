#pragma once
#include "Point.h"

template <class pt>
bool half(pt p){
    assert(p.x != 0 || p.y != 0);
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

template<class pt, class iter>
void polarSort(iter first, iter last){
    sort(first, last, [](pt l, pt r) {
        return tuple{half(l), 0} < tuple{half(r), cross(l, r)};
    });
}

template<class pt, class iter>
void polarSortAround(pt o, iter first, iter last){
    sort(first, last, [&](pt l, pt r) {
        return tuple{half(l - o), 0} < tuple{half(r - o), cross(l - o, r - o)};
    });
}