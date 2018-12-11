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