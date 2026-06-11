#ifndef FRONT_H
#define FRONT_H

#include <gtk/gtk.h>

//Estrutura para armazenar widgets de entrada de dados (LOGIN)
typedef struct {
    GtkWidget *login;
    GtkWidget *senha;
    GtkWidget *erro_login;
    GtkWidget *erro_senha;
} Dados_login_senha;

//activate - Tela de login da aplicacao
void activate (GtkApplication *app, gpointer user_data);

//abrir_janela_de_cadastro - Tela de cadastro de novo doutor
void abrir_janela_de_cadastro(GtkWidget *widget, gpointer data);

//abrir_tela_ala_do_paciente - Tela principal (menu de pacientes)
void abrir_tela_ala_do_paciente(GtkWidget *widget, gpointer data);

#endif