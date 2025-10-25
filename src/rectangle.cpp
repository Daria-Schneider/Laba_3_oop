#include "rectangle.h"

Rectangle::Rectangle() {
    v.push(Point(0, 0));
    v.push(Point(2, 0));
    v.push(Point(2, 1));
    v.push(Point(0, 1));
}

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
    v.push(p4);
}

long double Rectangle::Area() const {
    return CalcArea(v);
}

Point Rectangle::Center() const {
    return CalcCenter(v);
}

Rectangle::~Rectangle() {}