#include "sort.h"
#include "utils.h"
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <functional>
#include <ctime>
#include <iostream>

int main() {
  std::map<std::string, std::vector<double>> resultsMap;
  std::map<std::string, std::function<std::vector<std::string>(const std::vector<std::string>&)>> sorts;
  sorts["selection sort"] = selectionSort<std::string>;
  sorts["merge sort"] = mergeSort<std::string>;
  sorts["quick sort"] = quickSort<std::string>;
  sorts["insertion sort"] = insertionSort<std::string>;
  std::vector<double> ns;
  for(int n = 1000; n <= 10000; n += 1000) {
    ns.push_back(n);
    std::vector<std::string> words(n);
    std::ifstream f("pan-tadeusz.txt");
    for(auto &word : words) {
      f >> word;
    }
    for(const auto& [key, sort] : sorts) {
      std::cout << key << ' ' << n << '\n';
      auto start = std::clock();
      sort(words);
      auto end = std::clock();
      resultsMap[key].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);
    }
  }

  std::string filename = "plot_test.png";
  plot(ns, resultsMap, filename);
  return 0;
}
