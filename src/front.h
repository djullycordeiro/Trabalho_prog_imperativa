#ifndef FRONT_H
#define FRONT_H

#include <gtk/gtk.h>

void abrir_janela_de_cadastro(GtkWidget *widget, gpointer data);

void abrir_tela_ala_do_paciente(GtkWidget *widget, gpointer data);

void activate (GtkApplication *app, gpointer user_data);

#endif