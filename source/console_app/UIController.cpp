#include "UIController.h"
#include "Application.h"


UIController::UIController()
{
    //std::ios_base::sync_with_stdio(0);
}

UIController::UIController(Application* app) :master_app(app) {}


UIController::~UIController()
{
}

void UIController::render()
{
    std::cout << layout->render();
}

void UIController::interact()
{
    // nothing!
    int c = _getch();
    layout->interact(c);
}

void UIController::clr_scr(char fill)
{
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void UIController::quit(int exitcode)
{
    master_app->quit(exitcode);
}

void UIController::setLayout(Layout* l)
{
    layout = l;
    layout->setMaster(this);
}