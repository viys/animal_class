// #pragma once
#ifndef __ANIMAL_H
#define __ANIMAL_H

#ifndef ENABLE_MACRO_ISOLATION
// #warning The compiler definition was not added in CMakeLists.txt : ENABLE_MACRO_ISOLATION
#include "macro_isolation.h"
#else
#include "../project/macro_isolation.h"
#endif // !ENABLE_MACRO_ISOLATION

typedef struct {
    unsigned char* name;
    unsigned char age;
    unsigned char* sound;
}Animal_Attribute;

typedef struct  {
    void (*show_sound)(void* t);
    void (*get_name)(void* t);
    void (*get_age)(void* t);
}ANIMAL_IMPLEMENTS;

typedef struct {
    ANIMAL_IMPLEMENTS api;
    Animal_Attribute attr;
    void (*init)(void* t, Animal_Attribute* attr);
}ANIMAL;

ANIMAL* ANIMAL_CTOR(void);
void ANIMAL_DTOR(ANIMAL* t);

#endif // !__ANIMAL_H
