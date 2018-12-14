#include "LoginScreen.h"
#include "UIController.h"
#include "InsuranceKeeper.h"

LoginScreen::LoginScreen(InsuranceKeeper* ma):master_app(ma)
{
    m_title = new PlainText(
        L"Авторизуйтесь для работы с приложением\n"
    );
    m_errors = new PlainText();

    m_username = new InputField();
    m_password = new InputField();
    m_password->setPassword(true);

    m_username->setHint(L"Логин");
    m_password->setHint(L"Пароль");

    addObject(m_title);
    addObject(m_errors);
    addObject(m_username, true);
    addObject(m_password);

    m_object_selected = 2;
}


LoginScreen::~LoginScreen()
{
    delete m_title;
    delete m_errors;
    delete m_username;
    delete m_password;
}


void LoginScreen::interact(int code)
{
    switch (code)
    {
    case KEY_UP:
        move_selector_up();
        break;
    case KEY_DOWN:
        move_selector_down();
        break;
    case KEY_ENTER:
        authorize();
        break;
    case KEY_ESC:
        m_master_controller->quit(0);
        break;
    default:
        Layout::interact(code);
    }
}


void LoginScreen::move_selector_up()
{
    if (m_object_selected == 2) return;

    m_object_selected--;
    setMain(m_object_selected);
}

void LoginScreen::move_selector_down()
{
    if (m_object_selected == m_objects.size() - 1) return;

    m_object_selected++;
    setMain(m_object_selected);
}


void LoginScreen::authorize()
{
    std::string username = m_username->stdValue();
    std::string password = m_password->stdValue();
    
    User user;
    user = master_app->authorization.authorize(username, password);
    
    if (user.anonymous()) {
        m_errors->setValue(L"\nНеправильный логин или пароль!\n");
        return;
    }

    master_app->user = user;
    m_master_controller->setLayout(master_app->mainMenu);
}