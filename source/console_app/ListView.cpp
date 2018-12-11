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

    for (size_t i = 0; i < dm->size(); ++i)
    {
        insertPosition(MenuPosition((*dm)[i].name()));
    }
}