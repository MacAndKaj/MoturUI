/*
 * Copyright (C) 2022 MacAndKaj - All Rights Reserved
 */
#include <view/ViewManager.hpp>

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);

        QTranslator translator;
        const QStringList uiLanguages = QLocale::system().uiLanguages();
        for (const QString &locale : uiLanguages) {
            const QString baseName = "MoturUI_" + QLocale(locale).name();
            if (translator.load(":/i18n/" + baseName)) {
                a.installTranslator(&translator);
                break;
            }
        }
        view::ViewManager manager;
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
