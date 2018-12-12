#pragma once
#include "Layout.h"
#include "PlainText.h"
#include "InputField.h"
#include "DataManager.h"

class InsuranceKeeper;

class ContractEdit :
    public Layout
{
protected:
    Layout* m_prev_layout;

    PlainText* m_title;
    InputField* m_name;
    InputField* m_insured;
    InputField* m_tariff_rate;
    InputField* m_office_id;
    InputField* m_insurance_type;

    DataManager* m_data;
    unsigned m_index;

    InsuranceKeeper* master_app;

    unsigned m_object_selected;
    void move_selector_up();
    void move_selector_down();
public:
    ContractEdit(InsuranceKeeper*);
    virtual ~ContractEdit();

    virtual void interact(int code);

    void setPrevLayout(Layout*);
    void setContractData(DataManager*, unsigned);
    void save_data();
};