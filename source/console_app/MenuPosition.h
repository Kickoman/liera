#pragma once
#include "PlainText.h"

class MenuPosition :
    public PlainText
{
public:
    MenuPosition();
    MenuPosition(const std::wstring& v) :PlainText(v) {}
    virtual ~MenuPosition();

    // signals
    Signal<> selected;
};

