#include "button_class.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

static void button_callback(void* t) {
    BUTTON* this = (BUTTON*)t;

    switch (this->attr.id)
    {
    case 0x01:
        CLASS_LOG("Button 1 int triger\n");
        break;
    default:
        break;
    }
}

static void button_init(void* t, Button_Attr* attr) {
    BUTTON* this = (BUTTON*)t;

    memcpy(&this->attr, attr, sizeof(Button_Attr));

    this->attr.init(this, this->callback);
}

static void button_deinit(void* t) {
    BUTTON* this = (BUTTON*)t;

    this->attr.deinit();
}

static void button_get_state(void* t, unsigned short* level) {
    BUTTON* this = (BUTTON*)t;

    this->attr.get_level(level);
}

BUTTON* BUTTON_CTOR(void) {
    BUTTON* this = (BUTTON*)CLASS_MALLOC(sizeof(BUTTON));

    this->init = button_init;
    this->deinit = button_deinit;
    this->callback = button_callback;

    this->api.get_state = button_get_state;

    return this;
}

void BUTTON_DTOR(BUTTON* t) {
    t->deinit(t);

    CLASS_FREE(t);
}
