#include <string.h>
#include "back.h"

/**
 * back.c - Logica de negocio e servicos da aplicacao
 * 
 * IMPORTANTE: Este arquivo NAO deve conter qualquer referencia a GTK.
 * 
 * Responsabilidades:
 *   - Implementar regras de negocio
 *   - Validar dados antes de persistir
 *   - Gerenciar arvore de decisao para diagnosticos
 *   - Coordenar operacoes com a camada de persistence
 * 
 * Este eh o cerebro da aplicacao (separado da interface).
 */

/**
 * verificar_criacao_de_login - Valida os dados de cadastro de novo doutor
 * 
 * Quando o botao Cadastrar eh clicado, essa funcao eh chamada para validar:
 *   - Se o CRO ja esta registrado no sistema
 *   - Se o email ja foi cadastrado
 *   - Se a senha atende aos criterios de seguranca
 * 
 * Retorna: TRUE se valido, FALSE caso contrario
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

/**
 * verificar_confirmacao_de_login - Valida os dados de login existente
 * 
 * Quando o botao Confirmar da pagina de login eh clicado, essa funcao
 * valida se os dados inseridos existem no sistema:
 *   - Verifica se o login (CPF) existe
 *   - Verifica se a senha esta correta
 * 
 * Se os dados forem validos, a aplicacao prossegue para o menu principal.
 * Se invalidos, exibe mensagem de erro e mantem o usuario na tela de login.
 * 
 * Retorna: TRUE se valido, FALSE caso contrario
 */
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