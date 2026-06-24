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

// Função para validar o nome, evitanod inserts de nomes com caracteres inválidos
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

    if (strchr(email, ',') != NULL) {
        return 0; // evita quebrar o parsing do CSV
    }

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

    if (strchr(senha, ',') != NULL || strchr(senha, '\n') != NULL) {
        return 0; // evita quebrar o parsing do CSV
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

int validarCpf(const char *cpf) {
    if (strlen(cpf) != 11) {
        return 0;
    }

    // Verifica se todos são dígitos
    for (int i = 0; i < 11; i++) {
        if (!isdigit((unsigned char)cpf[i])) {
            return 0;
        }
    }

    // Evita CPFs com números repetidos
    int iguais = 1;
    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) {
        return 0;
    }

    // Primeiro dígito verificador
    int soma = 0;
    for (int i = 0, peso = 10; i < 9; i++, peso--) {
        soma += (cpf[i] - '0') * peso;
    }

    int resto = soma % 11;
    int dig1 = (resto < 2) ? 0 : 11 - resto;

    if (dig1 != (cpf[9] - '0')) {
        return 0;
    }

    // Segundo dígito verificador
    soma = 0;
    for (int i = 0, peso = 11; i < 10; i++, peso--) {
        soma += (cpf[i] - '0') * peso;
    }

    resto = soma % 11;
    int dig2 = (resto < 2) ? 0 : 11 - resto;

    if (dig2 != (cpf[10] - '0')) {
        return 0;
    }

    return 1;
}
// Função para validar o CoA
int validar_coa (double coa) {
    if (coa >= 80 && coa <= 108) {
        return 1; // válido
    } else {
        return 0; // inválido
    }
}
int validarIdade(const char *idade) {
    if (idade == NULL || strlen(idade) == 0) {
        return 0;
    }

    for (size_t i = 0; i < strlen(idade); i++) {
        if (!isdigit((unsigned char)idade[i])) {
            return 0;
        }
    }

    int valor = atoi(idade);
    if (valor < 0 || valor > 120) {
        return 0;
    }

    return 1;
}


// Valida se um valor genérico é maior que zero
int validar_valores_positivos (double valor) {
    if (valor > 0) {
        return 1; // válido
    } else {
        return 0; // inválido
    }
}

//validação de campo vazio, CRO/email/senha estruturados 
ResultadoCadastro validarCadastro(const char *nome, const char *cro, const char *email, const char *senha) {
    ResultadoCadastro resultado;
    //verifica se os campos estão vazios ou inválidos, se sim, retorna a mensagem de erro correspondente
    resultado.nome = !validarNome(nome) ? "Insira um nome válido" : NULL;
    resultado.cro = (!validarCro(cro) || croExiste(cro)) ? "Insira um CRO válido" : NULL;
    resultado.email = !validarEmail(email) ? "Insira um email válido" : NULL;
    resultado.senha = !validarSenha(senha) ? "Insira uma senha válida" : NULL;

    return resultado;
}

//validação de login, CRO/senha estruturados
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

// Valida os dados de cadastro de um paciente e retorna mensagens de erro se houver algum problema
ResultadoPaciente validarPaciente(const char *nome, const char *cpf, const char *idade, const char *coa, const char *cogn, const char *afai) {
    ResultadoPaciente resultado;

    resultado.nome = !validarNome(nome) ? "Insira um nome válido" : NULL;
    resultado.cpf = !validarCpf(cpf) ? "Insira um CPF válido" : NULL;
    resultado.idade = (!validarIdade(idade)) ? "Insira uma idade válida" : NULL;
    resultado.coa = (!validar_coa(atof(coa))) ? "Insira um CoA válido" : NULL;
    resultado.cogn = (!validar_valores_positivos(atoi(cogn))) ? "Insira um CoGn válido" : NULL;
    resultado.afai = (!validar_valores_positivos(atoi(afai))) ? "Insira um AFAI válido" : NULL;

    return resultado;
   
}

ResultadoDiagnostico calcular_diagnostico(Paciente *p) {
    ResultadoDiagnostico resultado;
    double coa;
    int cogn, afai;
    // Converte strings para numeros 
    sscanf(p->coa, "%lf", &coa);
    sscanf(p->cogn, "%d", &cogn);
    sscanf(p->afai, "%d", &afai);

    // Preenche a estrutura ResultadoDiagnostico com os valores do paciente
    resultado.paciente = *p; 

    // Ajusta o valor do CoA com base no tipo de maxila
    if (p->tipo_maxila == MAXILA_NORMAL) {
        resultado.coa_ajustado = coa;
    }
    else if (p->tipo_maxila == MAXILA_PROTRUIDA) {
        resultado.coa_ajustado = coa - p->grau_maxila;
    }
    else {
        resultado.coa_ajustado = coa + p->grau_maxila;
    }
 
    LinhaMcNamara linha_certa;
    int achou = 0;
    // Procura a linha correspondente na tabela de McNamara
    for (int i = 0; i < 29; i++) {
        if (TABELA_MCNAMARA[i].coa == (int)resultado.coa_ajustado) {
            linha_certa = TABELA_MCNAMARA[i];
            achou = 1;
            break;
        }
    }

    // Se não encontrar na tabela, retorna mensagem de erro
    if (!achou) {
        resultado.mensagem = "CoA fora da faixa da tabela";
        resultado.cogn_min_ideal = 0;
        resultado.cogn_max_ideal = 0;
        resultado.afai_min_ideal = 0;
        resultado.afai_max_ideal = 0;
        resultado.classificacao_cogn = "N/A";
        resultado.classificacao_afai = "N/A";
        return resultado;
    }

    // Preenche os valores ideais de CoGn e AFAI a partir da linha correspondente na tabela
    resultado.cogn_min_ideal = linha_certa.cogn_min;
    resultado.cogn_max_ideal = linha_certa.cogn_max;
    resultado.afai_min_ideal = linha_certa.afai_min;
    resultado.afai_max_ideal = linha_certa.afai_max;
    resultado.mensagem = NULL;

    // Classifica o CoGn e AFAI do paciente com base nos valores ideais da tabela
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