#pragma once

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
