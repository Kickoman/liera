#include "ModalDialog.h"



ModalDialog::ModalDialog()
{
    m_title = new PlainText();
    m_menu = new PlainMenu();
}


ModalDialog::ModalDialog(UIController* m) :ModalDialog()
{
    m_controller = m;
}


ModalDialog::~ModalDialog()
{
}


void ModalDialog::addOption(std::string name, int code)
{
    m_menu->insertPosition(MenuPosition(name));
}

void ModalDialog::setText(std::string question)
{
    m_title->setValue(question);
}

int ModalDialog::exec()
{
    Layout l;
    l.addObject(m_title);
    l.addObject(m_menu, true);
    
    Application app(&l);

    m_menu->pressed.connect_member(&app, &Application::quit);

    return app.run();
}