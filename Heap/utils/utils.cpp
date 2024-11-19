#include "utils.h"
#include <matplot/matplot.h>
void plot(const std::vector<double>& x, const std::map<std::string, std::vector<double>> & resultsMap, std::string filename) {
  matplot::figure();
  matplot::gcf()->width(1200);
  matplot::gcf()->height(900);
  matplot::gcf()->font_size(20);
  matplot::gca()->font_size(20);
  matplot::hold(matplot::on);
  for (auto it : resultsMap){
    auto singlePlot = matplot::plot(x, it.second);
    singlePlot->display_name(it.first);
    singlePlot->line_width(3);
  }
  auto legend = matplot::legend();
  legend->font_size(20);
  legend->location(matplot::legend::general_alignment::topleft);
  matplot::save(filename);
}
