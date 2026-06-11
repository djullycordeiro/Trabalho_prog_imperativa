#ifndef BACK_H
#define BACK_H

/**
 * Estrutura para armazenar dados do paciente
 */
typedef struct {
    char classificacao_maxila[50];
    float CoA;
    float CoGn;
    float AFAI;
} Paciente;

/**
 * Funcoes de validacao de logica de negocio
 * Estas funcoes implementam as regras de negocio
 * e NAO devem conter nenhuma referencia a GTK
 */

/**
 * validar_login - Valida credenciais de login
 * @login: string com CPF ou username
 * @senha: string com a senha
 * 
 * Retorna: 1 se valido, 0 se invalido
 */
int validar_login(const char *login, const char *senha);

/**
 * validar_cadastro - Valida dados de cadastro de novo doutor
 * @nome: nome completo do doutor
 * @cro: numero do CRO
 * @email: email profissional
 * @senha: senha do sistema
 * 
 * Retorna: 1 se valido, 0 se invalido
 */
int validar_cadastro(const char *nome, const char *cro, const char *email, const char *senha);

#endif