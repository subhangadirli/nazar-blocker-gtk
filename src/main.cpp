#include <QApplication>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QLocale>
#include <QObject>
#include <QTranslator>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QIcon>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTranslator *translator = new QTranslator(&app);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(nullptr, "Systray", "No system tray available");
        return 1;
    }

    QApplication::setQuitOnLastWindowClosed(false);

    QString language = QLocale::system().name();
    if (translator->load(":/po/nazar_" + language + ".qm")) {
        app.installTranslator(translator);
    } else {
        std::cout << "No transtation available" << std::endl;
    }

    // Create the tray icon
    QSystemTrayIcon trayIcon;
    // Set tray message
    trayIcon.setToolTip(
        QCoreApplication::translate("Main","May light shield me from envy and harm.")
    );
    // Set tray icon
    QIcon ic(":/src/nazar.svg");
    if (ic.isNull()) {
        QMessageBox::warning(nullptr,
            QCoreApplication::translate("Main","Icon"),
            QCoreApplication::translate("Main","Failed to load icon")
        );
    } else {
        trayIcon.setIcon(ic);
        trayIcon.show();
    }

    // Create a context menu with an Exit action
    QMenu menu;
    QAction *quitAct = menu.addAction(
        QCoreApplication::translate("Main","Exit")
    );

    QObject::connect(quitAct, &QAction::triggered, &app, &QCoreApplication::quit);

    trayIcon.setContextMenu(&menu);
    trayIcon.show();

    return app.exec();
}
