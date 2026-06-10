#include <gtk/gtk.h>
#include "back.h"
#include "front.h"

int main (int argc, char **argv){
    GtkApplication *app;
    int status;
    
    // Criação de uma nova instância pro app
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    // Chama a função activate, puxando a página de login do site
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

    // Começa a aplicação e recebe o status da aplicação
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
