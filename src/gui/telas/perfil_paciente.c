#include "front.h"

//informações de uma unidade de paciente
void abrir_tela_perfil_paciente(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela = create_window(data, "Perfil do Paciente", 600, 400);
    GtkWidget *caixa = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);

    gtk_widget_set_margin_top(caixa, 30);
    gtk_widget_set_margin_bottom(caixa, 30);
    gtk_widget_set_margin_start(caixa, 30);
    gtk_widget_set_margin_end(caixa, 30);

    gtk_window_set_child(GTK_WINDOW(janela), caixa);

    GtkWidget *titulo = gtk_label_new("Perfil do Paciente");
    gtk_box_append(GTK_BOX(caixa), titulo);

    GtkWidget *descricao = gtk_label_new("Detalhes do paciente não implementados.");
    gtk_box_append(GTK_BOX(caixa), descricao);

    GtkWidget *botao_fechar = gtk_button_new_with_label("Fechar");
    gtk_box_append(GTK_BOX(caixa), botao_fechar);

    g_signal_connect_swapped(
        botao_fechar,
        "clicked",
        G_CALLBACK(gtk_window_close),
        janela
    );

    gtk_window_present(GTK_WINDOW(janela));
}