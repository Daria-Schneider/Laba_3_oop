#pragma once

#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    ~Rectangle() override;
    Rectangle(Point, Point, Point, Point);
    long double Area() const override;
    Point Center() const override;
};