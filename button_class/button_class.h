#ifndef __BUTTON_CLASS
#define __BUTTON_CLASS

#ifndef ENABLE_MACRO_ISOLATION
// #warning The compiler definition was not added in CMakeLists.txt : ENABLE_MACRO_ISOLATION
#include "macro_isolation.h"
#else
#include "../project/macro_isolation.h"
#endif // !ENABLE_MACRO_ISOLATION

typedef struct {
    unsigned char id;
    int (*init)(void* bind, void* callback);
    int (*deinit)(void);
    int (*get_level)(unsigned short* level);
}Button_Attr;

typedef struct  {
    void (*press)(void* t);
    void (*get_state)(void* t, unsigned short* level);
}BUTTON_IMPLEMENTS;

typedef struct {
    BUTTON_IMPLEMENTS api;
    Button_Attr attr;
    void (*init)(void* t, Button_Attr* attr);
    void (*deinit)(void* t);
    void (*callback)(void* t);
}BUTTON;

BUTTON* BUTTON_CTOR(void);
void BUTTON_DTOR(BUTTON* t);

#endif // !__BUTTON_CLASS