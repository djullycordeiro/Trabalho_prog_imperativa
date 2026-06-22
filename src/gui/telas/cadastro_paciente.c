#include "front.h"

/**
abrir_tela_cadastro_paciente - Cria a tela de cadastro de novo paciente
@widget: widget que disparou o evento
@data: dados passados ao callback

Constrói e exibe uma janela com formulário para cadastro de novo doutor
contendo campos: nome, data de nascimento, CoA, CoGn, AFAI
*/

//* TELA POPUP
void abrir_tela_cadastro_paciente(GtkWidget *widget, gpointer data)
{
    GtkApplication *app = NULL;
    
    if (data != NULL && GTK_IS_APPLICATION(data)) {
        app = GTK_APPLICATION(data);
    }

    GtkWidget *janela = create_window(data, "Novo Paciente", 500, 500);
    GtkWidget *caixa;
    
    GtkWidget *titulo;
    GtkWidget *nome;
    GtkWidget *idade;
    GtkWidget *data_de_nascimento;
    GtkWidget *coa;
    GtkWidget *cogn;
    GtkWidget *afai;

    GtkWidget *botao_arquivo;
    GtkWidget *label_arquivo;

    GtkWidget *botao_salvar;
    GtkWidget *botao_voltar;

    /* title and default size set by create_window */

    caixa = gtk_box_new(
        GTK_ORIENTATION_VERTICAL,
        12
    );

    gtk_widget_set_margin_top(caixa, 30);
    gtk_widget_set_margin_bottom(caixa, 30);
    gtk_widget_set_margin_start(caixa, 30);
    gtk_widget_set_margin_end(caixa, 30);

    gtk_window_set_child(
        GTK_WINDOW(janela),
        caixa
    );

    titulo = gtk_label_new("Cadastrar Novo Paciente");
    gtk_box_append(GTK_BOX(caixa), titulo);

    nome = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(nome), "Nome do paciente");
    gtk_box_append(GTK_BOX(caixa), nome);

    data_de_nascimento = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(data_de_nascimento), "Data de nascimento");
    gtk_box_append(GTK_BOX(caixa), data_de_nascimento);

    coa = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(coa), "CoA - Comprimento da Maxila");
    gtk_box_append(GTK_BOX(caixa), coa);

    cogn = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(cogn), "CoGn - Comprimento Mandibular");
    gtk_box_append(GTK_BOX(caixa), cogn);

    afai = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(afai), "AFAI - Altura Facial Anterior");
    gtk_box_append(GTK_BOX(caixa), afai);

    botao_salvar = gtk_button_new_with_label("Salvar Paciente");
    gtk_box_append(GTK_BOX(caixa), botao_salvar);

    botao_voltar = gtk_button_new_with_label("Voltar");
    gtk_box_append(GTK_BOX(caixa), botao_voltar);

    g_signal_connect_swapped(
        botao_voltar,
        "clicked",
        G_CALLBACK(gtk_window_close),
        janela
    );
    
    gtk_window_present(GTK_WINDOW(janela));
}