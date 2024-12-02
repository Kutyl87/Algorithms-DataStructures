#include "BSTNode.h"
#include "BSTTree.h"

template <typename T>
void BSTTree<T>::put(T key) {
  put(root, key);
}

template <typename T>
void BSTTree<T>::put(std::unique_ptr<BSTNode<T>>& node, T key) {
  if (!node) {
    node = std::make_unique<BSTNode<T>>(key);
    return;
  }
  if (key < node->value) {
    put(node->left, key);
  } else if (key > node->value) {
    put(node->right, key);
  }
}

template <typename T>
std::optional<T> BSTTree<T>::get(const BSTNode<T>* node, T key) const {
  if (!node) {
    return std::nullopt;
  }
  if (key == node->value) {
    return node->value;
  } else if (key < node->value) {
    return get(node->left.get(), key);
  } else {
    return get(node->right.get(), key);
  }
}

template <typename T>
std::optional<T> BSTTree<T>::get(T key) const {
  return get(root.get(), key);
}

template <typename T>
void BSTTree<T>::deleteNode(T key) {
  root = deleteNode(std::move(root), key);
}

template <typename T>
std::unique_ptr<BSTNode<T>> BSTTree<T>::deleteNode(std::unique_ptr<BSTNode<T>> node, T key) {
  if (!node) {
    return nullptr;
  }

  if (key < node->value) {
    node->left = deleteNode(std::move(node->left), key);
  } else if (key > node->value) {
    node->right = deleteNode(std::move(node->right), key);
  } else {
    if (!node->left) {
      return std::move(node->right);
    }
    if (!node->right) {
      return std::move(node->left);
    }
    node->value = min(node->right.get())->value;
    node->right = removeMin(std::move(node->right));
  }
  return node;
}

template <typename T>
BSTNode<T>* BSTTree<T>::min(BSTNode<T>* node) const {
  if (!node) {
    return nullptr;
  }
  if (!node->left) {
    return node;
  }
  return min(node->left.get());
}

template <typename T>
std::unique_ptr<BSTNode<T>> BSTTree<T>::removeMin(std::unique_ptr<BSTNode<T>> node) {
  if (!node) {
    return nullptr;
  }
  if (!node->left) {
    return std::move(node->right);
  }
  node->left = removeMin(std::move(node->left));
  return node;
}