#include "gpio_api.h"
#include "stdio.h"
#include "stdlib.h"

static GPIO_Attr* GPIO_LIST[16] = {};
unsigned short EXIT_LINE = 0x0000;

int gpio_init(GPIO_ID id, GPIO_Attr attr) {
    GPIO_Ret_Code ret = GPIO_RET_CODE_SUCCESS;
    GPIO_Attr* this = GPIO_LIST[id];

    if (this == NULL) {
        this = (GPIO_Attr*)malloc(sizeof(GPIO_Attr));
        GPIO_LIST[id] = this;
        this->callback = NULL;
        this->bind = attr.bind;
    }

    this->mode = attr.mode;

    switch (this->mode)
    {
    case GPIO_MODE_OUTPUT:
        this->callback = NULL;
        this->level = GPIO_LEVEL_LOW;
        break;
    case GPIO_MODE_DINPUT:
        this->level = GPIO_LEVEL_LOW;
    case GPIO_MODE_UINPUT:
        this->level = GPIO_LEVEL_HIGIH;
        this->callback = attr.callback;
        break;
    case GPIO_MODE_AINPUT:
        this->level = GPIO_LEVEL_ANALOG;
        this->callback = attr.callback;
        break;
    default:
        break;
    }

    printf("gpio %d init suc\n", id);

    return ret;
}

int gpio_deinit(GPIO_ID id) {
    GPIO_Attr* this = GPIO_LIST[id];

    free(this);
    this = NULL;

    return GPIO_RET_CODE_SUCCESS;
}

int gpio_get_level(GPIO_ID id, GPIO_Level* level) {
    GPIO_Attr* this = GPIO_LIST[id];

    if (this == NULL) {
        return GPIO_RET_CODE_DEINIT;
    }

    *level = this->level;

    return GPIO_RET_CODE_SUCCESS;
}

int gpio_set_level(GPIO_ID id, GPIO_Level level) {
    GPIO_Attr* this = GPIO_LIST[id];

    if (this == NULL) {
        return GPIO_RET_CODE_DEINIT;
    }

    return GPIO_RET_CODE_SUCCESS;
}

// 模拟 GPIO 中断
int hardware_int(void* param) {
    if (EXIT_LINE | GPIO_ID_0) {
        if (GPIO_LIST[GPIO_ID_0] != NULL && GPIO_LIST[GPIO_ID_0]->callback != NULL) {
            GPIO_LIST[GPIO_ID_0]->callback(param);
        }
        return EXIT_LINE ^ GPIO_ID_0;
    }

    if (EXIT_LINE | GPIO_ID_1) {
        
        return EXIT_LINE ^ GPIO_ID_1;
    }

    if (EXIT_LINE | GPIO_ID_2) {
        
        return EXIT_LINE ^ GPIO_ID_2;
    }

}

void gpio_set_int(GPIO_ID id) {
    EXIT_LINE |= id;
    hardware_int(GPIO_LIST[id]->bind);
}