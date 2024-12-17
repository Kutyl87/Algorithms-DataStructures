#include "utils.h"
#include <matplot/matplot.h>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#else
#include <unistd.h>
#include <fcntl.h>
#endif

class StdErrRedirector {
public:
  StdErrRedirector() : originalFd(-1), devNullFd(-1) {}

  void redirectToDevNull() {
#ifdef _WIN32
    devNullFd = _open("NUL", _O_WRONLY);
#else
    devNullFd = open("/dev/null", O_WRONLY);
#endif
    if (devNullFd == -1) {
      throw std::runtime_error("Failed to open null device.");
    }

#ifdef _WIN32
    originalFd = _dup(_fileno(stderr));
#else
    originalFd = dup(STDERR_FILENO);
#endif
    if (originalFd == -1) {
      throw std::runtime_error("Failed to duplicate stdout file descriptor.");
    }

#ifdef _WIN32
    if (_dup2(devNullFd, _fileno(stderr)) == -1) {
#else
    if (dup2(devNullFd, STDERR_FILENO) == -1) {
#endif
      throw std::runtime_error("Failed to redirect stdout to null device.");
    }
  }

  void restore() {
    if (originalFd != -1) {
#ifdef _WIN32
      _dup2(originalFd, _fileno(stderr));
#else
      dup2(originalFd, STDERR_FILENO);
#endif
      close(originalFd);
      originalFd = -1;
    }
    if (devNullFd != -1) {
      close(devNullFd);
      devNullFd = -1;
    }
  }

  ~StdErrRedirector() {
    restore();
  }

private:
  int originalFd;
  int devNullFd;
};

void plot(const std::vector<double>& x, const std::map<std::string, std::vector<double>> & resultsMap, std::string filename) {
  StdErrRedirector redirector;
  redirector.redirectToDevNull();
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
