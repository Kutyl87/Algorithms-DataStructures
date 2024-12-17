#include "BSTTree.h"
#include "AVLTree.h"
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

  AVLTree<int> printAvlTree;
  for(size_t i = 0; i < 60; ++i) {
    printAvlTree.put(numbers[i]);
  }
  std::cout << "Drzewo AVL:\n";
  printAvlTree.print();

  BSTTree<int> printBstTree;
  for(size_t i = 0; i < 60; ++i) {
    printBstTree.put(numbers[i]);
  }
  std::cout << "Drzewo BST:\n";
  printBstTree.print();

  std::map<std::string, std::vector<double>> createResults;
  std::map<std::string, std::vector<double>> searchResults;
  std::map<std::string, std::vector<double>> deleteResults;

  std::vector<double> ns;
  for(size_t n = 10000; n <= numElements; n += 10000) {
    ns.push_back(n);
    auto start = std::clock();
    BSTTree<int> bstTree;
    for(size_t i = 0; i < n; ++i) {
      bstTree.put(numbers[i]);
    }
    auto end = std::clock();
    createResults["BST"].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);
    BSTTree<int> bigBstTree;
    for(size_t i = 0; i < numElements; ++i) {
      bigBstTree.put(numbers[i]);
    }
    start = std::clock();
    for(size_t i = 0; i < n; ++i) {
      bigBstTree.get(numbers[i]);
    }
    end = std::clock();
    searchResults["BST"].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);

    start = std::clock();
    for(size_t i = 0; i < n; ++i) {
      bigBstTree.deleteNode(numbers[i]);
    }
    end = std::clock();
    deleteResults["BST"].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);

    start = std::clock();
    AVLTree<int> avlTree;
    for(size_t i = 0; i < n; ++i) {
      avlTree.put(numbers[i]);
    }
    end = std::clock();
    createResults["AVL"].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);
    AVLTree<int> bigAvlTree;
    for(size_t i = 0; i < numElements; ++i) {
      bigAvlTree.put(numbers[i]);
    }
    start = std::clock();
    for(size_t i = 0; i < n; ++i) {
      bigAvlTree.get(numbers[i]);
    }
    end = std::clock();
    searchResults["AVL"].push_back(static_cast<double>(end-start)/CLOCKS_PER_SEC);
  }

  std::string createResultsFilename = "create_plot.png";
  plot(ns, createResults, createResultsFilename);
  std::string searchResultsFilename = "search_plot.png";
  plot(ns, searchResults, searchResultsFilename);
  std::string deleteResultsFilename = "delete_plot.png";
  plot(ns, deleteResults, deleteResultsFilename);
  return 0;
}
