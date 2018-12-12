#pragma once
#include "Layout.h"
#include "PlainMenu.h"
#include "PlainText.h"

// tmp
#include "InputField.h"

class InsuranceKeeper;

class MainMenu :
    public Layout
{
protected:
    PlainText* m_title;
    PlainMenu* m_menu;

    InsuranceKeeper* master_app;

    // tmp
    InputField* inputField;
public:
    MainMenu(InsuranceKeeper* ma);
    virtual ~MainMenu();

    // slots
    void on_menu_pressed(int);
};