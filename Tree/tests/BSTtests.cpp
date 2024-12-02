#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "BSTNode.h"
#include "BSTTree.h"

TEST_CASE("BSTTree put and get operations") {
  BSTTree<int> tree;
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

TEST_CASE("BSTTree deleteNode operations") {
  BSTTree<int> tree;
  tree.put(10);
  tree.put(20);
  tree.put(5);
  tree.put(15);
  tree.deleteNode(5);
  REQUIRE_FALSE(tree.get(5).has_value());
  tree.deleteNode(20);
  REQUIRE_FALSE(tree.get(20).has_value());
  tree.deleteNode(10);
  REQUIRE_FALSE(tree.get(10).has_value());
  tree.deleteNode(100);
  REQUIRE_FALSE(tree.get(100).has_value());
}

TEST_CASE("BSTTree edge cases") {
  BSTTree<int> tree;
  REQUIRE_FALSE(tree.get(10).has_value());
  tree.put(10);
  REQUIRE(tree.get(10).has_value());
  tree.deleteNode(10);
  REQUIRE_FALSE(tree.get(10).has_value());
  tree.deleteNode(10);
  REQUIRE_FALSE(tree.get(10).has_value());
}