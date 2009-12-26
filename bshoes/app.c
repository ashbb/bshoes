#include <ruby.h>
#include "bshoes/world.h"
#include "bshoes/app.h"

VALUE
bshoes_app_window(int argc, VALUE *argv, VALUE self, VALUE owner)
{
  HWND window;
  
  window = CreateWindowEx(
    bshoes_world->os.classex.style, BSHOES_SHORTNAME, BSHOES_APPNAME, WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 600, 500, 
    HWND_DESKTOP, NULL, bshoes_world->os.instance, NULL);
  
  ShowWindow(window, SW_SHOWNORMAL);
  
  return self;
}


VALUE
bshoes_app_main(int argc, VALUE *argv, VALUE self)
{
  return bshoes_app_window(argc, argv, self, Qnil);
}
