#pragma once
#include "Application.h"
#include "DataManager.h"
#include "MainMenu.h"
#include "FullList.h"
#include "ContractDetails.h"
#include "ContractEdit.h"
#include "LoginScreen.h"
#include "Authorization.h"

class InsuranceKeeper :
    public Application
{
public:
    // add authorization
    Authorization authorization;
    User user;

    // Layouts
    LoginScreen* loginScreen;
    MainMenu* mainMenu;
    FullList* fullList;
    ContractDetails* contractDetails;
    ContractEdit* contractEdit;

    DataManager data;
public:
    InsuranceKeeper();
    virtual ~InsuranceKeeper();

    virtual int run();

    // layout makers
    Layout* make_authorization();
};

