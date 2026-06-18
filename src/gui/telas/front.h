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

// Estrutura para armazenar widgets do formulário de cadastro de doutor
typedef struct {
    GtkWidget *nome;
    GtkWidget *cro;
    GtkWidget *email;
    GtkWidget *senha;
    GtkWidget *janela;
} Dados_doutor;

typedef struct {
    GtkWidget *nome;
    GtkWidget *idade;
    GtkWidget *coa;
    GtkWidget *cogn;
    GtkWidget *afai;
    GtkWidget *classificacao_maxila;
    GtkWidget *janela;
} Dados_paciente;

//activate - Tela de login da aplicacao
void activate (GtkApplication *app, gpointer user_data);

//abrir_janela_de_cadastro - Tela de cadastro de novo doutor
void abrir_janela_de_cadastro(GtkWidget *widget, gpointer data);

//abrir_tela_ala_do_paciente - Tela principal (menu de pacientes)
void abrir_tela_ala_do_paciente(GtkWidget *widget, gpointer data);

//abrir_tela_novo_paciente - Tela de cadastro de novo paciente (subir arquivos)
void abrir_tela_novo_paciente(GtkWidget *widget, gpointer data);

//abrir_tela_visualizar_pacientes - Tela de visualização dos pacientes cadastrados
void abrir_tela_visualizar_pacientes(GtkWidget *widget, gpointer data);

//abrir_tela_arquivos_paciente - Tela de visualização dos arquivos de um paciente com mais detalhes
void abrir_tela_arquivos_paciente(GtkWidget *widget, gpointer data);

//abrir_tela_ala_do_paciente - Tela principal (menu de pacientes)
void abrir_tela_visualizar_pacientes(GtkWidget *widget, gpointer data);

#endif