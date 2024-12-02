#ifndef ALGORITHMS_DATASTRUCTURES_BSTNODE_H
#define ALGORITHMS_DATASTRUCTURES_BSTNODE_H
#include <memory>

template <typename T>
class BSTNode {
public:
  T value;
  std::unique_ptr<BSTNode<T>> left;
  std::unique_ptr<BSTNode<T>> right;
  int height;
  BSTNode(T value) : value(value) {}
};

#endif // ALGORITHMS_DATASTRUCTURES_BSTNODE_H