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

    Dados_paciente *dados_paciente;
    //aloca a memória e inicializa tudo com 0 ao invés de valores aleatórios da memória
    dados_paciente = g_new0(Dados_paciente, 1);
    
    const char *classificacoes_maxila[] = {
        "Maxila Normal",
        "Maxila Protuída",
        "Maxila Retruída",
        NULL
    };
    GtkStringList *lista_maxila = gtk_string_list_new(classificacoes_maxila);
    GtkWidget *dropdown;

    GtkWidget *janela = create_window(data, "Novo Paciente", 500, 500);
    dados_paciente->janela = janela;

    GtkWidget *caixa;    
    GtkWidget *titulo;
    
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

    dados_paciente->nome = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->nome), 
        "Nome do paciente"
    );
    gtk_box_append(GTK_BOX(caixa), dados_paciente->nome);

    dados_paciente->idade = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->idade), 
        "Idade"
    );
    gtk_box_append(GTK_BOX(caixa), dados_paciente->idade);
    
    dados_paciente->cpf = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->cpf), 
        "CPF"
    );
    gtk_box_append(GTK_BOX(caixa), dados_paciente->cpf);

    dados_paciente->coa = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->coa), 
        "CoA - Comprimento da Maxila"
    );
    gtk_box_append(GTK_BOX(caixa), dados_paciente->coa);

    dados_paciente->cogn = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->cogn), 
        "CoGn - Comprimento Mandibular"
    );
    gtk_box_append(GTK_BOX(caixa), dados_paciente->cogn);

    dados_paciente->afai = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->afai), 
        "AFAI - Altura Facial Anterior"
    );
    gtk_box_append(GTK_BOX(caixa), dados_paciente->afai);

    
    dados_paciente->classificacao_maxila = gtk_drop_down_new(
        G_LIST_MODEL(lista_maxila),
        NULL
    );
    gtk_box_append(GTK_BOX(caixa), dados_paciente->classificacao_maxila);

    botao_salvar = gtk_button_new_with_label("Salvar Paciente");
    gtk_box_append(GTK_BOX(caixa), botao_salvar);

    g_signal_connect(
        botao_salvar, 
        "clicked", 
        G_CALLBACK(clicar_botao_cadastrar_paciente), 
        dados_paciente
    );

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