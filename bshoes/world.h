#ifndef BSHOES_WORLD_H
#define BSHOES_WORLD_H

#include "bshoes/code.h"
#include "bshoes/config.h"
#include "bshoes/ruby.h"

extern "C" {

BSHOES_EXTERN typedef struct _bshoes_world_t {
  BSHOES_WORLD_OS os;
  int mainloop;
  VALUE apps, msgs;
} bshoes_world_t;

extern BSHOES_EXTERN bshoes_world_t *bshoes_world;

BSHOES_EXTERN bshoes_world_t *bshoes_world_alloc(void);
BSHOES_EXTERN void bshoes_world_free(bshoes_world_t *);

BSHOES_EXTERN bshoes_code bshoes_init(BSHOES_INIT_ARGS);
BSHOES_EXTERN bshoes_code bshoes_start(char *, char *);
BSHOES_EXTERN bshoes_code bshoes_final(void);

}

#endif