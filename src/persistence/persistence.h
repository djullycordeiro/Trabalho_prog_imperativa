#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "../services/back.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// Estrutura usada para comentários (compartilhada entre GUI e persistence)
typedef struct {
	GtkWidget *comentario_widget; // widget TextView usado pela GUI
	char comentarioD[2000];       // texto do comentário para persistência
	char cpf[20];                 // cpf do paciente (usado no nome do arquivo)
} DadosComentario;

// Nova struct pra comentários
typedef struct {
    char linhas[30][500]; 
    int qtd_linhas;
} ComentarioPuro;

// Funções de Cadastro 
int cadastrarDoutor(const Doutor *doutor);

int cadastrarPaciente(const Paciente *paciente);

int realizarLogin(const char *login, const char *senha);

// Cria array de struct de pacientes e conta a quantidade de pacientes salvos
int listarPacientes(Paciente pacientes[]);

// Funções de salvamento e carregamento de comentário
int salvarComentario(const DadosComentario *comentario_save);

ComentarioPuro carregarComentario(const char *cpf);

// Função de verificação de duplicata de cro
int croExiste(const char *cro);

#endif