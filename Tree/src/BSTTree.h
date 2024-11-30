//
// Created by Pawel Kutyla on 30/11/2024.
//
#include "BSTNode.h"
#ifndef ALGORITHMS_DATASTRUCTURES_BSTTREE_H
#define ALGORITHMS_DATASTRUCTURES_BSTTREE_H
template <typename T> class BSTNode;
template <typename T> class BSTTree {
private:
  std::optional<BSTNode<T>> root;

  void put(std::optional<BSTNode<T>>& node, T key);
  std::optional<T> get(const std::optional<BSTNode<T>>& node, T key) const;
  std::optional<BSTNode<T>> deleteNode(std::optional<BSTNode<T>> node, T key);
  std::optional<BSTNode<T>> min(const std::optional<BSTNode<T>>& node) const;
  std::optional<BSTNode<T>> removeMin(std::optional<BSTNode<T>> node);

public:
  void put(T key);
  std::optional<T> get(T key) const;
  void deleteNode(T key);
};
#endif // ALGORITHMS_DATASTRUCTURES_BSTTREE_H
