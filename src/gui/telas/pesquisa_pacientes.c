#include "front.h"

//pesquisa no banco de pacientes
void abrir_tela_pesquisar_pacientes(GtkWidget *widget, gpointer data)
{
    GtkApplication *app = NULL;
    
    if (data != NULL && GTK_IS_APPLICATION(data)) {
        app = GTK_APPLICATION(data);
    }

    GtkWidget *janela;
    GtkWidget *caixa_principal;
    GtkWidget *titulo;
    GtkWidget *cabecalho;
    GtkWidget *lista;
    GtkWidget *paciente1;
    GtkWidget *paciente2;
    GtkWidget *paciente3;
    GtkWidget *botao_voltar;

    if (app != NULL) {
        janela = gtk_application_window_new(app);
    } else {
        janela = gtk_window_new();
    }

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
        G_CALLBACK(abrir_tela_perfil_paciente),
        NULL
    );

    gtk_box_append(GTK_BOX(lista), paciente1);

    paciente2 = gtk_button_new_with_label(
        "Maria Souza | 22/03/2008 | 987.654.321-00 | CoA: 118 | CoGn: 75 | AFAI: 122"
    );

    g_signal_connect(
        paciente2,
        "clicked",
        G_CALLBACK(abrir_tela_perfil_paciente),
        NULL
    );

    gtk_box_append(GTK_BOX(lista), paciente2);

    paciente3 = gtk_button_new_with_label(
        "João Silva | 10/11/2007 | 456.789.123-00 | CoA: 121 | CoGn: 77 | AFAI: 126"
    );

    g_signal_connect(
        paciente3,
        "clicked",
        G_CALLBACK(abrir_tela_perfil_paciente),
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
