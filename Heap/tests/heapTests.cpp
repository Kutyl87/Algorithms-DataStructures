#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include "heap.h"

TEST_CASE("Heap operations with 3-ary heap", "[Heap]") {
  Heap<int> heap(3);

  SECTION("Push elements into the heap") {
    heap.push(5);
    heap.push(3);
    heap.push(8);
    heap.push(1);
    REQUIRE(heap.top() == 1);
  }

  SECTION("Pop elements from the heap") {
    heap.push(5);
    heap.push(3);
    heap.push(8);
    heap.push(1);

    REQUIRE(heap.pop() == 1);
    REQUIRE(heap.top() == 3);
  }

  SECTION("Heap maintains the heap property") {
    heap.push(10);
    heap.push(4);
    heap.push(15);
    heap.push(7);

    REQUIRE(heap.top() == 4);
  }
}

TEST_CASE("Heap operations with 5-ary heap", "[Heap]") {
  Heap<int> heap(5);

  SECTION("Push and pop maintain heap property") {
    heap.push(9);
    heap.push(2);
    heap.push(14);
    heap.push(6);
    heap.push(5);
    REQUIRE(heap.top() == 2);
    heap.pop();
    REQUIRE(heap.top() == 5);
  }
}