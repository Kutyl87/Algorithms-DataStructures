#ifndef ALGORITHMS_DATASTRUCTURES_BSTTREE_H
#define ALGORITHMS_DATASTRUCTURES_BSTTREE_H
#include "BSTNode.h"
#include <optional>

template <typename T>
class BSTTree {
private:
  std::unique_ptr<BSTNode<T>> root;

  void put(std::unique_ptr<BSTNode<T>>& node, T key);
  std::optional<T> get(const BSTNode<T>* node, T key) const;
  std::unique_ptr<BSTNode<T>> deleteNode(std::unique_ptr<BSTNode<T>> node, T key);
  BSTNode<T>* min(BSTNode<T>* node) const;
  std::unique_ptr<BSTNode<T>> removeMin(std::unique_ptr<BSTNode<T>> node);

public:
  void put(T key);
  std::optional<T> get(T key) const;
  void deleteNode(T key);
  void print(const BSTNode<T> *node = nullptr, std::string prefix = "", bool up = false) const; 
};
#include "BSTTree.tpp"
#endif // ALGORITHMS_DATASTRUCTURES_BSTTREE_H
