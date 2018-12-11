#pragma once
#include <ctime>
#include <string>
class Datetime
{
protected:
    time_t m_time = 0;
public:
    Datetime();
    Datetime(int);
    virtual ~Datetime();

    void set_current();
    std::string localstr() const;

    friend bool operator< (const Datetime& lhs, const Datetime& rhs);// { return m_value < rhs.m_value; }
    friend bool operator> (const Datetime& lhs, const Datetime& rhs);// { return rhs < *this; }
    friend bool operator<=(const Datetime& lhs, const Datetime& rhs);// { return !(*this > rhs); }
    friend bool operator>=(const Datetime& lhs, const Datetime& rhs);// { return !(*this < rhs); }
};
