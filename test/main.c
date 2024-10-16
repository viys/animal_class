#include "stdio.h"
#include "animal.h"

ANIMAL *Cat = NULL;
ANIMAL_IMPLEMENTS *cat = NULL;

ANIMAL *Mouse = NULL;
ANIMAL_IMPLEMENTS *mouse = NULL;

int main(void)
{
    Animal_Attribute attr1 = {
        .name = "cat",
        .age = 4,
        .sound = "mimi"
    };

    Cat = ANIMAL_CTOR();
    Cat->init(Cat, &attr1);
    cat = (ANIMAL_IMPLEMENTS*)Cat;
    cat->get_name(cat);
    cat->get_age(cat);
    cat->show_sound(cat);

    Animal_Attribute attr2 = {
        .name = "mouse",
        .age = 2,
        .sound = "xixi"
    };

    Mouse = ANIMAL_CTOR();
    Mouse->init(Mouse, &attr2);
    mouse = (ANIMAL_IMPLEMENTS*)Mouse;
    mouse->get_name(mouse);
    mouse->get_age(mouse);
    mouse->show_sound(mouse);

}