#include "ui.hpp"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
UI::UI() { std::cout << "\033c"; }
void UI::set_title(std::string title) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int width = w.ws_col;
  int txtstart = (width / 2) - (title.length() / 2);
  int x = 0;
  std::cout << "\033[7m";
  for (int i = 0; i < txtstart; i++) {
    std::cout << " ";
    x++;
  }
  std::cout << title;
  x += title.length();
  for (int i = 0; i < width - x; i++) {
    std::cout << " ";
  }
  std::cout << "\033[0m";
}
void UI::set_bg(int color, int secondary) {
  //  if ((color >= 40 && color <= 47) || (color >= 100 && color <= 107)) {
  //   if (secondary >= 0 && secondary <= 7) {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int width = w.ws_col;
  int heigth = w.ws_row;
  std::cout << "\033[" << secondary << ";" << color << 236 << "m";
  for (int y = 0; y < heigth; y++) {
    for (int x = 0; x < width; x++) {
      std::cout << " ";
    }
  }
  std::cout << "\033[0m";
  // } else {
  std::cout << "[UI] Incorrect set_bg secondary color";
  //  }
  // } else {
  std::cout << "[UI] Incorrect set_bg color";
  // }
}
