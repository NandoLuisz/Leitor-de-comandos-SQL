#ifndef TRABALHO_ESTRUTURA_DADOS_PET_H
#define TRABALHO_ESTRUTURA_DADOS_PET_H

#include "Utils.h"

#define MAX_LENGTH 255
#define MAX_COMMANDS 500

struct pet{
    char codigo[MAX_LENGTH];
    char codigo_pes[MAX_LENGTH];
    char nome[MAX_LENGTH];
    char codigo_tipo[MAX_LENGTH];
};

struct no_pet{
    struct no_pet *prox;
    struct no_pet *ant;
    struct pet pet;
};

struct a_no_pet{
    struct no_pet *pet;
    struct a_no_pet *esq;
    struct a_no_pet *dir;
};

typedef struct a_no_pet a_no_pet;

//ARQUIVOS
void write_pet_bin(struct no_pet **l);
void read_pet_bin(struct no_pet **l);

//LISTAS
void imprimir_lista_pet(struct no_pet *l);
void liberar_lista_pets(struct no_pet **l);

//DESESTRUTURAÇÂO DO COMANDO
void inserir_pet(struct columns *columns, struct no_pet **pets, struct no_pessoa **pessoas, struct no_tipo_pet **tipo_pets);
void select_pet(struct no_pet **pets, char *column, char *valor);
void update_pet(struct no_pet **pets, struct no_tipo_pet **tipos_pet, struct no_pessoa **pessoas, char *coluna_pesquisada,char *valor_pesquisado,char *coluna_a_ser_alterada,char *valor_a_ser_alterado);
void delete_pet(struct no_pet **pets, char *column_to_be_deleted, char *value_to_be_deleted);

//ÁRVORE BINÁRIA
void select_order_pet(struct no_pet **pets, char *column);
a_no_pet *a_inserir_pet_rr(struct a_no_pet *raiz, struct no_pet *pet, char *column);
void a_in_order_pet(a_no_pet *raiz);
void a_destruir_pet(a_no_pet *raiz);

#endif //TRABALHO_ESTRUTURA_DADOS_PET_H
