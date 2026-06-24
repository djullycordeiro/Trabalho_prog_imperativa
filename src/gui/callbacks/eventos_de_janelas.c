#include "eventos_de_janelas.h"

/**
eventos_de_janelas.c - Callbacks e manipuladores de eventos da GUI

RESPONSABILIDADES:
    - Capturar eventos de interacao do usuario (cliques, entrada de texto, etc)
    - Validar entradas atraves de chamadas para services/back.c
    - Atualizar a interface grafica com feedback visual
 */

//clicar_botao_confirmar_login - Valida os dados de login inseridos
void clicar_botao_confirmar_login (GtkWidget *widget, gpointer user_data){
    Dados_login_senha *dados = user_data;

    const gchar *login = gtk_editable_get_text(GTK_EDITABLE(dados->login));
    const gchar *senha = gtk_editable_get_text(GTK_EDITABLE(dados->senha));
    
    g_print("Login: %s\n", login);
    g_print("Senha: %s\n", senha);
    
    // tratamento de entrada (campo vazio)
    if (strlen(login) == 0 || strlen(senha) == 0 || realizarLogin(login, senha) == 0) {
        gtk_widget_set_visible(dados->erro_login, TRUE);
        return;
    }

    gtk_widget_set_visible(dados->erro_login, FALSE);

    GtkWidget *janela_login = gtk_widget_get_ancestor(GTK_WIDGET(widget), GTK_TYPE_WINDOW);
    GtkApplication *app = gtk_window_get_application(GTK_WINDOW(janela_login));

    abrir_tela_home_doutor_logado(NULL, app);

    if (janela_login) {
        gtk_window_close(GTK_WINDOW(janela_login));
    }
}

// Callback para o botão de cadastrar doutor
void clicar_botao_cadastrar_doutor(GtkWidget *widget, gpointer user_data) {
    Dados_doutor *dados = user_data;
    
    const gchar *nome = gtk_editable_get_text(GTK_EDITABLE(dados->nome));
    const gchar *cro = gtk_editable_get_text(GTK_EDITABLE(dados->cro));
    const gchar *email = gtk_editable_get_text(GTK_EDITABLE(dados->email));
    const gchar *senha = gtk_editable_get_text(GTK_EDITABLE(dados->senha));
    
    ResultadoCadastro valida_cadastro = validarCadastro(nome, cro, email, senha);

    gtk_widget_set_visible(dados->erro_nome, FALSE); 
    gtk_widget_set_visible(dados->erro_cro, FALSE); 
    gtk_widget_set_visible(dados->erro_email, FALSE); 
    gtk_widget_set_visible(dados->erro_senha, FALSE); 
    gtk_widget_set_visible(dados->erro_cadastro, FALSE); 

    if (valida_cadastro.nome || valida_cadastro.cro ||valida_cadastro.email || valida_cadastro.senha ) {
        g_print("Erro: todos os campos de cadastro são obrigatórios.\n");
        gtk_widget_set_visible(dados->erro_cadastro, TRUE);
        if (valida_cadastro.nome){
            g_print("%s\n", valida_cadastro.nome);
            gtk_widget_set_visible(dados->erro_nome, TRUE);}
        if (valida_cadastro.cro){
            g_print("%s\n", valida_cadastro.cro);
            gtk_widget_set_visible(dados->erro_cro, TRUE);}
        if (valida_cadastro.email){
            g_print("%s\n", valida_cadastro.email);
            gtk_widget_set_visible(dados->erro_email, TRUE);}
        if (valida_cadastro.senha){
            g_print("%s\n", valida_cadastro.senha);
            gtk_widget_set_visible(dados->erro_senha, TRUE);}
        return;
    }

    Doutor novo;

    //Tratamento de strings
    strncpy(novo.nome, nome, sizeof(novo.nome)-1);
    novo.nome[sizeof(novo.nome)-1] = '\0';
    strncpy(novo.cro, cro, sizeof(novo.cro)-1);
    novo.cro[sizeof(novo.cro)-1] = '\0';
    strncpy(novo.email, email, sizeof(novo.email)-1);
    novo.email[sizeof(novo.email)-1] = '\0';
    strncpy(novo.senha, senha, sizeof(novo.senha)-1);
    novo.senha[sizeof(novo.senha)-1] = '\0';

    if (cadastrarDoutor(&novo)) {
        g_print("Doutor cadastrado com sucesso: %s\n", novo.nome);
        gtk_window_close(GTK_WINDOW(dados->janela));
    } else {
        g_print("Erro ao cadastrar doutor.\n");
    }
}

void clicar_botao_cadastrar_paciente(GtkWidget *widget, gpointer user_data){
    Dados_paciente *dados = user_data;
    
    // aqui podemos puxar a função do cálculo dos valores ideais
    Paciente novo;
    
    const gchar *nome = gtk_editable_get_text(GTK_EDITABLE(dados->nome));
    const gchar *idade = gtk_editable_get_text(GTK_EDITABLE(dados->idade));
    const gchar *cpf = gtk_editable_get_text(GTK_EDITABLE(dados->cpf));
    const gchar *coa = gtk_editable_get_text(GTK_EDITABLE(dados->coa));
    const gchar *cogn = gtk_editable_get_text(GTK_EDITABLE(dados->cogn));
    const gchar *afai = gtk_editable_get_text(GTK_EDITABLE(dados->afai));
    guint indice_tipo_maxila = gtk_drop_down_get_selected(GTK_DROP_DOWN(dados->tipo_maxila));
    novo.tipo_maxila = (TipoMaxila) indice_tipo_maxila;
    guint indice_grau_maxila = gtk_drop_down_get_selected(GTK_DROP_DOWN(dados->grau_maxila));
    novo.grau_maxila = indice_grau_maxila;

    ResultadoPaciente valida_paciente = validarPaciente(nome, cpf, idade, coa, cogn, afai);
    
    gtk_widget_set_visible(dados->erro_nome, FALSE); 
    gtk_widget_set_visible(dados->erro_cpf, FALSE); 
    gtk_widget_set_visible(dados->erro_idade, FALSE); 
    gtk_widget_set_visible(dados->erro_coa, FALSE); 
    gtk_widget_set_visible(dados->erro_cogn, FALSE); 
    gtk_widget_set_visible(dados->erro_afai, FALSE); 

    if (valida_paciente.nome || valida_paciente.cpf || valida_paciente.idade || 
        valida_paciente.coa || valida_paciente.cogn || valida_paciente.afai ) {
        g_print("Erro: todos os campos de cadastro são obrigatórios.\n");
        gtk_widget_set_visible(dados->erro_cadastro, TRUE);
        if (valida_paciente.nome){
            g_print("%s\n", valida_paciente.nome);
            gtk_widget_set_visible(dados->erro_nome, TRUE);}
        if (valida_paciente.cpf){
            g_print("%s\n", valida_paciente.cpf);
            gtk_widget_set_visible(dados->erro_cpf, TRUE);}
        if (valida_paciente.idade){
            g_print("%s\n", valida_paciente.idade);
            gtk_widget_set_visible(dados->erro_idade, TRUE);}
        if (valida_paciente.coa){
            g_print("%s\n", valida_paciente.coa);
            gtk_widget_set_visible(dados->erro_coa, TRUE);}
        if (valida_paciente.cogn){
            g_print("%s\n", valida_paciente.cogn);
            gtk_widget_set_visible(dados->erro_cogn, TRUE);}
        if (valida_paciente.afai){
            g_print("%s\n", valida_paciente.afai);
            gtk_widget_set_visible(dados->erro_afai, TRUE);}
        return;
    }


    //Tratamento de strings
    strncpy(novo.nome, nome, sizeof(novo.nome)-1);
    novo.nome[sizeof(novo.nome)-1] = '\0';
    strncpy(novo.idade, idade, sizeof(novo.idade)-1);
    novo.idade[sizeof(novo.idade)-1] = '\0';
    strncpy(novo.cpf, cpf, sizeof(novo.cpf)-1);
    novo.cpf[sizeof(novo.cpf)-1] = '\0';
    strncpy(novo.coa, coa, sizeof(novo.coa)-1);
    novo.coa[sizeof(novo.coa)-1] = '\0';
    strncpy(novo.cogn, cogn, sizeof(novo.cogn)-1);
    novo.cogn[sizeof(novo.cogn)-1] = '\0';
    strncpy(novo.afai, afai, sizeof(novo.afai)-1);
    novo.afai[sizeof(novo.afai)-1] = '\0';

    if (cadastrarPaciente(&novo)) {
        g_print("Paciente cadastrado com sucesso: %s\n", novo.nome);
        gtk_window_close(GTK_WINDOW(dados->janela));
    } else {
        g_print("Erro ao cadastrar Paciente.\n");
    }
}

void clicar_botao_salvar_comentario(GtkWidget *widget, gpointer user_data){
    DadosComentario *dados = user_data;
    DadosComentario comentario;

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(dados->comentario_widget));

    GtkTextIter inicio, fim;

    gtk_text_buffer_get_start_iter(buffer, &inicio);
    gtk_text_buffer_get_end_iter(buffer, &fim);

    char *texto = gtk_text_buffer_get_text(
        buffer,
        &inicio,
        &fim,
        FALSE
    );

    strncpy(comentario.comentarioD, texto, sizeof(comentario.comentarioD)-1);
    comentario.comentarioD[sizeof(comentario.comentarioD)-1] = '\0';
    strncpy(comentario.cpf, dados->cpf, sizeof(comentario.cpf)-1);
    comentario.cpf[sizeof(comentario.cpf)-1] = '\0';

    if (salvarComentario(&comentario)) g_print("Comentário salvo!\n");
    else g_print("Erro ao salvar comentário.\n");

    g_free(texto);

}