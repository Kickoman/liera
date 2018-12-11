#include "MainMenu.h"
#include "UIController.h"
#include "InsuranceKeeper.h"


MainMenu::MainMenu(InsuranceKeeper* ma):master_app(ma)
{
    m_title = new PlainText("Welcome here!\n");

    m_menu = new PlainMenu();
    m_menu->insertPosition(MenuPosition("List all contracts"));
    m_menu->insertPosition(MenuPosition("Search"));
    m_menu->insertPosition(MenuPosition("Add contract"));
    m_menu->insertPosition(MenuPosition("Quit"));

    addObject(m_title);
    addObject(m_menu, true);

    m_menu->pressed.connect_member(this, &MainMenu::on_menu_pressed);
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
            break;
        case 3:
            // Quit
            m_master_controller->quit(0);
            break;
    }
}