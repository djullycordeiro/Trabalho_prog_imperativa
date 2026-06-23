#include "front.h"


//informações de uma unidade de paciente
void abrir_tela_perfil_paciente(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela;
    GtkWidget *caixa;
    GtkWidget *titulo;
    GtkWidget *dados;
    GtkWidget *subtitulo_comentarios;
    GtkWidget *comentarios;
    GtkWidget *botao_salvar_comentario;
    GtkWidget *botao_voltar;

    Paciente *paciente = data;

    const char *tipos_maxila[] = {
        "Maxila Normal",
        "Maxila Protuída",
        "Maxila Retruída",
        NULL
    };

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

    char infoPaciente[500]; 

    sprintf(infoPaciente, 
        "Nome: %s\n"
        "Idade: %s\n"
        "CPF: %s\n"
        "CoA: %s\n"
        "CoGn: %s\n"
        "AFAI: %s\n"
        "Classificação Maxila: %s %d",
        paciente->nome, paciente->idade,
        paciente->cpf, paciente->coa,
        paciente->cogn, paciente->afai,
        tipos_maxila[paciente->tipo_maxila], paciente->grau_maxila
    );
    

    dados = gtk_label_new(infoPaciente);
    gtk_box_append(GTK_BOX(caixa), dados);

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