#include <gtk/gtk.h>
#include "gui/telas/front.h"
#include "services/back.h"

/**
 * main.c - Ponto de entrada do programa
 * 
 * Responsabilidades:
 *   - Inicializar GTK
 *   - Criar a aplicação GTK
 *   - Abrir a primeira tela (login)
 *   - Configurações gerais da aplicação
 */

int main (int argc, char **argv){
    GtkApplication *app;
    int status;
    
    // Criação de uma nova instância da aplicação
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    
    // Conecta o sinal 'activate' à função que abre a tela de login
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

    // Executa a aplicação e recebe o status
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
