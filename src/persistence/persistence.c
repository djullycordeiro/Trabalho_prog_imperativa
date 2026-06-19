#include "../services/back.h"
#include <string.h>
#include <stdio.h>

int cadastrarDoutor(const Doutor *doutor) {
    if (doutor == NULL) {
        return 0;
    }

    char caminho_csv[] = "../src/data/usuarios.csv";

    FILE *arquivo = fopen(caminho_csv, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o banco de dados!\n");
        return 0;
    }

    if (fprintf(arquivo, "%s,%s,%s,%s\n", doutor->nome, doutor->senha, doutor->email, doutor->cro) < 0) {
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    printf("\nCadastro do doutor '%s' realizado com sucesso!\n", doutor->nome);
    return 1;
}

int cadastrarPaciente(const Paciente *paciente){
    if (paciente == NULL) {
        return 0;
    }

    char caminho_csv[] = "../src/data/pacientes.csv";

    FILE *arquivo = fopen(caminho_csv, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o banco de dados!\n");
        return 0;
    }

    if (fprintf(arquivo, "%s,%s,%s,%s,%s,%s\n", paciente->nome, paciente->idade, paciente->coa, paciente->cogn, paciente->afai, paciente->classificacao_maxila) < 0) {
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    printf("\nCadastro do paciente '%s' realizado com sucesso!\n", paciente->nome);
    return 1;

}

int realizarLogin() {
    // Nessa função a gente vai ler o arquivo csv e verificar se as primeiras duas colunas batem com o login e senha
    FILE *arquivo = fopen("usuarios.csv", "r");
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