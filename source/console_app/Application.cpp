#include "Application.h"



Application::Application()
{
    controller = nullptr;
    statuscode = PROCEED;
}

Application::Application(Layout* l)
{
    controller = new UIController();
    controller->setLayout(l);
    statuscode = PROCEED;
}


Application::~Application()
{
    delete controller;
}


int Application::run()
{
    if (!controller)
    {
        throw "error";
    }

    while (statuscode == PROCEED)
    {
        controller->clr_scr();
        controller->render();
        controller->interact();
    }

    return statuscode;
}

void Application::quit(int exitcode)
{
    statuscode = exitcode;
}