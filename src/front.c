#include <gtk/gtk.h>
#include "back.h"

static void abrir_nova_janela(GtkWidget *widget, gpointer data)
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
        "Cadastrar"
    );

    gtk_window_set_default_size(
        GTK_WINDOW(janela),
        420,
        360
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

    titulo = gtk_label_new("Cadastrar");
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

    gtk_window_present(
        GTK_WINDOW(janela)
    );
}

static void abrir_tela_principal(GtkWidget *widget, gpointer data)
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
        "JustAlloc"
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

    botao_novo_paciente =
        gtk_button_new_with_label("Novo Paciente");

    gtk_box_append(
        GTK_BOX(caixa),
        botao_novo_paciente
    );

    botao_visualizar =
        gtk_button_new_with_label("Visualizar Pacientes");

    gtk_box_append(
        GTK_BOX(caixa),
        botao_visualizar
    );

    botao_sair =
        gtk_button_new_with_label("Sair");

    gtk_box_append(
        GTK_BOX(caixa),
        botao_sair
    );

    gtk_window_present(
        GTK_WINDOW(janela)
    );
}

static void activate (GtkApplication *app, gpointer user_data){
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *caixa_login;
    GtkWidget *caixa_senha;
    GtkWidget *botao_criar_login;
    GtkWidget *erro_login;
    GtkWidget *erro_senha;
    
    // janela da aplicação
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "JustAlloc");
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
    
    //botão pra mostrar o texto
    button = gtk_button_new_with_label("Confirmar");
    // Conecta o evento de clique ao callback, passando a estrutura de dados
    g_signal_connect(button, "clicked", G_CALLBACK(abrir_tela_principal), NULL);
    gtk_box_append(GTK_BOX(container), button);


    botao_criar_login = gtk_button_new_with_label("Criar login");
    gtk_widget_add_css_class(botao_criar_login, "flat"); // Remove o fundo e as bordas
    g_signal_connect(botao_criar_login, "clicked", G_CALLBACK(abrir_nova_janela), NULL);
    gtk_box_append(GTK_BOX(container), botao_criar_login);
    
    // liberação de memória quando a janela fechar
    g_object_set_data_full(G_OBJECT(window), "dados_app", dados, g_free);

    gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char **argv){
    GtkApplication *app;
    int status;
    
    // criação de uma nova instância pro app
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
