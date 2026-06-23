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
    GtkWidget *scroll;
    GtkWidget *lista;
    
    GtkWidget *botao_paciente;
    GtkWidget *botao_voltar;

    if (app != NULL) {
        janela = gtk_application_window_new(app);
    } else {
        janela = gtk_window_new();
    }
    
    
    Paciente paciente[100];
    int quantidade = listarPacientes(paciente);
    
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
    
    scroll = gtk_scrolled_window_new();
    //coloca o scroll dentro da caixa principal da janela
    gtk_box_append(GTK_BOX(caixa_principal), scroll);

    // Controla quando a barra de rolagem aparece
    gtk_scrolled_window_set_policy(
        GTK_SCROLLED_WINDOW(scroll),
        GTK_POLICY_AUTOMATIC,
        GTK_POLICY_AUTOMATIC
    );
    // Faz o scroll ocupar o espaço livre da janela 
    gtk_widget_set_vexpand(scroll, TRUE);

    GtkWidget *container_scroll = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // Coloca o container dentro do scroll
    gtk_scrolled_window_set_child(
        GTK_SCROLLED_WINDOW(scroll),
        container_scroll
    );

    lista = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
    gtk_box_append(GTK_BOX(container_scroll), lista);
    

    for (int i = 0; i<quantidade; i++){
        char resumo_paciente[200];

        sprintf(
            resumo_paciente, 
            "%s | Idade: %s | CPF: %s ",
            paciente[i].nome,
            paciente[i].idade,
            paciente[i].cpf
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