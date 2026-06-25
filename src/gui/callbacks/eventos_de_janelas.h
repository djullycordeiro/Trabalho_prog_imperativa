#ifndef EVENTOS_DE_JANELAS_H
#define EVENTOS_DE_JANELAS_H

#include <gtk/gtk.h>
#include <string.h>
#include "../telas/front.h"
#include "../../services/back.h"
#include "../../persistence/persistence.h"

/**
Callbacks (manipuladores de eventos) para widgets da interface gráfica.
 
Responsabilidades:
  - Capturar eventos de widgets (cliques, mudanças em campos, etc)
  - Chamar funções de validação do services/back.c
  - Atualizar a interface com base nos resultados
**/

/**
clicar_botao_confirmar_login - Callback para o botão de confirmação de login
Valida os campos de login e senha, exibindo mensagens de erro se necessário.
 */
void clicar_botao_confirmar_login (GtkWidget *widget, gpointer user_data);

// Callback para o botão de cadastrar doutor
void clicar_botao_cadastrar_doutor(GtkWidget *widget, gpointer user_data);

// Callback para o botão de cadastro de paciente
void clicar_botao_cadastrar_paciente(GtkWidget *widget, gpointer user_data);

// Callback para salvar comentário do paciente
void clicar_botao_salvar_comentario(GtkWidget *widget, gpointer user_data);

#endif
