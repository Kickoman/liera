#pragma once
#include "Object.h"
#include "MenuPosition.h"
#include <vector>

class PlainMenu :
    public Object
{
protected:
    const std::string SELECTOR = "--> ";
    const std::string FILLER   = "    ";

    std::vector<MenuPosition> m_elements;
    unsigned m_selected;

    void selector_move_up();
    void selector_move_down();
public:
    PlainMenu();
    virtual ~PlainMenu();

    virtual std::string render();
    virtual void interact(int);

    virtual void insertPosition(MenuPosition);

    // signals
    Signal<int> pressed;
};

