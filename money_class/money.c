#include "money.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

static void money_init(void* t, Money_Attribute* attr) {
    MONEY* this = (MONEY*)t;

    memcpy(&this->attr, attr, sizeof(Money_Attribute));
}

static void money_comparison(void* t, void* target) {
    MONEY* this = (MONEY*)t;
    MONEY* this_target = (MONEY*)target;

    if (this->attr.amount > this_target->attr.amount) {
        CLASS_LOG("I'm bigger than him\n");
    } else if (this->attr.amount < this_target->attr.amount) {
        CLASS_LOG("I'm smaller than him\n");
    } else {
        CLASS_LOG("I'm as big as he is\n");
    }
}

static int money_get_amount(void* t) {
    MONEY* this = (MONEY*)t;

    CLASS_LOG("get amount: %d\n", this->attr.amount);
}

static void money_set_amount(void* t, int amount) {
    MONEY* this = (MONEY*)t;

    CLASS_LOG("Set amount: %d\n", this->attr.amount);
}

MONEY* MONEY_CTOR(void) {
    MONEY* this = (MONEY*)CLASS_MALLOC(sizeof(MONEY));
    
    this->init = money_init;
    this->api.get_amount = money_get_amount;
    this->api.set_amount = money_set_amount;
    this->api.comparison = money_comparison;

    return this;
}

void MONEY_DTOR(MONEY* t) {
    CLASS_FREE(t);
}
