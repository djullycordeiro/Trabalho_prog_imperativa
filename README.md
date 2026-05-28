# Trabalho de Programação Imperativa

## Sobre o projeto
Este repositório contém uma aplicação GTK em C desenvolvida para o trabalho de Programação Imperativa. O objetivo é criar uma interface simples com entrada de texto e um botão para exibir o conteúdo digitado no terminal.

## Como compilar
### No WSL
```bash
mkdir build
cd build
cmake ..
make
./ProjetoPI-FOP
```

### No MSYS2
```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
ProjetoPI-FOP.exe
```

### Ninja
```bash
mkdir build
cd build
cmake -G Ninja ..
ninja
.\ProjetoPI-FOP.exe 

## Como executar
- Execute o binário gerado após a compilação.

## Links úteis
- [Documentação GTK 4](https://docs.gtk.org/gtk4/index.html)
- [GtkEntry — componente de entrada de texto](https://docs.gtk.org/gtk4/class.Entry.html)
- [Repositório de referência da monitoria](https://github.com/MonitoriaPI/Tarefases)
