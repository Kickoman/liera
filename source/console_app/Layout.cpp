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

std::wstring Layout::render()
{
    std::wstring result;
    for (auto obj : m_objects)
    {
        if (obj->hidden) continue;
        result += obj->render() + L"\n";
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


Object* Layout::operator[](int index) const
{
    return m_objects[index];
}

Object* Layout::operator[](int index)
{
    return m_objects[index];
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
    if (index < m_objects.size()) 
        m_objects[m_main_object]->disable();
    m_main_object = index;
    m_objects[m_main_object]->enable();
}

const unsigned Layout::width() const
{
    return m_width;
}

const unsigned Layout::height() const
{
    return m_height;
}