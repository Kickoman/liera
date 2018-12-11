#pragma once
#include "Object.h"
#include "DataManager.h"

class ContractView :
    public Object
{
protected:
    DataManager* m_data_manager;
    unsigned m_contract_index;

public:
    ContractView();
    ContractView(DataManager* dm, unsigned index) :
        m_data_manager(dm),
        m_contract_index(index) {}

    virtual ~ContractView();

    virtual std::string render();

    void setManager(DataManager*);
    void setIndex(unsigned);
};

