#pragma once

typedef enum {
    GPIO_RET_CODE_SUCCESS = 0x00,
    GPIO_RET_CODE_ERROR = 0x01,
    GPIO_RET_CODE_DEINIT = 0x02,
}GPIO_Ret_Code;

typedef enum {
    // GPIO_MODE_NONE = 0x00,
    GPIO_MODE_OUTPUT = 0x00,
    GPIO_MODE_DINPUT = 0x01,
    GPIO_MODE_UINPUT = 0x02,
    GPIO_MODE_AINPUT = 0x03,
}GPIO_Mode;

typedef enum {
    GPIO_ID_0 = 0,
    GPIO_ID_1 = 1,
    GPIO_ID_2 = 2,
    GPIO_ID_3 = 3,
    GPIO_ID_4 = 4,
    GPIO_ID_5 = 5,
    GPIO_ID_6 = 6,
    GPIO_ID_7 = 7,
    GPIO_ID_8 = 8,
    GPIO_ID_9 = 9,
    GPIO_ID_10 = 10,
    GPIO_ID_11 = 11,
    GPIO_ID_12 = 12,
    GPIO_ID_13 = 13,
    GPIO_ID_14 = 14,
    GPIO_ID_15 = 15,
}GPIO_ID;

typedef enum {
    GPIO_LEVEL_LOW = 0x0000,
    GPIO_LEVEL_ANALOG = 0x0001,
    GPIO_LEVEL_HIGIH = 0xffff
}GPIO_Level;

typedef struct {
    GPIO_Mode mode : 8;
    GPIO_Level level : 16;
    void (*callback)(void* param);
}GPIO_Attr;

int gpio_init(GPIO_ID id, GPIO_Attr attr);
int gpio_get_level(GPIO_ID id, GPIO_Level* level);
int gpio_set_level(GPIO_ID id, GPIO_Level level);
