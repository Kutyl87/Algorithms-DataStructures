#include "sort.h"
#include <algorithm>

template <typename T>
std::vector<T> selectionSort(const std::vector<T> &entryArray) {
  size_t n = entryArray.size();
  if (n ==0) {
    return entryArray;
  }
  std::vector<T> outputArray = entryArray;
  for (size_t i = 0; i < n; i++) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < n; j++) {
      if (outputArray[j] < outputArray[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(outputArray[i], outputArray[minIndex]);
  }
  return outputArray;
}


template <typename T>
std::vector<T> merge(std::vector<T> leftPart, std::vector<T> rightPart) {
  std::vector<T> outputArray;
  size_t leftIndex = 0;
  size_t rightIndex = 0;
  while (leftIndex < leftPart.size() && rightIndex < rightPart.size()) {
    if (leftPart[leftIndex] < rightPart[rightIndex]) {
      outputArray.push_back(leftPart[leftIndex]);
      leftIndex++;
    } else {
      outputArray.push_back(rightPart[rightIndex]);
      rightIndex++;
    }
  }
  while (leftIndex < leftPart.size()) {
    outputArray.push_back(leftPart[leftIndex]);
    leftIndex++;
  }
  while (rightIndex < rightPart.size()) {
    outputArray.push_back(rightPart[rightIndex]);
    rightIndex++;
  }
  return outputArray;
}


template <typename T>
std::vector<T> mergeSort(const std::vector<T> &entryArray) {
    if (entryArray.size() <= 1) {
        return entryArray;
      }
    std::vector<T> leftPart = std::vector<T>(entryArray.begin(), entryArray.begin() + (int)entryArray.size()/2);
    std::vector<T> rightPart = std::vector<T>(entryArray.begin()+ (int)entryArray.size()/2, entryArray.end());
    return merge(mergeSort(leftPart), mergeSort(rightPart));
}
