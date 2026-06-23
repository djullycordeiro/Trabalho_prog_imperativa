#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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

void verificar_criacao_de_login(const char *nome, const char *cro, const char *email, const char *senha){
    /*
    Quando apertar o botão "cadastrar" essa função vai ser chamada
    A função vai verificar se o cadastro está válido no sistema:
        - se o CRO já existe
        - se o email já foi cadastrado
        - se a senha é segura
    */

    return;
}


void verificar_confirmacao_de_login(const char *login, const char *senha){
    /*
    Quando apertar o botão "confirma" da página de login essa função vai ser chamada
    A função vai verificar se existe os dados cadastrados no sistema:
    Login
    Senha

    se não confirmar ele interrompe a criação de uma nova janela, se confirmar abre.
    */
    return;
}

int validarNome(const char *nome) {
    if (strlen(nome) == 0) {
        return 0;
    }

    int temLetra = 0;

    for (size_t i = 0; i < strlen(nome); i++) {
        //verifica se o caractere é uma letra ou espaço, se não for retorna 0
        if (!isalpha((unsigned char)nome[i]) && !isspace((unsigned char)nome[i])) {
            return 0;
        }
        //verifica se tem pelo menos uma letra
        if (isalpha((unsigned char)nome[i])) {
            temLetra = 1; 
        }
    }

    if (!temLetra) {
        return 0; // se não achou letras, só tinha espaços, retorna 0
    }

    return 1;
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

    if (*(arroba + 1) == '\0' ) {
        return 0; // '@' está no final da string
    }

    if (strchr(arroba + 1, '@') != NULL) {
        return 0; // Contém mais de um '@'
    }

    if (strchr(arroba + 1, '.') == NULL) {
        return 0; // Não contém '.' após o '@'

    }   
    return 1;
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
int validarCro(const char *cro) {
    if (strlen(cro) != 8) return 0; //validação do tamanho XX-XXXXX
    if (cro[2] != '-') return 0; // validação do formato

    char sigla[3] = {cro[0], cro[1], '\0'};

    const char *estados_validos[] = {
        "AC","AL","AP","AM","BA","CE","DF","ES","GO",
        "MA","MT","MS","MG","PA","PB","PR","PE","PI",
        "RJ","RN","RS","RO","RR","SC","SP","SE","TO"
    };
    //procura se a sigla corresponde a um estado que existe
    int sigla_valida = 0;
    for (int i = 0; i < 27; i++) {
        if (strcmp(sigla, estados_validos[i]) == 0) {
            sigla_valida = 1;
            break;
        }
    }

    if (!sigla_valida) return 0;

    //analisa se digitaram numeros depois do hifen 
    for (int i = 3; i < 8; i++) {
        if (!isdigit((unsigned char)cro[i])) return 0;
    }

    return 1;
}

//validação de campo vazio, CRO/email/senha estruturados 
ResultadoCadastro validarCadastro(const char *nome, const char *cro, const char *email, const char *senha) {
    ResultadoCadastro resultado;
    //verifica se os campos estão vazios ou inválidos, se sim, retorna a mensagem de erro correspondente
    resultado.nome = !validarNome(nome) ? "Insira um nome válido" : NULL;
    resultado.cro = !validarCro(cro) ? "Insira um CRO válido" : NULL;
    resultado.email = !validarEmail(email) ? "Insira um email válido" : NULL;
    resultado.senha = !validarSenha(senha) ? "Insira uma senha válida" : NULL;

    return resultado;
}

ResultadoLogin validarLogin(const char *cro, const char *senha) {
    ResultadoLogin resultado;

    //checa formatação do cro e senha antes de procurar se o login existe
    resultado.cro = (!validarCro(cro)) ? "Insira um CRO válido" : NULL; 
    resultado.senha = (!validarSenha(senha)) ? "Insira uma senha válida" : NULL; 
    resultado.autenticacao = NULL;

    // só verifica no arquivo se o formato já tiver ok
    if (resultado.cro == NULL && resultado.senha == NULL) {
        if (!realizarLogin(cro, senha)) {
            resultado.autenticacao = "CRO ou senha incorretos";
        }
    }

    return resultado;

}
// Função para validar o CoA
int validar_coa (double coa) {
    if (coa >= 80 && coa <= 108) {
        return 1; // válido
    } else {
        return 0; // inválido
    }
}
// Valida se um valor genérico é maior que zero
int validar_valores_positivos (double valor) {
    if (valor > 0) {
        return 1; // válido
    } else {
        return 0; // inválido
    }
}

// Função auxiliar para converter a string do GTK de forma segura e validar o cadastro do paciente
ResultadoValidacao validar_dados_paciente(const char *nome, const char *coa_str, const char *idade_str) {

    if (strlen(nome) == 0) {
        return (ResultadoValidacao){0, "Nome do paciente não pode ser vazio"};
        }
        char *endptr;
        double coa = strtod(coa_str, &endptr);

    // Aqui vou verificar se a Conversão falhou ou se o campo tá vazio
    if (endptr == coa_str || *endptr != '\0') {
        return (ResultadoValidacao){0, "CoA inválido, corrija!"};
    }

    double idade = strtod(idade_str, &endptr);
    if (endptr == idade_str || *endptr != '\0') {
        return (ResultadoValidacao){0, "Idade inválida, corrija!"};
    }

    // Aplicando o valor positivo e o CoA válido
    if (!validar_coa) {
        return (ResultadoValidacao){0, "CoA fora da faixa de 80 a 108, corrija!"};
    }

    if (!validar_valores_positivos(idade)) {
        return (ResultadoValidacao){0, "Idade deve ser maior que zero, corrija!"};
    }

    return (ResultadoValidacao){1, NULL}; // Todos os campos válidos
}

ResultadoDiagnostico calcular_diagnostico(Paciente *p) {
    ResultadoDiagnostico resultado;
    int coa, cogn, afai;

    sscanf(p->coa, "%d", &coa);
    sscanf(p->cogn, "%d", &cogn);
    sscanf(p->afai, "%d", &afai);

    if (p->tipo_maxila == MAXILA_NORMAL) {
        resultado.coa_ajustado = coa;
    }
    else if (p->tipo_maxila == MAXILA_PROTRUIDA) {
        resultado.coa_ajustado = coa - p->grau_maxila;
    }
    else { // RETRUIDA
        resultado.coa_ajustado = coa + p->grau_maxila;
    }

    LinhaMcNamara linha_certa;
    int achou = 0;

    for (int i = 0; i < 29; i++) {
        if (TABELA_MCNAMARA[i].coa == resultado.coa_ajustado) {
            linha_certa = TABELA_MCNAMARA[i];
            achou = 1;
            break;
        }
    }

    if (!achou) {
        resultado.mensagem = "CoA fora da faixa da tabela";
        return resultado;
    }

    resultado.cogn_min_ideal = linha_certa.cogn_min;
    resultado.cogn_max_ideal = linha_certa.cogn_max;
    resultado.afai_min_ideal = linha_certa.afai_min;
    resultado.afai_max_ideal = linha_certa.afai_max;
    resultado.paciente = *p;
    resultado.mensagem = NULL;

    if (cogn >= linha_certa.cogn_min && cogn <= linha_certa.cogn_max) {
        resultado.classificacao_cogn = "normal";
    } else if (cogn < linha_certa.cogn_min) {
        resultado.classificacao_cogn = "reduzido";
    } else {
        resultado.classificacao_cogn = "aumentado";
    }

    if (afai >= linha_certa.afai_min && afai <= linha_certa.afai_max) {
        resultado.classificacao_afai = "normal";
    } else if (afai < linha_certa.afai_min) {
        resultado.classificacao_afai = "reduzido";
    } else {
        resultado.classificacao_afai = "aumentado";
    }

    return resultado;
}