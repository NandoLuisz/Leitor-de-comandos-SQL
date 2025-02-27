#include "Pessoa.h"

void write_pessoas_bin(struct no_pessoa **l){
    FILE *arquivo = fopen("arquivo_pessoas.bin", "wb");
    if(!arquivo){
        printf("Problema ao abrir arquivo Pessoas\n!");
        return;
    }
    struct no_pessoa *aux = *l;
    if (!aux) {
        fclose(arquivo);
        return;
    }
    while(aux != NULL){
        fwrite(&aux->pessoa, sizeof(struct pessoa), 1, arquivo);
        aux = aux->prox;
    }
    fclose(arquivo);
    liberar_lista_pessoas(l);
}

void read_pessoa_bin(struct no_pessoa **l) {
    FILE *arquivo_pessoas = fopen("arquivo_pessoas.bin", "rb");
    if (!arquivo_pessoas) {
        return;
    }
    struct pessoa p;
    struct no_pessoa *ultimo = NULL;
    while (fread(&p, sizeof(struct pessoa), 1, arquivo_pessoas) == 1) {
        struct no_pessoa *novo = malloc(sizeof(struct no_pessoa));
        if (!novo) {
            printf("\nErro ao alocar memória no ler arquivo pessoa!");
            fclose(arquivo_pessoas);
            return;
        }
        memcpy(&novo->pessoa, &p, sizeof(struct pessoa));
        novo->prox = NULL;
        novo->ant = ultimo;
        if (*l == NULL) {
            *l = novo;
        } else {
            ultimo->prox = novo;
        }
        ultimo = novo;
    }
    fclose(arquivo_pessoas);
}

void imprimir_lista_pessoa(struct no_pessoa *l){
    struct no_pessoa *aux = l;
    if(!aux){
        printf("Lista Pessoas vazia!\n");
        return;
    };
    printf("\n---------Lista Pessoas:---------\n");
    while(aux != NULL){
        printf("Codigo: %s\n", aux->pessoa.codigo);
        printf("Nome: %s\n", aux->pessoa.nome);
        printf("Data de nascimento: %s\n", aux->pessoa.data_nascimento);
        printf("Fone: %s\n", aux->pessoa.fone);
        printf("Endereco: %s\n", aux->pessoa.endereco);
        printf("--------------------------\n");
        aux = aux->prox;
    }
}

void liberar_lista_pessoas(struct no_pessoa **l){
    struct no_pessoa *aux = *l;
    while(aux != NULL){
        struct no_pessoa *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *l = NULL;
}

void inserir_pessoa(struct columns *columns, struct no_pessoa **pessoas) {
    struct no_pessoa *nova_pessoa = malloc(sizeof(struct no_pessoa));
    if (!nova_pessoa) {
        printf("\nErro: Falha ao alocar memória para lista pessoa.");
        return;
    }
    nova_pessoa->ant = NULL;
    memset(&nova_pessoa->pessoa, 0, sizeof(nova_pessoa->pessoa));
    int checked_data = 0;
    for(int i = 0; i < 5; i++){
        if (strcmp(columns[i].name, "codigo") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
        if (strcmp(columns[i].name, "nome") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
        if (strcmp(columns[i].name, "data_nascimento") == 0 && strcmp(columns[i].value, "") != 0) {
            checked_data += 1;
        }
    }
    if(checked_data == 3){
        for (int i = 0; i < 5; i++) {
            if (strcmp(columns[i].name, "codigo") == 0) {
                if(verificar_codigo_pessoa(pessoas, columns[i].value)){
                    strncpy(nova_pessoa->pessoa.codigo, columns[i].value, sizeof(nova_pessoa->pessoa.codigo) - 1);
                }else{
                    printf("\nCodigo Pessoa ja existe %s!", columns[i].value);
                    return;
                }
            } else if (strcmp(columns[i].name, "nome") == 0) {
                strncpy(nova_pessoa->pessoa.nome, columns[i].value, sizeof(nova_pessoa->pessoa.nome) - 1);
            } else if (strcmp(columns[i].name, "fone") == 0) {
                strncpy(nova_pessoa->pessoa.fone, columns[i].value, sizeof(nova_pessoa->pessoa.fone) - 1);
            } else if (strcmp(columns[i].name, "endereco") == 0) {
                strncpy(nova_pessoa->pessoa.endereco, columns[i].value, sizeof(nova_pessoa->pessoa.endereco) - 1);
            } else if (strcmp(columns[i].name, "data_nascimento") == 0) {
                strncpy(nova_pessoa->pessoa.data_nascimento, columns[i].value, sizeof(nova_pessoa->pessoa.data_nascimento) - 1);
            }
        }
    }else{
        printf("\nPreencha os campos codigo, nome e data de nascimento da Pessoa corretamente!\n");
        free(nova_pessoa);
        return;
    }
    if(*pessoas == NULL){
        nova_pessoa->prox = NULL;
    }else{
        nova_pessoa->prox = *pessoas;
        (*pessoas)->ant = nova_pessoa;
    }
    *pessoas = nova_pessoa;
}

void select_pessoa(struct no_pessoa **pessoas, char *column, char *valor) {
    struct no_pessoa *aux = *pessoas;
    int found = 0;
    while (aux != NULL) {
        if ((strcmp(column, "codigo") == 0 && strcmp(aux->pessoa.codigo, valor) == 0) ||
            (strcmp(column, "nome") == 0 && strcmp(aux->pessoa.nome, valor) == 0) ||
            (strcmp(column, "fone") == 0 && strcmp(aux->pessoa.fone, valor) == 0) ||
            (strcmp(column, "endereco") == 0 && strcmp(aux->pessoa.endereco, valor) == 0) ||
            (strcmp(column, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, valor) == 0)) {
            printf("\n##########SELECT Pessoa#########\n");
            printf("Codigo: %s\n", aux->pessoa.codigo);
            printf("Nome: %s\n", aux->pessoa.nome);
            printf("Data de nascimento: %s\n", aux->pessoa.data_nascimento);
            printf("Fone: %s\n", aux->pessoa.fone);
            printf("Endereco: %s", aux->pessoa.endereco);
            printf("\n##############################\n");
            found = 1;
        }
        aux = aux->prox;
    }

    if (!found) {
        printf("\nErro ao procurar pessoa com %s igual a %s", column, valor);
    }
}

void update_pessoa(struct no_pessoa **pessoas,
                   char *coluna_pesquisa,
                   char *valor_pesquisado,
                   char *coluna_a_ser_alterada,
                   char *valor_a_ser_alterado) {
    struct no_pessoa *aux = *pessoas;
    int found = 0;

    while (aux != NULL) {
        if ((strcmp(coluna_pesquisa, "codigo") == 0 && strcmp(aux->pessoa.codigo, valor_pesquisado) == 0) ||
            (strcmp(coluna_pesquisa, "nome") == 0 && strcmp(aux->pessoa.nome, valor_pesquisado) == 0) ||
            (strcmp(coluna_pesquisa, "fone") == 0 && strcmp(aux->pessoa.fone, valor_pesquisado) == 0) ||
            (strcmp(coluna_pesquisa, "endereco") == 0 && strcmp(aux->pessoa.endereco, valor_pesquisado) == 0) ||
            (strcmp(coluna_pesquisa, "data_nascimento") == 0 &&
             strcmp(aux->pessoa.data_nascimento, valor_pesquisado) == 0)) {
            found = 1;
            break;
        }
        aux = aux->prox;
    }
    if (!found) {
        printf("\nErro ao procurar pessoa com %s igual a %s", coluna_pesquisa, valor_pesquisado);
    }
    if (!aux) {
        return;
    }
    if (strcmp(coluna_a_ser_alterada, "codigo") == 0) {
        strcpy(aux->pessoa.codigo, valor_a_ser_alterado);
    } else if (strcmp(coluna_a_ser_alterada, "nome") == 0) {
        strcpy(aux->pessoa.nome, valor_a_ser_alterado);
    } else if (strcmp(coluna_a_ser_alterada, "data_nascimento") == 0) {
        strcpy(aux->pessoa.data_nascimento, valor_a_ser_alterado);
    } else if (strcmp(coluna_a_ser_alterada, "fone") == 0) {
        strcpy(aux->pessoa.fone, valor_a_ser_alterado);
    }else if (strcmp(coluna_a_ser_alterada, "endereco") == 0) {
        strcpy(aux->pessoa.endereco, valor_a_ser_alterado);
    }else{
        printf("\nError na coluna: select-pessoa");
    }
}

void delete_pessoa(struct no_pessoa **pessoas, struct no_pet **pets, char *column_to_be_deleted, char *value_to_be_deleted) {
    if (!(*pessoas)) return;

    struct no_pessoa *aux = *pessoas;

    while (aux != NULL) {
        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pessoa.codigo, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pessoa.nome, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "fone") == 0 && strcmp(aux->pessoa.fone, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "endereco") == 0 && strcmp(aux->pessoa.endereco, value_to_be_deleted) == 0) ||
            (strcmp(column_to_be_deleted, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, value_to_be_deleted) == 0)) {

            if (verificar_pelo_codigo_se_pode_deletar_pessoa(pets, aux->pessoa.codigo)) {
                if (aux->ant) {
                    aux->ant->prox = aux->prox;
                } else {
                    *pessoas = aux->prox;
                }
                if (aux->prox) {
                    aux->prox->ant = aux->ant;
                }
                free(aux);
                return;
            } else {
                printf("\nNao foi possivel deletar pessoa com nome %s porque ela tem pet!", aux->pessoa.nome);
                return;
            }
        }
        aux = aux->prox;
    }
    printf("\nErro ao DELETAR pessoa com %s igual a %s\n", column_to_be_deleted, value_to_be_deleted);
}

void select_order_pessoa(struct no_pessoa **pessoas, char *column){
    a_no_pessoa *raiz = NULL;
    struct no_pessoa *aux = *pessoas;
    while(aux != NULL){
        if(strcmp(column, "nome") == 0){
            raiz = a_inserir_rr(raiz,aux, column);
        }else if(strcmp(column, "codigo") == 0){
            raiz = a_inserir_rr(raiz,aux, column);
        }else if(strcmp(column, "data_nascimento") == 0){
            raiz = a_inserir_rr(raiz,aux, column);
        }else{
            printf("\nErro ao ordenar Pessoas!\n");
            return;
        }
        aux = aux->prox;
    }
    printf("\n--------Pessoas Em Ordem de %s---------\n", column);
    a_in_order(raiz);
    a_destruir(raiz);
}

a_no_pessoa *a_inserir_rr(struct a_no_pessoa *raiz, struct no_pessoa *pessoa, char *column){
    if (raiz == NULL){
        a_no_pessoa *aux = malloc(sizeof(a_no_pessoa));
        aux->pessoa = pessoa;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }
    if(strcmp(column, "nome") == 0){
        if (strcmp(pessoa->pessoa.nome, raiz->pessoa->pessoa.nome) > 0) { // Se valor é maior, vai para a direita
            raiz->dir = a_inserir_rr(raiz->dir, pessoa, column);
        } else if (strcmp(pessoa->pessoa.nome, raiz->pessoa->pessoa.nome) <= 0) { // Se valor é menor, vai para a esquerda
            raiz->esq = a_inserir_rr(raiz->esq, pessoa, column);
        }
    }else if(strcmp(column, "codigo") == 0){
        int codigo_pessoa = atoi(pessoa->pessoa.codigo);
        int codigo_raiz = atoi(raiz->pessoa->pessoa.codigo);
        if (codigo_pessoa > codigo_raiz) {
            raiz->dir = a_inserir_rr(raiz->dir, pessoa, column);
        } else {
            raiz->esq = a_inserir_rr(raiz->esq, pessoa, column);
        }
    }else if(strcmp(column, "data_nascimento") == 0){
        int comparacao = comparar_data(pessoa->pessoa.data_nascimento, raiz->pessoa->pessoa.data_nascimento);
        if (comparacao > 0) { // Se valor é maior, vai para a direita
            raiz->dir = a_inserir_rr(raiz->dir, pessoa, column);
        } else { // Se valor é menor, vai para a esquerda
            raiz->esq = a_inserir_rr(raiz->esq, pessoa, column);
        }
    }
    return raiz;
}

void a_in_order(a_no_pessoa *raiz){
    if (raiz != NULL){
        a_in_order(raiz->esq);
        printf("Nome: %s\n", raiz->pessoa->pessoa.nome);
        printf("Codigo: %s\n", raiz->pessoa->pessoa.codigo);
        printf("Data de nascimento: %s\n", raiz->pessoa->pessoa.data_nascimento);
        printf("Fone: %s\n", raiz->pessoa->pessoa.fone);
        printf("Endereco: %s\n", raiz->pessoa->pessoa.endereco);
        printf("--------------------------\n");
        a_in_order(raiz->dir);
    }
}

void a_destruir(a_no_pessoa *raiz) {
    if (raiz == NULL) return;
    a_destruir(raiz->esq);
    a_destruir(raiz->dir);
    free(raiz);
}
