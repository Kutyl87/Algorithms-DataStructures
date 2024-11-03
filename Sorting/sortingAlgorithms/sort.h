#ifndef SORT_H
#define SORT_H

#include <vector>
template<typename T>
std::vector<T>& selectionSort(std::vector<T>& entryArray);
template<typename T>
std::vector<T> merge(std::vector<T> leftPart, std::vector<T> rightPart);
template<typename T>
std::vector<T> mergeSort(std::vector<T>& entryArray);
#include "sort.tpp"
#endif