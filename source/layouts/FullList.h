#pragma once
#pragma once
#include "Layout.h"
#include "ListView.h"
#include "PlainText.h"

class InsuranceKeeper;

class FullList :
    public Layout
{
protected:
    PlainText* m_title;
    ListView* m_list;

    InsuranceKeeper* master_app;
public:
    FullList(InsuranceKeeper*, DataManager*);
    virtual ~FullList();

    virtual void interact(int code);
    // slots
    void on_menu_pressed(int);
};