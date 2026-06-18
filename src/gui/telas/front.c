#include <gtk/gtk.h>
#include <string.h>
#include "front.h"
#include "../callbacks/eventos_de_janelas.h"
#include "../../services/back.h"


/**
abrir_janela_de_cadastro - Cria a tela de cadastro de novo doutor
@widget: widget que disparou o evento
@data: dados passados ao callback

Constrói e exibe uma janela com formulário para cadastro de novo doutor
contendo campos: nome, CRO, email e senha
*/

void abrir_tela_novo_paciente(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela;
    GtkWidget *caixa;

    GtkWidget *titulo;
    GtkWidget *nome;
    GtkWidget *idade;
    GtkWidget *coa;
    GtkWidget *cogn;
    GtkWidget *afai;
    GtkWidget *classificacao_maxila;

    GtkWidget *botao_arquivo;
    GtkWidget *label_arquivo;

    GtkWidget *botao_salvar;
    GtkWidget *botao_voltar;

    janela = gtk_window_new();

    gtk_window_set_title(
        GTK_WINDOW(janela),
        "Novo Paciente"
    );

    gtk_window_set_default_size(
        GTK_WINDOW(janela),
        500,
        500
    );

    caixa = gtk_box_new(
        GTK_ORIENTATION_VERTICAL,
        12
    );

    gtk_widget_set_margin_top(caixa, 30);
    gtk_widget_set_margin_bottom(caixa, 30);
    gtk_widget_set_margin_start(caixa, 30);
    gtk_widget_set_margin_end(caixa, 30);

    gtk_window_set_child(
        GTK_WINDOW(janela),
        caixa
    );

    titulo = gtk_label_new("Cadastrar Novo Paciente");
    gtk_box_append(GTK_BOX(caixa), titulo);

    nome = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(nome), "Nome do paciente");
    gtk_box_append(GTK_BOX(caixa), nome);

    idade = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(idade), "Idade");
    gtk_box_append(GTK_BOX(caixa), idade);

    coa = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(coa), "CoA - Comprimento da Maxila");
    gtk_box_append(GTK_BOX(caixa), coa);

    cogn = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(cogn), "CoGn - Comprimento Mandibular");
    gtk_box_append(GTK_BOX(caixa), cogn);

    afai = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(afai), "AFAI - Altura Facial Anterior");
    gtk_box_append(GTK_BOX(caixa), afai);

    classificacao_maxila = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(classificacao_maxila), "Classificação da Maxila do Paciente");
    gtk_box_append(GTK_BOX(caixa), classificacao_maxila);

    botao_salvar = gtk_button_new_with_label("Salvar Paciente");
    gtk_box_append(GTK_BOX(caixa), botao_salvar);

    Dados_paciente *dados_paciente = g_malloc(sizeof(Dados_paciente));
    dados_paciente->nome = nome;
    dados_paciente->idade = idade;
    dados_paciente->coa = coa;
    dados_paciente->cogn = cogn;
    dados_paciente->afai = afai;
    dados_paciente->classificacao_maxila = classificacao_maxila;
    dados_paciente->janela = janela;

    g_signal_connect(
        botao_salvar,
        "clicked",
        G_CALLBACK(clicar_botao_cadastrar_paciente),
        dados_paciente
    );

    botao_voltar = gtk_button_new_with_label("Voltar");
    gtk_box_append(GTK_BOX(caixa), botao_voltar);

    g_signal_connect_swapped(
        botao_voltar,
        "clicked",
        G_CALLBACK(gtk_window_close),
        janela
    );

    gtk_window_present(GTK_WINDOW(janela));
}


void abrir_janela_de_cadastro(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela;
    GtkWidget *caixa;

    GtkWidget *titulo;
    GtkWidget *subtitulo;

    GtkWidget *nome;
    GtkWidget *cro;
    GtkWidget *email;
    GtkWidget *senha;

    GtkWidget *botao;

    janela = gtk_window_new();

    gtk_window_set_title(
        GTK_WINDOW(janela),
        "Cadastro de Doutor"
    );

    gtk_window_set_default_size(
        GTK_WINDOW(janela),
        800,
        600
    );

    caixa = gtk_box_new(
        GTK_ORIENTATION_VERTICAL,
        12
    );

    gtk_widget_set_margin_top(caixa, 30);
    gtk_widget_set_margin_bottom(caixa, 30);
    gtk_widget_set_margin_start(caixa, 30);
    gtk_widget_set_margin_end(caixa, 30);

    gtk_window_set_child(
        GTK_WINDOW(janela),
        caixa
    );

    titulo = gtk_label_new("Cadastrar Doutor");
    gtk_box_append(GTK_BOX(caixa), titulo);

    subtitulo = gtk_label_new("Preencha os dados abaixo");
    gtk_box_append(GTK_BOX(caixa), subtitulo);

    nome = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(nome),
        "Nome completo"
    );
    gtk_box_append(GTK_BOX(caixa), nome);
    
    cro = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(cro),
        "Número do CRO"
    );
    gtk_box_append(GTK_BOX(caixa), cro);

    email = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(email),
        "E-mail profissional"
    );
    gtk_box_append(GTK_BOX(caixa), email);

    senha = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(senha),
        "Crie uma senha"
    );

    gtk_entry_set_visibility(
        GTK_ENTRY(senha),
        FALSE
    );

    gtk_box_append(
        GTK_BOX(caixa),
        senha
    );

    botao = gtk_button_new_with_label(
        "Cadastrar"
    );

    gtk_box_append(
        GTK_BOX(caixa),
        botao
    );

    // Cria estrutura para passar widgets ao callback de cadastro
    Dados_doutor *dados_doutor = g_malloc(sizeof(Dados_doutor));
    dados_doutor->nome = nome;
    dados_doutor->cro = cro;
    dados_doutor->email = email;
    dados_doutor->senha = senha;
    dados_doutor->janela = janela;

    g_signal_connect(
        botao,
        "clicked",
        G_CALLBACK(clicar_botao_cadastrar_doutor),
        dados_doutor
    );

    gtk_window_present(
        GTK_WINDOW(janela)
    );
}

/**
abrir_tela_ala_do_paciente - Cria a tela principal (menu de pacientes)
@widget: widget que disparou o evento
@data: dados passados ao callback

Constrói e exibe a janela principal com opções de:
- Novo Paciente
- Visualizar Pacientes
- Sair
*/
void abrir_tela_ala_do_paciente(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela;
    GtkWidget *caixa;

    GtkWidget *titulo;
    GtkWidget *botao_novo_paciente;
    GtkWidget *botao_visualizar;
    GtkWidget *botao_sair;

    janela = gtk_window_new();

    gtk_window_set_title(
        GTK_WINDOW(janela),
        "JustAllign"
    );

    gtk_window_set_default_size(
        GTK_WINDOW(janela),
        600,
        400
    );

    caixa = gtk_box_new(
        GTK_ORIENTATION_VERTICAL,
        15
    );

    gtk_widget_set_margin_top(caixa, 40);
    gtk_widget_set_margin_bottom(caixa, 40);
    gtk_widget_set_margin_start(caixa, 40);
    gtk_widget_set_margin_end(caixa, 40);

    gtk_window_set_child(
        GTK_WINDOW(janela),
        caixa
    );

    titulo = gtk_label_new("Menu Principal");
    gtk_box_append(GTK_BOX(caixa), titulo);

    botao_novo_paciente = gtk_button_new_with_label("Novo Paciente");

    g_signal_connect(        
        botao_novo_paciente,
        "clicked",
        G_CALLBACK(abrir_tela_novo_paciente),
        NULL
    );

    gtk_box_append(
        GTK_BOX(caixa),
        botao_novo_paciente
    );

    botao_visualizar = gtk_button_new_with_label("Visualizar Pacientes");

    g_signal_connect(
        botao_visualizar,
        "clicked",
        G_CALLBACK(abrir_tela_visualizar_pacientes),
        NULL
    );

    gtk_box_append(
        GTK_BOX(caixa),
        botao_visualizar
    );

    botao_sair = gtk_button_new_with_label("Sair");

    gtk_box_append(
        GTK_BOX(caixa),
        botao_sair
    );

    g_signal_connect_swapped(
        botao_sair,
        "clicked",
        G_CALLBACK(gtk_window_close),
        activate
    );


    gtk_window_present(GTK_WINDOW(janela));
}

void abrir_tela_visualizar_pacientes(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela;
    GtkWidget *caixa_principal;
    GtkWidget *titulo;
    GtkWidget *cabecalho;
    GtkWidget *lista;
    GtkWidget *paciente1;
    GtkWidget *paciente2;
    GtkWidget *paciente3;
    GtkWidget *botao_voltar;

    janela = gtk_window_new();

    gtk_window_set_title(GTK_WINDOW(janela), "Visualizar Pacientes");
    gtk_window_set_default_size(GTK_WINDOW(janela), 850, 450);

    caixa_principal = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);

    gtk_widget_set_margin_top(caixa_principal, 30);
    gtk_widget_set_margin_bottom(caixa_principal, 30);
    gtk_widget_set_margin_start(caixa_principal, 30);
    gtk_widget_set_margin_end(caixa_principal, 30);

    gtk_window_set_child(GTK_WINDOW(janela), caixa_principal);

    titulo = gtk_label_new("Pacientes Cadastrados");
    gtk_box_append(GTK_BOX(caixa_principal), titulo);

    cabecalho = gtk_label_new("Nome | Data de nascimento | CPF | CoA | CoGn | AFAI");
    gtk_box_append(GTK_BOX(caixa_principal), cabecalho);

    lista = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_box_append(GTK_BOX(caixa_principal), lista);

    paciente1 = gtk_button_new_with_label(
        "Jefferson Junior | 16/06/2009 | 123.456.789-00 | CoA: 125 | CoGn: 79 | AFAI: 129"
    );

    g_signal_connect(
        paciente1,
        "clicked",
        G_CALLBACK(abrir_tela_arquivos_paciente),
        NULL
    );

    gtk_box_append(GTK_BOX(lista), paciente1);

    paciente2 = gtk_button_new_with_label(
        "Maria Souza | 22/03/2008 | 987.654.321-00 | CoA: 118 | CoGn: 75 | AFAI: 122"
    );

    g_signal_connect(
        paciente2,
        "clicked",
        G_CALLBACK(abrir_tela_arquivos_paciente),
        NULL
    );

    gtk_box_append(GTK_BOX(lista), paciente2);

    paciente3 = gtk_button_new_with_label(
        "João Silva | 10/11/2007 | 456.789.123-00 | CoA: 121 | CoGn: 77 | AFAI: 126"
    );

    g_signal_connect(
        paciente3,
        "clicked",
        G_CALLBACK(abrir_tela_arquivos_paciente),
        NULL
    );

    gtk_box_append(GTK_BOX(lista), paciente3);

    botao_voltar = gtk_button_new_with_label("Voltar");
    gtk_box_append(GTK_BOX(caixa_principal), botao_voltar);

    g_signal_connect_swapped(
        botao_voltar,
        "clicked",
        G_CALLBACK(gtk_window_close),
        janela
    );

    gtk_window_present(GTK_WINDOW(janela));
}

/**
activate - Cria a tela inicial de login da aplicação
@app: aplicação GTK
@user_data: dados do usuário

Constrói e exibe a janela de login com campos para:
- Login (CPF)
- Senha
- Botão "Confirmar" (executa validação)
- Botão "Criar login" (abre tela de cadastro)
 */
void activate (GtkApplication *app, gpointer user_data){
    /*
    Página inicial de abertura da aplicação
    Abre uma página de login com opções de:
        - Criar conta
        - Fazer Login
    */
    
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *caixa_login;
    GtkWidget *caixa_senha;
    GtkWidget *botao_criar_login;
    GtkWidget *erro_login;
    GtkWidget *erro_senha;
    
    // janela da aplicação
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "JustAllign");
    gtk_window_set_default_size (GTK_WINDOW (window), 1000, 800);

    Dados_login_senha *dados;

    // n sei oq isso faz ---> aloca a memória e inicializa tudo com 0 ao invés de valores aleatórios da memória
    dados = g_new0(Dados_login_senha, 1);

    // cria um conteiner que guarda as duas caixas de entrada
    GtkWidget *container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_widget_set_margin_top(container, 100);
    gtk_widget_set_margin_bottom(container, 160);
    gtk_widget_set_margin_start(container, 40);
    gtk_widget_set_margin_end(container, 40);
    gtk_window_set_child(GTK_WINDOW(window), container);
    
    GtkWidget *titulo;
    GtkWidget *subtitulo;

    titulo = gtk_label_new("JustAllign");
    gtk_box_append(GTK_BOX(container), titulo);

    subtitulo = gtk_label_new("Sistema de Classificação Odontológica");
    gtk_box_append(GTK_BOX(container), subtitulo);

    // caixa de entrada login
    caixa_login = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    dados->login = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(dados->login), "Digite seu login: ");
    gtk_box_append(GTK_BOX(caixa_login), dados->login);
    gtk_box_append(GTK_BOX(container), caixa_login);

    //mensagem de erro_login
    dados->erro_login = gtk_label_new("Insira um endereço de login válido");
    gtk_widget_set_visible(dados->erro_login, FALSE);
    gtk_box_append(GTK_BOX(container), dados->erro_login);


    // caixa de entrada senha
    caixa_senha = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    dados->senha = gtk_entry_new();
    //muda a visibilidade da caixa da senha
    gtk_entry_set_visibility(GTK_ENTRY(dados->senha), FALSE);
    gtk_entry_set_placeholder_text(GTK_ENTRY(dados->senha), "Digite sua senha: ");
    gtk_box_append(GTK_BOX(caixa_senha), dados->senha);
    gtk_box_append(GTK_BOX(container), caixa_senha);

    //mensagem de erro_senha
    dados->erro_senha = gtk_label_new("Insira uma senha válida");
    gtk_widget_set_visible(dados->erro_senha, FALSE);
    gtk_box_append(GTK_BOX(container), dados->erro_senha);
    
    // Botão para confirmar login
    button = gtk_button_new_with_label("Confirmar");
    // Conecta o evento de clique ao callback de validação de login
    g_signal_connect(button, "clicked", G_CALLBACK(clicar_botao_confirmar_login), dados);
    gtk_box_append(GTK_BOX(container), button);


    botao_criar_login = gtk_button_new_with_label("Criar login");
    gtk_widget_add_css_class(botao_criar_login, "flat"); // Remove o fundo e as bordas
    g_signal_connect(botao_criar_login, "clicked", G_CALLBACK(abrir_janela_de_cadastro), NULL);
    gtk_box_append(GTK_BOX(container), botao_criar_login);
    
    // Garante a liberação de memória quando a janela fechar
    g_object_set_data_full(G_OBJECT(window), "dados_app", dados, g_free);

    gtk_window_present(GTK_WINDOW(window)); // login desativado para testes
    //abrir_tela_ala_do_paciente(NULL, NULL);
    gtk_window_present (GTK_WINDOW (window));
}
    

void abrir_tela_arquivos_paciente(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela;
    GtkWidget *caixa;
    GtkWidget *titulo;
    GtkWidget *dados;
    GtkWidget *subtitulo_arquivos;
    GtkWidget *arquivo1;
    GtkWidget *arquivo2;
    GtkWidget *subtitulo_comentarios;
    GtkWidget *comentarios;
    GtkWidget *botao_salvar_comentario;
    GtkWidget *botao_voltar;

    janela = gtk_window_new();

    gtk_window_set_title(GTK_WINDOW(janela), "Detalhes do Paciente");
    gtk_window_set_default_size(GTK_WINDOW(janela), 600, 600);

    caixa = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);

    gtk_widget_set_margin_top(caixa, 30);
    gtk_widget_set_margin_bottom(caixa, 30);
    gtk_widget_set_margin_start(caixa, 30);
    gtk_widget_set_margin_end(caixa, 30);

    gtk_window_set_child(GTK_WINDOW(janela), caixa);

    titulo = gtk_label_new("Dados do Paciente");
    gtk_box_append(GTK_BOX(caixa), titulo);

    dados = gtk_label_new(
        "Nome: Jefferson Junior\n"
        "Data de nascimento: 16/06/2009\n"
        "CPF: 123.456.789-00\n"
        "CoA: 125\n"
        "CoGn: 79\n"
        "AFAI: 129\n"
        "Classificação: Maxila Protrusa"
    );
    gtk_box_append(GTK_BOX(caixa), dados);

    subtitulo_arquivos = gtk_label_new("Arquivos enviados");
    gtk_box_append(GTK_BOX(caixa), subtitulo_arquivos);

    arquivo1 = gtk_button_new_with_label("Radiografia frontal.png");
    gtk_box_append(GTK_BOX(caixa), arquivo1);

    arquivo2 = gtk_button_new_with_label("Radiografia lateral.png");
    gtk_box_append(GTK_BOX(caixa), arquivo2);

    subtitulo_comentarios = gtk_label_new("Comentários do médico sobre a evolução");
    gtk_box_append(GTK_BOX(caixa), subtitulo_comentarios);

    comentarios = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(comentarios), GTK_WRAP_WORD);
    gtk_widget_set_size_request(comentarios, 500, 120);
    gtk_box_append(GTK_BOX(caixa), comentarios);

    botao_salvar_comentario = gtk_button_new_with_label("Salvar comentário");
    gtk_box_append(GTK_BOX(caixa), botao_salvar_comentario);

    botao_voltar = gtk_button_new_with_label("Voltar");
    gtk_box_append(GTK_BOX(caixa), botao_voltar);

    g_signal_connect_swapped(
        botao_voltar,
        "clicked",
        G_CALLBACK(gtk_window_close),
        janela
    );

    gtk_window_present(GTK_WINDOW(janela));
}