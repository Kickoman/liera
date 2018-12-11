#include "Layout.h"


Layout::Layout(): m_main_object(0)
{
}


Layout::~Layout()
{
    for (auto obj : m_objects)
    {
        delete obj;
    }
    m_objects.clear();
}

std::string Layout::render()
{
    std::string result;
    for (auto obj : m_objects)
    {
        if (obj->hidden) continue;
        result += obj->render() + "\n";
    }
    return result;
}

void Layout::addObject(Object* obj, bool is_main)
{
    m_objects.push_back(obj);
    if (is_main)
        m_main_object = m_objects.size() - 1;
}

void Layout::interact(int code)
{
    // TODO: main object support 
    m_objects[m_main_object]->interact(code);
}

void Layout::setSize(const unsigned height, const unsigned width)
{
    m_height = height;
    m_width = width;
}

void Layout::setWidth(const unsigned width)
{
    m_width = width;
}

void Layout::setHeight(const unsigned height)
{
    m_height = height;
}

void Layout::setMaster(UIController* controller)
{
    m_master_controller = controller;
}

void Layout::setMain(const unsigned index)
{
    m_main_object = index;
}

const unsigned Layout::width() const
{
    return m_width;
}

const unsigned Layout::height() const
{
    return m_height;
}