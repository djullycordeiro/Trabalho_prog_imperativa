#include <gtk/gtk.h>
#include <string.h>
#include "front.h"
#include "../callbacks/eventos_de_janelas.h"
#include "../../services/back.h"

/**
activate - Cria a tela inicial de login da aplicação
@app: aplicação GTK
@user_data: dados do usuário

Constrói e exibe a janela de login com campos para:
- Login (CPF)
- Senha
- Botão "Confirmar" (executa validação)
- Botão "Criar login" (abre tela de cadastro)
 */
void activate(GtkApplication *app, gpointer user_data){
    
    abrir_tela_login(NULL, app);

}
    

