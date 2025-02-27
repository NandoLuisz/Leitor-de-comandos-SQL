#include "Pet.h"

void write_pet_bin(struct no_pet **l){
    FILE *arquivo = fopen("arquivo_pets.bin", "wb");
    if(!arquivo){
        printf("\nProblema ao abrir arquivo Pet!");
        return;
    }
    struct no_pet *aux = *l;
    if (!aux) {
        fclose(arquivo);
        return;
    }
    while(aux != NULL){
        fwrite(&aux->pet, sizeof(struct pet), 1, arquivo);
        aux = aux->prox;
    }
    fclose(arquivo);
    liberar_lista_pets(l);
}

void read_pet_bin(struct no_pet **l) {
    FILE *arquivo_pet = fopen("arquivo_pets.bin", "rb");
    if (!arquivo_pet) {
        return;
    }
    struct pet p;
    struct no_pet *ultimo = NULL;
    while (fread(&p, sizeof(struct pet), 1, arquivo_pet) == 1) {
        struct no_pet *novo = malloc(sizeof(struct no_pet));
        if (!novo) {
            perror("Erro ao alocar memória para ler arquivo Pet");
            fclose(arquivo_pet);
            return;
        }
        memcpy(&novo->pet, &p, sizeof(struct pet));
        novo->prox = NULL;
        if (*l == NULL) {
            *l = novo;
        } else {
            ultimo->prox = novo;
        }
        ultimo = novo;
    }
    fclose(arquivo_pet);
}

void imprimir_lista_pet(struct no_pet *l){
    struct no_pet *aux = l;
    if(!aux) return;
    printf("\n---------Lista Pet:---------\n");
    while(aux != NULL){
        printf("Codigo: %s\n", aux->pet.codigo);
        printf("Nome: %s\n", aux->pet.nome);
        printf("Codigo do Dono: %s\n", aux->pet.codigo_pes);
        printf("Codigo Tipo: %s\n", aux->pet.codigo_tipo);
        printf("--------------------------\n");
        aux = aux->prox;
    }
}

void liberar_lista_pets(struct no_pet **l){
    struct no_pet *aux = *l;
    while(aux != NULL){
        struct no_pet *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *l = NULL;
}

void inserir_pet(struct columns *columns, struct no_pet **pets, struct no_pessoa **pessoas, struct no_tipo_pet **tipo_pets){
    struct no_pet *novo_pet = malloc(sizeof(struct no_pet));
    if (!novo_pet) {
        printf("Erro: Falha ao alocar memória para a lista pet.\n");
        return;
    }
    novo_pet->ant = NULL;
    memset(&novo_pet->pet, 0, sizeof(novo_pet->pet));
    int checked_data = 0;
    for(int i = 0; i < 5; i++){
        if (strcmp(columns[i].name, "codigo") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
        if (strcmp(columns[i].name, "nome") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
        if (strcmp(columns[i].name, "codigo_pes") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
        if (strcmp(columns[i].name, "codigo_tipo") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
    }
    if(checked_data == 4){
        for (int i = 0; i < 4; i++) {
            if (!columns[i].filled) continue;

            if (strcmp(columns[i].name, "codigo") == 0) {
                if(verificar_codigo_pet(pets, columns[i].value)){
                    strncpy(novo_pet->pet.codigo, columns[i].value, sizeof(novo_pet->pet.codigo) - 1);
                }else{
                    printf("\nCodigo Pet %s ja existe!", columns[i].value);
                    return;
                }
            } else if (strcmp(columns[i].name, "nome") == 0) {
                strncpy(novo_pet->pet.nome, columns[i].value, sizeof(novo_pet->pet.nome) - 1);
            } else if (strcmp(columns[i].name, "codigo_pes") == 0) {
                if(verificar_codigo_pessoa_para_cadastro_de_pet(pessoas, columns[i].value)){
                    strncpy(novo_pet->pet.codigo_pes, columns[i].value, sizeof(novo_pet->pet.codigo_pes) - 1);
                }else{
                    printf("\nNao eh possivel inserir pet, codigo Pessoa %s nao existe", columns[i].value);
                    return;
                }
            } else {
                if(verificar_codigo_tipo_pet_para_cadastro_de_pet(tipo_pets, columns[i].value)){
                    strncpy(novo_pet->pet.codigo_tipo, columns[i].value, sizeof(novo_pet->pet.codigo_tipo) - 1);
                }else{
                    printf("\nNao eh possivel inserir pet, Codigo Tipo Pet %s nao existe!", columns[i].value);
                    return;
                }
            }
        }
    }else{
        printf("\nPreencha os campos codigo, nome, codigo_pes e codigo_tipo de Pet corretamente!");
        free(novo_pet);
        return;
    }
    if(*pets == NULL){
        novo_pet->prox = NULL;
    }else{
        novo_pet->prox = *pets;
        (*pets)->ant = novo_pet;
    }
    *pets = novo_pet;
}

void select_pet(struct no_pet **pets, char *column, char *valor){
    struct no_pet *aux = *pets;
    int found = 0;
    while (aux != NULL) {
        if ((strcmp(column, "codigo") == 0 && strcmp(aux->pet.codigo, valor) == 0) ||
            (strcmp(column, "nome") == 0 && strcmp(aux->pet.nome, valor) == 0) ||
            (strcmp(column, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, valor) == 0) ||
            (strcmp(column, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, valor) == 0)) {
            printf("\n########SELECT Pet##########\n");
            printf("Codigo: %s\n", aux->pet.codigo);
            printf("Nome: %s\n", aux->pet.nome);
            printf("Codigo do dono: %s\n", aux->pet.codigo_pes);
            printf("Codigo do tipo: %s\n", aux->pet.codigo_tipo);
            printf("##############################\n");
            found = 1;
        }
        aux = aux->prox;
    }
    if (!found) {
        printf("\nErro ao procurar pet com %s igual a %s", column, valor);
    }
}

void update_pet(struct no_pet **pets,
                struct no_tipo_pet **tipos_pet,
                struct no_pessoa **pessoas,
                char *coluna_pesquisada,
                char *valor_pesquisado,
                char *coluna_a_ser_alterada,
                char *valor_a_ser_alterado){
    struct no_pet *aux = *pets;
    int found = 0;
    while (aux != NULL) {
        if ((strcmp(coluna_pesquisada, "codigo") == 0 && strcmp(aux->pet.codigo, valor_pesquisado) == 0) ||
            (strcmp(coluna_pesquisada, "nome") == 0 && strcmp(aux->pet.nome, valor_pesquisado) == 0) ||
            (strcmp(coluna_pesquisada, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, valor_pesquisado) == 0) ||
            strcmp(coluna_pesquisada, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, valor_pesquisado) == 0){
            found = 1;
            break;
        }
        aux = aux->prox;
    }
    if (!found) {
        printf("\nErro ao procurar pet com %s igual a %s", coluna_pesquisada, valor_pesquisado);
    }
    if (!aux) {
        return;
    }
    if (strcmp(coluna_a_ser_alterada, "codigo") == 0) {
        strcpy(aux->pet.codigo, valor_a_ser_alterado);
    } else if (strcmp(coluna_a_ser_alterada, "nome") == 0) {
        strcpy(aux->pet.nome, valor_a_ser_alterado);
    } else if (strcmp(coluna_a_ser_alterada, "codigo_pes") == 0) {
        if(verificar_codigo_pessoa_para_cadastro_de_pet(pessoas, valor_a_ser_alterado)){
            strcpy(aux->pet.codigo_pes, valor_a_ser_alterado);
        }else{
            printf("\nO codigo Pessoa precisa ser valido para o Pet ser alterado!");
            return;
        }
    } else if (strcmp(coluna_a_ser_alterada, "codigo_tipo") == 0) {
        if(verificar_codigo_tipo_pet_para_cadastro_de_pet(tipos_pet, valor_a_ser_alterado)){
            strcpy(aux->pet.codigo_tipo, valor_a_ser_alterado);
        }else{
            printf("\nO codigo Tipo Pet precisa ser valido para o Pet ser alterado!");
            return;
        }
    }else{
        printf("Error na coluna: select-pet");
    }
}

void delete_pet(struct no_pet **pet, char *column_to_be_deleted, char *value_to_be_deleted) {
    if (!(*pet)) return;
    struct no_pet *aux = *pet, *ant = NULL;
    while (aux != NULL &&
           ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pet.codigo, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pet.nome, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, value_to_be_deleted) == 0))) {
        *pet = aux->prox;
        free(aux);
        return;
    }
    while (aux != NULL) {
        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pet.codigo, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pet.nome, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, value_to_be_deleted) == 0)) {
            ant->prox = aux->prox;
            free(aux);
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
    printf("\nErro ao DELETAR pet com %s igual a %s", column_to_be_deleted, value_to_be_deleted);
}

void select_order_pet(struct no_pet **pets, char *column){
    a_no_pet *raiz = NULL;
    struct no_pet *aux = *pets;
    while(aux != NULL){
        if(strcmp(column, "nome") == 0){
            raiz = a_inserir_pet_rr(raiz, aux, column);
        }else if(strcmp(column, "codigo") == 0){
            raiz = a_inserir_pet_rr(raiz,aux, column);
        }else if(strcmp(column, "codigo_pes") == 0){
            raiz = a_inserir_pet_rr(raiz,aux, column);
        }else if(strcmp(column, "codigo_tipo") == 0){
            raiz = a_inserir_pet_rr(raiz,aux, column);
        }else{
            printf("\nErro ao ordenar Pets!\n");
            return;
        }
        aux = aux->prox;
    }

    printf("\n\n--------Pets Em Ordem de %s---------\n", column);
    a_in_order_pet(raiz);
    a_destruir_pet(raiz);
}
a_no_pet *a_inserir_pet_rr(struct a_no_pet *raiz, struct no_pet *pet, char *column){
    if (raiz == NULL){
        a_no_pet *aux = malloc(sizeof(a_no_pet));
        aux->pet = pet;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }
    if(strcmp(column, "nome") == 0){
        if (strcmp(pet->pet.nome, raiz->pet->pet.nome) > 0) { // Se valor é maior, vai para a direita
            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
        } else if (strcmp(pet->pet.nome, raiz->pet->pet.nome) <= 0) { // Se valor é menor, vai para a esquerda
            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
        }
    }else if(strcmp(column, "codigo") == 0){
        int codigo = atoi(pet->pet.codigo);
        int codigo_raiz = atoi(raiz->pet->pet.codigo);
        if (codigo > codigo_raiz) {
            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
        } else {
            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
        }
    }else if(strcmp(column, "codigo_pes") == 0){
        int codigo_pes = atoi(pet->pet.codigo_pes);
        int codigo_raiz = atoi(raiz->pet->pet.codigo_pes);
        if (codigo_pes > codigo_raiz) {
            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
        } else {
            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
        }
    }else if(strcmp(column, "codigo_tipo") == 0){
        int codigo_tipo = atoi(pet->pet.codigo_tipo);
        int codigo_raiz = atoi(raiz->pet->pet.codigo_tipo);
        if (codigo_tipo > codigo_raiz) { // Se valor é maior, vai para a direita
            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
        } else { // Se valor é menor, vai para a esquerda
            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
        }
    }
    return raiz;
}

void a_in_order_pet(a_no_pet *raiz){
    if (raiz != NULL){
        a_in_order_pet(raiz->esq);
        printf("Nome: %s\n", raiz->pet->pet.nome);
        printf("Codigo: %s\n", raiz->pet->pet.codigo);
        printf("Codigo do Dono: %s\n", raiz->pet->pet.codigo_pes);
        printf("Codigo do Tipo: %s\n", raiz->pet->pet.codigo_tipo);
        printf("--------------------------\n");
        a_in_order_pet(raiz->dir);
    }
}
void a_destruir_pet(a_no_pet *raiz){
    if (raiz == NULL) return;
    a_destruir_pet(raiz->esq);
    a_destruir_pet(raiz->dir);
    free(raiz);
}