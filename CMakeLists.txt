cmake_minimum_required(VERSION 3.31)
project(ProjetoPI-FOP C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
    src/gui/telas/front.c
    src/gui/telas/login.c
    src/gui/callbacks/eventos_de_janelas.c
    src/gui/telas/home_logado.c
    src/gui/telas/cadastro_doutor.c
    src/gui/telas/cadastro_paciente.c
    src/gui/telas/pesquisa_pacientes.c
    src/gui/telas/perfil_paciente.c
    src/services/back.c
    src/persistence/persistence.c
    src/main.c
)

# Isso é pra encontrar o gtk em cada sistema operacional
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew" "/usr/local")
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::GTK)
