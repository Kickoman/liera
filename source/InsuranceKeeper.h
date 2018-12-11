#pragma once
#include "Application.h"
#include "DataManager.h"
#include "MainMenu.h"
#include "FullList.h"
#include "ContractDetails.h"

class InsuranceKeeper :
    public Application
{
public:
    // Layouts
    MainMenu* mainMenu;
    Layout* authorization;
    FullList* fullList;
    ContractDetails* contractDetails;

    DataManager data;
public:
    InsuranceKeeper();
    virtual ~InsuranceKeeper();

    // layout makers
    Layout* make_authorization();
};

