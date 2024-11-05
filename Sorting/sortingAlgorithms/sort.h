#ifndef SORT_H
#define SORT_H

#include <vector>
template<typename T>
std::vector<T> selectionSort(const std::vector<T>& entryArray);
template<typename T>
std::vector<T> merge(std::vector<T> leftPart, std::vector<T> rightPart);
template<typename T>
std::vector<T> mergeSort(const std::vector<T>& entryArray);
template<typename T>
std::vector<T> quickSort(const std::vector<T>& entryArray);
#include "sort.tpp"
#endif
