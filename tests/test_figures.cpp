#include <gtest/gtest.h>
#include "point.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"

TEST(TriangleTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(1, 0);
    Point p3(0, 1);
    Triangle tri(p1, p2, p3);
    EXPECT_NEAR(static_cast<double>(tri.Area()), 0.5, 1e-10);
}

TEST(TriangleTest, CenterCalculation) {
    Point p1(0, 0);
    Point p2(2, 0);
    Point p3(0, 2);
    Triangle tri(p1, p2, p3);
    Point center = tri.Center();
    EXPECT_EQ(center.x, 0);
    EXPECT_EQ(center.y, 0);
}

TEST(SquareTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(2, 0);
    Point p3(2, 2);
    Point p4(0, 2);
    Square sq(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(sq.Area()), 4.0, 1e-10);
}

TEST(SquareTest, CenterCalculation) {
    Point p1(1, 1);
    Point p2(3, 1);
    Point p3(3, 3);
    Point p4(1, 3);
    Square sq(p1, p2, p3, p4);
    Point center = sq.Center();
    EXPECT_EQ(center.x, 2);
    EXPECT_EQ(center.y, 2);
}

TEST(RectangleTest, AreaCalculation) {
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 3);
    Point p4(0, 3);
    Rectangle rect(p1, p2, p3, p4);
    EXPECT_NEAR(static_cast<double>(rect.Area()), 12.0, 1e-10);
}

TEST(RectangleTest, CenterCalculation) {
    Point p1(0, 0);
    Point p2(4, 0);
    Point p3(4, 2);
    Point p4(0, 2);
    Rectangle rect(p1, p2, p3, p4);
    Point center = rect.Center();
    EXPECT_EQ(center.x, 2);
    EXPECT_EQ(center.y, 1);
}

TEST(FigureTest, EqualityOperator) {
    Square sq1(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    Square sq2(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    Square sq3(Point(1, 1), Point(3, 1), Point(3, 3), Point(1, 3));
    
    EXPECT_TRUE(sq1 == sq2);
    EXPECT_FALSE(sq1 == sq3);
    EXPECT_TRUE(sq1 != sq3);
}