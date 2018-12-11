#pragma once
#include <string>
#include "Money.h"
#include "Datetime.h"

class Contract
{
protected:
    unsigned int m_id;

    Datetime m_datetime;
    Money m_insured;

    std::wstring m_name; // имя подписанта

    int m_tariff_rate;
    int m_office_id;
    int m_insurance_type;
    int m_pages_number;

public:
    Contract(); 
    Contract(
        unsigned id,
        Datetime datetime,
        Money insured,
        std::wstring name,
        int tariff_rate,
        int office_id,
        int insurance_type,
        int pages_number
    ) : m_id(id),
        m_datetime(datetime),
        m_insured(insured),
        m_name(name),
        m_tariff_rate(tariff_rate),
        m_office_id(office_id),
        m_insurance_type(insurance_type),
        m_pages_number(pages_number)
    {}
    Contract(int);
    virtual ~Contract();

    std::wstring render() const;

    //getters
    unsigned id() const;
    Datetime datetime();
    Money insured();
    std::wstring name() const;
    int tariff_rate() const;
    int office_id() const;
    int insurance_type() const;
    int pages_number() const;

    //setters
    void set_datetime(const Datetime time);
    void set_insured(const Money sum);
    void set_name(const std::wstring name);
    void set_tariff(const int rate);
    void set_office(const int id);
    void set_type(const int type);

    // comparators
    static bool compName(Contract& a, Contract& b);
    static bool compDate(Contract& a, Contract& b);
    static bool compMoney(Contract& a, Contract& b);
};