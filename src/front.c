#include <gtk/gtk.h>
#include "back.h"

static void activate (GtkApplication *app, gpointer user_data){
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *caixa;
    
    // janela da aplicação
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "JustoBrush");
    gtk_window_set_default_size (GTK_WINDOW (window), 1000, 800);
    
    // botão que aparece na janela
    //button = gtk_button_new_with_label ("Botão que fala");
    //g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    //gtk_window_set_child (GTK_WINDOW (window), button);

    DadosApp *dados;

    // n sei oq isso faz
    dados = g_new0(DadosApp, 1);

    // caixa de entrada
    caixa = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
    gtk_widget_set_margin_top(caixa, 100);
    gtk_widget_set_margin_bottom(caixa, 160);
    gtk_widget_set_margin_start(caixa, 40);
    gtk_widget_set_margin_end(caixa, 40);
    gtk_window_set_child(GTK_WINDOW(window), caixa);

    // coloca os dados da caixa no struct
    dados->campo_texto = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(dados->campo_texto), "Digite o valor de CoA: ");
    gtk_box_append(GTK_BOX(caixa), dados->campo_texto);

    //Botão pra mostrar o texto
    button = gtk_button_new_with_label("mostra");
    
    // Conecta o evento de clique ao callback, passando a estrutura de dados
    g_signal_connect(button, "clicked", G_CALLBACK(clicar_botao_coa), dados);
    gtk_box_append(GTK_BOX(caixa), button);
    // Garante a liberação de memória quando a janela fechar
    g_object_set_data_full(G_OBJECT(window), "dados_app", dados, g_free);

    gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char **argv){
    GtkApplication *app;
    int status;
    
    // Criação de uma nova instância pro app
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
