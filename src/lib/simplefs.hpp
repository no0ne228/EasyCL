#ifndef EMU_SIMPLEFS
#define EMU_SIMPLEFS

#include <iostream>
#include <filesystem>

namespace simplefs {
  using std::filesystem::exists;
  int write(std::string f, std::string c);
  std::string read(std::string f);
}

#endif
