
#ifndef BSHOES_INTERNAL_H
#define BSHOES_INTERNAL_H

#define BSHOE_ALLOC_N(T, N)          (T *)malloc(sizeof(T) * N)
#define BSHOE_ALLOC(T)               (T *)malloc(sizeof(T))
#define BSHOE_FREE(T)                free((void*)T)

#define BSHOE_MEMZERO(p,type,n)      memset((p), 0, sizeof(type)*(n))

int bshoes_snprintf(char* str, size_t size, const char* format, ...);

#endif
