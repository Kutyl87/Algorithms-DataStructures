//
// Created by Pawel Kutyla on 30/11/2024.
//

#ifndef ALGORITHMS_DATASTRUCTURES_BSTNODE_H
#define ALGORITHMS_DATASTRUCTURES_BSTNODE_H
#include <optional>
template <typename T>
class BSTNode {
public:
  T value;
  std::optional<BSTNode<T>> left;
  std::optional<BSTNode<T>> right;

  BSTNode(T value) : value(value) {}
};
#endif // ALGORITHMS_DATASTRUCTURES_BSTNODE_H
