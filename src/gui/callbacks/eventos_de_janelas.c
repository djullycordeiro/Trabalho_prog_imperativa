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

void cadastrarDoutor() {
    FILE *arquivo = fopen("usuarios.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o banco de dados!\n");
        return;
    }

    Doutor novoDoutor;

    printf("\n CADASTRO DO DOUTOR (FOP) \n");
    printf("Nome completo: ");
    scanf(" %[^\n]", novoDoutor.nome); // Lê strings com espaços

    printf("CRO (ex: PE-12345): ");
    scanf("%s", novoDoutor.cro);

    printf("E-mail: ");
    scanf("%s", novoDoutor.email);

    printf("Senha: ");
    scanf("%s", novoDoutor.senha);

    fprintf(arquivo, "%s;%s;%s;%s\n", novoDoutor.nome, novoDoutor.cro, novoDoutor.email, novoDoutor.senha);

    fclose(arquivo);
    printf("\nCadastro realizado com sucesso!\n");
}

int realizarLogin() {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum usuário cadastrado ainda!\n");
        return 0; // Falha no login
    }

    char croLogin[20];
    char senhaLogin[50];

    printf("\nLOGIN \n");
    printf("Digite seu CRO: ");
    scanf("%s", croLogin);
    printf("Digite sua senha: ");
    scanf("%s", senhaLogin);

    Doutor usuarioLido;
    int loginSucesso = 0;

    while (fscanf(arquivo, " %[^;];%[^;];%[^;];%[^\n]\n",
                  usuarioLido.nome, usuarioLido.cro, usuarioLido.email, usuarioLido.senha) != EOF) {

        // Compara se o CRO e a senha digitados batem com a linha atual do arquivo
        if (strcmp(croLogin, usuarioLido.cro) == 0 && strcmp(senhaLogin, usuarioLido.senha) == 0) {
            loginSucesso = 1;
            printf("\nBem-vindo(a), Dr(a). %s!\n", usuarioLido.nome);
            break; // Sai do loop pois já achou o usuário
        }
    }

    fclose(arquivo);

    if (!loginSucesso) {
        printf("\nCRO ou senha incorretos!\n");
    }

    return loginSucesso; // Retorna 1 se deu certo, 0 se falhou
}


void verificar_criacao_de_login(){
    /*
    Quando apertar o botão "cadastrar" essa função vai ser chamada
    A função vai verificar se o cadastro está válido no sistema:
        - se o CRO já existe
        - se o email já foi cadastrado
        - se a senha é segura
    */


}

void verificar_confirmacao_de_login(){
    /*
    Quando apertar o botão "confirma" da página de login essa função vai ser chamada
    A função vai verificar se existe os dados cadastrados no sistema:
    Login (provavemente cpf)
    Senha

    se não confirmar ele interrompe a criação de uma nova janela, se confirmar abre.
    */

}