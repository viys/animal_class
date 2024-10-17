// #pragma once
#ifndef __MONEY_H
#define __MONEY_H

#ifndef ENABLE_MACRO_ISOLATION
// #warning The compiler definition was not added in CMakeLists.txt : ENABLE_MACRO_ISOLATION
#include "macro_isolation.h"
#else
#include "../project/macro_isolation.h"
#endif // !ENABLE_MACRO_ISOLATION

typedef struct {
    unsigned int amount;
}Money_Attribute;

typedef struct  {
    void (*comparison)(void* t, void* target);
    int (*get_amount)(void* t);
    void (*set_amount)(void* t, int amount);
}MONEY_IMPLEMENTS;

typedef struct {
    MONEY_IMPLEMENTS api;
    Money_Attribute attr;
    void (*init)(void* t, Money_Attribute* attr);
}MONEY;

MONEY* MONEY_CTOR(void);
void MONEY_DTOR(MONEY* t);

#endif // !__MONEY_H
