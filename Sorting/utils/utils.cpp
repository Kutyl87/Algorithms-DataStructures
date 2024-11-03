#include "utils.h"
#include <matplot/matplot.h>
void plot(const std::vector<double>& x, const std::unordered_map<std::string, std::vector<double>> & resultsMap, std::string filename) {
  matplot::figure();
  matplot::hold(matplot::on);
  for (auto it : resultsMap){
    auto singlePlot = matplot::plot(x, it.second);
    singlePlot->display_name(it.first);
  }
  matplot::legend();
  matplot::show();
  matplot::save(filename);
}
