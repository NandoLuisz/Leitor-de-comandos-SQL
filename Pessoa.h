#ifndef TRABALHO_ESTRUTURA_DADOS_PESSOA_H
#define TRABALHO_ESTRUTURA_DADOS_PESSOA_H

#include "Utils.h"

#define MAX_LENGTH 255
#define MAX_COMMANDS 500

struct pessoa{
    char codigo[MAX_LENGTH];
    char nome[MAX_LENGTH];
    char fone[MAX_LENGTH];
    char endereco[MAX_LENGTH];
    char data_nascimento[MAX_LENGTH];
};

struct no_pessoa{
    struct no_pessoa *prox;
    struct no_pessoa *ant;
    struct pessoa pessoa;
};

struct a_no_pessoa{
    struct no_pessoa *pessoa;
    struct a_no_pessoa *esq;
    struct a_no_pessoa *dir;
};

typedef struct a_no_pessoa a_no_pessoa;

//ARQUIVOS
void write_pessoas_bin(struct no_pessoa **l);
void read_pessoa_bin(struct no_pessoa **l);

//LISTAS
void imprimir_lista_pessoa(struct no_pessoa *l);
void liberar_lista_pessoas(struct no_pessoa **l);

//DESESTRUTURAÇÂO DO COMANDO
void inserir_pessoa(struct columns *columns, struct no_pessoa **pessoas);
void select_pessoa(struct no_pessoa **pessoas, char *column, char *valor);
void update_pessoa(struct no_pessoa **pessoas,char *coluna_pesquisa,char *valor_pesquisado,char *coluna_a_ser_alterada,char *valor_a_ser_alterado);
void delete_pessoa(struct no_pessoa **pessoas, struct no_pet **pets, char *column_to_be_deleted, char *value_to_be_deleted);

//ÁRVORE BINÁRIA
void select_order_pessoa(struct no_pessoa **pessoas, char *column);
a_no_pessoa *a_inserir_rr(struct a_no_pessoa *raiz, struct no_pessoa *pessoa, char *column);
void a_in_order(a_no_pessoa *raiz);
void a_destruir(a_no_pessoa *raiz);



#endif //TRABALHO_ESTRUTURA_DADOS_PESSOA_H
