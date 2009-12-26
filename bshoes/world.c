#include <ruby.h>
#include "bshoes/code.h"
#include "bshoes/world.h"
#include "bshoes/ruby.h"
#include "bshoes/internal.h"
#include "bshoes/native.h"

extern "C" {

bshoes_world_t *bshoes_world = NULL;
  
bshoes_world_t *
bshoes_world_alloc()
{
  bshoes_world_t *world = BSHOE_ALLOC(bshoes_world_t);
  BSHOE_MEMZERO(world, bshoes_world_t, 1);
  world->apps = rb_ary_new();
  world->msgs = rb_ary_new();
  world->mainloop = FALSE;
  rb_gc_register_address(&world->apps);
  rb_gc_register_address(&world->msgs);
  return world;
}

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
bshoes_init(BSHOES_INIT_ARGS)
{
  int argc;
  char **argv;
  char *path = NULL;
  
  path = BSHOE_ALLOC_N(char, BSHOES_BUFSIZE);
  GetModuleFileName(NULL, (LPSTR)path, BSHOES_BUFSIZE);
  
  bshoes_ruby_embed();
  bshoes_ruby_init();
  
  bshoes_world = bshoes_world_alloc();
  bshoes_world->os.instance = inst;
  bshoes_world->os.style = style;
  bshoes_native_init();

  bshoes_start(path, "/");
  
  if (path != NULL)
    BSHOE_FREE(path);
  
  return BSHOES_OK;
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
  
  bshoes_native_loop();

  return BSHOES_OK;
}

bshoes_code
bshoes_final()
{
  return BSHOES_OK;
}

}
