#pragma once
#include <vector>
#include <string>
#include "Object.h"

class UIController;

class Layout
{
protected:
    UIController* m_master_controller;

    std::vector<Object*> m_objects;
    
    unsigned m_main_object;

    unsigned m_height; // in characters
    unsigned m_width; 
public:
    Layout();
    virtual ~Layout();

    virtual std::string render();

    void addObject(Object*, bool is_main = false);
    
    virtual void interact(int code);

    // setters
    void setSize(const unsigned height, const unsigned width);
    void setWidth(const unsigned);
    void setHeight(const unsigned);

    void setMaster(UIController*);
    void setMain(const unsigned);

    // getters
    const unsigned width() const;
    const unsigned height() const;
};

