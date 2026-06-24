#ifndef FRONT_H
#define FRONT_H

#include <gtk/gtk.h>
#include <string.h>
#include "../callbacks/eventos_de_janelas.h"
#include "../../services/back.h"
#include "../../persistence/persistence.h"

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
    GtkWidget *erro_cadastro;
    GtkWidget *erro_nome;
    GtkWidget *erro_cro;
    GtkWidget *erro_email;
    GtkWidget *erro_senha;
} Dados_doutor;

typedef struct {
    GtkWidget *nome;
    GtkWidget *idade;
    GtkWidget *cpf;
    GtkWidget *coa;
    GtkWidget *cogn;
    GtkWidget *afai;
    GtkWidget *tipo_maxila;
    GtkWidget *grau_maxila;
    GtkWidget *janela;
    GtkWidget *erro_cadastro;
    GtkWidget *erro_nome;
    GtkWidget *erro_idade;
    GtkWidget *erro_cpf;
    GtkWidget *erro_coa;
    GtkWidget *erro_cogn;
    GtkWidget *erro_afai;
} Dados_paciente;

//activate - Tela de login da aplicacao
void activate(GtkApplication *app, gpointer user_data);

//abrir_tela_cadastro_doutor - Tela de cadastro de novo doutor
void abrir_tela_cadastro_doutor(GtkWidget *widget, gpointer data);

//abrir_tela_home_doutor_logado - Tela principal (menu de pacientes)
void abrir_tela_home_doutor_logado(GtkWidget *widget, gpointer data);

//abrir_tela_cadastro_paciente - Tela de cadastro de novo paciente (subir arquivos)
void abrir_tela_cadastro_paciente(GtkWidget *widget, gpointer data);

//abrir_tela_cadastro_paciente - Tela de cadastro de novo paciente
void abrir_tela_cadastro_paciente(GtkWidget *widget, gpointer data);

//abrir_tela_visualizar_pacientes - Tela de visualização dos pacientes cadastrados
void abrir_tela_visualizar_pacientes(GtkWidget *widget, gpointer data);

//abrir_tela_pesquisar_pacientes - Tela de pesquisa de pacientes
void abrir_tela_pesquisar_pacientes(GtkWidget *widget, gpointer data);

//abrir_tela_home_doutor_logado - Tela principal do doutor logado
void abrir_tela_home_doutor_logado(GtkWidget *widget, gpointer data);

//abrir_tela_perfil_paciente - Tela de visualização dos arquivos de um paciente com mais detalhes
void abrir_tela_perfil_paciente(GtkWidget *widget, gpointer data);

// Cria uma janela que usa GtkApplication quando disponível
GtkWidget *create_window(gpointer app_data, const char *title, int width, int height);

//abrir_tela_login - Tela inicial de login
void abrir_tela_login(GtkWidget *widget, gpointer user_data);

#endif