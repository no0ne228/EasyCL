#include <fstream>
#include "simplefs.hpp"

namespace simplefs {
  int write(std::string f, std::string c) {
    std::ofstream myfile(f);
    if (myfile.is_open()) {
      myfile << c;
      myfile.close();
      return 1;
    } else {
      return 0;
    }
  }
  std::string read(std::string f, int l = 0) {
    std::ifstream file(f);
    std::string c;
    std::string lc;
    int i = 0;
    if (file.is_open()) {
      while (getline(file, lc)) {
        if (i == l) {
          c = lc;
          break;
        }
        i++;
      }
    }
    return c;
  }
}
