#include "sort.h"
#include <algorithm>
#include <random>
#include <functional>

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

template <typename T>
std::vector<T> quickSort(const std::vector<T> &entryArray) {
  static auto getRandomInt = [](size_t min, size_t max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(min, max);
    return dist(gen);
  };

  static auto partition = [](std::vector<T> &vec, size_t start, size_t end) {
    size_t i = start;
    size_t j = end + 1;
    T pivot = vec[start];
    while(true) {
      while (vec[++i] < pivot) if (i == end) break;
      while (pivot < vec[--j]) if (j == start) break;
      if (i >= j) break;
      std::swap(vec[i], vec[j]);
    }
    std::swap(vec[start], vec[j]);
    return j;
  };

  static std::function<void(std::vector<T>&, size_t, size_t)> sort = [](std::vector<T> &vec, size_t start, size_t end) {
    if (end <= start) return;
    int j = partition(vec, start, end);
    if (j > 0) sort(vec, start, j-1);
    sort(vec, j+1, end);
  };

  size_t n = entryArray.size();

  if(n == 0) {
    return entryArray;
  }

  std::vector<T> outputArray = entryArray;

  for(size_t i = 0; i < n - 1; ++i) {
    std::swap(outputArray[i], outputArray[getRandomInt(i, n-1)]);
  }

  sort(outputArray, 0, n-1);
  return outputArray;
}

template <typename T>
std::vector<T> insertionSort(const std::vector<T> &entryArray) {
  size_t n = entryArray.size();
  if (n == 0) {
    return entryArray;
  }
  std::vector<T> outputArray = entryArray;
  for (size_t i = 1; i < n; i++) {
    for (size_t j = i; j > 0 && outputArray[j] < outputArray[j-1]; j--) {
      std::swap(outputArray[j], outputArray[j-1]);
    }
  }
  return outputArray;
}
