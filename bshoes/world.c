#include <ruby.h>
#include "bshoes/code.h"
#include "bshoes/world.h"
#include "bshoes/ruby.h"

extern "C" {

int
bshoes_ruby_embed()
{
  VALUE v;
  char *argv[] = {"ruby", "-e", "1"};
  int sysinit_argc = 0;
  char**  sysinit_argv = NULL;
  RUBY_INIT_STACK;
  ruby_sysinit( &sysinit_argc, &sysinit_argv );
  ruby_init();
  v = (VALUE)ruby_options(3, argv);
  return !FIXNUM_P(v);
}

bshoes_code
bshoes_init()
{
  bshoes_ruby_embed();
  bshoes_ruby_init();
  return BSHOES_OK;
}

bshoes_code
bshoes_final()
{
  return BSHOES_OK;
}

}

