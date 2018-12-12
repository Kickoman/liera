#include "InputField.h"


InputField::InputField()
{
    m_password = false;
    m_active = false;
}



InputField::~InputField()
{
}


std::wstring InputField::render()
{
    std::wstring result;
    result += L"(" + m_hint.render() + L") >";
    
    if (m_password)
    {
        result += std::wstring(m_value.size(), L'*');
    } else {
        result += m_value;
    }
    if (isActive()) result += L"_";
    return result;
}


void InputField::setHint(std::wstring hint)
{
    m_hint = hint;
}


std::wstring InputField::value()
{
    return m_value;
}


bool InputField::isPassword()
{
    return m_password;
}

void InputField::setPassword(bool f)
{
    m_password = f;
}

void InputField::setValue(std::wstring value)
{
    m_value = value;
}

void InputField::interact(int code)
{
    if (isCyrillicOrLatin(code))
    {
        m_value.push_back(code);
    } else {
        switch (code)
        {
            case KEY_BS:
                if (!m_value.empty())
                    m_value.pop_back();
                break;
        }
    }
}