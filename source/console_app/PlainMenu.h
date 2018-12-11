#pragma once
#include "Object.h"
#include "MenuPosition.h"
#include <vector>

class PlainMenu :
    public Object
{
protected:
    const std::wstring SELECTOR = L"--> ";
    const std::wstring FILLER   = L"    ";

    std::vector<MenuPosition> m_elements;
    unsigned m_selected;

    void selector_move_up();
    void selector_move_down();
public:
    PlainMenu();
    virtual ~PlainMenu();

    virtual std::wstring render();
    virtual void interact(int);

    virtual void insertPosition(MenuPosition);

    virtual void clear();

    // signals
    Signal<int> pressed;
};

