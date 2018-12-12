#include "ContractEdit.h"
#include "UIController.h"

ContractEdit::ContractEdit(InsuranceKeeper* ma):master_app(ma)
{
    m_title = new PlainText(L"Редактирование контракта");

    m_name = new InputField();
    m_insured = new InputField();
    m_tariff_rate = new InputField();
    m_office_id = new InputField();
    m_insurance_type = new InputField();

    m_name->setHint(L"Имя");
    m_insured->setHint(L"Сумма");
    m_tariff_rate->setHint(L"Тарифная ставка");
    m_office_id->setHint(L"ID офиса");
    m_insurance_type->setHint(L"Тип страхования");

    addObject(m_title);
    addObject(m_name, true);
    addObject(m_insured);
    addObject(m_tariff_rate);
    addObject(m_office_id);
    addObject(m_insurance_type);
    m_object_selected = 1;
}


ContractEdit::~ContractEdit()
{
    delete m_title;
    delete m_name;
    delete m_insured;
    delete m_tariff_rate;
    delete m_office_id;
    delete m_insurance_type;
}

void ContractEdit::interact(int code)
{
    switch (code)
    {
        case KEY_UP:
            move_selector_up();
            break;
        case KEY_DOWN:
            move_selector_down();
            break;
        case KEY_ENTER:
            save_data();
            m_master_controller->setLayout(m_prev_layout);
            break;
        case KEY_ESC:
            m_master_controller->setLayout(m_prev_layout);
            break;
        default:
            Layout::interact(code);
    }
}


void ContractEdit::move_selector_up()
{
    if (m_object_selected == 1) return;

    m_object_selected--;
    setMain(m_object_selected);
}

void ContractEdit::move_selector_down()
{
    if (m_object_selected == m_objects.size() - 1) return;

    m_object_selected++;
    setMain(m_object_selected);
}


void ContractEdit::setPrevLayout(Layout* l)
{
    m_prev_layout = l;
}

void ContractEdit::setContractData(DataManager* dm, unsigned index)
{
    m_data = dm;
    m_index = index;

    if (m_index >= dm->size()) return;

    m_name->setValue((*m_data)[m_index].name());
    m_insured->setValue((*m_data)[m_index].insured().str());
    m_tariff_rate->setValue(std::to_wstring((*m_data)[m_index].tariff_rate()));
    m_office_id->setValue(std::to_wstring((*m_data)[m_index].office_id()));
    m_insurance_type->setValue(std::to_wstring((*m_data)[m_index].insurance_type()));
}

void ContractEdit::save_data()
{
    if (m_index < m_data->size())
    {
        (*m_data)[m_index].set_name(m_name->value());
    } else {
        Contract c;
        c.set_name(m_name->value());
        m_data->append_data(c);
    }
    m_data->incLastChanged();
}