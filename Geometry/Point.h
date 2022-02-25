#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class T>
int sign(T x){
    return !x ? 0 : ((x > 0) ? 1 : -1);
}

template<class T>
struct Point{
    typedef Point pt;
    T x, y;
    Point(){}
    Point(T x, T y): x(x), y(y){}
    friend bool operator<(pt l, pt r){ return tie(l.x, l.y) < tie(r.x, r.y); }
    friend bool operator==(pt l, pt r){ return tie(l.x, l.y) == tie(r.x, r.y); }
    friend pt operator+(pt l, pt r){ return pt(l.x + r.x, l.y + r.y); }
    friend pt operator-(pt l, pt r){ return pt(l.x - r.x, l.y - r.y); }
    friend pt operator*(pt l, T v){ return pt(l.x * v, l.y * v); }
    friend pt operator/(pt l, T v){ return pt(l.x / v, l.y / v); }
    friend T dot(pt l, pt r){ return l.x * r.x + l.y * r.y; }
    friend T cross(pt l, pt r){ return l.x * r.y - l.y * r.x; }
    friend T orient(pt a, pt b, pt c){ return cross(b - a, c - a); }
    friend T sq(pt p){ return p.x * p.x + p.y * p.y; }
    friend double abs(pt p){ return sqrt(sq(p)); }
    friend double dist(pt a, pt b){ return abs(a - b); }
    // angle to x-axis in interval [-pi, pi]
    friend double angle(pt p){ return atan2(p.y, p.x); }
    friend pt unit(pt p){ return p / abs(p); } // makes dist()=1
    friend pt perp(pt p){ return {-p.y, p.x}; } // rotates +90 degrees
    friend pt normal(pt p){ return unit(perp(p)); }
    // returns point rotated 'a' radians ccw around the origin
    friend pt rotate(pt p, double a){
        return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)};
    }
    friend istream& operator>>(istream &is, pt &p){
        return is >> p.x >> p.y;
    }
    friend ostream& operator<<(ostream &os, pt p){
        return os << p.x << " " << p.y;
    }
};