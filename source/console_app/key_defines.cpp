#include "key_defines.h"
#include <cwctype>

bool isCyrillicOrLatin(wchar_t c)
{
    //std::locale utf("ru_RU.UTF8");
    //std::locale utf("en_US.UTF8");
    std::locale utf("");
    //return std::(c, utf);
    if (c == KEY_DOWN ||
        c == KEY_UP ||
        c == KEY_LEFT ||
        c == KEY_RIGHT ||
        c == 224)
        return false;

    return std::iswprint(c);
}