#include <ruby.h>
#include "bshoes/ruby.h"

VALUE progname;

void
bshoes_ruby_init()
{
  progname = rb_str_new2("(eval)");
  rb_define_variable("$0", &progname);
  rb_define_variable("$PROGRAM_NAME", &progname);
}
