/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include <mui/core/Core.hpp>
#include <mui/interface/InterfaceManager.hpp>
#include <mui/view/ViewManager.hpp>

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>

#include <optional>
#include <iostream>

std::string find(const QStringList& args, const QString& o1, const std::optional<QString>& o2=std::nullopt)
{
    auto i = args.indexOf(o1);
    if (i != -1)
    {
        return args.at(i+1).toStdString();
    }
    else if (not o2) 
    {
        return {};
    }


    i = args.indexOf(*o2);
    if (i != -1)
    {
        return args.at(i+1).toStdString();
    }

    return {};
}

std::string parse_password(const QStringList& args)
{
    return find(args, "--password", "-p");
}

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);
        QStringList program_arguments = a.arguments();
        qDebug() << program_arguments;

        QTranslator translator;
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        for (const QString &locale : uiLanguages) {
            const QString baseName = "MoturUI_" + QLocale(locale).name();
            if (translator.load(":/i18n/" + baseName)) {
                a.installTranslator(&translator);
                break;
            }
        }

        std::string password = parse_password(program_arguments);

        mui::interface::InterfaceManager interfaceManager;
        mui::core::Core core(interfaceManager, password);
        mui::view::ViewManager manager(interfaceManager);

        return a.exec();
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Exception catched: " << ex.what();
    }
    catch (...)
    {
        std::cerr << "Unknown exception catched!" << std::endl;
    }
    return EXIT_SUCCESS;
}
