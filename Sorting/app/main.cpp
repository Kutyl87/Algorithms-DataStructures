#include "sort.h"
#include "utils.h"
int main() {
  std::vector<double> x = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::unordered_map<std::string, std::vector<double>> resultsMap = {
      {"Series A", {0, 1, 4, 9, 16, 25, 36, 49, 64, 81}},
      {"Series B", {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},
      {"Series C", {0, -1, -2, -3, -4, -5, -6, -7, -8, -9}},
      {"Series D", {1, 0.5, 0.33, 0.25, 0.2, 0.167, 0.143, 0.125, 0.111, 0.1}}
  };
  std::string filename = "plot_test.png";
  plot(x, resultsMap, filename);
  return 0;
}