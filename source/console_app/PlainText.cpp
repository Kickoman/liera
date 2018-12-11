#include "PlainText.h"



PlainText::PlainText()
{
}

PlainText::PlainText(const std::string& val) :value(val) {}

PlainText::~PlainText()
{
}


std::string PlainText::render()
{
    return value;
}

void PlainText::setValue(const std::string& val)
{
    value = val;
}