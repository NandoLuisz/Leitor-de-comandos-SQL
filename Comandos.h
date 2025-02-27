////
//// Created by nando on 01/02/2025.
////
//
//#ifndef TRABALHO_ESTRUTURA_DADOS_COMANDOS_H
//#define TRABALHO_ESTRUTURA_DADOS_COMANDOS_H
//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//
//typedef struct {
//    char comando[255];
//} Comando;
//
//struct fila_comando{
//    char comando[MAX_LENGTH];
//    struct fila_comando *prox;
//};
//
//struct pessoa{
//    char codigo[MAX_LENGTH];
//    char nome[MAX_LENGTH];
//    char fone[MAX_LENGTH];
//    char endereco[MAX_LENGTH];
//    char data_nascimento[MAX_LENGTH];
//};
//
//struct pet{
//    char codigo[MAX_LENGTH];
//    char codigo_pes[MAX_LENGTH];
//    char nome[MAX_LENGTH];
//    char codigo_tipo[MAX_LENGTH];
//};
//
//struct tipo_pet{
//    char codigo[MAX_LENGTH];
//    char nome[MAX_LENGTH];
//};
//
//struct no_pessoa{
//    struct no_pessoa *prox;
//    struct no_pessoa *ant;
//    struct pessoa pessoa;
//};
//
//struct no_pet{
//    struct no_pet *prox;
//    struct no_pet *ant;
//    struct pet pet;
//};
//
//struct no_tipo_pet{
//    struct no_tipo_pet *prox;
//    struct no_tipo_pet *ant;
//    struct tipo_pet tipo_pet;
//};
//
//struct columns{
//    char name[20];
//    char value[30];
//    int filled;
//};
//
//struct a_no_pessoa{
//    struct no_pessoa *pessoa;
//    struct a_no_pessoa *esq;
//    struct a_no_pessoa *dir;
//};
//
//typedef struct a_no_pessoa a_no_pessoa;
//
//struct a_no_pet{
//    struct no_pet *pet;
//    struct a_no_pet *esq;
//    struct a_no_pet *dir;
//};
//
//typedef struct a_no_pet a_no_pet;
//
//struct a_no_tipo_pet{
//    struct no_tipo_pet *tipo_pet;
//    struct a_no_tipo_pet *esq;
//    struct a_no_tipo_pet *dir;
//};
//
//typedef struct a_no_tipo_pet a_no_tipo_pet;
//
////FILAS
//void fila_iniciar(struct fila_comando **fila, char *comando);
//void fila_executar(struct fila_comando *fila, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);//Já deleta cada objeto da fila
//
////ARQUIVOS
//void write_pessoas_bin(struct no_pessoa **l);
//void write_tipo_pet_bin(struct no_tipo_pet **l);
//void write_pet_bin(struct no_pet **l);
//void write_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);
//void read_pessoa_bin(struct no_pessoa **l);
//void read_tipo_pet_bin(struct no_tipo_pet **l);
//void read_pet_bin(struct no_pet **l);
//void read_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);
//void ler_comandos_do_usuario(struct fila_comando **fila);
//
////LISTAS
//void imprimir_lista_pessoa(struct no_pessoa *l);
//void imprimir_lista_tipo_pet(struct no_tipo_pet *l);
//void imprimir_lista_pet(struct no_pet *l);
//void liberar_lista_pessoas(struct no_pessoa **l);
//void liberar_lista_pets(struct no_pet **l);
//void liberar_lista_tipo_pet(struct no_tipo_pet **l);
//void liberar_todas_as_listas(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);
//
////DESESTRUTURAÇÂO DO COMANDO
//void inserir_pessoa(struct columns *columns, struct no_pessoa **pessoas);
//void inserir_pet(struct columns *columns, struct no_pet **pets, struct no_pessoa **pessoas, struct no_tipo_pet **tipo_pets);
//void inserir_tipo_pet(struct columns *columns, struct no_tipo_pet **tipo_pets);
//void insert(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
//void select_pessoa(struct no_pessoa **pessoas, char *column, char *valor);
//void select_pet(struct no_pet **pets, char *column, char *valor);
//void select_tipo_pet(struct no_tipo_pet **tipos_pet, char *column, char *valor);
//
////Árvore Binária
//void select_order_pessoa(struct no_pessoa **pessoas, char *column);
//a_no_pessoa *a_inserir_rr(struct a_no_pessoa *raiz, struct no_pessoa *pessoa, char *column);
//void a_in_order(a_no_pessoa *raiz);
//void a_destruir(a_no_pessoa *raiz);
//
//void select_order_pet(struct no_pet **pets, char *column);
//a_no_pet *a_inserir_pet_rr(struct a_no_pet *raiz, struct no_pet *pet, char *column);
//void a_in_order_pet(a_no_pet *raiz);
//void a_destruir_pet(a_no_pet *raiz);
//
//void select_order_tipo_pet(struct no_tipo_pet **tipos_pet, char *column);
//a_no_tipo_pet *a_inserir_tipo_pet_rr(struct a_no_tipo_pet *raiz, struct no_tipo_pet *pet, char *column);
//void a_in_order_tipo_pet(a_no_tipo_pet *raiz);
//void a_destruir_tipo_pet(a_no_tipo_pet *raiz);
//
//void lista_filtrada_a_ser_ordenada(
//                        struct no_pessoa **pessoas,struct no_pet **pets,struct no_tipo_pet **tipo_pets,
//                                char *tabela_order_by,
//                                char *coluna_a_ser_filtrada,
//                                char *valor_a_ser_filtrado,
//                                char *coluna_a_ser_ordenada);
//
//void select(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
//void update_pessoa(struct no_pessoa **pessoas,char *coluna_pesquisa,char *valor_pesquisado,char *coluna_a_ser_alterada,char *valor_a_ser_alterado);
//void update_tipo_pet(struct no_tipo_pet **tipos_pet,char *coluna_pesquisa,char *valor_pesquisado,char *coluna_a_ser_alterada,char *valor_a_ser_alterado);
//void update_pet(struct no_pet **pets, struct no_tipo_pet **tipos_pet, struct no_pessoa **pessoas, char *coluna_pesquisada,char *valor_pesquisado,char *coluna_a_ser_alterada,char *valor_a_ser_alterado);
//void update(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
//void delete_pessoa(struct no_pessoa **pessoas, struct no_pet **pets, char *column_to_be_deleted, char *value_to_be_deleted);
//void delete_tipo_pet(struct no_tipo_pet **tipos_pet, char *column_to_be_deleted, char *value_to_be_deleted);
//void delete_pet(struct no_pet **pets, char *column_to_be_deleted, char *value_to_be_deleted);
//void delete(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets);
//void destructuring_command(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);
//
////FUNÇÔES DE VERIFICAÇÂO
////int verificar_codigo_pessoa(struct no_pessoa **l, char *codigo);
////int verificar_codigo_pet(struct no_pet **l, char *codigo);
////int verificar_codigo_tipo_pet(struct no_tipo_pet **l, char *codigo);
////int verificar_codigo_pessoa_para_cadastro_de_pet(struct no_pessoa **l, char *codigo);
////int verificar_codigo_tipo_pet_para_cadastro_de_pet(struct no_tipo_pet **l, char *codigo);
////int verificar_pelo_codigo_se_pode_deletar_pessoa(struct no_pet **l, char *codigo);
////int comparar_data(char *data1, char *data2);
//
//
//#endif //TRABALHO_ESTRUTURA_DADOS_COMANDOS_H
