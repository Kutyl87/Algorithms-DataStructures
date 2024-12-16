#include "heap.h"
#include "utils.h"
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <functional>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>

int main() {
  const size_t numElements = 100000;
  const int minValue = 1;
  const int maxValue = 300000;

  std::vector<int> numbers;
  numbers.reserve(numElements);

  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> dist(minValue, maxValue);

  for (size_t i = 0; i < numElements; ++i) {
    numbers.push_back(dist(generator));
  }
  for(auto d : {2, 5, 7}) {
    Heap<int> heap(d);
    for(size_t i = 0; i < 60; ++i) {
      heap.push(numbers[i]);
    }
    std::cout << "Kopiec " << d << "-arny:\n";
    heap.print();
  }
  std::map<std::string, std::vector<double>> createResults;
  std::map<std::string, std::vector<double>> popResults;
  std::vector<double> ns;
  for(size_t n = 10000; n <= numElements; n += 10000) {
    ns.push_back(n);
    for(auto d : {2, 5, 7}) {
      auto start = std::clock();
      Heap<int> heap(d);
      for(size_t i = 0; i < n; ++i) {
        heap.push(numbers[i]);
      }
      auto end = std::clock();
      std::stringstream ss;
      ss << d << "-arny";
      createResults[ss.str()].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);
      Heap<int> bigHeap(d);
      for(size_t i = 0; i < numElements; ++i) {
        bigHeap.push(numbers[i]);
      }
      start = std::clock();
      for(size_t i = 0; i < n; ++i) {
        bigHeap.pop();
      }
      end = std::clock();
      popResults[ss.str()].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);
    }
  }

  std::string createResultsFilename = "create_plot.png";
  plot(ns, createResults, createResultsFilename);
  std::string popResultsFilename = "pop_plot.png";
  plot(ns, popResults, popResultsFilename);
  return 0;
}
