#ifndef TRABALHO_ESTRUTURA_DADOS_TIPO_PET_H
#define TRABALHO_ESTRUTURA_DADOS_TIPO_PET_H

#include "Utils.h"

#define MAX_LENGTH 255
#define MAX_COMMANDS 500

struct tipo_pet{
    char codigo[MAX_LENGTH];
    char nome[MAX_LENGTH];
};

struct no_tipo_pet{
    struct no_tipo_pet *prox;
    struct no_tipo_pet *ant;
    struct tipo_pet tipo_pet;
};

struct a_no_tipo_pet{
    struct no_tipo_pet *tipo_pet;
    struct a_no_tipo_pet *esq;
    struct a_no_tipo_pet *dir;
};

typedef struct a_no_tipo_pet a_no_tipo_pet;

//ARQUIVOS
void write_tipo_pet_bin(struct no_tipo_pet **l);
void read_tipo_pet_bin(struct no_tipo_pet **l);

//LISTAS
void imprimir_lista_tipo_pet(struct no_tipo_pet *l);
void liberar_lista_tipo_pet(struct no_tipo_pet **l);

//DESESTRUTURAÇÂO DO COMANDO
void inserir_tipo_pet(struct columns *columns, struct no_tipo_pet **tipo_pets);
void select_tipo_pet(struct no_tipo_pet **tipos_pet, char *column, char *valor);
void update_tipo_pet(struct no_tipo_pet **tipos_pet,char *coluna_pesquisa,char *valor_pesquisado,char *coluna_a_ser_alterada,char *valor_a_ser_alterado);
void delete_tipo_pet(struct no_tipo_pet **tipos_pet, char *column_to_be_deleted, char *value_to_be_deleted);

//ÁRVORE BINÁRIA
void select_order_tipo_pet(struct no_tipo_pet **tipos_pet, char *column);
a_no_tipo_pet *a_inserir_tipo_pet_rr(struct a_no_tipo_pet *raiz, struct no_tipo_pet *pet, char *column);
void a_in_order_tipo_pet(a_no_tipo_pet *raiz);
void a_destruir_tipo_pet(a_no_tipo_pet *raiz);

#endif //TRABALHO_ESTRUTURA_DADOS_TIPO_PET_H
