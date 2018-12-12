#pragma once
#include "Object.h"
#include "PlainText.h"

#include "key_defines.h"

class InputField :
    public Object
{
protected:
    PlainText m_hint;
    std::wstring m_value;

    bool m_password;
public:
    InputField();
    virtual ~InputField();

    virtual std::wstring render();

    void setHint(std::wstring);
    std::wstring value();

    bool isPassword();
    void setPassword(bool);
    void setValue(std::wstring);

    virtual void interact(int code);
};