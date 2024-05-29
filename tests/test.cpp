#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"
#include <string>

using namespace std;

TEST(VisitorTest, VisitCircle) {
    Circle circle(1.0);
    Draw visitor;

    circle.accept(visitor);

    ASSERT_TRUE(dynamic_cast<Visitor<Circle> const*>(&visitor));
}

TEST(VisitorTest, VisitSquare) {
    Square square(1.0);
    Draw visitor;

    square.accept(visitor);

    ASSERT_TRUE(dynamic_cast<Visitor<Square> const*>(&visitor));
}

TEST(VisitorTest, VisitAllShapes) {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(1.0));
    shapes.push_back(make_unique<Square>(1.0));

    Draw visitor;

    for (auto const& shape : shapes) {
        shape->accept(visitor);
    }

    ASSERT_TRUE(dynamic_cast<Visitor<Circle> const*>(&visitor));
    ASSERT_TRUE(dynamic_cast<Visitor<Square> const*>(&visitor));
}
