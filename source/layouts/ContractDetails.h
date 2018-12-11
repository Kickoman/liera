#pragma once
#include "Layout.h"
#include "PlainMenu.h"
#include "PlainText.h"
#include "ContractView.h"

class InsuranceKeeper;

class ContractDetails :
    public Layout
{
protected:
    Layout* m_prev_layout;

    PlainText* m_title;
    PlainMenu* m_menu;
    ContractView* m_contract;

    InsuranceKeeper* master_app;
public:
    ContractDetails(InsuranceKeeper*);
    virtual ~ContractDetails();

    virtual void interact(int code);

    void setPrevLayout(Layout*);
    void setContractData(DataManager*, unsigned);

    // slots
    void on_menu_pressed(int);
    void on_remove_pressed();
};