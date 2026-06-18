#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "../services/back.h"

// Persistance: registra um novo doutor a partir de uma estrutura Doutor
// Retorna 1 em caso de sucesso, 0 em caso de falha
int cadastrarDoutor(const Doutor *doutor);

int cadastrarPaciente(const Paciente *paciente);

int realizarLogin();

// Salva paciente em CSV (declarado em persistence.c)
int salvarPacienteCSV(Paciente paciente);

#endif