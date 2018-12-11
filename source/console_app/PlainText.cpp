#include "PlainText.h"



PlainText::PlainText()
{
}

PlainText::PlainText(const std::wstring& val) :value(val) {}

PlainText::~PlainText()
{
}


std::wstring PlainText::render()
{
    return value;
}

void PlainText::setValue(const std::wstring& val)
{
    value = val;
}