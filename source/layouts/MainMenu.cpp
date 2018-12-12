#include "MainMenu.h"
#include "UIController.h"
#include "InsuranceKeeper.h"


MainMenu::MainMenu(InsuranceKeeper* ma):master_app(ma)
{
    m_title = new PlainText(L"Добро пожаловать!\n");

    m_menu = new PlainMenu();
    m_menu->insertPosition(MenuPosition(L"Просмотреть все контракты"));
    m_menu->insertPosition(MenuPosition(L"Поиск"));
    m_menu->insertPosition(MenuPosition(L"Новый контракт"));
    m_menu->insertPosition(MenuPosition(L"Выйти"));

    addObject(m_title);
    addObject(m_menu, true);

    m_menu->pressed.connect_member(this, &MainMenu::on_menu_pressed);

    // tmp
    //inputField = new InputField();
    //inputField->setHint(L"Hint, little");
    //addObject(inputField, true);
}


MainMenu::~MainMenu()
{
    delete m_title;
    delete m_menu;
}


void MainMenu::on_menu_pressed(int index)
{
    switch (index)
    {
        case 0:
            // List all contracts
            m_master_controller->setLayout(master_app->fullList);
            break;
        case 1:
            // Search
            break;
        case 2:
            // Add contract
            master_app->contractEdit->setContractData(
                &master_app->data,
                master_app->data.size() + 1
            );
            master_app->contractEdit->setPrevLayout(this);
            m_master_controller->setLayout(master_app->contractEdit);
            break;
        case 3:
            // Quit
            m_master_controller->quit(0);
            break;
    }
}