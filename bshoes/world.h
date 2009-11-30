#ifndef BSHOES_WORLD_H
#define BSHOES_WORLD_H

#include "bshoes/code.h"
#include "bshoes/config.h"

extern "C" {

BSHOES_EXTERN bshoes_code bshoes_init();
BSHOES_EXTERN bshoes_code bshoes_start(char *, char *);
BSHOES_EXTERN bshoes_code bshoes_final(void);

}

#endif