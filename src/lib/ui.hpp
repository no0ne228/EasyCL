#ifndef EASYCL_UI
#define EASYCL_UI
#include <iostream>
class UI {
public:
  UI();
  void set_title(std::string title);
  void set_bg(int color = 41, int secondary = 0);
};
#endif
