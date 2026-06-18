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
void activate(GtkApplication *app, gpointer user_data);

//abrir_tela_cadastro_doutor - Tela de cadastro de novo doutor
void abrir_tela_cadastro_doutor(GtkWidget *widget, gpointer data);

//abrir_tela_home_doutor_logado - Tela principal (menu de pacientes)
void abrir_tela_home_doutor_logado(GtkWidget *widget, gpointer data);

//abrir_tela_cadastro_paciente - Tela de cadastro de novo paciente (subir arquivos)
void abrir_tela_cadastro_paciente(GtkWidget *widget, gpointer data);

//abrir_tela_pesquisar_pacientes - Tela de visualização dos pacientes cadastrados
void abrir_tela_pesquisar_pacientes(GtkWidget *widget, gpointer data);

//abrir_tela_perfil_paciente - Tela de visualização dos arquivos de um paciente com mais detalhes
void abrir_tela_perfil_paciente(GtkWidget *widget, gpointer data);

//abrir_tela_login - Tela inicial de login
void abrir_tela_login(GtkWidget *widget, gpointer user_data);


#endif