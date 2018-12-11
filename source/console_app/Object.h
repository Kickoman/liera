#pragma once
// TODO: replace std::string with something 
#include <string>
#include "Signal.h"

class Object
{
protected:
public:
    Object();
    virtual ~Object();

    virtual std::string render();
    virtual void interact(int);

    bool hidden;
};

