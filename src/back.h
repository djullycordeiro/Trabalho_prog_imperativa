#ifndef BACK_H
#define BACK_H

#include <gtk/gtk.h>

void clicar_botao_confirmar_login (GtkWidget *widget, gpointer user_data);

typedef struct {
    GtkWidget *login;
    GtkWidget *senha;
    GtkWidget *erro_login;
    GtkWidget *erro_senha;
} Dados_login_senha;

typedef struct {
    char classificacao_maxila[50]; //drop down
    float CoA;
    float CoGn;
    float AFAI;
} Paciente;


// Definindo a estrutura para o cadastro do Sensei
typedef struct {
    char nome[100];
    char cro[20];      // CREA DOS CARAS
    char email[100];
    char senha[50];
} Doutor;


#endif