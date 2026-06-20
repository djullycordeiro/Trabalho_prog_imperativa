#include "front.h"

/**
abrir_tela_cadastro_doutor - Cria a tela de cadastro de novo doutor
@widget: widget que disparou o evento
@data: dados passados ao callback

Constrói e exibe uma janela com formulário para cadastro de novo doutor
contendo campos: nome, CRO, email e senha
*/
void abrir_tela_cadastro_doutor(GtkWidget *widget, gpointer data)
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
        600,
        450
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

    gtk_window_present(
        GTK_WINDOW(janela)
    );
}