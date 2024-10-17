#include "stdio.h"
#include "button_class.h"
#include "gpio_api/gpio_api.h"

/*
 * 按键按下后中断触发，中断函数执行
 */

BUTTON* Button = NULL;
BUTTON_IMPLEMENTS* button = NULL;

int button1_init(void* bind, void* callback) {
    GPIO_Attr attr = {
        .mode = GPIO_MODE_UINPUT,
        .callback = callback,
        .bind = bind,
    };
    return gpio_init(GPIO_ID_0, attr);
}

int button1_get_level(unsigned short* level) {
    return gpio_get_level(GPIO_ID_0, (GPIO_Level*)level);
}

int main(void)
{
    unsigned short level = 0;
    Button_Attr attr1 = {
        .id = 0x01,
        .init = button1_init,
        .get_level = button1_get_level,
    };

    Button = BUTTON_CTOR();
    Button->init(Button, &attr1);
    button = (BUTTON_IMPLEMENTS*)Button;

    button->get_state(button, &level);
    CLASS_LOG("Button1 level: %d\n", level);

    gpio_set_int(GPIO_ID_0);
}