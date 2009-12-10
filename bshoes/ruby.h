#include <ruby.h>

#ifndef BSHOES_RUBY_H
#define BSHOES_RUBY_H

typedef VALUE (*HOOK)(...);
#define CASTHOOK(x) reinterpret_cast<HOOK>(x)

void bshoes_ruby_init(void);

#endif
