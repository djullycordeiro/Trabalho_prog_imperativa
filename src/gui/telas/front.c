#include <gtk/gtk.h>
#include "front.h"

/**
activate - Cria a tela inicial de login da aplicação
@app: aplicação GTK
@user_data: dados do usuário

Constrói e exibe a janela de login com campos para:
- Login (CPF)
- Senha
- Botão "Confirmar" (executa validação)
- Botão "Criar login" (abre tela de cadastro)
*/
void activate(GtkApplication *app, gpointer user_data){
    
    abrir_tela_login(NULL, app);
}

// Cria uma janela que usa GtkApplication quando disponível
//  elimina rendundâncias de ficar usando o mesmo template pra janela toda hora
GtkWidget *create_window(gpointer app_data, const char *title, int width, int height) {
    GtkApplication *app = NULL;
    if (app_data != NULL && GTK_IS_APPLICATION(app_data)) {
        app = GTK_APPLICATION(app_data);
    }

    GtkWidget *window = NULL;
    if (app != NULL) {
        window = gtk_application_window_new(app);
    } else {
        window = gtk_window_new();
    }

    if (title) {
        gtk_window_set_title(GTK_WINDOW(window), title);
    }
    if (width > 0 && height > 0) {
        gtk_window_set_default_size(GTK_WINDOW(window), width, height);
    }

    return window;
}

