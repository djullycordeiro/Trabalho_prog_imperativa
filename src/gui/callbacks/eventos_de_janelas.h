#ifndef EVENTOS_DE_JANELAS_H
#define EVENTOS_DE_JANELAS_H

#include <gtk/gtk.h>
#include "../telas/front.h"

/**
 * Callbacks (manipuladores de eventos) para widgets da interface gráfica.
 * 
 * Responsabilidades:
 *   - Capturar eventos de widgets (cliques, mudanças em campos, etc)
 *   - Chamar funções de validação do services/back.c
 *   - Atualizar a interface com base nos resultados
 */

/**
 * clicar_botao_confirmar_login - Callback para o botão de confirmação de login
 * @widget: widget que disparou o evento
 * @user_data: dados do login (estrutura Dados_login_senha)
 * 
 * Valida os campos de login e senha, exibindo mensagens de erro se necessário.
 */
void clicar_botao_confirmar_login (GtkWidget *widget, gpointer user_data);

// Callback para o botão de cadastrar doutor
void clicar_botao_cadastrar_doutor(GtkWidget *widget, gpointer user_data);

// Callback para o botão de cadastro de paciente
void clicar_botao_cadastrar_paciente();

#endif
