#include <QApplication>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(nullptr, "Systray", "No system tray available");
        return 1;
    }

    QApplication::setQuitOnLastWindowClosed(false);

    // Create the tray icon
    QSystemTrayIcon trayIcon;
    // Set tray message
    trayIcon.setToolTip("Elem Terem Fiş Kem Gözlere Şiş");
    // Set tray icon
    QIcon ic(":/src/nazar.svg");
    if (ic.isNull()) {
        QMessageBox::warning(nullptr, "Icon", "Failed to load icon");
    } else {
        trayIcon.setIcon(ic);
        trayIcon.show();
    }

    // Create a context menu with an Exit action
    QMenu menu;
    QAction *quitAct = menu.addAction("Exit");

    QObject::connect(quitAct, &QAction::triggered, &app, &QCoreApplication::quit);

    trayIcon.setContextMenu(&menu);
    trayIcon.show();

    return app.exec();
}
