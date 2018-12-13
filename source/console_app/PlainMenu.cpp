#include "PlainMenu.h"
#include "key_defines.h"

PlainMenu::PlainMenu()
{
}


PlainMenu::~PlainMenu()
{
}


std::wstring PlainMenu::render()
{
    std::wstring result;
    for (size_t i = 0; i < m_elements.size(); ++i)
    {
        result += (i == m_selected ? SELECTOR : FILLER);
        result += m_elements[i].render() + L"\n";
    }
    return result;
}

void PlainMenu::insertPosition(MenuPosition pos)
{
    m_elements.push_back(pos);
}

void PlainMenu::interact(int code)
{
    switch (code)
    {
        case KEY_UP:
            selector_move_up();
            break;
        case KEY_DOWN:
            selector_move_down();
            break;
        case KEY_ENTER:
            pressed.emit(m_selected);
            break;
    }
}

void PlainMenu::selector_move_up()
{
    if (m_selected > 0)
        m_selected--;
    else
        m_selected = (unsigned) m_elements.size() - 1;
}

void PlainMenu::selector_move_down()
{
    m_selected = (m_selected + 1) % m_elements.size();
}


void PlainMenu::clear()
{
    m_selected = 0;
    m_elements.clear();
}