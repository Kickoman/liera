#pragma once
#include "Object.h"


class PlainText :
    public Object
{
protected:
    std::wstring value;
public:
    PlainText();
    PlainText(const std::wstring&);
    virtual ~PlainText();

    virtual std::wstring render();

    void setValue(const std::wstring&);
};

