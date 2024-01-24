/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */

#include <mui/view/AccessPointsComboBox.hpp>

#include <QComboBox>

#include <iostream>

namespace mui::view
{

AccessPointsComboBox::AccessPointsComboBox(QComboBox& combo_box)
    : m_combo_box(combo_box)
{
    connect(&m_combo_box, &QComboBox::currentTextChanged, this, &AccessPointsComboBox::onCurrentTextChanged);
}

void AccessPointsComboBox::update(const std::vector<std::string>& access_points)
{
    std::cout << "Clearing APs combo box" << std::endl;
    m_combo_box.clear();

    for (auto &&ap : access_points)
    {
        m_combo_box.addItem(QString::fromStdString(ap));
    }
    std::cout << "AP combo box updated" << std::endl; 
}


void AccessPointsComboBox::onCurrentTextChanged(const QString& text)
{
    auto ap = text.toStdString();
    std::cout << "Current AP updated: " << ap << std::endl; 

    emit selectedAccessPointChanged(ap);
}

} // namespace mui::view
