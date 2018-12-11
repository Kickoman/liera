#pragma once
#include "Layout.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stack>

class Application;

class UIController
{
protected:
    
public:

    Layout* layout;
    Application* master_app;

    UIController();
    UIController(Application*);
    virtual ~UIController();

    void render();
    void interact();
    void clr_scr(char fill = ' ');

    void quit(int);

    // setters;
    void setLayout(Layout*);
};

