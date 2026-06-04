# Trabalho de Programação Imperativa

## Sobre o projeto
Este repositório contém uma aplicação GTK em C desenvolvida para o Projeto de Extensão de Programação Imperativa da Poli-UPE. O objetivo é criar um aplicativo simples para a Faculdade de Odontologia da Universidade de Pernambuco utilizando a linguagem de programação C.

## Como Funciona?

Cada paciente possui os seguintes valores:
- CoA (Maxila do paciente);
- CoGn (Mandíbula do paciente);
- AFAI (Altura facial do paciente).

Tais valores se relacionam pela seguinte tabela (Tabela de McNAMARA):
| Comprimento da Maxila | Comprimento Mandibular | Altura Facial Anterior |
| --- | --- | ---|
|80 |                   97-100 |            57-58|
|81	|                   99-102 |            57-58|
|82	|			        101-104 |           58-59|
|83	|			        103-106	|			58-59|
|84	|			        104-107	|			59-60|
|85	|			        105-108	|			60-62|
|86	|			        107-110	|			60-62|
|87	|			        109-112	|			61-63|
|88	|			        111-114	|			61-63|
|89	|			        112-115	|			62-64|
|90	|			        113-116	|			63-64|
|91	|			        115-118	|			63-64|
|92	|			        117-120	|			64-65|
|93	|			        119-122	|			65-66|
|94	|			        121-124	|			66-67|
|95	|			        122-125	|			67-69|
|96	|			        124-127	|			67-69|
|97	|			        126-129	|			68-70|
|98	|			        128-131	|			68-70|
|99	|			        129-132	|			69-71|
|100 |				       130-133	|			70-74|
|101 |				        132-135	|			71-75|
|102 |				        134-137	|			72-76|
|103 |				        136-139	|			73-77|
|104 |				        137-140	|			74-78|
|105 |				        138-141	|			75-79|
|106 |				        139-142	|			76-80|
|107 |				        140-143	|			77-81|
|108 |				        141-144	|			78-82|

Após a classificação da Maxila pelo Profissional, podendo ser uma Maxila normal, Protuída, ou Retruída. Ele colocará no sistema sua análise da Maxila e os valores do paciente.

O sistema fará o cálculo para encontrar a medida ideal da mandíbula do paciente, mostrará a escala para comprimento mandibular e altura facial ideal para o paciente, e classificará seu comprimento mandibular e altura facial.

**Exemplo:**

Dados:

    MAXILA RETROGNÁTICA 2
    CoA = 89mm
    CoGn = 108mm
    AFAI = 70mm

CoA a ser utilizado = 89 + 2 = 91 

Tabela: 

para CoA 91, CoGn deveria ser 115-118, CoGn de 108mm (do paciente):

**TAMANHO MANDIBULAR REDUZIDO**

para CoA 91, AFAI deveria ser 63-64, AFAI de 70mm (do paciente)

**ALTURA FACIAL AUMENTADA**

## Como compilar
### No WSL (Luis)
```bash
mkdir build
cd build
cmake ..
make
./ProjetoPI-FOP
```

### No MSYS2 (Jamerson)
```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
ProjetoPI-FOP.exe
```

### Ninja (Giulia)
```bash
mkdir build
cd build
cmake -G Ninja ..
ninja
.\ProjetoPI-FOP.exe 
```

### MacOS (Fentes)

```bash
mkdir build
cd build

cmake ..
make

./ProjetoPI-FOP
```


## Como executar
- Execute o binário gerado após a compilação.

## Links úteis
- [Documentação GTK 4](https://docs.gtk.org/gtk4/index.html)
- [GtkEntry — componente de entrada de texto](https://docs.gtk.org/gtk4/class.Entry.html)
- [Repositório de referência da monitoria](https://github.com/MonitoriaPI/Tarefases)


## Alunos: 
- Djullyene da Silva Cordeiro
- Giulia Sousa Mendes
- Jamerson Lucas Félix Virginio de Souza
- Luis Felipe Teixeira de Mello
- Matheus Fentes Huang
