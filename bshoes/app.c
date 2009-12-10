#include <ruby.h>

VALUE
bshoes_app_main(int argc, VALUE *argv, VALUE self)
{
  MessageBox(NULL, "BShoes.app was launched in bshoes.rb", "bshoes_app_main", 0);
  return self;
}