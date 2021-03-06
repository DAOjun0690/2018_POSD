#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>    // std::sort
#include <string>
#include <vector>

#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/sort.h"
using namespace std;

TEST(ShapeTest, Sorting)
{
  vector<Shape*> shapes;

  Shape *c10 = new Circle(10.0);
  Shape *t003004 = new Triangle(0, 0, 3, 0, 0, 4);
  Shape *r48 = new Rectangle(4,8);
  Shape *c5d25 = new Circle(5.25);
  Shape *t000680 = new Triangle(0, 0, 0, 6, 8, 0);

  shapes.push_back(c10);  //area 314.15 pe 62.82
  shapes.push_back(t003004); //area 0.9999 pe 12
  shapes.push_back(r48); //area 32 pe 24
  shapes.push_back(c5d25); //area pe 32.98
  shapes.push_back(t000680); //area 24

  // v->push_back(new Rectangle(0.5, 1.5));
  //Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5, 6), new Rectangle(0.5, 1.5)};
  Sort *s = new Sort(&shapes);

  // auto sortByAscendingArea = [](Shape *a, Shape *b){
  //   return a->area() < b->area();
  // };
  // auto sortByDescendingArea = [](Shape *a, Shape *b){
  //   return a->area() > b->area();
  // };

  // bool sortByAscendingPerimeter = true;
  // bool sortByDescendingPerimeter = false;

  s->sortArea([](Shape *a, Shape *b){
    return a->area() < b->area();
  });
  ASSERT_NEAR(314.15, shapes[4]->area(), 0.01);
  ASSERT_NEAR(6, shapes[0]->area(), 0.01);
  ASSERT_NEAR(32, shapes[2]->area(), 0.01);
  ASSERT_NEAR(86.59, shapes[3]->area(), 0.01);
  ASSERT_NEAR(24, shapes[1]->area(), 0.01);

  s->sortPerimeter(perimeterAscendingComparison);
  ASSERT_NEAR(62.83, shapes[4]->perimeter(), 0.01); // 0-12 1-24
  ASSERT_NEAR(12, shapes[0]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[1]->perimeter(), 0.01);
  ASSERT_NEAR(32.979, shapes[3]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[2]->perimeter(), 0.01);

  // TEST(SortTest, sortByDescendingPerimeter)
  s->sortPerimeter(perimeterDescendingComparison);
  ASSERT_NEAR(62.83, shapes[0]->perimeter(), 0.01); // 0-12 1-24
  ASSERT_NEAR(12, shapes[4]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[3]->perimeter(), 0.01);
  ASSERT_NEAR(32.979, shapes[1]->perimeter(), 0.01);
  ASSERT_NEAR(24, shapes[2]->perimeter(), 0.01);

  // TEST(SortTest, sortCompactnessAscendingComparison)
  s->sortCompactness(CompactnessAscendingComparison());
  // ASSERT_NEAR(12.5664, shapes[0]->compactness(), 0.01);
  // ASSERT_NEAR(12.5664, shapes[1]->compactness(), 0.01);
  // ASSERT_NEAR(18.0000, shapes[2]->compactness(), 0.01);
  // ASSERT_NEAR(23.3137, shapes[3]->compactness(), 0.01);
  // ASSERT_NEAR(23.3137, shapes[4]->compactness(), 0.01);

  // TEST(SortTest, sortCompactnessDescendingComparison)
  s->sortCompactness(CompactnessDescendingComparison());
  // ASSERT_NEAR(12.5664, shapes[4]->compactness(), 0.01);
  // ASSERT_NEAR(12.5664, shapes[3]->compactness(), 0.01);
  // ASSERT_NEAR(18.0000, shapes[2]->compactness(), 0.01);
  // ASSERT_NEAR(23.3137, shapes[1]->compactness(), 0.01);
  // ASSERT_NEAR(23.3137, shapes[0]->compactness(), 0.01);
}
TEST(SortTest, sortByAscendingAreaWithOneParameter)
{

}
TEST(SortTest, sortByDescendingPerimeterWithOneParameter)
{
  // sortbyOneParameter->sortArea(perimeterDescendingComparison);
}

TEST(SortTest, sortByDescendingCompactnessWithOneParameter)
{
  //sortbyOneParameter->sortCompactness(CompactnessDescendingComparison());
}

TEST(SortTest, sortByAscendingAreaWithOneAreaIsZero)
{
  //Shape* c0 = new Circle(0.0);
}

  // sortbyOneParameter->sortArea(perimeterDescendingComparison);


  // ASSERT_EQ(0.0, shapes[0]->compactness());
  // ASSERT_NEAR(0.5, shapes[1]->compactness(), 0.01);
  // ASSERT_NEAR(1, shapes[2]->compactness(), 0.01);
  //  ASSERT_NEAR(32, shapes[3]->compactness(), 0.01);
  // ASSERT_NEAR(86.5901, shapes[4]->compactness(), 0.01);
  // ASSERT_NEAR(314.159, shapes[5]->compactness(), 0.01);







  /*std::sort(test_array, test_array+4, [](Shape * a, Shape *b) {
    return a->area() < b->area();
  });*/













  /*s->sortCompactness([](Shape *a, Shape *b){
    return a->compactness() < b->compactness();
  }*/
