#ifndef BSHOES_CONFIG_H
#define BSHOES_CONFIG_H

#define BSHOES_BUFSIZE    4096
#define BSHOES_INIT_ARGS  HINSTANCE inst, int style
#define BSHOES_EXTERN     __declspec(dllimport)

typedef struct {
  HINSTANCE instance;
  int style;
  HWND hidden;
  WNDCLASSEX classex;
  ATOM classatom;
} bshoes_world_win32, BSHOES_WORLD_OS;

#endif
