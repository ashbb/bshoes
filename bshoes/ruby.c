#include <ruby.h>
#include "bshoes/ruby.h"
#include "bshoes/canvas.h"

VALUE cBShoes;
VALUE progname;

void
bshoes_ruby_init()
{
  progname = rb_str_new2("(eval)");
  rb_define_variable("$0", &progname);
  rb_define_variable("$PROGRAM_NAME", &progname);
  
  cBShoes = rb_define_class("BShoes", rb_cObject);
  rb_define_singleton_method(cBShoes, "app", CASTHOOK(bshoes_app_main), -1);
}
