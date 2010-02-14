#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <windows.h>

int
bshoes_snprintf(char* str, size_t size, const char* format, ...)
{
  size_t count;
  va_list args;

  va_start(args, format);
  count = _vscprintf(format, args);
  _vsnprintf(str, size, format, args);
  va_end(args);

  return count;
}

