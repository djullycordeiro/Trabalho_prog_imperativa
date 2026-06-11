#ifndef FRONT_H
#define FRONT_H

#include <gtk/gtk.h>

void abrir_nova_janela(GtkWidget *widget, gpointer data);

void abrir_tela_principal(GtkWidget *widget, gpointer data);

void activate (GtkApplication *app, gpointer user_data);

#endif