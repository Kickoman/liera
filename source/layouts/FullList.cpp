#include "FullList.h"
#include "UIController.h"
#include "InsuranceKeeper.h"


FullList::FullList(InsuranceKeeper* ma, DataManager* dm):master_app(ma)
{
    m_title = new PlainText(L"Все контракты\n");

    m_list = new ListView();
    m_list->setData(dm);
    m_list->pressed.connect_member(this, &FullList::on_menu_pressed);
        
    addObject(m_title);
    addObject(m_list, true);
}


FullList::~FullList()
{
    delete m_title;
    delete m_list;
}

void FullList::interact(int code)
{
    switch (code)
    {
        case KEY_ESC:
            m_master_controller->setLayout(master_app->mainMenu);
            break;
        default:
            Layout::interact(code);
            break;
    }
}

void FullList::on_menu_pressed(int index)
{
    master_app->contractDetails->setPrevLayout(this);
    master_app->contractDetails->setContractData(&master_app->data, index);
    m_master_controller->setLayout(master_app->contractDetails);
}