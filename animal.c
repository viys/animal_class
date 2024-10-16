#include "animal.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

static void animal_init(void* t, Animal_Attribute* attr) {
    ANIMAL* this = (ANIMAL*)t;

    memcpy(&this->attr, attr, sizeof(Animal_Attribute));
}

static void animal_show_sound(void* t) {
    ANIMAL* this = (ANIMAL*)t;

    CLASS_LOG("Sound: %s\n", this->attr.sound);
}

static void animal_get_name(void* t) {
    ANIMAL* this = (ANIMAL*)t;

    CLASS_LOG("Name: %s\n", this->attr.name);
}

static void animal_get_age(void* t) {
    ANIMAL* this = (ANIMAL*)t;

    CLASS_LOG("Age: %d\n", (int)this->attr.age);
}

ANIMAL* ANIMAL_CTOR(void) {
    ANIMAL* this = (ANIMAL*)CLASS_MALLOC(sizeof(ANIMAL));
    
    this->init = animal_init;
    this->api.get_name = animal_get_name;
    this->api.get_age = animal_get_age;
    this->api.show_sound = animal_show_sound;

    return this;
}

void ANIMAL_DTOR(ANIMAL* t) {
    CLASS_FREE(t);
}
