// #pragma once
#ifndef __ANIMAL_H
#define __ANIMAL_H

#ifndef CLASS_MALLOC
#define CLASS_MALLOC malloc
#warning The compiler definition was not added in CMakeLists.txt : add_definitions(-DCLASS_MALLOC=xxx_malloc)
#endif // !CLASS_MALLOC

#ifndef CLASS_FREE
#define CLASS_FREE free
#warning The compiler definition was not added in CMakeLists.txt : add_definitions(-DCLASS_FREE=xxx_free)
#endif // !CLASS_FREE

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
