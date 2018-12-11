#include "ContractView.h"

using namespace std;

ContractView::ContractView()
{
}


ContractView::~ContractView()
{
}


void ContractView::setIndex(unsigned index)
{
    m_contract_index = index;
}

void ContractView::setManager(DataManager* dm)
{
    m_data_manager = dm;
}

wstring ContractView::render()
{
    std::wstring result;
    result = (*m_data_manager)[m_contract_index].render();
    return result;
    /*Contract* c = &(*m_data_manager)[m_contract_index];
    result += "Name:\t" + c->name();
    result += "Id:\t" + to_string(c->id());
    result += "Created:\t" + c->datetime().localstr();
    result += "Insured:\t" + c->insured().str();
    result += */
}

