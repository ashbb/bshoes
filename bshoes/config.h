#ifndef BSHOES_CONFIG_H
#define BSHOES_CONFIG_H

#define BSHOES_BUFSIZE    4096
#define BSHOES_INIT_ARGS  HINSTANCE inst, int style
#define BSHOES_EXTERN     __declspec(dllimport)

typedef struct {
  HINSTANCE instance;
  int style;
  WNDCLASSEX classex;
  ATOM classatom;
} BSHOES_WORLD_OS;

#endif
