#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <windows.h>

void
bshoes_snprintf(char* str, size_t size, const char* format, ...)
{
  va_list args;

  va_start(args, format);
  _vsnprintf(str, size, format, args);
  va_end(args);
}
