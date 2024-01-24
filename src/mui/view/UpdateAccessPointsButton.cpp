/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */

#include <mui/view/UpdateAccessPointsButton.hpp>

#include <QPushButton>

namespace mui::view
{

UpdateAccessPointsButton::UpdateAccessPointsButton(QPushButton& button)
    : m_button(button)
{
    connect(&m_button, &QPushButton::clicked, [this](){emit triggerUpdateAccessPoints();});
}

} // namespace mui::view
