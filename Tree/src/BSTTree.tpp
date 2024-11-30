#include "BSTNode.h"
#include "BSTTree.h"

template <typename T> void BSTTree<T>::put(T key) { put(root, key); }

template <typename T>
void BSTTree<T>::put(std::optional<BSTNode<T>> &node, T key) {
  if (!node) {
    node = BSTNode<T>(key);
    return;
  }
  if (key < node->value) {
    put(node->left, key);
  } else if (key > node->value) {
    put(node->right, key);
  }
}

template <typename T>
std::optional<T> BSTTree<T>::get(const std::optional<BSTNode<T>> &node,
                                 T key) const {
  if (!node) {
    return std::nullopt;
  }
  if (key == node->value) {
    return node->value;
  } else if (key < node->value) {
    return get(node->left, key);
  } else {
    return get(node->right, key);
  }
}

template <typename T> std::optional<T> BSTTree<T>::get(T key) const {
  return get(root, key);
}

template <typename T> void BSTTree<T>::deleteNode(T key) {
  root = deleteNode(std::move(root), key);
}

template <typename T>
std::optional<BSTNode<T>> BSTTree<T>::deleteNode(std::optional<BSTNode<T>> node,
                                                 T key) {
  if (!node)
    return std::nullopt;

  if (key < node->value) {
    node->left = deleteNode(std::move(node->left), key);
  } else if (key > node->value) {
    node->right = deleteNode(std::move(node->right), key);
  } else {
    if (!node->left) {
      return node->right;
    }
    if (!node->right) {
      return node->left;
    }
    node->value = min(node->right)->value;
    node->right = removeMin(std::move(node->right));
  }
  return node;
}

template <typename T>
std::optional<BSTNode<T>>
BSTTree<T>::min(const std::optional<BSTNode<T>> &node) const {
  if (!node)
    return std::nullopt;
  if (!node->left)
    return node;
  return min(node->left);
}

template <typename T>
std::optional<BSTNode<T>>
BSTTree<T>::removeMin(std::optional<BSTNode<T>> node) {
  if (!node)
    return std::nullopt;
  if (!node->left)
    return node->right;
  node->left = removeMin(std::move(node->left));
  return node;
}