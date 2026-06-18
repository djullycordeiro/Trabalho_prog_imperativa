#include <gtk/gtk.h>
#include <string.h>
#include "../telas/front.h"
#include "../../services/back.h"
#include "../../persistence/persistence.h"

/**
eventos_de_janelas.c - Callbacks e manipuladores de eventos da GUI

RESPONSABILIDADES:
    - Capturar eventos de interacao do usuario (cliques, entrada de texto, etc)
    - Validar entradas atraves de chamadas para services/back.c
    - Atualizar a interface grafica com feedback visual
 */

//clicar_botao_confirmar_login - Valida os dados de login inseridos
void clicar_botao_confirmar_login (GtkWidget *widget, gpointer user_data){
    Dados_login_senha *dados = user_data;

    const gchar *login = gtk_editable_get_text(GTK_EDITABLE(dados->login));
    const gchar *senha = gtk_editable_get_text(GTK_EDITABLE(dados->senha));
    
    g_print("Login: %s\n", login);
    g_print("Senha: %s\n", senha);
    
    //tratamento de entrada (campo vazio)
    if (strlen(login)==0)
    gtk_widget_set_visible(dados->erro_login, TRUE);
    else 
    gtk_widget_set_visible(dados->erro_login,FALSE);

    if (strlen(senha)==0)
    gtk_widget_set_visible(dados->erro_senha, TRUE);
    else 
    gtk_widget_set_visible(dados->erro_senha, FALSE);
}

// Callback para o botão de cadastrar doutor
void clicar_botao_cadastrar_doutor(GtkWidget *widget, gpointer user_data) {
    Dados_doutor *dados = user_data;

    const gchar *nome = gtk_editable_get_text(GTK_EDITABLE(dados->nome));
    const gchar *cro = gtk_editable_get_text(GTK_EDITABLE(dados->cro));
    const gchar *email = gtk_editable_get_text(GTK_EDITABLE(dados->email));
    const gchar *senha = gtk_editable_get_text(GTK_EDITABLE(dados->senha));

    if (strlen(nome) == 0 || strlen(cro) == 0 || strlen(email) == 0 || strlen(senha) == 0) {
        g_print("Erro: todos os campos de cadastro são obrigatórios.\n");
        return;
    }

    Doutor novo;

    //Tratamento de strings
    strncpy(novo.nome, nome, sizeof(novo.nome)-1);
    novo.nome[sizeof(novo.nome)-1] = '\0';
    strncpy(novo.cro, cro, sizeof(novo.cro)-1);
    novo.cro[sizeof(novo.cro)-1] = '\0';
    strncpy(novo.email, email, sizeof(novo.email)-1);
    novo.email[sizeof(novo.email)-1] = '\0';
    strncpy(novo.senha, senha, sizeof(novo.senha)-1);
    novo.senha[sizeof(novo.senha)-1] = '\0';

    if (cadastrarDoutor(&novo)) {
        g_print("Doutor cadastrado com sucesso: %s\n", novo.nome);
        gtk_window_close(GTK_WINDOW(dados->janela));
    } else {
        g_print("Erro ao cadastrar doutor.\n");
    }
}

void clicar_botao_cadastrar_paciente(GtkWidget *widget, gpointer user_data){
    Dados_paciente *dados = user_data;

    const gchar *nome = gtk_editable_get_text(GTK_EDITABLE(dados->nome));
    const gchar *idade = gtk_editable_get_text(GTK_EDITABLE(dados->idade));
    const gchar *coa = gtk_editable_get_text(GTK_EDITABLE(dados->coa));
    const gchar *cogn = gtk_editable_get_text(GTK_EDITABLE(dados->cogn));
    const gchar *afai = gtk_editable_get_text(GTK_EDITABLE(dados->afai));
    const gchar *classificacao_maxila = gtk_editable_get_text(GTK_EDITABLE(dados->classificacao_maxila));


    if (strlen(nome) == 0 || strlen(idade) == 0 || strlen(coa) == 0 || strlen(cogn) == 0 || strlen(afai) == 0 || strlen(classificacao_maxila) == 0) {
        g_print("Erro: todos os campos de cadastro são obrigatórios.\n");
        return;
    }

    // aqui podemos puxar a função do cálculo dos valores ideais

    Paciente novo;

    //Tratamento de strings
    strncpy(novo.nome, nome, sizeof(novo.nome)-1);
    novo.nome[sizeof(novo.nome)-1] = '\0';
    strncpy(novo.idade, idade, sizeof(novo.idade)-1);
    novo.idade[sizeof(novo.idade)-1] = '\0';
    strncpy(novo.coa, coa, sizeof(novo.coa)-1);
    novo.coa[sizeof(novo.coa)-1] = '\0';
    strncpy(novo.cogn, cogn, sizeof(novo.cogn)-1);
    novo.cogn[sizeof(novo.cogn)-1] = '\0';
    strncpy(novo.afai, afai, sizeof(novo.afai)-1);
    novo.afai[sizeof(novo.afai)-1] = '\0';
    strncpy(novo.classificacao_maxila, classificacao_maxila, sizeof(novo.classificacao_maxila)-1);
    novo.classificacao_maxila[sizeof(novo.classificacao_maxila)-1] = '\0';

    if (cadastrarPaciente(&novo)) {
        g_print("Paciente cadastrado com sucesso: %s\n", novo.nome);
        gtk_window_close(GTK_WINDOW(dados->janela));
    } else {
        g_print("Erro ao cadastrar Paciente.\n");
    }
}