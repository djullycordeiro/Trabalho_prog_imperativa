#ifndef BACK_H
#define BACK_H

/**
Funcoes de validacao de logica de negocio
Estas funcoes implementam as regras de negocio
e NAO devem conter nenhuma referencia a GTK
*/

typedef struct {
    int coa;        // Comprimento efetivo da Maxila (Co-A) em mm
    char cogn_ideal[9]; // Comprimento efetivo da Mandíbula (Co-Gn) ideal em mm
    char afai_ideal[9];  // Altura Facial Anterior Inferior (AFAI) ideal em mm
} LinhaMcNamara;

// usem como base o da primeira linha,
// usem a tabela que tá no readme, ela é a que foi passado nos arquivos do professor
static const LinhaMcNamara TABELA_MCNAMARA[] = {
    {80, '97-100',  '57-58'},
    {81, 99-102,  58},
    {82, 101-104, 59},
    {83, 103-106, 59},
    {84, 104-107, 60},
    {85, 105-108, 60},
    {86, 107-110, 61},
    {87, 109-112, 62},
    {88, 111-114, 63},
    {89, 112-115, 64},
    {90, 113-116, 65},
    {91},
    {92},
    {93},
    {94},
    {95},
    {96},
    {97},
    {98},
    {99},
    {100},
    {101},
    {102},
    {103},
    {104},
    {105},
    {106},
    {107},
    {108},
};

//Estrutura para armazenar dados do paciente
typedef struct {
    char nome[100];
    char idade[4];
    char coa[4];
    char cogn[4];
    char afai[4];
    char classificacao_maxila[50];
    char faixa_cogn[9];
    char faixa_afai[9];
} Paciente;

typedef struct {
    char nome[100];
    char cro[20];
    char email[100];
    char senha[50];
} Doutor;

//resultado da validação em 1 lugar só 
typedef struct {
    int valido;
    const char *mensagem;
} ResultadoValidacao;

// Persistance: registra um novo doutor a partir de uma estrutura Doutor
// Retorna 1 em caso de sucesso, 0 em caso de falha
int cadastrarDoutor(const Doutor *doutor);
int cadastrarPaciente(const Paciente *paciente);

int realizarLogin(const char *login, const char *senha);

/**
validar_login - Valida credenciais de login
@login: string com CPF ou username
@senha: string com a senha

Retorna: 1 se valido, 0 se invalido
*/
int validarLogin(const char *login, const char *senha);

/**
validar_cadastro - Valida dados de cadastro de novo doutor
@nome: nome completo do doutor
@cro: numero do CRO
@email: email profissional
@senha: senha do sistema

Retorna: 1 se valido, 0 se invalido
*/
ResultadoValidacao validarCadastro(const char *nome, const char *cro, const char *email, const char *senha);
// declarando existência

int validarCro(const char *cro);

int validarEmail(const char *email); 
int validarSenha(const char *senha);


#endif