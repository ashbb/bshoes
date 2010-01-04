
#include <windows.h>
#include <commdlg.h>
#include <shlobj.h>
#include "bshoes/app.h"
#include "bshoes/code.h"
#include "bshoes/world.h"

LRESULT CALLBACK
bshoes_app_win32proc(HWND win, UINT msg, WPARAM w, LPARAM l)
{
  switch(msg)
  {
    case WM_CLOSE:
      DestroyWindow(win);
      return FALSE;
    case WM_DESTROY:
      PostQuitMessage(0);
      return FALSE;
    default:
      return DefWindowProc(win, msg, w, l);
  }
}

bshoes_code
bshoes_classex_init()
{
  bshoes_code code = BSHOES_OK;

  bshoes_world->os.classex.hInstance = bshoes_world->os.instance;
  bshoes_world->os.classex.lpszClassName = BSHOES_SHORTNAME;
  bshoes_world->os.classex.lpfnWndProc = bshoes_app_win32proc;
  bshoes_world->os.classex.style = CS_HREDRAW | CS_VREDRAW;
  bshoes_world->os.classex.cbSize = sizeof(WNDCLASSEX);
  bshoes_world->os.classex.hIcon = LoadIcon(bshoes_world->os.instance, IDI_APPLICATION);
  bshoes_world->os.classex.hIconSm = LoadIcon(bshoes_world->os.instance, IDI_APPLICATION);
  bshoes_world->os.classex.hCursor = LoadCursor(NULL, IDC_ARROW);
  bshoes_world->os.classex.lpszMenuName = NULL;
  bshoes_world->os.classex.cbClsExtra = 0;
  bshoes_world->os.classex.cbWndExtra = 0;
  bshoes_world->os.classex.hbrBackground = (HBRUSH)COLOR_WINDOW;

  bshoes_world->os.classatom = RegisterClassEx(&bshoes_world->os.classex);

  return code;
}

void bshoes_native_init()
{
  bshoes_classex_init();
}

void
bshoes_native_loop()
{
  MSG msg;
  while(TRUE)
  {
    if (PeekMessage(&msg, 0, 0, 0, PM_NOREMOVE))
    {
      if (!GetMessage(&msg, NULL, 0, 0)) break;
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    else
      rb_eval_string("sleep(0.001)");
  }
}
