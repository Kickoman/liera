#include "InsuranceKeeper.h"

InsuranceKeeper::InsuranceKeeper()
{
    // source managing
    data.setSource("try.bin");
    try {
        data.loadData();
    }
    catch (...)
    {
        // source file is corrupted or does not exists
        // or it has been created on other CPU with different arch
        // (re-)creating it
        data.saveData();
    }

    authorization.setSource("users.bin");
    try {
        authorization.loadData();
    }
    catch (...)
    {
        // creating superadmin to add new users
        authorization.addUser(
            "superadmin",
            "superpassword"
        );
        authorization.saveData();
    }

    controller = new UIController(this);

    // Layouts generating
    loginScreen = new LoginScreen(this);
    mainMenu = new MainMenu(this);
    fullList = new FullList(this, &data);
    contractDetails = new ContractDetails(this);
    contractEdit = new ContractEdit(this);

    controller->setLayout(loginScreen);

}

int InsuranceKeeper::run()
{
    if (user.anonymous())
        controller->setLayout(loginScreen);
    return Application::run();
}

InsuranceKeeper::~InsuranceKeeper()
{
    data.saveData();
}


Layout* InsuranceKeeper::make_authorization()
{
    return new Layout();
}