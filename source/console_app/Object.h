#pragma once
// TODO: replace std::string with something 
#include <string>
#include "Signal.h"

class Object
{
protected:
    bool m_active;
public:
    Object();
    virtual ~Object();

    virtual std::wstring render();
    virtual void interact(int);
    

    virtual bool isActive();
    virtual void enable();
    virtual void disable();
    
    bool hidden;
};

