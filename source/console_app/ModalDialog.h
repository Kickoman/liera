#pragma once
#include "UIController.h"
#include "Application.h"
#include "Layout.h"
#include "PlainMenu.h"
#include "PlainText.h"

class ModalDialog
{
protected:
    PlainText* m_title;
    PlainMenu* m_menu;

    Application app;
    UIController* m_controller;
public:
    ModalDialog();
    ModalDialog(UIController* m);
    virtual ~ModalDialog();

    virtual void addOption(std::string, int);
    virtual void setText(std::string);
    virtual int exec();
};
