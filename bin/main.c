#include <stdio.h>
#include <windows.h>
#include "bshoes/world.h"

int WINAPI
WinMain(HINSTANCE inst, HINSTANCE inst2, LPSTR arg, int style)
{
  bshoes_init();
  bshoes_final();
  return 0;
}
