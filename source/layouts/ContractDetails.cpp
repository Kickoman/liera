#include "ContractDetails.h"
#include "InsuranceKeeper.h"

ContractDetails::ContractDetails(InsuranceKeeper* ma) :master_app(ma)
{
    m_title = new PlainText(L"Подробности о контракте");

    m_menu = new PlainMenu();
    m_menu->insertPosition(MenuPosition(L"Изменить"));
    m_menu->insertPosition(MenuPosition(L"Удалить"));
    m_menu->pressed.connect_member(this, &ContractDetails::on_menu_pressed);

    m_contract = new ContractView();

    addObject(m_title);
    addObject(m_contract);
    addObject(m_menu, true);
}

ContractDetails::~ContractDetails()
{
    delete m_title;
    delete m_menu;
    delete m_contract;
}

void ContractDetails::interact(int code)
{
    switch (code)
    {
    case KEY_ESC:
        m_master_controller->setLayout(m_prev_layout);
        break;
    default:
        Layout::interact(code);
        break;
    }
}


void ContractDetails::setPrevLayout(Layout* l)
{
    m_prev_layout = l;
}


void ContractDetails::setContractData(DataManager* dm, unsigned index)
{
    m_contract->setManager(dm);
    m_contract->setIndex(index);
}


void ContractDetails::on_menu_pressed(int index)
{
    switch (index)
    {
    case 0:
        // edit
        break;
    case 1:
        // delete
        break;
    }
}