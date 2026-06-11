#include <gtk/gtk.h>
#include <string.h>
#include "../telas/front.h"
#include "../../services/back.h"

/**
 * eventos_de_janelas.c - Callbacks e manipuladores de eventos da GUI
 * 
 * Responsabilidades:
 *   - Capturar eventos de interacao do usuario (cliques, entrada de texto, etc)
 *   - Validar entradas atraves de chamadas para services/back.c
 *   - Atualizar a interface grafica com feedback visual
 */

/**
 * clicar_botao_confirmar_login - Valida os dados de login inseridos
 * @widget: o botao que foi clicado
 * @user_data: estrutura Dados_login_senha contendo os widgets de entrada
 * 
 * Obtem os valores dos campos de login e senha, valida se estao vazios,
 * e exibe mensagens de erro caso necessario.
 */
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