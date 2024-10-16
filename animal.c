#include "animal.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void animal_init(void* t, Animal_Attribute* attr) {
    ANIMAL* this = (ANIMAL*)t;

    memcpy(&this->attr, attr, sizeof(Animal_Attribute));
}

void animal_show_sound(void* t) {
    ANIMAL* this = (ANIMAL*)t;

    printf("Sound: %s\n", this->attr.sound);
}

void animal_get_name(void* t) {
    ANIMAL* this = (ANIMAL*)t;

    printf("Name: %s\n", this->attr.name);
}

void animal_get_age(void* t) {
    ANIMAL* this = (ANIMAL*)t;

    printf("Age: %d\n", (int)this->attr.age);
}

ANIMAL* ANIMAL_CTOR(void) {
    ANIMAL* this = (ANIMAL*)malloc(sizeof(ANIMAL));
    
    this->init = animal_init;
    this->api.get_name = animal_get_name;
    this->api.get_age = animal_get_age;
    this->api.show_sound = animal_show_sound;

    return this;
}

void ANIMAL_DTOR(ANIMAL* t) {
    free(t);
}