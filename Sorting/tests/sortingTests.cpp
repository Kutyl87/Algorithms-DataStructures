#include "sort.h"

#include <vector>
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
TEST_CASE("Sorting works on empty array", "[selectionSort]") {
  std::vector<int> entryArray;
  std::vector<int> expectedArray;
  std::vector<int>& outputArray = selectionSort(entryArray);
  REQUIRE(expectedArray == outputArray);
}


TEST_CASE("Sorting works on non sorted array without duplicates", "[selectionSort]") {
  std::vector<int> entryArray = {1, 7, 3 ,9, 12, 19, 8};
  std::vector<int> expectedArray = {1, 3, 7, 8, 9, 12, 19};
  std::vector<int>& outputArray = selectionSort(entryArray);
  REQUIRE(expectedArray == outputArray);
}

TEST_CASE("Sorting works on non sorted array with duplicates", "[selectionSort]") {
  std::vector<int> entryArray = {1, 7, 3 ,9, 12, 3, 19, 8, 8};
  std::vector<int> expectedArray = {1, 3, 3, 7, 8, 8, 9, 12, 19};
  std::vector<int>& outputArray = selectionSort(entryArray);
  REQUIRE(expectedArray == outputArray);
}