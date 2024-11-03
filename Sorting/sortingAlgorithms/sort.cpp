#include <vector>
#include <algorithm>
template<typename T>


std::vector<T> selectionSort(std::vector<T> entryArray) {
  T minElement;
  for(i = 0, i < antryArray.size(), i++) {
    minElement = entryArray[i];
    for (j=i, j < entryArray.size(), j++ ) {
      if (entryArray[j] < minElement){
        minElement = entryArray[j];
      }
    }
    std::swap(entryArray[i], minElement);
  }
  return entryArray;
}