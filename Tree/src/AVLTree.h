#ifndef ALGORITHMS_DATASTRUCTURES_AVLTREE_H
#define ALGORITHMS_DATASTRUCTURES_AVLTREE_H
#include "BSTNode.h"
#include <optional>
#include <memory>

template <typename T>
class AVLTree {
private:
  std::unique_ptr<BSTNode<T>> root;

  void put(std::unique_ptr<BSTNode<T>>& node, T key);
  std::optional<T> get(const BSTNode<T>* node, T key) const;
  int height(const BSTNode<T>* node) const;
  int balanceFactor(const BSTNode<T>* node) const;
  void updateHeight(BSTNode<T>* node);
  std::unique_ptr<BSTNode<T>> rotateRight(std::unique_ptr<BSTNode<T>> y);
  std::unique_ptr<BSTNode<T>> rotateLeft(std::unique_ptr<BSTNode<T>> x);
  std::unique_ptr<BSTNode<T>> balance(std::unique_ptr<BSTNode<T>> node);

public:
  void put(T key);
  std::optional<T> get(T key) const;
  void print(const BSTNode<T> *node = nullptr, std::string prefix = "", bool up = false) const; 
};

#include "AVLTree.tpp"

#endif // ALGORITHMS_DATASTRUCTURES_AVLTREE_H
