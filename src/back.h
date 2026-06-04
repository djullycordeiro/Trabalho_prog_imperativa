#ifndef BACK_H
#define BACK_H

#include <gtk/gtk.h>

void clicar_botao_confirmar_login (GtkWidget *widget, gpointer user_data);

typedef struct {
    GtkWidget *login;
    GtkWidget *senha;
} Dados_login_senha;

typedef struct {
    char classificacao_maxila[50]; //drop down
    float CoA;
    float CoGn;
    float AFAI;
} Paciente;

#endif