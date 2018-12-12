#pragma once
#include "Application.h"
#include "DataManager.h"
#include "MainMenu.h"
#include "FullList.h"
#include "ContractDetails.h"
#include "ContractEdit.h"

class InsuranceKeeper :
    public Application
{
public:
    // Layouts
    MainMenu* mainMenu;
    Layout* authorization;
    FullList* fullList;
    ContractDetails* contractDetails;
    ContractEdit* contractEdit;

    DataManager data;
public:
    InsuranceKeeper();
    virtual ~InsuranceKeeper();

    // layout makers
    Layout* make_authorization();
};

