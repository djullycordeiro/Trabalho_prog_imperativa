#ifndef BACK_H
#define BACK_H

#include <gtk/gtk.h>

void clicar_botao_coa (GtkWidget *widget, gpointer user_data);

typedef struct {
    // Struct pra receber a string
    GtkWidget *campo_texto;
} DadosApp;

typedef struct {
    char classificacao_maxila[50]; //drop down
    float CoA;
    float CoGn;
    float AFAI;
} Paciente;

#endif