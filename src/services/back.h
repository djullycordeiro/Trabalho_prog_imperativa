#ifndef BACK_H
#define BACK_H

/**
Funcoes de validacao de logica de negocio
Estas funcoes implementam as regras de negocio
e NAO devem conter nenhuma referencia a GTK
*/

typedef struct {
    int coa;        // Comprimento efetivo da Maxila (Co-A) em mm
    int cogn_min; //  Comprimento efetivo da Mandibula (Cogn) min em mm
    int cogn_max; // COGN máx ideal em mm
    int afai_min;  // Altura Facial Anterior Inferior (AFAI) min em mm
    int afai_max; // AFAI max ideal em mm
} LinhaMcNamara;

static const LinhaMcNamara TABELA_MCNAMARA[] = {
    //coa, cogn_min, cogn_max, afai_min, afai_max
    {80, 97, 100, 57, 58},
    {81, 99, 102, 57, 58},
    {82, 101, 104, 58, 59},
    {83, 103, 106, 58, 59},
    {84, 104, 107, 59, 60},
    {85, 105, 108, 60, 62},
    {86, 107, 110, 60, 62},
    {87, 109, 112, 61, 63},
    {88, 111, 114, 61, 63},
    {89, 112, 115, 62, 64},
    {90, 113, 116, 63, 64},
    {91, 115, 118, 63, 64},
    {92, 117, 120, 64, 65},
    {93, 119, 122, 65, 66},
    {94, 121, 124, 66, 67},
    {95, 122, 125, 67, 69},
    {96, 124, 127, 67, 69},
    {97, 126, 129, 68, 70},
    {98, 128, 131, 68, 70},
    {99, 129, 132, 69, 71},
    {100, 130, 133, 70, 74},
    {101, 132, 135, 71, 75},
    {102, 134, 137, 72, 76},
    {103, 136, 139, 73, 77},
    {104, 137, 140, 74, 78},
    {105, 138, 141, 75, 79},
    {106, 139, 142, 76, 80},
    {107, 140, 143, 77, 81},
    {108, 141, 144, 78, 82},
};

//lista de classificações permitidas 
typedef enum {

    MAXILA_NORMAL,
    MAXILA_PROTRUIDA,
    MAXILA_RETRUIDA

} TipoMaxila;

//Estrutura para armazenar dados do paciente
typedef struct {
    char nome[100];
    char idade[4];
    char cpf[20];
    char coa[4];
    char cogn[4];
    char afai[4];
    TipoMaxila tipo_maxila;
    int grau_maxila;
} Paciente;

//estrutura pra armezenar dados do Doutor 
typedef struct {
    char nome[100];
    char cro[20];
    char email[100];
    char senha[50];
} Doutor;

//resultado da validação do cadastro
typedef struct {
    const char *nome;   
    const char *cro;
    const char *email;
    const char *senha;
} ResultadoCadastro;

ResultadoCadastro validarCadastro(const char *nome, const char *cro, const char *email, const char *senha);

//resultado da validação do login
typedef struct {
    const char *cro;
    const char *senha;
    const char *autenticacao; // "CRO ou senha incorretos" ou NULL se ok
} ResultadoLogin;

// struct com os resultados do diagnostico 
typedef struct {
    int coa_ajustado;       // o CoA depois de aplicar o ajuste da maxila
    int cogn_min_ideal;     // valor min faixa ideal de CoGn
    int cogn_max_ideal;     // valor max faixa ideal de CoGn
    int afai_min_ideal;     // valor min faixa ideal de AFAI
    int afai_max_ideal;     // valor max faixa ideal de AFAI
    const char *classificacao_cogn; // "reduzido" / "normal" / "aumentado"
    const char *classificacao_afai; // "reduzido" / "normal" / "aumentado"
    Paciente paciente;
    const char *mensagem;
} ResultadoDiagnostico;

ResultadoDiagnostico calcular_diagnostico(Paciente *p);

// Persistance: registra um novo doutor a partir de uma estrutura Doutor
// Retorna 1 em caso de sucesso, 0 em caso de falha
int cadastrarDoutor(const Doutor *doutor);
int cadastrarPaciente(const Paciente *paciente);

int realizarLogin(const char *login, const char *senha);

/**
validar_login - Valida credenciais de login
@login: string com CPF ou username
@senha: string com a senha
*/
ResultadoLogin validarLogin(const char *cro, const char *senha);

/**
validar_cadastro - Valida dados de cadastro de novo doutor
@nome: nome completo do doutor
@cro: numero do CRO
@email: email profissional
@senha: senha do sistema

Retorna: 1 se valido, 0 se invalido
*/
// declarando existência

int validarCro(const char *cro);

int validarEmail(const char *email); 

int validarSenha(const char *senha);


#endif