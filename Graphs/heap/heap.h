#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <string>
#include <unordered_map>

template <typename keyT, typename priorityT>
class Node {
  keyT key;
  priorityT priority;
};

template <typename keyT, typename priorityT, typename hash_fun = std::hash<keyT>>
class Heap {
  using NodeT = Node<keyT, priorityT>;
private:
  int arn;
  std::vector<NodeT> dataContainer;

  std::size_t parent(std::size_t k) const { return (k - 1) / arn; }
  std::size_t left(std::size_t k) const { return arn * k + 1; }
  void up_heap(std::size_t k);
  void down_heap(std::size_t k);
  std::unordered_map<keyT, size_t, hash_fun> positionMap;

public:
  explicit Heap(int arnNumber) : arn(arnNumber) {}
  NodeT top() const { return dataContainer[0]; }
  NodeT pop();
  void push(NodeT element);
  void print(std::size_t index = 0, std::string prefix = "", bool last = false);
  void decreasePriotity(keyT key, priorityT newPriority);
};

#include "heap.tpp"
#endif
