#include "front.h"
#include "../callbacks/eventos_de_janelas.h"

/**
abrir_tela_cadastro_doutor - Cria a tela de cadastro de novo doutor
@widget: widget que disparou o evento
@data: dados passados ao callback

Constrói e exibe uma janela com formulário para cadastro de novo doutor
contendo campos: nome, CRO, email e senha
*/

//* TELA POPUP

void abrir_tela_cadastro_doutor(GtkWidget *widget, gpointer data)
{
    GtkApplication *app = NULL;
    
    if (data != NULL && GTK_IS_APPLICATION(data)) {
        app = GTK_APPLICATION(data);
    }
    
    GtkWidget *janela;
    GtkWidget *caixa;
    
    GtkWidget *titulo;
    GtkWidget *subtitulo;
    
    GtkWidget *botao;

    //nome, cro, email e senha
    Dados_doutor *dados_doutor;
    //aloca a memória e inicializa tudo com 0 ao invés de valores aleatórios da memória
    dados_doutor = g_new0(Dados_doutor, 1);

    janela = create_window(data, "Cadastro de Doutor", 600, 450);
    dados_doutor->janela = janela;

    caixa = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

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

    dados_doutor->nome = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_doutor->nome),
        "Nome completo"
    );
    gtk_box_append(GTK_BOX(caixa), dados_doutor->nome);

    dados_doutor->erro_nome = gtk_label_new("Insira um nome válido");
    gtk_widget_set_visible(dados_doutor->erro_nome, FALSE);
    gtk_box_append(GTK_BOX(caixa), dados_doutor->erro_nome);
    
    dados_doutor->cro = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_doutor->cro),
        "Número do CRO"
    );
    gtk_box_append(GTK_BOX(caixa), dados_doutor->cro);

    dados_doutor->erro_cro = gtk_label_new("Insira um CRO válido");
    gtk_widget_set_visible(dados_doutor->erro_cro, FALSE);
    gtk_box_append(GTK_BOX(caixa), dados_doutor->erro_cro);

    dados_doutor->email = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_doutor->email),
        "E-mail profissional"
    );
    gtk_box_append(GTK_BOX(caixa), dados_doutor->email);

    dados_doutor->erro_email = gtk_label_new("Insira um email válido");
    gtk_widget_set_visible(dados_doutor->erro_email, FALSE);
    gtk_box_append(GTK_BOX(caixa), dados_doutor->erro_email);

    dados_doutor->senha = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_doutor->senha),
        "Crie uma senha"
    );
    gtk_entry_set_visibility(GTK_ENTRY(dados_doutor->senha), FALSE);
    gtk_box_append(GTK_BOX(caixa), dados_doutor->senha);

    dados_doutor->erro_senha = gtk_label_new("Insira um senha válida (Ex: Senha!123)");
    gtk_widget_set_visible(dados_doutor->erro_senha, FALSE);
    gtk_box_append(GTK_BOX(caixa), dados_doutor->erro_senha);
    
    dados_doutor->erro_cadastro = gtk_label_new("ERRO: Corrija as informações indicadas");
    gtk_widget_set_visible(dados_doutor->erro_cadastro, FALSE);
    gtk_box_append(GTK_BOX(caixa), dados_doutor->erro_cadastro);
    
    // Botão para confirmar login
    botao = gtk_button_new_with_label(
        "Cadastrar"
    );
    // Conecta o evento de clique ao callback de validação de login
    g_signal_connect(
        botao, 
        "clicked", 
        G_CALLBACK(clicar_botao_cadastrar_doutor), 
        dados_doutor
    );

    gtk_box_append(
        GTK_BOX(caixa),
        botao
    );

    gtk_window_present(
        GTK_WINDOW(janela)
    );
}