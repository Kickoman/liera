#include "ListView.h"



ListView::ListView():m_data(nullptr)
{
}


ListView::~ListView()
{
}


void ListView::setData(DataManager* dm)
{
    m_data = dm;
    m_last_changed = dm->lastChanged();

    for (size_t i = 0; i < dm->size(); ++i)
    {
        insertPosition(MenuPosition((*dm)[i].name()));
    }
}

void ListView::rebuild()
{
    clear();
    for (size_t i = 0; i < m_data->size(); ++i)
    {
        insertPosition(MenuPosition((*m_data)[i].name()));
    }
    m_last_changed = m_data->lastChanged();
}

std::wstring ListView::render()
{
    if (m_last_changed != m_data->lastChanged()) rebuild();
    return PlainMenu::render();
}