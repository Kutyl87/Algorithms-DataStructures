#include <iostream>
#include <vector>

template <typename keyT, typename priorityT, typename hash_fun>
void Heap<keyT, priorityT, hash_fun>::up_heap(std::size_t k) {
  while (k != 0 && dataContainer[parent(k)].priority > dataContainer[k].priority) {
    std::swap(dataContainer[k], dataContainer[parent(k)]);
    k = parent(k);
  }
}

template <typename keyT, typename priorityT, typename hash_fun>
void Heap<keyT, priorityT, hash_fun>::down_heap(std::size_t k) {
  while (left(k) < dataContainer.size()) {
    std::size_t leftIndex = left(k);
    std::size_t branches = arn - 1;
    while (branches) {
      if (leftIndex + branches < dataContainer.size() &&
          dataContainer[leftIndex + branches].priority < dataContainer[leftIndex].priority) {
        leftIndex += branches;
        break;
      }
      branches--;
    }
    if (dataContainer[k].priority < dataContainer[leftIndex].priority) {
      break;
    }
    std::swap(dataContainer[k].priority, dataContainer[leftIndex].priority);
    k = leftIndex;
  }
}

template  <typename keyT, typename priorityT, typename hash_fun>
void Heap<keyT, priorityT, hash_fun>::push(Node<keyT, priorityT> element) {
  dataContainer.push_back(element);
  up_heap(dataContainer.size() - 1);
}

template  <typename keyT, typename priorityT, typename hash_fun>
Node<keyT, priorityT> Heap<keyT, priorityT, hash_fun>::pop() {
  Node<keyT, priorityT> root = dataContainer[0];
  dataContainer[0] = dataContainer[dataContainer.size() - 1];
  dataContainer.pop_back();
  if (!dataContainer.empty()) {
    down_heap(0);
  }
  return root;
}

template  <typename keyT, typename priorityT, typename hash_fun>
void Heap<keyT, priorityT, hash_fun>::print(std::size_t index, std::string prefix, bool last) {
  std::cout << prefix;
  if(index > 0) {
    std::cout << (last ? "   `" : "   |");
  }
  std::cout << "---" << dataContainer[index] << "\n";
  size_t i = left(index);
  prefix = index == 0 ? "" : prefix + (last ? "    " : "   |");
  for(; i + 1 < left(index) + arn && i + 1 < dataContainer.size(); ++i) {
    print(i, prefix);
  }
  if(i < dataContainer.size()) {
    print(i, prefix, true);
  }
}
