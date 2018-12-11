#include "Contract.h"

Contract::Contract() :m_id(0)
{
    //ctor
}

Contract::Contract(int id) : m_id(id) {}

Contract::~Contract()
{
    //dtor
}


std::wstring Contract::render() const
{
    std::wstring result;
    result = L"ID:\t\t" + std::to_wstring(m_id) + L"\n";
    result += L"Сумма страхования: " + m_insured.str() + L"\n";
    return result;
}


// getters
unsigned Contract::id() const
{
    return m_id;
}

Datetime Contract::datetime()
{
    return m_datetime;
}

Money Contract::insured()
{
    return m_insured;
}

std::wstring Contract::name() const
{
    return m_name;
}

int Contract::tariff_rate() const
{
    return m_tariff_rate;
}

int Contract::office_id() const
{
    return m_office_id;
}

int Contract::insurance_type() const
{
    return m_insurance_type;
}

int Contract::pages_number() const
{
    return m_pages_number;
}

// setters
void Contract::set_datetime(const Datetime time)
{
    m_datetime = time;
}

void Contract::set_insured(const Money sum)
{
    m_insured = sum;
}

void Contract::set_name(const std::wstring name)
{
    m_name = name;
}

void Contract::set_tariff(const int rate)
{
    m_tariff_rate = rate;
}

void Contract::set_office(const int id)
{
    m_office_id = id;
}

void Contract::set_type(const int type)
{
    m_insurance_type = type;
}

bool Contract::compName(Contract& a, Contract& b)
{
    return a.name() < b.name();
}

bool Contract::compDate(Contract& a, Contract& b)
{
    return a.datetime() < b.datetime();
}

bool Contract::compMoney(Contract& a, Contract& b)
{
    return a.insured() < b.insured();
}