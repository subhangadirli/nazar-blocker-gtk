#include <gtk/gtk.h>
#ifdef HAVE_APPINDICATOR
#include <libayatana-appindicator/app-indicator.h>
#endif
#include <glib/gi18n.h>
#include <locale.h>

#ifndef PACKAGE
#define PACKAGE "nazar"
#endif
#ifndef LOCALEDIR
#define LOCALEDIR "/usr/share/locale"
#endif

static void on_quit(GtkMenuItem *item, gpointer data)
{
    (void)item;
    (void)data;
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    bindtextdomain(PACKAGE, LOCALEDIR);
    bind_textdomain_codeset(PACKAGE, "UTF-8");
    textdomain(PACKAGE);

    gtk_init(&argc, &argv);

#ifdef HAVE_APPINDICATOR
    AppIndicator *indicator = app_indicator_new(
        "nazar",
        "nazar",
        APP_INDICATOR_CATEGORY_APPLICATION_STATUS
    );

    app_indicator_set_status(indicator, APP_INDICATOR_STATUS_ACTIVE);
    app_indicator_set_title(indicator, _("May light shield me from envy and harm."));

    GtkWidget *menu = gtk_menu_new();
    GtkWidget *quit_item = gtk_menu_item_new_with_label(_("Exit"));
    g_signal_connect(quit_item, "activate", G_CALLBACK(on_quit), NULL);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), quit_item);
    gtk_widget_show_all(menu);

    app_indicator_set_menu(indicator, GTK_MENU(menu));
#else
    /* Fallback: show window without tray support */
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), _("Nazar Blocker"));
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *label = gtk_label_new(_("May light shield me from envy and harm."));
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    GtkWidget *quit_btn = gtk_button_new_with_label(_("Exit"));
    g_signal_connect(quit_btn, "clicked", G_CALLBACK(on_quit), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), quit_btn, FALSE, FALSE, 0);

    gtk_widget_show_all(window);
#endif

    gtk_main();
    return 0;
}
