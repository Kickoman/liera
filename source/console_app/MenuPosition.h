#pragma once
#include "PlainText.h"

class MenuPosition :
    public PlainText
{
public:
    MenuPosition();
    MenuPosition(const std::string& v) :PlainText(v) {}
    virtual ~MenuPosition();

    // signals
    Signal<> selected;
};

