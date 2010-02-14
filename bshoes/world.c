#include <ruby.h>
#include "bshoes/code.h"
#include "bshoes/world.h"
#include "bshoes/ruby.h"
#include "bshoes/internal.h"

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
bshoes_start(char *path, char *uri)
{
  char bootup[BSHOES_BUFSIZE];

  int len = bshoes_snprintf(bootup,
    BSHOES_BUFSIZE,
    "begin;"
      "DIR = File.expand_path(File.dirname(%%q<%s>));"
      "$:.replace([DIR+'/ruby/lib/'+RUBY_PLATFORM, DIR+'/ruby/lib', DIR+'/lib', '.']);"
      "require 'bshoes';"
      "DIR;"
    "rescue Object => e;"
      "puts(e.message);"
    "end",
    path);

  rb_eval_string(bootup);
  return BSHOES_OK;
}

bshoes_code
bshoes_init()
{
  int argc;
  char **argv;
  char *path = NULL;
  
  path = BSHOE_ALLOC_N(char, BSHOES_BUFSIZE);
  GetModuleFileName(NULL, (LPSTR)path, BSHOES_BUFSIZE);
  
  bshoes_ruby_embed();
  bshoes_ruby_init();

  bshoes_start(path, "/");
  
  if (path != NULL)
    BSHOE_FREE(path);
  
  return BSHOES_OK;
}

bshoes_code
bshoes_final()
{
  return BSHOES_OK;
}
