#pragma once
#include "Application.h"
#include "DataManager.h"
#include "MainMenu.h"
#include "FullList.h"


class InsuranceKeeper :
    public Application
{
public:
    // Layouts
    Layout* mainMenu;
    Layout* authorization;
    Layout* fullList;
    Layout* contractView;

    DataManager data;
public:
    InsuranceKeeper();
    virtual ~InsuranceKeeper();

    // layout makers
    Layout* make_authorization();
};

