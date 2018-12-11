#pragma once
#include "PlainMenu.h"
#include "DataManager.h"
#include "Contract.h"

class ListView :
    public PlainMenu
{
protected:
    DataManager* m_data;
    unsigned m_last_changed;
public:
    ListView();
    virtual ~ListView();

    virtual std::wstring render();

    void rebuild();
    void setData(DataManager*);
};

