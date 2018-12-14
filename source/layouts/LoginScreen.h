#pragma once
#include "Layout.h"
#include "PlainText.h"
#include "InputField.h"

class InsuranceKeeper;

class LoginScreen :
    public Layout
{
protected:
    PlainText* m_title;
    PlainText* m_errors;
    InputField* m_username;
    InputField* m_password;

    InsuranceKeeper* master_app;

    unsigned m_object_selected;
    void move_selector_up();
    void move_selector_down();
public:
    LoginScreen(InsuranceKeeper*);
    virtual ~LoginScreen();

    virtual void interact(int code);

    // slots
    void authorize();
};