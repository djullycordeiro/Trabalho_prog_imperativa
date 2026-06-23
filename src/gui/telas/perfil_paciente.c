#include "front.h"

//informações de uma unidade de paciente
void abrir_tela_perfil_paciente(GtkWidget *widget, gpointer data)
{
    GtkWidget *janela;
    GtkWidget *caixa_principal;
    GtkWidget *titulo;

    GtkWidget *caixa_exames_diag;
    GtkWidget *subtitulo_exames_diag;

    GtkWidget *info;
    GtkWidget *exames;
    GtkWidget *exames_ajust;
    GtkWidget *diagnostico;

    GtkWidget *subtitulo_comentarios;
    GtkWidget *comentarios;
    GtkWidget *scroll_comentarios;
    GtkWidget *botao_salvar_comentario;
    GtkWidget *botao_voltar;

    Paciente *paciente = data;
    ResultadoDiagnostico pacienteDiag = calcular_diagnostico(paciente);

    DadosComentario *coment = g_new0(DadosComentario, 1);
    strcpy(coment->cpf, paciente->cpf);
    
    const char *tipos_maxila[] = {
        "Maxila Normal",
        "Maxila Protuída",
        "Maxila Retruída",
        NULL
    };

    janela = gtk_window_new();

    gtk_window_set_title(GTK_WINDOW(janela), "Detalhes do Paciente");
    gtk_window_set_default_size(GTK_WINDOW(janela), 500, 600);
    
    caixa_principal = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    caixa_exames_diag = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    scroll_comentarios = gtk_scrolled_window_new();
    
    gtk_widget_set_margin_top(caixa_principal, 30);
    gtk_widget_set_margin_bottom(caixa_principal, 30);
    gtk_widget_set_margin_start(caixa_principal, 30);
    gtk_widget_set_margin_end(caixa_principal, 30);
    
    gtk_window_set_child(GTK_WINDOW(janela), caixa_principal);

    gtk_widget_set_size_request(scroll_comentarios, 500,120);

    titulo = gtk_label_new("Dados do Paciente");
    gtk_box_append(GTK_BOX(caixa_principal), titulo);
    
    char infoPaciente[200]; 
    sprintf(infoPaciente, 
        "Nome: %s\n"
        "Idade: %s\n"
        "CPF: %s\n",       
        paciente->nome, paciente->idade,
        paciente->cpf
    );
    info = gtk_label_new(infoPaciente);
    gtk_box_append(GTK_BOX(caixa_principal), info);

    char examPaciente[200]; 
    sprintf(examPaciente, 
        "CoA: %s\n"
        "CoGn: %s\n"
        "AFAI: %s\n"
        "Classificação Maxila: %s %d",
        paciente->coa,
        paciente->cogn, paciente->afai,
        tipos_maxila[paciente->tipo_maxila], paciente->grau_maxila
    );
    exames = gtk_label_new(examPaciente);
    gtk_widget_set_hexpand(exames, TRUE);
    gtk_label_set_xalign(GTK_LABEL(exames), 0.0);
    gtk_box_append(GTK_BOX(caixa_exames_diag), exames);

    char exam_ajust_Paciente[200]; 
    sprintf(exam_ajust_Paciente, 
        "CoA (ajustado): %d\n"
        "CoGn (valor ideal): %d - %d\n"
        "Classificação CoGn: %s\n"
        "AFAI (valor ideal): %d - %d\n"
        "Classificação AFAI: %s\n",
        pacienteDiag.coa_ajustado,
        pacienteDiag.cogn_min_ideal, pacienteDiag.cogn_max_ideal,
        pacienteDiag.classificacao_cogn,
        pacienteDiag.afai_min_ideal, pacienteDiag.afai_max_ideal,
        pacienteDiag.classificacao_afai
    );
    exames_ajust = gtk_label_new(exam_ajust_Paciente);
    gtk_widget_set_hexpand(exames_ajust, TRUE);
    gtk_label_set_xalign(GTK_LABEL(exames_ajust), 0.0);
    gtk_box_append(GTK_BOX(caixa_exames_diag), exames_ajust);
    
    subtitulo_exames_diag = gtk_label_new("Exames e Diagnóstico");
    gtk_box_append(GTK_BOX(caixa_principal), subtitulo_exames_diag);
    gtk_box_append(GTK_BOX(caixa_principal), caixa_exames_diag);
    
    subtitulo_comentarios = gtk_label_new("Comentários do médico sobre a evolução");
    gtk_box_append(GTK_BOX(caixa_principal), subtitulo_comentarios);
    

    comentarios = gtk_text_view_new();

    ComentarioPuro historico = carregarComentario(paciente->cpf);
    char texto_completo[10000] = "";
    for (int i = 0; i < historico.qtd_linhas; i++) {
        strcat(texto_completo, historico.linhas[i]);
        strcat(texto_completo, "\n");
    }
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(comentarios));
    gtk_text_buffer_set_text(buffer, texto_completo, -1);

    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(comentarios), GTK_WRAP_WORD);
    gtk_widget_set_size_request(comentarios, 500, 120);
    coment->comentario_widget = comentarios;

    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_comentarios), comentarios);
    gtk_box_append(GTK_BOX(caixa_principal), scroll_comentarios);
    
    botao_salvar_comentario = gtk_button_new_with_label("Salvar comentário");
    gtk_box_append(GTK_BOX(caixa_principal), botao_salvar_comentario);

    g_signal_connect(
        botao_salvar_comentario, 
        "clicked", 
        G_CALLBACK(clicar_botao_salvar_comentario), 
        coment
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