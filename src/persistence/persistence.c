#include "../services/back.h"
#include <string.h>
#include <stdio.h>

static const char caminho_usuarios[] = "../src/data/usuarios.csv";
static const char caminho_pacientes[] = "../src/data/pacientes.csv";

int cadastrarDoutor(const Doutor *doutor) {
    if (doutor == NULL) {
        return 0;
    }

    FILE *arquivo = fopen(caminho_usuarios, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o banco de dados!\n");
        return 0;
    }

    if (fprintf(arquivo, "%s, %s, %s, %s\n", 
    doutor->nome, doutor->senha, doutor->email, doutor->cro
    ) < 0) {
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

    FILE *arquivo = fopen(caminho_pacientes, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o banco de dados!\n");
        return 0;
    }

    if (fprintf(arquivo, "%s, %s, %s, %s, %s, %s, %s\n",
    paciente->nome, paciente->idade, paciente->cpf, paciente->coa, paciente->cogn, paciente->afai, paciente->classificacao_maxila
    ) < 0) {
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    printf("\nCadastro do paciente '%s' realizado com sucesso!\n", paciente->nome);
    return 1;

}

int realizarLogin(const char *login, const char *senha) {
    // Nessa função a gente vai ler o arquivo csv e verificar se as primeiras duas colunas batem com o login e senha
    FILE *arquivo = fopen(caminho_usuarios, "r");
    if (arquivo == NULL) {
        return 0; // Falha no login
    }

    Doutor usuarioLido;
    int loginSucesso = 0;

    while (fscanf(arquivo, " %[^,],%[^,],%[^,],%[^\n]\n",
    usuarioLido.nome, usuarioLido.senha, usuarioLido.email, usuarioLido.cro
    )!= EOF) {

        // Compara se o CRO e a senha digitados batem com a linha atual do arquivo
        if (strcmp(login, usuarioLido.cro) == 0 && strcmp(senha, usuarioLido.senha) == 0) {
            loginSucesso = 1;
            break; // Sai do loop pois já achou o usuário
        }
    }

    fclose(arquivo);

    return loginSucesso; // Retorna 1 se deu certo, 0 se falhou
}

int listarPacientes (Paciente pacientes[]){
    FILE *arquivo = fopen(caminho_usuarios, "r");
    if (arquivo == NULL) {
        return 0;
    }

    int qnt = 0;

    while (fscanf(arquivo, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
    pacientes[qnt]->nome, pacientes[qnt]->idade, pacientes[qnt]->cpf, 
    pacientes[qnt]->coa, pacientes[qnt]->cogn, pacientes[qnt]->afai, 
    pacientes[qnt]->classificacao_maxila
    )!= EOF) {
        qnt++;   
    }

    fclose(arquivo);
    return qnt;
}