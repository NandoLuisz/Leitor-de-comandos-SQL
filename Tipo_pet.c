#include "Tipo_pet.h"

void write_tipo_pet_bin(struct no_tipo_pet **l){
    FILE *arquivo = fopen("arquivo_tipos_pet.bin", "wb");
    if(!arquivo){
        printf("Problema ao abrir arquivo Tipo Pet!\n");
        return;
    }
    struct no_tipo_pet *aux = *l;
    if (!aux) {
        fclose(arquivo);
        return;
    }
    while(aux != NULL){
        fwrite(&aux->tipo_pet, sizeof(struct tipo_pet), 1, arquivo);
        aux = aux->prox;
    }
    fclose(arquivo);
    liberar_lista_tipo_pet(l);
}

void read_tipo_pet_bin(struct no_tipo_pet **l) {
    FILE *arquivo_tipo_pet = fopen("arquivo_tipos_pet.bin", "rb");
    if (!arquivo_tipo_pet) {
        return;
    }
    struct tipo_pet p;
    struct no_tipo_pet *ultimo = NULL;
    while (fread(&p, sizeof(struct tipo_pet), 1, arquivo_tipo_pet) == 1) {
        struct no_tipo_pet *novo = malloc(sizeof(struct no_tipo_pet));
        if (!novo) {
            printf("Erro ao alocar memória para ler arquivo tipo_pet\n");
            fclose(arquivo_tipo_pet);
            return;
        }
        memcpy(&novo->tipo_pet, &p, sizeof(struct tipo_pet));
        novo->prox = NULL;
        novo->ant = ultimo;

        if (*l == NULL) {
            *l = novo;
        } else {
            ultimo->prox = novo;
        }
        ultimo = novo;
    }
    fclose(arquivo_tipo_pet);
}

void imprimir_lista_tipo_pet(struct no_tipo_pet *l){
    struct no_tipo_pet *aux = l;
    if(!aux) return;
    printf("\n---------Lista Tipo Pet:---------\n");
    while(aux != NULL){
        printf("Codigo: %s\n", aux->tipo_pet.codigo);
        printf("Nome: %s\n", aux->tipo_pet.nome);
        printf("--------------------------\n");
        aux = aux->prox;
    }
}

void liberar_lista_tipo_pet(struct no_tipo_pet **l){
    struct no_tipo_pet *aux = *l;
    while(aux != NULL){
        struct no_tipo_pet *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *l = NULL;
}

void inserir_tipo_pet(struct columns *columns, struct no_tipo_pet **tipo_pets){
    struct no_tipo_pet *novo_tipo_pet = malloc(sizeof(struct no_tipo_pet));
    if (!novo_tipo_pet) {
        printf( "\nErro: Falha ao alocar memória para a lista tipo pet.");
        return;
    }
    novo_tipo_pet->ant = NULL;
    memset(&novo_tipo_pet->tipo_pet, 0, sizeof(novo_tipo_pet->tipo_pet));
    int checked_data = 0;
    for(int i = 0; i < 2; i++){
        if (strcmp(columns[i].name, "codigo") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
        if (strcmp(columns[i].name, "nome") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
    }
    if(checked_data == 2){
        for (int i = 0; i < 2; i++) {
            if (!columns[i].filled) continue;

            if (strcmp(columns[i].name, "codigo") == 0) {
                if(verificar_codigo_tipo_pet(tipo_pets, columns[i].value)){
                    strncpy(novo_tipo_pet->tipo_pet.codigo, columns[i].value, sizeof(novo_tipo_pet->tipo_pet.codigo) - 1);
                }else{
                    printf("\nCodigo Tipo Pet ja existe!");
                    return;
                }
            } else {
                strncpy(novo_tipo_pet->tipo_pet.nome, columns[i].value, sizeof(novo_tipo_pet->tipo_pet.nome) - 1);
            }
        }
    }else{
        printf("\nPreencha os campos codigo e nome de tipo_pet corretamente!");
        free(novo_tipo_pet);
        return;
    }
    if(*tipo_pets == NULL){
        novo_tipo_pet->prox = NULL;
    }else{
        novo_tipo_pet->prox = *tipo_pets;
        (*tipo_pets)->ant = novo_tipo_pet;
    }
    *tipo_pets = novo_tipo_pet;
}

void select_tipo_pet(struct no_tipo_pet **tipos_pet, char *column, char *valor){
    struct no_tipo_pet *aux = *tipos_pet;
    int found = 0;
    while(aux != NULL){
        if ((strcmp(column, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, valor) == 0) ||
            (strcmp(column, "nome") == 0 && strcmp(aux->tipo_pet.nome, valor) == 0)) {
            printf("\n########SELECT Tipo Pet#######\n");
            printf("Codigo: %s\n", aux->tipo_pet.codigo);
            printf("Nome: %s", aux->tipo_pet.nome);
            printf("\n##############################\n");
            found = 1;
        }
        aux = aux->prox;
    }
    if (!found) {
        printf("\nErro ao procurar tipo_pet com %s igual a %s", column, valor);
    }
}

void update_tipo_pet(struct no_tipo_pet **tipos_pet,
                     char *coluna_pesquisa,
                     char *valor_pesquisado,
                     char *coluna_a_ser_alterada,
                     char *valor_a_ser_alterado){
    struct no_tipo_pet *aux = *tipos_pet;
    int found = 0;
    while (aux != NULL) {
        if ((strcmp(coluna_pesquisa, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, valor_pesquisado) == 0) ||
            (strcmp(coluna_pesquisa, "nome") == 0 && strcmp(aux->tipo_pet.nome, valor_pesquisado) == 0)) {
            found = 1;
            break;
        }
        aux = aux->prox;
    }
    if (!found) {
        printf("\nErro ao procurar tipo_pet com %s igual a %s", coluna_pesquisa, valor_pesquisado);
    }
    if (!aux) {
        return;
    }
    if (strcmp(coluna_a_ser_alterada, "codigo") == 0) {
        strcpy(aux->tipo_pet.codigo, valor_a_ser_alterado);
    } else if (strcmp(coluna_a_ser_alterada, "nome") == 0) {
        strcpy(aux->tipo_pet.nome, valor_a_ser_alterado);
    }else{
        printf("\nError na coluna: select-tipo_pet");
    }
}

void delete_tipo_pet(struct no_tipo_pet **tipos_pet, char *column_to_be_deleted, char *value_to_be_deleted) {
    if (!(*tipos_pet)) return;

    struct no_tipo_pet *aux = *tipos_pet;

    while (aux != NULL) {
        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->tipo_pet.nome, value_to_be_deleted) == 0)) {

            if (aux->ant) {
                aux->ant->prox = aux->prox;
            } else {
                *tipos_pet = aux->prox;
            }
            if (aux->prox) {
                aux->prox->ant = aux->ant;
            }
            free(aux);
            return;
        }
        aux = aux->prox;
    }
    printf("\nErro ao DELETAR tipo pet com %s igual a %s", column_to_be_deleted, value_to_be_deleted);
}

void select_order_tipo_pet(struct no_tipo_pet **tipos_pet, char *column){
    a_no_tipo_pet *raiz = NULL;
    struct no_tipo_pet *aux = *tipos_pet;
    while(aux != NULL){
        if(strcmp(column, "nome") == 0){
            raiz = a_inserir_tipo_pet_rr(raiz,aux, column);
        }else if(strcmp(column, "codigo") == 0){
            raiz = a_inserir_tipo_pet_rr(raiz,aux, column);
        }else{
            printf("\nErro ao ordenar Tipo Pet!");
            return;
        }
        aux = aux->prox;
    }
    printf("\n--------Tipo Pet Em Ordem de %s---------\n", column);
    a_in_order_tipo_pet(raiz);
    a_destruir_tipo_pet(raiz);
}

a_no_tipo_pet *a_inserir_tipo_pet_rr(struct a_no_tipo_pet *raiz, struct no_tipo_pet *tipo_pet, char *column){
    if (raiz == NULL){
        a_no_tipo_pet *aux = malloc(sizeof(a_no_pessoa));
        aux->tipo_pet = tipo_pet;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }
    if(strcmp(column, "nome") == 0){
        if (strcmp(tipo_pet->tipo_pet.nome, raiz->tipo_pet->tipo_pet.nome) > 0) { // Se valor é maior, vai para a direita
            raiz->dir = a_inserir_tipo_pet_rr(raiz->dir, tipo_pet, column);
        } else if (strcmp(tipo_pet->tipo_pet.nome, raiz->tipo_pet->tipo_pet.nome) <= 0) { // Se valor é menor, vai para a esquerda
            raiz->esq = a_inserir_tipo_pet_rr(raiz->esq, tipo_pet, column);
        }
    }else if(strcmp(column, "codigo") == 0){
        int codigo = atoi(tipo_pet->tipo_pet.codigo);
        int codigo_raiz = atoi(raiz->tipo_pet->tipo_pet.codigo);
        if (codigo > codigo_raiz) {
            raiz->dir = a_inserir_tipo_pet_rr(raiz->dir, tipo_pet, column);
        } else {
            raiz->esq = a_inserir_tipo_pet_rr(raiz->esq, tipo_pet, column);
        }
    }
    return raiz;
}

void a_in_order_tipo_pet(a_no_tipo_pet *raiz){
    if (raiz != NULL){
        a_in_order_tipo_pet(raiz->esq);
        printf("Nome: %s\n", raiz->tipo_pet->tipo_pet.nome);
        printf("Codigo: %s\n", raiz->tipo_pet->tipo_pet.codigo);
        printf("--------------------------\n");
        a_in_order_tipo_pet(raiz->dir);
    }
}
void a_destruir_tipo_pet(a_no_tipo_pet *raiz){
    if (raiz == NULL) return;
    a_destruir_tipo_pet(raiz->esq);
    a_destruir_tipo_pet(raiz->dir);
    free(raiz);
}