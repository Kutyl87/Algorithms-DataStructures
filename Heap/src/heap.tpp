#include <iostream>
#include <vector>

template <typename T>
void Heap<T>::up_heap(std::size_t k) {
  while (k != 0 && dataContainer[parent(k)] > dataContainer[k]) {
    std::swap(dataContainer[k], dataContainer[parent(k)]);
    k = parent(k);
  }
}

template <typename T>
void Heap<T>::down_heap(std::size_t k) {
  while (left(k) < dataContainer.size()) {
    std::size_t leftIndex = left(k);
    std::size_t branches = arn - 1;
    while (branches) {
      std::cout << leftIndex + branches;
      if (leftIndex + branches < dataContainer.size() &&
          dataContainer[leftIndex + branches] < dataContainer[leftIndex]) {
        leftIndex += branches;
        break;
      }
      branches--;
    }
    if (dataContainer[k] < dataContainer[leftIndex]) {
      break;
    }
    std::swap(dataContainer[k], dataContainer[leftIndex]);
    k = leftIndex;
  }
}

template <typename T>
void Heap<T>::push(T element) {
  dataContainer.push_back(element);
  up_heap(dataContainer.size() - 1);
}

template <typename T>
T Heap<T>::pop() {
  T root = dataContainer[0];
  dataContainer[0] = dataContainer[dataContainer.size() - 1];
  dataContainer.pop_back();
  if (!dataContainer.empty()) {
    down_heap(0);
  }
  return root;
}