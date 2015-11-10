#include "BG_Images.h"
#include "welcome.c"
#include "Goodbye.c"

int Logo_getBGOpening_size(void)
{
    return sizeof(g_ucBGOpening);
}

int Logo_getBGGoodbye_size(void)
{
    return sizeof(g_ucBGGoodbye);
}
