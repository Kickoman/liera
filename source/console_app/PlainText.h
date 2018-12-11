#pragma once
#include "Object.h"


class PlainText :
    public Object
{
protected:
    std::string value;
public:
    PlainText();
    PlainText(const std::string&);
    virtual ~PlainText();

    virtual std::string render();

    void setValue(const std::string&);
};

