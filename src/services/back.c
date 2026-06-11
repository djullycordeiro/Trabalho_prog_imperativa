#include <string.h>
#include <stdio.h>
#include "back.h"

/**
back.c - Logica de negocio e servicos da aplicacao

IMPORTANTE: Este arquivo NAO deve conter qualquer referencia a GTK

RESPONSABILIDADES:
    - Implementar regras de negocio
    - Validar dados antes de persistir
    - Gerenciar arvore de decisao para diagnosticos
    - Coordenar operacoes com a camada de persistence

Este eh o cerebro da aplicacao (separado da interface).
*/

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

    return;
}


void verificar_confirmacao_de_login(){
    /*
    Quando apertar o botão "confirma" da página de login essa função vai ser chamada
    A função vai verificar se existe os dados cadastrados no sistema:
    Login (provavemente cpf)
    Senha

    se não confirmar ele interrompe a criação de uma nova janela, se confirmar abre.
    */
    return;
}