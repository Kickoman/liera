#include "Object.h"



Object::Object()
{
    hidden = false;
}


Object::~Object()
{
}


std::wstring Object::render()
{
    return L"";
}

void Object::interact(int code)
{
}



void Object::enable()
{
    m_active = true;
}

void Object::disable()
{
    m_active = false;
}

bool Object::isActive()
{
    return m_active;
}