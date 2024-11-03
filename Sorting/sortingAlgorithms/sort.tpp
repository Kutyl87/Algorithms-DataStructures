#include "sort.h"
#include <algorithm>

template <typename T>
std::vector<T> &selectionSort(std::vector<T> &entryArray) {
  size_t n = entryArray.size();
  if (n ==0) {
    return entryArray;
  }
  for (size_t i = 0; i < n; i++) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < n; j++) {
      if (entryArray[j] < entryArray[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(entryArray[i], entryArray[minIndex]);
  }
  return entryArray;
}