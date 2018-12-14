#pragma once
#include "UIController.h"
#include "Layout.h"

constexpr auto PROCEED = 228;

class Application
{
protected:
    UIController* controller;

    int statuscode;
public:
    Application();
    Application(Layout*);
    virtual ~Application();

    virtual int run();
    void quit(int code = 0);
};

