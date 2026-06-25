#include "persistence.h"

// Caminhos para os arquivos .csv
static const char caminho_usuarios[] = "../src/data/usuarios.csv";
static const char caminho_pacientes[] = "../src/data/pacientes.csv";

// Função que faz a escrita do doutor no csv
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

// Função que faz o cadastro do paciente no arquivo .csv
int cadastrarPaciente(const Paciente *paciente){
    if (paciente == NULL) {
        return 0;
    }

    FILE *arquivo = fopen(caminho_pacientes, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o banco de dados!\n");
        return 0;
    }

    if (fprintf(arquivo, "%s, %s, %s, %s, %s, %s, %d, %d\n",
    paciente->nome, paciente->idade, paciente->cpf, paciente->coa, paciente->cogn, paciente->afai, paciente->tipo_maxila, paciente->grau_maxila
    ) < 0) {
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    printf("\nCadastro do paciente '%s' realizado com sucesso!\n", paciente->nome);
    return 1;

}

// Essa função vai ler o arquivo csv e verificar se as primeiras duas colunas batem com o login e senha
int realizarLogin(const char *login, const char *senha) {
    FILE *arquivo = fopen(caminho_usuarios, "r");
    if (arquivo == NULL) {
        return 0; // Falha no login
    }

    Doutor usuarioLido;
    int loginSucesso = 0;

    while (fscanf(arquivo, "%[^,], %[^,], %[^,], %[^\n]\n",
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

// Função que guarda os pacientes cadastrados numa lista de structs
int listarPacientes(Paciente pacientes[]){
    FILE *arquivo = fopen(caminho_pacientes, "r");
    if (arquivo == NULL) {
        return 0;
    }
    printf("Abrindo arquivo...\n");

    int qnt = 0;

    while (fscanf(arquivo, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %d, %d\n",
    pacientes[qnt].nome, pacientes[qnt].idade, pacientes[qnt].cpf, 
    pacientes[qnt].coa, pacientes[qnt].cogn, pacientes[qnt].afai, 
    (int *)&pacientes[qnt].tipo_maxila , &pacientes[qnt].grau_maxila 
    )!= EOF) {
        qnt++; 
        printf("Lendo paciente %d\n", qnt); 
    }

    fclose(arquivo);
    return qnt;
}

// Função que salva o comentário em um arquivo .txt
int salvarComentario(const DadosComentario *comentario_save){
    char caminho_comentario[500];
    sprintf(caminho_comentario, "../src/data/comentarios/%s.txt", comentario_save->cpf);

    FILE *arquivo = fopen(caminho_comentario, "w");
    if (arquivo == NULL){
        return 0;
    }

    if (fprintf(arquivo, "%s\n", comentario_save->comentarioD) < 0) {
        fclose(arquivo);
        return 0;
    }

    fclose(arquivo);
    return 1;
}

// Função que carrega o comentário de um arquivo .txt para ficar em tela.
ComentarioPuro carregarComentario(const char *cpf) {
    char caminho_comentario[100];
    sprintf(caminho_comentario, "../src/data/comentarios/%s.txt", cpf);

    ComentarioPuro dados;
    dados.qtd_linhas = 0;

    FILE *arquivo = fopen(caminho_comentario, "r");
    if (arquivo == NULL) return dados;

    char buffer_linha[500];
    
    // Enquanto houver linhas no arquivo e houver espaço no nosso array
    while (fgets(buffer_linha, sizeof(buffer_linha), arquivo) != NULL && dados.qtd_linhas < 30) {
        
        // Remove o '\n' do final que o fgets traz
        buffer_linha[strcspn(buffer_linha, "\n")] = '\0';

        // Copia a string do buffer direto para a posição atual do array de strings
        strcpy(dados.linhas[dados.qtd_linhas], buffer_linha);

        dados.qtd_linhas++; // Avança para a próxima "linha do caderno"
    }

    fclose(arquivo);
    return dados;
}

// Função que verifica a existência de um cro igual ao puxado como referência pra evitar duplicatas.
int croExiste(const char *cro){
    FILE *arquivo = fopen(caminho_usuarios, "r");
    if (arquivo == NULL) return 0;

    Doutor doutorLido;
    int existe = 0;

    while (fscanf(arquivo, "%[^,], %[^,], %[^,], %[^\n]\n",
    doutorLido.nome, doutorLido.senha, doutorLido.email, doutorLido.cro
    )!= EOF) {
        // Compara se o CRO digitado batem com a linha atual do arquivo
        if (strcmp(cro, doutorLido.cro) == 0) {
            existe = 1;
            break;
        }
    }

    fclose(arquivo);

    return existe;
}