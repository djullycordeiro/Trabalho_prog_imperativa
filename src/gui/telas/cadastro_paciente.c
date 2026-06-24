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
    
    const char *tipos_maxila[] = {"Maxila Normal", "Maxila Protuída", "Maxila Retruída", NULL};
    GtkStringList *tipo_maxila = gtk_string_list_new(tipos_maxila);
    const char *graus_maxila[] = {"0", "1", "2", "3", "4", "5", "6", NULL};
    GtkStringList *grau_maxila = gtk_string_list_new(graus_maxila);

    GtkWidget *janela = create_window(data, "Novo Paciente", 500, 500);
    dados_paciente->janela = janela;

    GtkWidget *caixa_principal; 
    GtkWidget *caixa_maxila; 
    GtkWidget *titulo;
    
    GtkWidget *botao_arquivo;
    GtkWidget *label_arquivo;

    GtkWidget *botao_salvar;
    GtkWidget *botao_voltar;

    /* title and default size set by create_window */

    caixa_principal = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    caixa_maxila = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_hexpand(caixa_maxila, TRUE);

    gtk_widget_set_margin_top(caixa_principal, 30);
    gtk_widget_set_margin_bottom(caixa_principal, 30);
    gtk_widget_set_margin_start(caixa_principal, 30);
    gtk_widget_set_margin_end(caixa_principal, 30);
    
    gtk_window_set_child(
        GTK_WINDOW(janela),
        caixa_principal
    );
    
    titulo = gtk_label_new("Cadastrar Novo Paciente");
    gtk_box_append(GTK_BOX(caixa_principal), titulo);

    dados_paciente->nome = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->nome), 
        "Nome do paciente"
    );
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->nome);
    
    dados_paciente->erro_nome = gtk_label_new("Insira um nome válido");
    gtk_widget_set_visible(dados_paciente->erro_nome, FALSE);
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->erro_nome);

    dados_paciente->idade = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->idade), 
        "Idade"
    );
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->idade);

    dados_paciente->erro_idade = gtk_label_new("Insira um idade válido");
    gtk_widget_set_visible(dados_paciente->erro_idade, FALSE);
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->erro_idade);
    
    dados_paciente->cpf = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->cpf), 
        "CPF"
    );
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->cpf);

    dados_paciente->erro_cpf = gtk_label_new("Insira um cpf válido");
    gtk_widget_set_visible(dados_paciente->erro_cpf, FALSE);
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->erro_cpf);

    dados_paciente->coa = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->coa), 
        "CoA - Comprimento da Maxila"
    );
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->coa);

    dados_paciente->erro_coa = gtk_label_new("Insira um coa válido");
    gtk_widget_set_visible(dados_paciente->erro_coa, FALSE);
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->erro_coa);

    dados_paciente->cogn = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->cogn), 
        "CoGn - Comprimento Mandibular"
    );
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->cogn);

    dados_paciente->erro_cogn = gtk_label_new("Insira um cogn válido");
    gtk_widget_set_visible(dados_paciente->erro_cogn, FALSE);
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->erro_cogn);
    
    dados_paciente->afai = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(dados_paciente->afai), 
        "AFAI - Altura Facial Anterior"
    );
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->afai);
    
    dados_paciente->erro_afai = gtk_label_new("Insira um afai válido");
    gtk_widget_set_visible(dados_paciente->erro_afai, FALSE);
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->erro_afai);
    
    //dropdowns
    gtk_box_append(GTK_BOX(caixa_principal), caixa_maxila);
    dados_paciente->tipo_maxila = gtk_drop_down_new(
        G_LIST_MODEL(tipo_maxila),
        NULL
    );
    gtk_widget_set_hexpand(dados_paciente->tipo_maxila, TRUE);
    gtk_box_append(GTK_BOX(caixa_maxila), dados_paciente->tipo_maxila);
    
    dados_paciente->grau_maxila = gtk_drop_down_new(
        G_LIST_MODEL(grau_maxila),
        NULL
    );
    gtk_widget_set_size_request(dados_paciente->grau_maxila,60,-1);
    gtk_box_append(GTK_BOX(caixa_maxila), dados_paciente->grau_maxila);

    dados_paciente->erro_cadastro = gtk_label_new("Erro: todos os campos de cadastro são obrigatórios.");
    gtk_widget_set_visible(dados_paciente->erro_cadastro, FALSE);
    gtk_box_append(GTK_BOX(caixa_principal), dados_paciente->erro_cadastro);

    botao_salvar = gtk_button_new_with_label("Salvar Paciente");
    gtk_box_append(GTK_BOX(caixa_principal), botao_salvar);

    g_signal_connect(
        botao_salvar, 
        "clicked", 
        G_CALLBACK(clicar_botao_cadastrar_paciente), 
        dados_paciente
    );

    botao_voltar = gtk_button_new_with_label("Voltar");
    gtk_box_append(GTK_BOX(caixa_principal), botao_voltar);

    g_signal_connect_swapped(
        botao_voltar,
        "clicked",
        G_CALLBACK(gtk_window_close),
        janela
    );
    
    gtk_window_present(GTK_WINDOW(janela));
}