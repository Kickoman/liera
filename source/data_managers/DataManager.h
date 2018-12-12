#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Contract.h"

using namespace std;

//template<class T>

class DataManager
{
protected:
    string m_source_file;
    vector<Contract> m_data;

    unsigned m_last_changed;
public:
    DataManager() : m_last_changed(0) {}
    virtual ~DataManager() {}

    int setSource(const string& filename)
    {
        m_source_file = filename;
        return 0;
    }

    int loadData()
    {
        ifstream filer(m_source_file.c_str(), ios::in | ios::binary);

        if (!filer) {
            throw "no such file";
        }

        size_t bufferSize = 0;
        filer.read((char*)&bufferSize, sizeof(size_t));

        m_data.clear();

        for (size_t i = 0; i < bufferSize; ++i)
        {
            unsigned id;
            Datetime datetime;
            Money insured;
            size_t name_len;
            wchar_t* name;

            int tariff_rate;
            int office_id;
            int insurance_type;
            int pages_number;

            filer.read((char*)&id, sizeof(int));
            filer.read((char*)&datetime, sizeof(Datetime));
            filer.read((char*)&insured, sizeof(Money));
            filer.read((char*)&name_len, sizeof(size_t));

            name = new wchar_t[name_len];

            filer.read((char*)name, name_len * sizeof(wchar_t));
            //std::wstring wideName(name);

            filer.read((char*)&tariff_rate, sizeof(int));
            filer.read((char*)&office_id, sizeof(int));
            filer.read((char*)&insurance_type, sizeof(int));
            filer.read((char*)&pages_number, sizeof(int));

            Contract c(id, datetime, insured, name, tariff_rate, office_id, insurance_type, pages_number);
            m_data.push_back(c);
        }

        filer.close();

        return 0;
    }

    int saveData()
    {
        ofstream filew(m_source_file.c_str(), ios::out | ios::binary);

        if (!filew) {
            return -1;
        }

        size_t sz = m_data.size();
        filew.write((char*)&sz, sizeof(m_data.size()));

        for (size_t i = 0; i < m_data.size(); ++i)
        {
            unsigned id = m_data[i].id();
            Datetime datetime = m_data[i].datetime();
            Money    insured = m_data[i].insured();
            size_t   name_len = wcslen(m_data[i].name().c_str()) + 1;

            wchar_t* name = new wchar_t[name_len];
            wcscpy_s(name, name_len, m_data[i].name().c_str());

            int tariff_rate = m_data[i].tariff_rate();
            int office_id = m_data[i].office_id();
            int insurance_type = m_data[i].insurance_type();
            int pages_number = m_data[i].pages_number();

            filew.write((char*)&id, sizeof(id));
            filew.write((char*)&datetime, sizeof(datetime));
            filew.write((char*)&insured, sizeof(insured));
            filew.write((char*)&name_len, sizeof(name_len));
            filew.write((char*)name, sizeof(wchar_t) * name_len);

            filew.write((char*)&tariff_rate, sizeof(int));
            filew.write((char*)&office_id, sizeof(int));
            filew.write((char*)&insurance_type, sizeof(int));
            filew.write((char*)&pages_number, sizeof(int));
        }
        filew.close();
        return 0;
    }

    void setData(vector<Contract>& data)
    {
        m_data = data;
    }

    size_t size()
    {
        return m_data.size();
    }

    Contract operator[](int index) const
    {
        return m_data[index];
    }

    Contract& operator[](int index)
    {
        return m_data[index];
    }

    void remove(unsigned index)
    {
        if (index >= m_data.size()) return;

        for (size_t i = index; i < m_data.size() - 1; ++i)
            swap(m_data[i], m_data[i + 1]);

        m_data.pop_back();
        m_last_changed++;
    }

    void incLastChanged()
    {
        m_last_changed++;
    }

    unsigned lastChanged() const
    {
        return m_last_changed;
    }

    void append_data(Contract c)
    {
        m_data.push_back(c);
    }
};
