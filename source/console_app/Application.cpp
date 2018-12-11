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
        controller->render();
        controller->interact();
        controller->clr_scr();
    }

    return statuscode;
}

void Application::quit(int exitcode)
{
    statuscode = exitcode;
}