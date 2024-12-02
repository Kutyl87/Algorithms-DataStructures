#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "AVLTree.h"

TEST_CASE("AVLTree put and get operations") {
  AVLTree<int> tree;
  tree.put(10);
  REQUIRE(tree.get(10).has_value());
  REQUIRE(tree.get(10).value() == 10);
  tree.put(20);
  tree.put(5);
  REQUIRE(tree.get(20).has_value());
  REQUIRE(tree.get(5).has_value());
  REQUIRE(tree.get(20).value() == 20);
  REQUIRE(tree.get(5).value() == 5);
  REQUIRE_FALSE(tree.get(15).has_value());
}

TEST_CASE("AVLTree balancing operations") {
  AVLTree<int> tree;
  tree.put(10);
  tree.put(20);
  tree.put(30);
  REQUIRE(tree.get(10).has_value());
  REQUIRE(tree.get(20).has_value());
  REQUIRE(tree.get(30).has_value());
  REQUIRE(tree.get(10).value() == 10);
  REQUIRE(tree.get(20).value() == 20);
  REQUIRE(tree.get(30).value() == 30);
}

TEST_CASE("AVLTree edge cases") {
  AVLTree<int> tree;
  REQUIRE_FALSE(tree.get(10).has_value());
  tree.put(10);
  REQUIRE(tree.get(10).has_value());
  tree.put(20);
  tree.put(5);
  REQUIRE(tree.get(20).has_value());
  REQUIRE(tree.get(5).has_value());
  REQUIRE(tree.get(20).value() == 20);
  REQUIRE(tree.get(5).value() == 5);
}