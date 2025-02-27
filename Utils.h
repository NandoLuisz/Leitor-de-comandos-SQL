#ifndef TRABALHO_ESTRUTURA_DADOS_UTILS_H
#define TRABALHO_ESTRUTURA_DADOS_UTILS_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "Pessoa.h"
#include "Pet.h"
#include "Tipo_pet.h"

#define MAX_LENGTH 255
#define MAX_COMMANDS 500

typedef struct {
    char comando[MAX_LENGTH];
} comando;

struct fila_comando{
    comando comando;
    struct fila_comando *prox;
};

struct columns{
    char name[20];
    char value[30];
    int filled;
};

//FILAS
void fila_iniciar(struct fila_comando **fila, char *comando);
void fila_executar(struct fila_comando *fila, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);//Já deleta cada objeto da fila

//ARQUIVOS
void write_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);
void read_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);
void ler_comandos_do_usuario(struct fila_comando **fila);

//LISTAS
void liberar_todas_as_listas(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);
void lista_filtrada_a_ser_ordenada(
        struct no_pessoa **pessoas,struct no_pet **pets,struct no_tipo_pet **tipo_pets,
        char *tabela_order_by,
        char *coluna_a_ser_filtrada,
        char *valor_a_ser_filtrado,
        char *coluna_a_ser_ordenada);

//DESESTRUTURAÇÂO DO COMANDO
void insert(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
void select(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
void update(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
void delete(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
void destructuring_command(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);

//FUNÇÔES DE VERIFICAÇÂO
int verificar_codigo_pessoa(struct no_pessoa **l, char *codigo);
int verificar_codigo_pet(struct no_pet **l, char *codigo);
int verificar_codigo_tipo_pet(struct no_tipo_pet **l, char *codigo);
int verificar_codigo_pessoa_para_cadastro_de_pet(struct no_pessoa **l, char *codigo);
int verificar_codigo_tipo_pet_para_cadastro_de_pet(struct no_tipo_pet **l, char *codigo);
int verificar_pelo_codigo_se_pode_deletar_pessoa(struct no_pet **l, char *codigo);
int comparar_data(char *data1, char *data2);

//FUNÇÃO EXECUTAR
void executar_comandos(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet, struct fila_comando **fila_comandos);


#endif //TRABALHO_ESTRUTURA_DADOS_UTILS_H
