#include "FullList.h"
#include "UIController.h"
#include "InsuranceKeeper.h"
#include "key_defines.h"


FullList::FullList(InsuranceKeeper* ma, DataManager* dm):master_app(ma)
{
    m_title = new PlainText("All contracts\n");

    m_list = new ListView();
    m_list->setData(dm);
        
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
    
}