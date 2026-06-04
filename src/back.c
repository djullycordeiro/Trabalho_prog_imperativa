#include <gtk/gtk.h>
#include "back.h"


void clicar_botao_coa (GtkWidget *widget, gpointer user_data){
    // puxa os dados do struct
    DadosApp *dados = user_data;

    // Recebe os dados e printa no terminal
    const gchar *texto = gtk_editable_get_text(GTK_EDITABLE(dados->campo_texto));
    g_print("Texto digitado: %s\n", texto);
}

