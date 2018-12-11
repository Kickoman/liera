#include "InsuranceKeeper.h"

// temp
#include "ModalDialog.h"


InsuranceKeeper::InsuranceKeeper()
{
    // source managing
    data.setSource("try.bin");
    data.loadData();

    controller = new UIController(this);

    // Layouts generating
    mainMenu = new MainMenu(this);
    fullList = new FullList(this, &data);
    contractDetails = new ContractDetails(this);

    controller->setLayout(mainMenu);

}


InsuranceKeeper::~InsuranceKeeper()
{

}


Layout* InsuranceKeeper::make_authorization()
{
    return new Layout();
}