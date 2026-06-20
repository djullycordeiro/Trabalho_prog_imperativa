#include <string.h>
#include <stdio.h>
#include "back.h"
#include "../persistence/persistence.h"

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



int validarEmail(const char *email) {

    char *arroba = strchr(email, '@'); // strchr retorna um ponteiro para a primeira ocorrência do caractere '@' na string email
  
    if (arroba == NULL) {
        return 0; // Não contém '@'
    }

    if (arroba == email) {
        return 0; // '@' está no início da string
    }

    if (*(arroba + 1) ) {
        return 0; // '@' está no final da string
    }

    if (strchr(arroba + 1, '@') != NULL) {
        return 0; // Contém mais de um '@'
    }

    if (strchr(arroba + 1, '.') == NULL) {
        return 0; // Não contém '.' após o '@'

    }   
 


}