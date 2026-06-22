#include <string.h>
#include <stdio.h>
#include <ctype.h>
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

// Função para validar o email

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

// Função para validar a senha
int validarSenha(const char *senha) {
    if (strlen(senha) < 8) {
        return 0; // A senha deve ter pelo menos 8 caracteres
    }

    int temMaiuscula = 0, temMinuscula = 0, temNumero = 0, temEspecial = 0;

    for (size_t i = 0; i < strlen(senha); i++) {
        if (isupper((unsigned char)senha[i])) temMaiuscula = 1;
        else if (islower((unsigned char)senha[i])) temMinuscula = 1;
        else if (isdigit((unsigned char)senha[i])) temNumero = 1;
        else temEspecial = 1;
    }

    return temMaiuscula && temMinuscula && temNumero && temEspecial;
}

//função pra validar o CRO, evitando inserts 
int validar_cro(const char *cro) {
    if (strlen(cro) != 8) return 0;
    if (cro[2] != '-') return 0;

    char sigla[3];
    sigla[0] = cro[0];
    sigla[1] = cro[1];
    sigla[2] = '\0';

    const char *estados_validos[] = {
        "AC","AL","AP","AM","BA","CE","DF","ES","GO",
        "MA","MT","MS","MG","PA","PB","PR","PE","PI",
        "RJ","RN","RS","RO","RR","SC","SP","SE","TO"
    };

    int sigla_valida = 0;
    for (int i = 0; i < 27; i++) {
        if (strcmp(sigla, estados_validos[i]) == 0) {
            sigla_valida = 1;
            break;
        }
    }

    if (!sigla_valida) return 0;


    for (int i = 3; i < 8; i++) {
        if (!isdigit((unsigned char)cro[i])) return 0;
    }

    return 1;
}
//validação de campo vazio, CRO/email/senha estruturados 
int validar_cadastro(const char *nome, const char *cro, const char *email, const char *senha){
    if (strlen(nome)==0){
        printf ("Insira um nome válido\n");
        return 0;
    }

    if (!validar_cro(cro)) {   
        printf("Insira um CRO válido\n");
        return 0;
    }

    if (!validarEmail(email)) {
        printf("Insira um email válido\n");
        return 0;
    }

    if (!validarSenha(senha)) {
        printf("Insira uma senha válida\n");
        return 0;
    }

    return 1;

}