#include "front.h"
#include "../callbacks/eventos_de_janelas.h"
#include "../../services/back.h"

/*
Página inicial de abertura da aplicação
Abre uma página de login com opções de:
    - Criar conta
    - Fazer Login
*/

void abrir_tela_login(GtkWidget *widget, gpointer user_data){
    
    GtkApplication *app = GTK_APPLICATION(user_data);

    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *caixa_login;
    GtkWidget *caixa_senha;
    GtkWidget *botao_criar_login;
    GtkWidget *erro_login;
    GtkWidget *erro_senha;
    
    // janela da aplicação
    window = gtk_application_window_new(app);
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

    subtitulo = gtk_label_new("Sistema de Interpretação Odontológica");
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
    g_signal_connect(botao_criar_login, "clicked", G_CALLBACK(abrir_tela_cadastro_doutor), NULL);
    gtk_box_append(GTK_BOX(container), botao_criar_login);
    
    // Garante a liberação de memória quando a janela fechar
    g_object_set_data_full(G_OBJECT(window), "dados_app", dados, g_free);

    gtk_window_present(GTK_WINDOW(window)); // login desativado para testes
    //abrir_tela_home_doutor_logado(NULL, NULL);
    gtk_window_present (GTK_WINDOW (window));
}