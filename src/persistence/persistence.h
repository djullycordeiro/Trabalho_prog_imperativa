#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "../services/back.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// Persistance: registra um novo doutor a partir de uma estrutura Doutor
// Retorna 1 em caso de sucesso, 0 em caso de falha
int cadastrarDoutor(const Doutor *doutor);

int cadastrarPaciente(const Paciente *paciente);

int realizarLogin(const char *login, const char *senha);

// Salva paciente em CSV (declarado em persistence.c)
int salvarPacienteCSV(Paciente paciente);

//cria array de struct de pacientes e conta a quantidade de pacientes salvos
int listarPacientes(Paciente pacientes[]);

// Estrutura usada para comentários (compartilhada entre GUI e persistence)
typedef struct {
	GtkWidget *comentario_widget; // widget TextView usado pela GUI
	char comentarioD[2000];       // texto do comentário para persistência
	char cpf[20];                 // cpf do paciente (usado no nome do arquivo)
} DadosComentario;

typedef struct {
    // Um array de 30 strings. Cada posição (ex: linhas[0]) é uma string completa.
    char linhas[30][500]; 
    int qtd_linhas;
} ComentarioPuro;

int salvarComentario(const DadosComentario *comentario_save);

ComentarioPuro carregarComentario(const char *cpf);

#endif