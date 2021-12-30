#pragma once
#include "Point.h"
typedef long long ll;
#define all(x) (x).begin(), (x).end()

typedef Point<ll> pt;
vector<pt> convexHull(vector<pt> pts) {
    if (pts.size() <= 1) return pts;
    sort(all(pts));

    while(unique(all(pts)) != pts.end());

    vector<pt> h(pts.size() + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (pt p : pts) {
            while (t >= s + 2 && orient(h[t - 2], h[t - 1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

typedef Point<ll> pt;
vector<pt> convexHullWithCollinearPoints(vector<pt> pts) {
    if (pts.size() <= 1) return pts;
    sort(all(pts));

    bool one_line = true;
    for(int i = 0; i < (int)pts.size() - 2; ++i)
        if(orient(pts[i], pts[i + 1], pts[i + 2])){
            one_line = false;
            break;
        }
    if(one_line)
        return pts;

    vector<pt> h;
    int s = 0;
    for (int it = 2; it--; s = (int)h.size() - 1, h.pop_back(), reverse(all(pts)))
        for (pt p : pts) {
            while (h.size() >= s + 2 && orient(h[h.size() - 2], h.back(), p) < 0)
                h.pop_back();
            h.push_back(p);
        }

    if(h.size() == 2 && h[0] == h[1])
        h.pop_back();
    return h;
}