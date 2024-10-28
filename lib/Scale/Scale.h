#pragma once
#include <HX711.h>

class Scale
{
    public:
      Scale(int, int);
      bool is_ready();

  private:
      HX711 scale;
      const int LOADCELL_DOUT_PIN;
      const int LOADCELL_SCK_PIN;
};