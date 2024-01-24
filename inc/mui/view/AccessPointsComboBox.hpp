/*
 * Copyright (C) 2024 MacAndKaj - All Rights Reserved
 */
#ifndef MUI_VIEW_ACCESSPOINTSCOMBOBOX_HPP
#define MUI_VIEW_ACCESSPOINTSCOMBOBOX_HPP

#include <QObject>
#include <QString>

#include <string>
#include <vector>

class QComboBox;

namespace mui::view
{

class AccessPointsComboBox : public QObject
{
    Q_OBJECT

public:
    AccessPointsComboBox() = delete;
    explicit AccessPointsComboBox(QComboBox& combo_box);
    virtual ~AccessPointsComboBox() = default;

    void update(const std::vector<std::string>& access_points);

signals:
    void selectedAccessPointChanged(const std::string& ap);

protected:
    void onCurrentTextChanged(const QString& text);

private:
    QComboBox& m_combo_box;
};

} // namespace mui::view

#endif // MUI_VIEW_ACCESSPOINTSCOMBOBOX_HPP
