#include "UIController.h"
#include "Application.h"


UIController::UIController()
{
    //std::ios_base::sync_with_stdio(0);
    _setmode(_fileno(stdout), _O_U8TEXT);
}

UIController::UIController(Application* app) :UIController()
{
    master_app = app;
}


UIController::~UIController()
{
}

void UIController::render()
{
    //wprintf(L"%s", layout->render().c_str());
    _putws(layout->render().c_str());
    //std::wstring res = layout->render();
    //std::wcout << res;
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