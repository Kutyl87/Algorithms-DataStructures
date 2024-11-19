#ifndef HEAP_H
#define HEAP_H
#include <vector>

template <typename T>
class Heap {
private:
  int arn;
  std::vector<T> dataContainer;

  std::size_t parent(std::size_t k) const { return (k - 1) / arn; }
  std::size_t left(std::size_t k) const { return arn * k + 1; }
  void up_heap(std::size_t k);
  void down_heap(std::size_t k);

public:
  explicit Heap(int arnNumber) : arn(arnNumber) {}
  T top() const { return dataContainer[0]; }
  T pop();
  void push(T element);
};

#include "heap.tpp"
#endif
