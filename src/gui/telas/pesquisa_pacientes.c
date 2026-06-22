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
    
    GtkWidget *botao_paciente;
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

    for (int i = 0; i<qtd; i++){
        char resumo_paciente[200];

        sprintf(
            resumo_paciente, 
            "%s | Idade: %s | CPF: %s ",
            paciente[i].nome,
            paciente[i].idade,
            paciente[i].cpf,
        );

        botao_paciente = gtk_button_new_with_label(resumo_paciente);
        
        g_signal_connect(
            botao_paciente,
            "clicked",
            G_CALLBACK(abrir_tela_perfil_paciente),
            NULL
        );

        gtk_box_append(GTK_BOX(lista), botao_paciente);
    }
    /*
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
    */

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
