#pragma once

#include "figure.h"

class Square : public Figure {
public:
    Square();
    ~Square() override;
    Square(Point, Point, Point, Point);
    long double Area() const override;
    Point Center() const override;
};