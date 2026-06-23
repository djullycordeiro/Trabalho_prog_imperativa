#include "front.h"

/**
abrir_tela_home_doutor_logado - Cria a tela principal (menu de pacientes)
@widget: widget que disparou o evento
@data: dados passados ao callback

Constrói e exibe a janela principal com opções de:
- Novo Paciente
- Visualizar Pacientes
- Sair
*/
void abrir_tela_home_doutor_logado(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela = create_window(data, "JustAllign", 600, 500);
    GtkWidget *caixa;

    GtkWidget *titulo;
    GtkWidget *botao_novo_paciente;
    GtkWidget *botao_visualizar;
    GtkWidget *botao_sair;
    GtkWidget *upe;

    
    caixa = gtk_box_new(
        GTK_ORIENTATION_VERTICAL,
        15
    );
    
    gtk_widget_set_margin_top(caixa, 60);
    gtk_widget_set_margin_bottom(caixa, 60);
    gtk_widget_set_margin_start(caixa, 60);
    gtk_widget_set_margin_end(caixa, 60);

    gtk_window_set_child(
        GTK_WINDOW(janela),
        caixa
    );
    
    upe = gtk_image_new_from_file("../img/upeim1.png");
    gtk_widget_set_halign(upe, GTK_ALIGN_CENTER);
    gtk_box_append(GTK_BOX(caixa), upe);

    titulo = gtk_label_new("Menu Principal");
    gtk_box_append(GTK_BOX(caixa), titulo);

    botao_novo_paciente = gtk_button_new_with_label("Novo Paciente");
    g_signal_connect(        
        botao_novo_paciente,
        "clicked",
        G_CALLBACK(abrir_tela_cadastro_paciente),
        data
    );

    gtk_box_append(
        GTK_BOX(caixa),
        botao_novo_paciente
    );

    botao_visualizar = gtk_button_new_with_label("Visualizar Pacientes");

    g_signal_connect(
        botao_visualizar,
        "clicked",
        G_CALLBACK(abrir_tela_pesquisar_pacientes),
        data
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
        janela
    );


    gtk_window_present(GTK_WINDOW(janela));
}