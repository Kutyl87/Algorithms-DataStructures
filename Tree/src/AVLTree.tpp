#include "BSTNode.h"
#include "AVLTree.h"
#include <iostream>

template <typename T>
void AVLTree<T>::put(T key) {
  put(root, key);
}

template <typename T>
void AVLTree<T>::put(std::unique_ptr<BSTNode<T>>& node, T key) {
  if (!node) {
    node = std::make_unique<BSTNode<T>>(key);
    return;
  }
  if (key < node->value) {
    put(node->left, key);
  } else if (key > node->value) {
    put(node->right, key);
  }
  node = balance(std::move(node));
}

template <typename T>
std::optional<T> AVLTree<T>::get(const BSTNode<T>* node, T key) const {
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
std::optional<T> AVLTree<T>::get(T key) const {
  return get(root.get(), key);
}


template <typename T>
int AVLTree<T>::height(const BSTNode<T>* node) const {
  return node ? node->height : 0;
}

template <typename T>
int AVLTree<T>::balanceFactor(const BSTNode<T>* node) const {
  return height(node->right.get()) - height(node->left.get());
}

template <typename T>
void AVLTree<T>::updateHeight(BSTNode<T>* node) {
  node->height = 1 + std::max(height(node->left.get()), height(node->right.get()));
}

template <typename T>
std::unique_ptr<BSTNode<T>> AVLTree<T>::rotateRight(std::unique_ptr<BSTNode<T>> y) {
  std::unique_ptr<BSTNode<T>> x = std::move(y->left);
  y->left = std::move(x->right);
  x->right = std::move(y);
  updateHeight(x->right.get());
  updateHeight(x.get());
  return x;
}

template <typename T>
std::unique_ptr<BSTNode<T>> AVLTree<T>::rotateLeft(std::unique_ptr<BSTNode<T>> x) {
  std::unique_ptr<BSTNode<T>> y = std::move(x->right);
  x->right = std::move(y->left);
  y->left = std::move(x);
  updateHeight(y->left.get());
  updateHeight(y.get());
  return y;
}

template <typename T>
std::unique_ptr<BSTNode<T>> AVLTree<T>::balance(std::unique_ptr<BSTNode<T>> node) {
  updateHeight(node.get());
  if (balanceFactor(node.get()) == 2) {
    if (balanceFactor(node->right.get()) < 0) {
      node->right = rotateRight(std::move(node->right));
    }
    return rotateLeft(std::move(node));
  }
  if (balanceFactor(node.get()) == -1) {
    if (balanceFactor(node->left.get()) > 0) {
      node->left = rotateLeft(std::move(node->left));
    }
    return rotateRight(std::move(node));
  }
  return node;
}

template <typename T>
void AVLTree<T>::print(const BSTNode<T> *node, std::string prefix, bool up) const {
  if(!root) {
    return;
  }
  if(node == nullptr) {
    node = root.get();
  }
  if(node->left) {
    print(node->left.get(), prefix + (node == root.get() ? "" : (up ? "    " : "   |")), true);
  }
  std::cout << prefix;
  if(node != root.get()) std::cout << (up ? "   ," : "   `");
  std::cout << "---" << node->value << "\n";
  if(node->right) {
    print(node->right.get(), prefix + (node == root.get() ? "" : (up ? "   |" : "    ")), false);
  }
}
