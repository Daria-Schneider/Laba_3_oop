#include <gtest/gtest.h>
#include "vector-points.h"
#include "vector-figure.h"
#include "point.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"

TEST(VectorPointsTest, DefaultConstructor) {
    VectorPoints vp;
    EXPECT_EQ(vp.len(), 0);
}

TEST(VectorPointsTest, AddAndGetPoints) {
    VectorPoints vp;
    Point p1(1, 2);
    Point p2(3, 4);
    vp.push(p1);
    vp.push(p2);
    EXPECT_EQ(vp.len(), 2);
    EXPECT_TRUE(vp.get(0) == p1);
    EXPECT_TRUE(vp.get(1) == p2);
}

TEST(VectorPointsTest, PopPoint) {
    VectorPoints vp;
    vp.push(Point(1, 2));
    vp.push(Point(3, 4));
    vp.pop();
    EXPECT_EQ(vp.len(), 1);
}

TEST(VectorPointsTest, SetAndGet) {
    VectorPoints vp;
    vp.push(Point(0, 0));
    vp.push(Point(0, 0));
    vp.set(0, Point(5, 5));
    vp.set(1, Point(7, 9));
    EXPECT_EQ(vp.get(0).x, 5);
    EXPECT_EQ(vp.get(0).y, 5);
    EXPECT_EQ(vp.get(1).x, 7);
    EXPECT_EQ(vp.get(1).y, 9);
}

TEST(VectorFigureTest, DefaultConstructor) {
    VectorFigure vf;
    EXPECT_EQ(vf.len(), 0);
}

TEST(VectorFigureTest, AddAndGetFigures) {
    VectorFigure vf;
    Triangle* tri = new Triangle(Point(0, 0), Point(1, 0), Point(0, 1));
    Square* sq = new Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2));
    
    vf.push(tri);
    vf.push(sq);
    
    EXPECT_EQ(vf.len(), 2);
    EXPECT_NEAR(static_cast<double>(vf.get(0)->Area()), 0.5, 1e-10);
    EXPECT_NEAR(static_cast<double>(vf.get(1)->Area()), 4.0, 1e-10);
}

TEST(VectorFigureTest, EraseFunction) {
    VectorFigure vf;
    vf.push(new Triangle(Point(0, 0), Point(1, 0), Point(0, 1)));
    vf.push(new Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));
    vf.push(new Rectangle(Point(0, 0), Point(4, 0), Point(4, 3), Point(0, 3)));
    
    EXPECT_EQ(vf.len(), 3);
    
    vf.erase(1);
    EXPECT_EQ(vf.len(), 2);
    
    EXPECT_NEAR(static_cast<double>(vf.get(0)->Area()), 0.5, 1e-10);
    EXPECT_NEAR(static_cast<double>(vf.get(1)->Area()), 12.0, 1e-10);
}

TEST(VectorFigureTest, TotalAreaCalculation) {
    VectorFigure vf;
    vf.push(new Triangle(Point(0, 0), Point(1, 0), Point(0, 1)));
    vf.push(new Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));
    vf.push(new Rectangle(Point(0, 0), Point(4, 0), Point(4, 3), Point(0, 3)));
    
    double totalArea = vf.TotalArea();
    
    EXPECT_NEAR(totalArea, 16.5, 1e-10);
}