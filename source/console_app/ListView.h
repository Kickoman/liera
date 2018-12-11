#pragma once
#include "PlainMenu.h"
#include "DataManager.h"
#include "Contract.h"

class ListView :
    public PlainMenu
{
protected:
    DataManager* m_data;
public:
    ListView();
    virtual ~ListView();

    void setData(DataManager*);
};

