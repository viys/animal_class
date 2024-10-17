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
    GPIO_ID_0 = 0x0001,
    GPIO_ID_1 = 0x0002,
    GPIO_ID_2 = 0x0004,
    GPIO_ID_3 = 0x0008,
    GPIO_ID_4 = 0x0010,
    GPIO_ID_5 = 0x0020,
    GPIO_ID_6 = 0x0040,
    GPIO_ID_7 = 0x0080,
    GPIO_ID_8 = 0x0100,
    GPIO_ID_9 = 0x0200,
    GPIO_ID_10 =0x0400,
    GPIO_ID_11 =0x0800,
    GPIO_ID_12 =0x1000,
    GPIO_ID_13 =0x2000,
    GPIO_ID_14 =0x4000,
    GPIO_ID_15 =0x8000,
}GPIO_ID;

typedef enum {
    GPIO_LEVEL_LOW = 0x0000,
    GPIO_LEVEL_ANALOG = 0x0001,
    GPIO_LEVEL_HIGIH = 0xffff
}GPIO_Level;

typedef struct {
    GPIO_Mode mode : 8;
    GPIO_Level level : 16;
    void* bind;
    void (*callback)(void* bind);
}GPIO_Attr;

int gpio_init(GPIO_ID id, GPIO_Attr attr);
int gpio_get_level(GPIO_ID id, GPIO_Level* level);
int gpio_set_level(GPIO_ID id, GPIO_Level level);
void gpio_set_int(GPIO_ID id);
