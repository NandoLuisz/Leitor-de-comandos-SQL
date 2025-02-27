////
//// Created by nando on 01/02/2025.
////
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "Comandos.h"
//
//
//void fila_iniciar(struct fila_comando **fila, char *comando){
//    struct fila_comando *new_comando = malloc(sizeof(struct fila_comando));
//    if (new_comando == NULL) {
//        printf("Erro ao alocar memória para o novo comando.\n");
//        return;
//    }
//    strcpy(new_comando->comando, comando);
//    new_comando->prox = NULL;
//    if(!(*fila)){
//        *fila = new_comando;
//    }else{
//        struct fila_comando *aux = *fila;
//        while(aux->prox != NULL){
//            aux = aux->prox;
//        }
//        aux->prox = new_comando;
//    }
//}
//
//void fila_executar(struct fila_comando *fila, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
//    struct fila_comando *aux;
//    while (fila != NULL) {
//        aux = fila;
//        destructuring_command(aux->comando, pessoas, pets, tipos_pet);
//        fila = (fila)->prox;
//        free(aux);
//    }
//}
//
//void write_pessoas_bin(struct no_pessoa **l){
//    FILE *arquivo = fopen("arquivo_pessoas.bin", "wb");
//    if(!arquivo){
//        printf("Problema ao abrir arquivo Pessoas\n!");
//        return;
//    }
//    struct no_pessoa *aux = *l;
//    if (!aux) {
//        fclose(arquivo);
//        return;
//    }
//    while(aux != NULL){
//        fwrite(&aux->pessoa, sizeof(struct pessoa), 1, arquivo);
//        aux = aux->prox;
//    }
//    fclose(arquivo);
//    liberar_lista_pessoas(l);
//}
//
//void write_tipo_pet_bin(struct no_tipo_pet **l){
//    FILE *arquivo = fopen("arquivo_tipos_pet.bin", "wb");
//    if(!arquivo){
//        printf("Problema ao abrir arquivo Tipo Pet!\n");
//        return;
//    }
//    struct no_tipo_pet *aux = *l;
//    if (!aux) {
//        fclose(arquivo);
//        return;
//    }
//    while(aux != NULL){
//        fwrite(&aux->tipo_pet, sizeof(struct tipo_pet), 1, arquivo);
//        aux = aux->prox;
//    }
//    fclose(arquivo);
//    liberar_lista_tipo_pet(l);
//}
//
//void write_pet_bin(struct no_pet **l){
//    FILE *arquivo = fopen("arquivo_pets.bin", "wb");
//    if(!arquivo){
//        printf("Problema ao abrir arquivo Pet!\n");
//        return;
//    }
//    struct no_pet *aux = *l;
//    if (!aux) {
//        fclose(arquivo);
//        return;
//    }
//    while(aux != NULL){
//        fwrite(&aux->pet, sizeof(struct pet), 1, arquivo);
//        aux = aux->prox;
//    }
//    fclose(arquivo);
//    liberar_lista_pets(l);
//}
//
//void write_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
//    write_pessoas_bin(pessoas);
//    write_pet_bin(pets);
//    write_tipo_pet_bin(tipos_pet);
//}
//
//void read_pessoa_bin(struct no_pessoa **l) {
//    FILE *arquivo_pessoas = fopen("arquivo_pessoas.bin", "rb");
//    if (!arquivo_pessoas) {
//        printf("Problema ao abrir arquivo Pessoa para leitura!\n");
//        return;
//    }
//    struct pessoa p;
//    struct no_pessoa *ultimo = NULL;
//    while (fread(&p, sizeof(struct pessoa), 1, arquivo_pessoas) == 1) {
//        struct no_pessoa *novo = malloc(sizeof(struct no_pessoa));
//        if (!novo) {
//            printf("Erro ao alocar memória");
//            fclose(arquivo_pessoas);
//            return;
//        }
//        memcpy(&novo->pessoa, &p, sizeof(struct pessoa));
//        novo->prox = NULL;
//        novo->ant = ultimo;
//        if (*l == NULL) {
//            *l = novo;
//        } else {
//            ultimo->prox = novo;
//        }
//        ultimo = novo;
//    }
//    fclose(arquivo_pessoas);
//}
//
//void read_tipo_pet_bin(struct no_tipo_pet **l) {
//    FILE *arquivo_tipo_pet = fopen("arquivo_tipos_pet.bin", "rb");
//    if (!arquivo_tipo_pet) {
//        printf("Problema ao abrir arquivo Tipo Pet para leitura!\n");
//        return;
//    }
//    struct tipo_pet p;
//    struct no_tipo_pet *ultimo = NULL;
//    while (fread(&p, sizeof(struct tipo_pet), 1, arquivo_tipo_pet) == 1) {
//        struct no_tipo_pet *novo = malloc(sizeof(struct no_tipo_pet));
//        if (!novo) {
//            printf("Erro ao alocar memória\n");
//            fclose(arquivo_tipo_pet);
//            return;
//        }
//        memcpy(&novo->tipo_pet, &p, sizeof(struct tipo_pet));
//        novo->prox = NULL;
//        novo->ant = ultimo;
//
//        if (*l == NULL) {
//            *l = novo;
//        } else {
//            ultimo->prox = novo;
//        }
//        ultimo = novo;
//    }
//    fclose(arquivo_tipo_pet);
//}
//
//void read_pet_bin(struct no_pet **l) {
//    FILE *arquivo_pet = fopen("arquivo_pets.bin", "rb");
//    if (!arquivo_pet) {
//        printf("Problema ao abrir arquivo Pet para leitura!\n");
//        return;
//    }
//    struct pet p;
//    struct no_pet *ultimo = NULL;
//    while (fread(&p, sizeof(struct pet), 1, arquivo_pet) == 1) {
//        struct no_pet *novo = malloc(sizeof(struct no_pet));
//        if (!novo) {
//            perror("Erro ao alocar memória");
//            fclose(arquivo_pet);
//            return;
//        }
//        memcpy(&novo->pet, &p, sizeof(struct pet));
//        novo->prox = NULL;
//        if (*l == NULL) {
//            *l = novo;
//        } else {
//            ultimo->prox = novo;
//        }
//        ultimo = novo;
//    }
//    fclose(arquivo_pet);
//}
//
//
//void read_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
//    read_pessoa_bin(pessoas);
//    read_pet_bin(pets);
//    read_tipo_pet_bin(tipos_pet);
//}
//
//void imprimir_lista_pessoa(struct no_pessoa *l){
//    struct no_pessoa *aux = l;
//    if(!aux){
//        printf("Lista Pessoas vazia!\n");
//        return;
//    };
//    printf("\n---------Lista Pessoas:---------\n");
//    while(aux != NULL){
//        printf("Codigo: %s\n", aux->pessoa.codigo);
//        printf("Nome: %s\n", aux->pessoa.nome);
//        printf("Data de nascimento: %s\n", aux->pessoa.data_nascimento);
//        printf("Fone: %s\n", aux->pessoa.fone);
//        printf("Endereco: %s\n", aux->pessoa.endereco);
//        printf("--------------------------\n");
//        aux = aux->prox;
//    }
//}
//
//void imprimir_lista_tipo_pet(struct no_tipo_pet *l){
//    struct no_tipo_pet *aux = l;
//    if(!aux) return;
//    printf("\n---------Lista Tipo Pet:---------\n");
//    while(aux != NULL){
//        printf("Codigo: %s\n", aux->tipo_pet.codigo);
//        printf("Nome: %s\n", aux->tipo_pet.nome);
//        printf("--------------------------\n");
//        aux = aux->prox;
//    }
//}
//
//void imprimir_lista_pet(struct no_pet *l){
//    struct no_pet *aux = l;
//    if(!aux) return;
//    printf("\n---------Lista Pet:---------\n");
//    while(aux != NULL){
//        printf("Codigo: %s\n", aux->pet.codigo);
//        printf("Nome: %s\n", aux->pet.nome);
//        printf("Codigo do Dono: %s\n", aux->pet.codigo_pes);
//        printf("Codigo Tipo: %s\n", aux->pet.codigo_tipo);
//        printf("--------------------------\n");
//        aux = aux->prox;
//    }
//}
//
//void imprimir_todas_as_listas(struct no_pessoa *pessoas, struct no_pet *pets, struct no_tipo_pet *tipos_pet){
//    imprimir_lista_pet(pets);
//    imprimir_lista_pessoa(pessoas);
//    imprimir_lista_tipo_pet(tipos_pet);
//}
//
//void liberar_lista_pessoas(struct no_pessoa **l){
//    struct no_pessoa *aux = *l;
//    while(aux != NULL){
//        struct no_pessoa *temp = aux;
//        aux = aux->prox;
//        free(temp);
//    }
//    *l = NULL;
//}
//
//void liberar_lista_pets(struct no_pet **l){
//    struct no_pet *aux = *l;
//    while(aux != NULL){
//        struct no_pet *temp = aux;
//        aux = aux->prox;
//        free(temp);
//    }
//    *l = NULL;
//}
//
//void liberar_lista_tipo_pet(struct no_tipo_pet **l){
//    struct no_tipo_pet *aux = *l;
//    while(aux != NULL){
//        struct no_tipo_pet *temp = aux;
//        aux = aux->prox;
//        free(temp);
//    }
//    *l = NULL;
//}
//
//void liberar_todas_as_listas(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
//    liberar_lista_pessoas(pessoas);
//    liberar_lista_pets(pets);
//    liberar_lista_tipo_pet(tipos_pet);
//}
//
//void inserir_pessoa(struct columns *columns, struct no_pessoa **pessoas) {
//    struct no_pessoa *nova_pessoa = malloc(sizeof(struct no_pessoa));
//    //Validação dos dados
//    if (!nova_pessoa) {
//        printf("Erro: Falha ao alocar memória para lista pessoa.\n");
//        return;
//    }
//    nova_pessoa->ant = NULL;
//    memset(&nova_pessoa->pessoa, 0, sizeof(nova_pessoa->pessoa));
//    int checked_data = 0;
//    for(int i = 0; i < 5; i++){
//        if (strcmp(columns[i].name, "codigo") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//        if (strcmp(columns[i].name, "nome") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//        if (strcmp(columns[i].name, "data_nascimento") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//    }
//    if(checked_data == 3){
//        for (int i = 0; i < 5; i++) {
//            if (strcmp(columns[i].name, "codigo") == 0) {
//                if(verificar_codigo_pessoa(pessoas, columns[i].value)){ // Verifica se já existe alguma pessoa com o código solicitado
//                    strncpy(nova_pessoa->pessoa.codigo, columns[i].value, sizeof(nova_pessoa->pessoa.codigo) - 1);
//                }else{
//                    printf("Code Person already registered!\n");
//                    return;
//                }
//            } else if (strcmp(columns[i].name, "nome") == 0) {
//                strncpy(nova_pessoa->pessoa.nome, columns[i].value, sizeof(nova_pessoa->pessoa.nome) - 1);
//            } else if (strcmp(columns[i].name, "fone") == 0) {
//                strncpy(nova_pessoa->pessoa.fone, columns[i].value, sizeof(nova_pessoa->pessoa.fone) - 1);
//            } else if (strcmp(columns[i].name, "endereco") == 0) {
//                strncpy(nova_pessoa->pessoa.endereco, columns[i].value, sizeof(nova_pessoa->pessoa.endereco) - 1);
//            } else if (strcmp(columns[i].name, "data_nascimento") == 0) {
//                strncpy(nova_pessoa->pessoa.data_nascimento, columns[i].value, sizeof(nova_pessoa->pessoa.data_nascimento) - 1);
//            }
//        }
//    }else{
//        printf("\nPreencha os campos codigo, nome e data de nascimento da Pessoa corretamente!\n");
//        free(nova_pessoa);
//        return;
//    }
//    if(*pessoas == NULL){
//        nova_pessoa->prox = NULL;
//    }else{
//        nova_pessoa->prox = *pessoas;
//        (*pessoas)->ant = nova_pessoa;
//    }
//    *pessoas = nova_pessoa;
//}
//
//void inserir_pet(struct columns *columns, struct no_pet **pets, struct no_pessoa **pessoas, struct no_tipo_pet **tipo_pets){
//    struct no_pet *novo_pet = malloc(sizeof(struct no_pet));
//    if (!novo_pet) {
//        printf("Erro: Falha ao alocar memória para a lista pet.\n");
//        return;
//    }
//    novo_pet->ant = NULL;
//    memset(&novo_pet->pet, 0, sizeof(novo_pet->pet));
//    int checked_data = 0;
//    for(int i = 0; i < 5; i++){
//        if (strcmp(columns[i].name, "codigo") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//        if (strcmp(columns[i].name, "nome") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//        if (strcmp(columns[i].name, "codigo_pes") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//        if (strcmp(columns[i].name, "codigo_tipo") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//    }
//    if(checked_data == 4){
//        for (int i = 0; i < 4; i++) {
//            if (!columns[i].filled) continue;
//
//            if (strcmp(columns[i].name, "codigo") == 0) {
//                if(verificar_codigo_pet(pets, columns[i].value)){
//                    strncpy(novo_pet->pet.codigo, columns[i].value, sizeof(novo_pet->pet.codigo) - 1);
//                }else{
//                    printf("Code Pet already registered!\n");
//                    return;
//                }
//            } else if (strcmp(columns[i].name, "nome") == 0) {
//                strncpy(novo_pet->pet.nome, columns[i].value, sizeof(novo_pet->pet.nome) - 1);
//            } else if (strcmp(columns[i].name, "codigo_pes") == 0) {
//                if(verificar_codigo_pessoa_para_cadastro_de_pet(pessoas, columns[i].value)){
//                    strncpy(novo_pet->pet.codigo_pes, columns[i].value, sizeof(novo_pet->pet.codigo_pes) - 1);
//                }else{
//                    printf("Code Person doesn't registered!\n");
//                    return;
//                }
//            } else {
//                if(verificar_codigo_tipo_pet_para_cadastro_de_pet(tipo_pets, columns[i].value)){
//                    strncpy(novo_pet->pet.codigo_tipo, columns[i].value, sizeof(novo_pet->pet.codigo_tipo) - 1);
//                }else{
//                    printf("Code Type Pet doesn't registered!\n");
//                    return;
//                }
//            }
//        }
//    }else{
//        printf("\nPreencha os campos codigo, nome, codigo_pes e codigo_tipo de Pet corretamente!\n");
//        free(novo_pet);
//        return;
//    }
//    if(*pets == NULL){
//        novo_pet->prox = NULL;
//    }else{
//        novo_pet->prox = *pets;
//        (*pets)->ant = novo_pet;
//    }
//    *pets = novo_pet;
//}
//
//void inserir_tipo_pet(struct columns *columns, struct no_tipo_pet **tipo_pets){
//    struct no_tipo_pet *novo_tipo_pet = malloc(sizeof(struct no_tipo_pet));
//    if (!novo_tipo_pet) {
//        fprintf(stderr, "Erro: Falha ao alocar memória para a lista tipo pet.\n");
//        return;
//    }
//    novo_tipo_pet->ant = NULL;
//    memset(&novo_tipo_pet->tipo_pet, 0, sizeof(novo_tipo_pet->tipo_pet));
//    int checked_data = 0;
//    for(int i = 0; i < 2; i++){
//        if (strcmp(columns[i].name, "codigo") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//        if (strcmp(columns[i].name, "nome") == 0 && strcmp(columns[i].value, "") != 0) {
//            checked_data += 1;
//        }
//    }
//    if(checked_data == 2){
//        for (int i = 0; i < 2; i++) {
//            if (!columns[i].filled) continue;
//
//            if (strcmp(columns[i].name, "codigo") == 0) {
//                if(verificar_codigo_tipo_pet(tipo_pets, columns[i].value)){
//                    strncpy(novo_tipo_pet->tipo_pet.codigo, columns[i].value, sizeof(novo_tipo_pet->tipo_pet.codigo) - 1);
//                }else{
//                    printf("Code Type Pet already registered!");
//                    return;
//                }
//            } else {
//                strncpy(novo_tipo_pet->tipo_pet.nome, columns[i].value, sizeof(novo_tipo_pet->tipo_pet.nome) - 1);
//            }
//        }
//    }else{
//        printf("\nPreencha os campos codigo e nome de Pet corretamente!\n");
//        free(novo_tipo_pet);
//        return;
//    }
//    if(*tipo_pets == NULL){
//        novo_tipo_pet->prox = NULL;
//    }else{
//        novo_tipo_pet->prox = *tipo_pets;
//        (*tipo_pets)->ant = novo_tipo_pet;
//    }
//    *tipo_pets = novo_tipo_pet;
//}
//
//void insert(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
//    struct columns columns[5] = {0};
//    char tables[][20] = {
//            "pessoa",
//            "pet",
//            "tipo_pet"
//    };
//    char destructuring_command[20][255];
//    char cpy_comando[255];
//    strcpy(cpy_comando, command);
//    int count = 0, intervalo = 0, verificated = 0;
//    char *token = strtok(cpy_comando, "(),' ");
//    while (token != NULL && count < 20) {
//        strcpy(destructuring_command[count], token);
//        if (strcmp(destructuring_command[count], "values") == 0 || strcmp(destructuring_command[count], "VALUES") == 0) {
//            for(int i = 0; i < count; i++){
//                if(strcmp(destructuring_command[i], "pessoa") == 0){
//                    verificated = 1;
//                }
//            }
//            if(verificated){
//                count++;
//                break;
//            }
//        }
//        count++;
//        token = strtok(NULL, "(),' ");
//    }
//    for(int i = 3; i < count; i++){
//        if(strcmp(destructuring_command[i], "values") == 0 || strcmp(destructuring_command[i], "VALUES") == 0){
//            break;
//        }
//        intervalo++;
//    }
//    if(strcmp(destructuring_command[2], "pessoa") == 0){
//        token = strtok(NULL, "()'");
//        while (token != NULL && count < 20) {
//            strcpy(destructuring_command[count], token);
//
//            count++;
//            token = strtok(NULL, "()'");
//        }
//        for (int i = intervalo + 4; i < count; i++) {
//            if (destructuring_command[i][0] == ',' && strlen(destructuring_command[i]) <= 2) {
//                for (int j = i; j < count - 1; j++) {
//                    strcpy(destructuring_command[j], destructuring_command[j + 1]);
//                }
//                count--;
//                i--;
//            }
//        }
//    }
//    if(strcmp(destructuring_command[1], "into") == 0 || strcmp(destructuring_command[1], "INTO") == 0){
//        for(int j = 0; j < 3; j++){
//            if(strcmp(destructuring_command[2], tables[j]) == 0) {
//                count = 0;
//                for(int k = 3; k < intervalo + 3; k++){
//                    columns[count].filled = 1;
//                    strcpy(columns[count].name,destructuring_command[k]);
//                    strcpy(columns[count].value,destructuring_command[k+intervalo+1]);
//                    count++;
//                }
//            }
//        }
//    }
//    if(strcmp(destructuring_command[2], "pessoa") == 0) {
//        for (int i = 0; i < intervalo; i++) {
//            if (strcmp(columns[i].name, "codigo") == 0) {
//                int len = strlen(columns[i].value);
//                int writeIndex = 0;
//                for (int j = 0; j < len; j++) {
//                    if (columns[i].value[j] != ',' && columns[i].value[j] != ' ') {
//                        columns[i].value[writeIndex++] = columns[i].value[j];
//                    }
//                }
//                columns[i].value[writeIndex] = '\0';
//            }
//        }
//    }
//    if(strcmp(destructuring_command[2], "pessoa") == 0){
//        inserir_pessoa(columns, pessoas);
//    }else if(strcmp(destructuring_command[2], "pet") == 0){
//        inserir_pet(columns, pets, pessoas, tipo_pets);
//    }else{
//        inserir_tipo_pet(columns, tipo_pets);
//    }
//}
//
//void select_pessoa(struct no_pessoa **pessoas, char *column, char *valor) {
//    struct no_pessoa *aux = *pessoas;
//    int found = 0;
//    while (aux != NULL) {
//        if ((strcmp(column, "codigo") == 0 && strcmp(aux->pessoa.codigo, valor) == 0) ||
//            (strcmp(column, "nome") == 0 && strcmp(aux->pessoa.nome, valor) == 0) ||
//            (strcmp(column, "fone") == 0 && strcmp(aux->pessoa.fone, valor) == 0) ||
//            (strcmp(column, "endereco") == 0 && strcmp(aux->pessoa.endereco, valor) == 0) ||
//            (strcmp(column, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, valor) == 0)) {
//            printf("\n############SELECT############\n");
//            printf("Codigo: %s\n", aux->pessoa.codigo);
//            printf("Nome: %s\n", aux->pessoa.nome);
//            printf("Data de nascimento: %s\n", aux->pessoa.data_nascimento);
//            printf("Fone: %s\n", aux->pessoa.fone);
//            printf("Endereco: %s", aux->pessoa.endereco);
//            printf("\n##############################\n");
//            found = 1;
//        }
//        aux = aux->prox;
//    }
//
//    if (!found) {
//        printf("Erro ao procurar pessoa com %s igual a %s\n", column, valor);
//    }
//}
//
//void select_pet(struct no_pet **pets, char *column, char *valor){
//    struct no_pet *aux = *pets;
//    int found = 0;
//    while (aux != NULL) {
//        if ((strcmp(column, "codigo") == 0 && strcmp(aux->pet.codigo, valor) == 0) ||
//            (strcmp(column, "nome") == 0 && strcmp(aux->pet.nome, valor) == 0) ||
//            (strcmp(column, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, valor) == 0) ||
//            (strcmp(column, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, valor) == 0)) {
//            printf("\n############SELECT############\n");
//            printf("Codigo: %s\n", aux->pet.codigo);
//            printf("Nome: %s\n", aux->pet.nome);
//            printf("Codigo do dono: %s\n", aux->pet.codigo_pes);
//            printf("Codigo do tipo: %s\n", aux->pet.codigo_tipo);
//            printf("##############################\n");
//            found = 1;
//        }
//        aux = aux->prox;
//    }
//    if (!found) {
//        printf("Erro ao procurar pet com %s igual a %s\n", column, valor);
//    }
//}
//
//void select_tipo_pet(struct no_tipo_pet **tipos_pet, char *column, char *valor){
//    struct no_tipo_pet *aux = *tipos_pet;
//    int found = 0;
//    while(aux != NULL){
//        if ((strcmp(column, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, valor) == 0) ||
//            (strcmp(column, "nome") == 0 && strcmp(aux->tipo_pet.nome, valor) == 0)) {
//            printf("\n############SELECT############\n");
//            printf("Codigo: %s\n", aux->tipo_pet.codigo);
//            printf("Nome: %s", aux->tipo_pet.nome);
//            printf("\n##############################\n");
//            found = 1;
//        }
//        aux = aux->prox;
//    }
//    if (!found) {
//        printf("Erro ao procurar tipo_pet com %s igual a %s\n", column, valor);
//    }
//}
//
//void select_order_pessoa(struct no_pessoa **pessoas, char *column){
//    a_no_pessoa *raiz = NULL;
//    struct no_pessoa *aux = *pessoas;
//    while(aux != NULL){
//        if(strcmp(column, "nome") == 0){
//            raiz = a_inserir_rr(raiz,aux, column);
//        }else if(strcmp(column, "codigo") == 0){
//            raiz = a_inserir_rr(raiz,aux, column);
//        }else if(strcmp(column, "data_nascimento") == 0){
//            raiz = a_inserir_rr(raiz,aux, column);
//        }else{
//            printf("\nErro ao ordenar Pessoas!\n");
//        }
//        aux = aux->prox;
//    }
//    printf("\n--------Pessoas Em Ordem de %s---------\n", column);
//    a_in_order(raiz);
//    a_destruir(raiz);
//}
//
//a_no_pessoa *a_inserir_rr(struct a_no_pessoa *raiz, struct no_pessoa *pessoa, char *column){
//    if (raiz == NULL){
//        a_no_pessoa *aux = malloc(sizeof(a_no_pessoa));
//        aux->pessoa = pessoa;
//        aux->esq = NULL;
//        aux->dir = NULL;
//        return aux;
//    }
//    if(strcmp(column, "nome") == 0){
//        if (strcmp(pessoa->pessoa.nome, raiz->pessoa->pessoa.nome) > 0) { // Se valor é maior, vai para a direita
//            raiz->dir = a_inserir_rr(raiz->dir, pessoa, column);
//        } else if (strcmp(pessoa->pessoa.nome, raiz->pessoa->pessoa.nome) <= 0) { // Se valor é menor, vai para a esquerda
//            raiz->esq = a_inserir_rr(raiz->esq, pessoa, column);
//        }
//    }else if(strcmp(column, "codigo") == 0){
//        int codigo_pessoa = atoi(pessoa->pessoa.codigo);
//        int codigo_raiz = atoi(raiz->pessoa->pessoa.codigo);
////        if (strcmp(pessoa->pessoa.codigo, raiz->pessoa->pessoa.codigo) > 0) { // Se valor é maior, vai para a direita
////            raiz->dir = a_inserir_rr(raiz->dir, pessoa, column);
////        } else if (strcmp(pessoa->pessoa.codigo, raiz->pessoa->pessoa.codigo) <= 0) { // Se valor é menor, vai para a esquerda
////            raiz->esq = a_inserir_rr(raiz->esq, pessoa, column);
////        }
//        if (codigo_pessoa > codigo_raiz) {
//            raiz->dir = a_inserir_rr(raiz->dir, pessoa, column);
//        } else {
//            raiz->esq = a_inserir_rr(raiz->esq, pessoa, column);
//        }
//    }else if(strcmp(column, "data_nascimento") == 0){
//        int comparacao = comparar_data(pessoa->pessoa.data_nascimento, raiz->pessoa->pessoa.data_nascimento);
//        if (comparacao > 0) { // Se valor é maior, vai para a direita
//            raiz->dir = a_inserir_rr(raiz->dir, pessoa, column);
//        } else { // Se valor é menor, vai para a esquerda
//            raiz->esq = a_inserir_rr(raiz->esq, pessoa, column);
//        }
//    }
//    return raiz;
//}
//
//void a_in_order(a_no_pessoa *raiz){
//    if (raiz != NULL){
//        a_in_order(raiz->esq);
//        printf("Nome: %s\n", raiz->pessoa->pessoa.nome);
//        printf("Codigo: %s\n", raiz->pessoa->pessoa.codigo);
//        printf("Data de nascimento: %s\n", raiz->pessoa->pessoa.data_nascimento);
//        printf("Fone: %s\n", raiz->pessoa->pessoa.fone);
//        printf("Endereco: %s\n", raiz->pessoa->pessoa.endereco);
//        printf("--------------------------\n");
//        a_in_order(raiz->dir);
//    }
//}
//
//void a_destruir(a_no_pessoa *raiz) {
//    if (raiz == NULL) return;
//    a_destruir(raiz->esq);
//    a_destruir(raiz->dir);
//    free(raiz);
//}
//
//void select_order_pet(struct no_pet **pets, char *column){
//    a_no_pet *raiz = NULL;
//    struct no_pet *aux = *pets;
//    while(aux != NULL){
//        if(strcmp(column, "nome") == 0){
//            raiz = a_inserir_pet_rr(raiz, aux, column);
//        }else if(strcmp(column, "codigo") == 0){
//            raiz = a_inserir_pet_rr(raiz,aux, column);
//        }else if(strcmp(column, "codigo_pes") == 0){
//            raiz = a_inserir_pet_rr(raiz,aux, column);
//        }else if(strcmp(column, "codigo_tipo") == 0){
//            raiz = a_inserir_pet_rr(raiz,aux, column);
//        }else{
//            printf("\nErro ao ordenar Pets!\n");
//        }
//        aux = aux->prox;
//    }
//
//    printf("\n--------Pets Em Ordem de %s---------\n", column);
//    a_in_order_pet(raiz);
//    a_destruir_pet(raiz);
//}
//a_no_pet *a_inserir_pet_rr(struct a_no_pet *raiz, struct no_pet *pet, char *column){
//    if (raiz == NULL){
//        a_no_pet *aux = malloc(sizeof(a_no_pet));
//        aux->pet = pet;
//        aux->esq = NULL;
//        aux->dir = NULL;
//        return aux;
//    }
//    if(strcmp(column, "nome") == 0){
//        if (strcmp(pet->pet.nome, raiz->pet->pet.nome) > 0) { // Se valor é maior, vai para a direita
//            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
//        } else if (strcmp(pet->pet.nome, raiz->pet->pet.nome) <= 0) { // Se valor é menor, vai para a esquerda
//            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
//        }
//    }else if(strcmp(column, "codigo") == 0){
//        int codigo = atoi(pet->pet.codigo);
//        int codigo_raiz = atoi(raiz->pet->pet.codigo);
//        if (codigo > codigo_raiz) {
//            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
//        } else {
//            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
//        }
////        if (strcmp(pet->pet.codigo, raiz->pet->pet.codigo) > 0) { // Se valor é maior, vai para a direita
////            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
////        } else if (strcmp(pet->pet.codigo, raiz->pet->pet.codigo) <= 0) { // Se valor é menor, vai para a esquerda
////            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
////        }
//    }else if(strcmp(column, "codigo_pes") == 0){
//        int codigo_pes = atoi(pet->pet.codigo_pes);
//        int codigo_raiz = atoi(raiz->pet->pet.codigo_pes);
//        if (codigo_pes > codigo_raiz) {
//            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
//        } else {
//            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
//        }
////        if (strcmp(pet->pet.codigo_pes, raiz->pet->pet.codigo_pes) > 0) { // Se valor é maior, vai para a direita
////            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
////        } else if (strcmp(pet->pet.codigo_pes, raiz->pet->pet.codigo_pes) < 0) { // Se valor é menor, vai para a esquerda
////            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
////        }
//    }else if(strcmp(column, "codigo_tipo") == 0){
//        int codigo_tipo = atoi(pet->pet.codigo_tipo);
//        int codigo_raiz = atoi(raiz->pet->pet.codigo_tipo);
//        if (codigo_tipo > codigo_raiz) {
//            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
//        } else {
//            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
//        }
////        if (strcmp(pet->pet.codigo_tipo, raiz->pet->pet.codigo_tipo) > 0) { // Se valor é maior, vai para a direita
////            raiz->dir = a_inserir_pet_rr(raiz->dir, pet, column);
////        } else if (strcmp(pet->pet.codigo_tipo, raiz->pet->pet.codigo_tipo) < 0) { // Se valor é menor, vai para a esquerda
////            raiz->esq = a_inserir_pet_rr(raiz->esq, pet, column);
////        }
//    }
//    return raiz;
//}
//
//void a_in_order_pet(a_no_pet *raiz){
//    if (raiz != NULL){
//        a_in_order_pet(raiz->esq);
//        printf("Nome: %s\n", raiz->pet->pet.nome);
//        printf("Codigo: %s\n", raiz->pet->pet.codigo);
//        printf("Codigo do Dono: %s\n", raiz->pet->pet.codigo_pes);
//        printf("Codigo do Tipo: %s\n", raiz->pet->pet.codigo_tipo);
//        printf("--------------------------\n");
//        a_in_order_pet(raiz->dir);
//    }
//}
//void a_destruir_pet(a_no_pet *raiz){
//    if (raiz == NULL) return;
//    a_destruir_pet(raiz->esq);
//    a_destruir_pet(raiz->dir);
//    free(raiz);
//}
//
//void select_order_tipo_pet(struct no_tipo_pet **tipos_pet, char *column){
//    a_no_tipo_pet *raiz = NULL;
//    struct no_tipo_pet *aux = *tipos_pet;
//    while(aux != NULL){
//        if(strcmp(column, "nome") == 0){
//            raiz = a_inserir_tipo_pet_rr(raiz,aux, column);
//        }else if(strcmp(column, "codigo") == 0){
//            raiz = a_inserir_tipo_pet_rr(raiz,aux, column);
//        }else{
//            printf("\nErro ao ordenar Tipo Pet!\n");
//        }
//        aux = aux->prox;
//    }
//    printf("\n--------Tipo Pet Em Ordem de %s---------\n", column);
//    a_in_order_tipo_pet(raiz);
//    a_destruir_tipo_pet(raiz);
//}
//
//a_no_tipo_pet *a_inserir_tipo_pet_rr(struct a_no_tipo_pet *raiz, struct no_tipo_pet *tipo_pet, char *column){
//    if (raiz == NULL){
//        a_no_tipo_pet *aux = malloc(sizeof(a_no_pessoa));
//        aux->tipo_pet = tipo_pet;
//        aux->esq = NULL;
//        aux->dir = NULL;
//        return aux;
//    }
//    if(strcmp(column, "nome") == 0){
//        if (strcmp(tipo_pet->tipo_pet.nome, raiz->tipo_pet->tipo_pet.nome) > 0) { // Se valor é maior, vai para a direita
//            raiz->dir = a_inserir_tipo_pet_rr(raiz->dir, tipo_pet, column);
//        } else if (strcmp(tipo_pet->tipo_pet.nome, raiz->tipo_pet->tipo_pet.nome) <= 0) { // Se valor é menor, vai para a esquerda
//            raiz->esq = a_inserir_tipo_pet_rr(raiz->esq, tipo_pet, column);
//        }
//    }else if(strcmp(column, "codigo") == 0){
//        int codigo = atoi(tipo_pet->tipo_pet.codigo);
//        int codigo_raiz = atoi(raiz->tipo_pet->tipo_pet.codigo);
//        if (codigo > codigo_raiz) {
//            raiz->dir = a_inserir_tipo_pet_rr(raiz->dir, tipo_pet, column);
//        } else {
//            raiz->esq = a_inserir_tipo_pet_rr(raiz->esq, tipo_pet, column);
//        }
////        if (strcmp(tipo_pet->tipo_pet.codigo, raiz->tipo_pet->tipo_pet.codigo) > 0) { // Se valor é maior, vai para a direita
////            raiz->dir = a_inserir_tipo_pet_rr(raiz->dir, tipo_pet, column);
////        } else if (strcmp(tipo_pet->tipo_pet.codigo, raiz->tipo_pet->tipo_pet.codigo) <= 0) { // Se valor é menor, vai para a esquerda
////            raiz->esq = a_inserir_tipo_pet_rr(raiz->esq, tipo_pet, column);
////        }
//    }
//    return raiz;
//}
//
//void a_in_order_tipo_pet(a_no_tipo_pet *raiz){
//    if (raiz != NULL){
//        a_in_order_tipo_pet(raiz->esq);
//        printf("Nome: %s\n", raiz->tipo_pet->tipo_pet.nome);
//        printf("Codigo: %s\n", raiz->tipo_pet->tipo_pet.codigo);
//        printf("--------------------------\n");
//        a_in_order_tipo_pet(raiz->dir);
//    }
//}
//void a_destruir_tipo_pet(a_no_tipo_pet *raiz){
//    if (raiz == NULL) return;
//    a_destruir_tipo_pet(raiz->esq);
//    a_destruir_tipo_pet(raiz->dir);
//    free(raiz);
//}
//
//void lista_filtrada_a_ser_ordenada(
//        struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets,
//        char *tabela_order_by,
//        char *coluna_a_ser_filtrada,
//        char *valor_a_ser_filtrado,
//        char *coluna_a_ser_ordenada) {
//
//    if (strcmp(tabela_order_by, "pessoa") == 0) {
//        struct no_pessoa *lista_a_ser_filtrada = NULL;
//        struct no_pessoa *aux = *pessoas;
//
//        while (aux != NULL) {
//            if ((strcmp(coluna_a_ser_filtrada, "codigo") == 0 && strcmp(aux->pessoa.codigo, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "nome") == 0 && strcmp(aux->pessoa.nome, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "fone") == 0 && strcmp(aux->pessoa.fone, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "endereco") == 0 && strcmp(aux->pessoa.endereco, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, valor_a_ser_filtrado) == 0)) {
//
//                struct no_pessoa *novo = malloc(sizeof(struct no_pessoa));
//                novo->pessoa = aux->pessoa;
//                novo->prox = lista_a_ser_filtrada;
//                if (lista_a_ser_filtrada) lista_a_ser_filtrada->ant = novo;
//                lista_a_ser_filtrada = novo;
//            }
//            aux = aux->prox;
//        }
//        select_order_pessoa(&lista_a_ser_filtrada, coluna_a_ser_ordenada);
//        liberar_lista_pessoas(&lista_a_ser_filtrada);
//    } else if (strcmp(tabela_order_by, "pet") == 0) {
//        struct no_pet *lista_filtrada_pet = NULL;
//        struct no_pet *aux = *pets;
//        while (aux != NULL) {
//            if ((strcmp(coluna_a_ser_filtrada, "codigo") == 0 && strcmp(aux->pet.codigo, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "nome") == 0 && strcmp(aux->pet.nome, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, valor_a_ser_filtrado) == 0)) {
//                struct no_pet *novo = malloc(sizeof(struct no_pet));
//                novo->pet = aux->pet;
//                novo->prox = lista_filtrada_pet;
//                lista_filtrada_pet = novo;
//            }
//            aux = aux->prox;
//        }
//        select_order_pet(&lista_filtrada_pet, coluna_a_ser_ordenada);
//        liberar_lista_pets(&lista_filtrada_pet);
//    } else if (strcmp(tabela_order_by, "tipo_pet") == 0) {
//        struct no_tipo_pet *lista_filtrada_tipo = NULL;
//        struct no_tipo_pet *aux = *tipo_pets;
//        while (aux != NULL) {
//            if ((strcmp(coluna_a_ser_filtrada, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, valor_a_ser_filtrado) == 0) ||
//                (strcmp(coluna_a_ser_filtrada, "nome") == 0 && strcmp(aux->tipo_pet.nome, valor_a_ser_filtrado) == 0)) {
//                struct no_tipo_pet *novo = malloc(sizeof(struct no_tipo_pet));
//                novo->tipo_pet = aux->tipo_pet;
//                novo->prox = lista_filtrada_tipo;
//                lista_filtrada_tipo = novo;
//            }
//            aux = aux->prox;
//        }
//        select_order_tipo_pet(&lista_filtrada_tipo, coluna_a_ser_ordenada);
//        liberar_lista_tipo_pet(&lista_filtrada_tipo);
//    } else {
//        printf("\nErro ao filtrar lista!");
//    }
//}
//
//void select(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
//    char destructuring_command[20][255];
//    int count = 0;
//
//    char *token = strtok(command, "(),'; ");
//    while (token != NULL && count < 20) {
//        strcpy(destructuring_command[count], token);
//        count++;
//        token = strtok(NULL, "(),'; ");
//    }
//
//    if(count == 4){
//        if(strcmp(destructuring_command[3], "pessoa") == 0){
//            imprimir_lista_pessoa(*pessoas);
//            return;
//        }else if(strcmp(destructuring_command[3], "pet") == 0){
//            imprimir_lista_pet(*pets);
//            return;
//        }else if(strcmp(destructuring_command[3], "tipo_pet") == 0){
//            imprimir_lista_tipo_pet(*tipo_pets);
//            return;
//        }else{
//            printf("\nError ao chamar funcao select\n");
//            return;
//        }
//    }
//
//    if((strcmp(destructuring_command[4], "where") == 0 || strcmp(destructuring_command[4], "WHERE") == 0)
//        &&(strcmp(destructuring_command[8], "order") == 0 || strcmp(destructuring_command[8], "ORDER") == 0)
//        && (strcmp(destructuring_command[9], "by") == 0 || strcmp(destructuring_command[9], "BY") == 0)){
//        char tabela_order_by[MAX_LENGTH];
//        strcpy(tabela_order_by, destructuring_command[3]);
//        char coluna_a_ser_filtrada[MAX_LENGTH];
//        strcpy(coluna_a_ser_filtrada, destructuring_command[5]);
//        char valor_a_ser_filtrado[MAX_LENGTH];
//        strcpy(valor_a_ser_filtrado, destructuring_command[7]);
//        char coluna_a_ser_ordenada[MAX_LENGTH];
//        strcpy(coluna_a_ser_ordenada, destructuring_command[10]);
//        lista_filtrada_a_ser_ordenada(pessoas, pets, tipo_pets,tabela_order_by, coluna_a_ser_filtrada, valor_a_ser_filtrado,coluna_a_ser_ordenada);
//        return;
//    }
//
//    if((strcmp(destructuring_command[4], "order") == 0 || strcmp(destructuring_command[4], "ORDER") == 0)
//        && (strcmp(destructuring_command[5], "by") == 0 || strcmp(destructuring_command[5], "BY") == 0)){
//            char column_order_by[MAX_LENGTH];
//            strcpy(column_order_by, destructuring_command[6]);
//            if(strcmp(destructuring_command[3], "pessoa") == 0){
//                select_order_pessoa(pessoas, column_order_by);
//                return;
//            }else if(strcmp(destructuring_command[3], "pet") == 0){
//                select_order_pet(pets, column_order_by);
//                return;
//            }else if(strcmp(destructuring_command[3], "tipo_pet") == 0){
//                select_order_tipo_pet(tipo_pets, column_order_by);
//                return;
//            }else{
//                printf("\nERROR SELECT BY ORDER\n");
//            }
//    }
//    char column[MAX_LENGTH];
//    char value[MAX_LENGTH];
//    strcpy(column, destructuring_command[5]);
//    strcpy(value, destructuring_command[7]);
//    if(strcmp(destructuring_command[1], "*") != 0){
//        printf("Invalid Command(error: *)!\n");
//        return;
//    }
//    if(strcmp(destructuring_command[2], "from") != 0 && strcmp(destructuring_command[2], "FROM") != 0){
//        printf("Invalid Command(error: from or FROM)!\n");
//        return;
//    }
//    if(strcmp(destructuring_command[3], "pessoa") == 0){
//        select_pessoa(pessoas, column, value);
//    }else if(strcmp(destructuring_command[3], "pet") == 0){
//        select_pet(pets, column, value);
//    }else if(strcmp(destructuring_command[3], "tipo_pet") == 0){
//        select_tipo_pet(tipo_pets, column, value);
//    }else{
//        printf("\nError ao chamar funcao select\n");
//    }
//}
//
//void update_pessoa(struct no_pessoa **pessoas,
//                   char *coluna_pesquisa,
//                   char *valor_pesquisado,
//                   char *coluna_a_ser_alterada,
//                   char *valor_a_ser_alterado) {
//    struct no_pessoa *aux = *pessoas;
//    int found = 0;
//
//    while (aux != NULL) {
//        if ((strcmp(coluna_pesquisa, "codigo") == 0 && strcmp(aux->pessoa.codigo, valor_pesquisado) == 0) ||
//            (strcmp(coluna_pesquisa, "nome") == 0 && strcmp(aux->pessoa.nome, valor_pesquisado) == 0) ||
//            (strcmp(coluna_pesquisa, "fone") == 0 && strcmp(aux->pessoa.fone, valor_pesquisado) == 0) ||
//            (strcmp(coluna_pesquisa, "endereco") == 0 && strcmp(aux->pessoa.endereco, valor_pesquisado) == 0) ||
//            (strcmp(coluna_pesquisa, "data_nascimento") == 0 &&
//             strcmp(aux->pessoa.data_nascimento, valor_pesquisado) == 0)) {
//            found = 1;
//            break;
//        }
//        aux = aux->prox;
//    }
//    if (!found) {
//        printf("Erro ao procurar pessoa com %s igual a %s\n", coluna_pesquisa, valor_pesquisado);
//    }
//    if (!aux) {
//        return;
//    }
//    if (strcmp(coluna_a_ser_alterada, "codigo") == 0) {
//        strcpy(aux->pessoa.codigo, valor_a_ser_alterado);
//    } else if (strcmp(coluna_a_ser_alterada, "nome") == 0) {
//        strcpy(aux->pessoa.nome, valor_a_ser_alterado);
//    } else if (strcmp(coluna_a_ser_alterada, "data_nascimento") == 0) {
//        strcpy(aux->pessoa.data_nascimento, valor_a_ser_alterado);
//    } else if (strcmp(coluna_a_ser_alterada, "fone") == 0) {
//        strcpy(aux->pessoa.fone, valor_a_ser_alterado);
//    }else if (strcmp(coluna_a_ser_alterada, "endereco") == 0) {
//        strcpy(aux->pessoa.endereco, valor_a_ser_alterado);
//    }else{
//        printf("Error na coluna: select-pessoa");
//    }
//}
//
//void update_tipo_pet(struct no_tipo_pet **tipos_pet,
//                    char *coluna_pesquisa,
//                    char *valor_pesquisado,
//                    char *coluna_a_ser_alterada,
//                    char *valor_a_ser_alterado){
//    struct no_tipo_pet *aux = *tipos_pet;
//    int found = 0;
//    while (aux != NULL) {
//        if ((strcmp(coluna_pesquisa, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, valor_pesquisado) == 0) ||
//            (strcmp(coluna_pesquisa, "nome") == 0 && strcmp(aux->tipo_pet.nome, valor_pesquisado) == 0)) {
//            found = 1;
//            break;
//        }
//        aux = aux->prox;
//    }
//    if (!found) {
//        printf("Erro ao procurar pessoa com %s igual a %s\n", coluna_pesquisa, valor_pesquisado);
//    }
//    if (!aux) {
//        return;
//    }
//    if (strcmp(coluna_a_ser_alterada, "codigo") == 0) {
//        strcpy(aux->tipo_pet.codigo, valor_a_ser_alterado);
//    } else if (strcmp(coluna_a_ser_alterada, "nome") == 0) {
//        strcpy(aux->tipo_pet.nome, valor_a_ser_alterado);
//    }else{
//        printf("Error na coluna: select-tipo_pet");
//    }
//}
//
//void update_pet(struct no_pet **pets,
//                struct no_tipo_pet **tipos_pet,
//                struct no_pessoa **pessoas,
//                char *coluna_pesquisada,
//                char *valor_pesquisado,
//                char *coluna_a_ser_alterada,
//                char *valor_a_ser_alterado){
//    struct no_pet *aux = *pets;
//    int found = 0;
//    while (aux != NULL) {
//        if ((strcmp(coluna_pesquisada, "codigo") == 0 && strcmp(aux->pet.codigo, valor_pesquisado) == 0) ||
//            (strcmp(coluna_pesquisada, "nome") == 0 && strcmp(aux->pet.nome, valor_pesquisado) == 0) ||
//            (strcmp(coluna_pesquisada, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, valor_pesquisado) == 0) ||
//            strcmp(coluna_pesquisada, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, valor_pesquisado) == 0){
//            found = 1;
//            break;
//        }
//        aux = aux->prox;
//    }
//    if (!found) {
//        printf("Erro ao procurar pessoa com %s igual a %s\n", coluna_pesquisada, valor_pesquisado);
//    }
//    if (!aux) {
//        return;
//    }
//    if (strcmp(coluna_a_ser_alterada, "codigo") == 0) {
//        strcpy(aux->pet.codigo, valor_a_ser_alterado);
//    } else if (strcmp(coluna_a_ser_alterada, "nome") == 0) {
//        strcpy(aux->pet.nome, valor_a_ser_alterado);
//    } else if (strcmp(coluna_a_ser_alterada, "codigo_pes") == 0) {
//        if(verificar_codigo_pessoa_para_cadastro_de_pet(pessoas, valor_a_ser_alterado)){
//            strcpy(aux->pet.codigo_pes, valor_a_ser_alterado);
//        }else{
//            printf("\nO codigo Pessoa precisa ser valido para o Pet ser alterado!");
//            return;
//        }
//    } else if (strcmp(coluna_a_ser_alterada, "codigo_tipo") == 0) {
//        if(verificar_codigo_tipo_pet_para_cadastro_de_pet(tipos_pet, valor_a_ser_alterado)){
//            strcpy(aux->pet.codigo_tipo, valor_a_ser_alterado);
//        }else{
//            printf("\nO codigo Tipo Pet precisa ser valido para o Pet ser alterado!");
//            return;
//        }
//    }else{
//        printf("Error na coluna: select-pet");
//    }
//}
//
//void update(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
//    char tables[][20] = {
//            "pessoa",
//            "pet",
//            "tipo_pet"
//    };
//
//    char pessoa_columns[][20] = {"codigo", "nome", "fone", "endereco", "data_nascimento"};
//    char pet_columns[][20] = {"codigo", "nome", "codigo_pes", "codigo_tipo"};
//    char tipo_pet_columns[][20] = {"codigo", "nome"};
//    char coluna_pesquisada[MAX_LENGTH];
//    char valor_pesquisado[MAX_LENGTH];
//    char coluna_a_ser_alterada[MAX_LENGTH];
//    char valor_a_ser_alterado[MAX_LENGTH];
//    char destructuring_command[20][255];
//    int count = 0, validated = 0;
//    char *token = strtok(command, "(),'; ");
//    while (token != NULL && count < 20) {
//        strcpy(destructuring_command[count], token);
//        count++;
//        token = strtok(NULL, "(),'; ");
//    }
//    for(int i = 0; i < 3; i++){
//        if(strcmp(destructuring_command[1], tables[i]) == 0){
//            validated = 1;
//        }
//    }
//    if(!validated){
//        printf("Error: table name!");
//        return;
//    }
//    validated = 0;
//    if(strcmp(destructuring_command[1], "pessoa") == 0){
//        for(int i = 0; i < 5; i++){
//            if(strcmp(destructuring_command[3], pessoa_columns[i]) == 0){
//                validated = 1;
//            }
//        }
//        if(!validated){
//            printf("Error: column name - pessoa!");
//            return;
//        }
//    }
//    validated = 0;
//    if(strcmp(destructuring_command[1], "pet") == 0){
//        for(int i = 0; i < 4; i++){
//            if(strcmp(destructuring_command[3], pet_columns[i]) == 0){
//                validated = 1;
//            }
//        }
//        if(!validated){
//            printf("Error: column name - pet!");
//            return;
//        }
//    }
//    validated = 0;
//    if(strcmp(destructuring_command[1], "tipo_pet") == 0){
//        for(int i = 0; i < 2; i++){
//            if(strcmp(destructuring_command[3], tipo_pet_columns[i]) == 0){
//                validated = 1;
//            }
//        }
//        if(!validated){
//            printf("Error: column name - tipo_pet!");
//            return;
//        }
//    }
//    if(strcmp(destructuring_command[6], "where") == 0 && strcmp(destructuring_command[6], "WHERE") == 0){
//        printf("Error: where");
//        return;
//    }
//    strcpy(coluna_pesquisada, destructuring_command[7]);
//    strcpy(valor_pesquisado, destructuring_command[9]);
//    strcpy(coluna_a_ser_alterada, destructuring_command[3]);
//    strcpy(valor_a_ser_alterado, destructuring_command[5]);
//    if(strcmp(destructuring_command[1], "pessoa") == 0){
//        update_pessoa(pessoas,
//                      coluna_pesquisada,valor_pesquisado,coluna_a_ser_alterada,valor_a_ser_alterado);
//    }else if(strcmp(destructuring_command[1], "pet") == 0){
//        update_pet(pets,tipo_pets,pessoas,coluna_pesquisada,valor_pesquisado,coluna_a_ser_alterada,valor_a_ser_alterado);
//    }else if(strcmp(destructuring_command[1], "tipo_pet") == 0) {
//        update_tipo_pet(tipo_pets,coluna_pesquisada,valor_pesquisado,coluna_a_ser_alterada,valor_a_ser_alterado);
//    }else{
//        printf("Problema ao chamar metodo update!\n");
//    }
//}
//
//void delete_pessoa(struct no_pessoa **pessoas, struct no_pet **pets, char *column_to_be_deleted, char *value_to_be_deleted) {
//    if (!(*pessoas)) return;
//
//    struct no_pessoa *aux = *pessoas;
//
//    while (aux != NULL) {
//        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pessoa.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pessoa.nome, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "fone") == 0 && strcmp(aux->pessoa.fone, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "endereco") == 0 && strcmp(aux->pessoa.endereco, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, value_to_be_deleted) == 0)) {
//
//            if (verificar_pelo_codigo_se_pode_deletar_pessoa(pets, aux->pessoa.codigo)) {
//                if (aux->ant) {
//                    aux->ant->prox = aux->prox;
//                } else {
//                    *pessoas = aux->prox;
//                }
//                if (aux->prox) {
//                    aux->prox->ant = aux->ant;
//                }
//                free(aux);
//                return;
//            } else {
//                printf("\nNao foi possivel deletar pessoa porque ela tem pet!\n");
//                return;
//            }
//        }
//        aux = aux->prox;
//    }
//    printf("Erro ao DELETAR pessoa com %s igual a %s\n", column_to_be_deleted, value_to_be_deleted);
//}
//
//
//void delete_tipo_pet(struct no_tipo_pet **tipos_pet, char *column_to_be_deleted, char *value_to_be_deleted) {
//    if (!(*tipos_pet)) return;
//
//    struct no_tipo_pet *aux = *tipos_pet;
//
//    while (aux != NULL) {
//        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->tipo_pet.nome, value_to_be_deleted) == 0)) {
//
//            if (aux->ant) {
//                aux->ant->prox = aux->prox;
//            } else {
//                *tipos_pet = aux->prox;
//            }
//            if (aux->prox) {
//                aux->prox->ant = aux->ant;
//            }
//            free(aux);
//            return;
//        }
//        aux = aux->prox;
//    }
//    printf("Erro ao DELETAR tipo pet com %s igual a %s\n", column_to_be_deleted, value_to_be_deleted);
//}
//
//
//void delete_pet(struct no_pet **pet, char *column_to_be_deleted, char *value_to_be_deleted) {
//    if (!(*pet)) return;
//    struct no_pet *aux = *pet, *ant = NULL;
//    while (aux != NULL &&
//           ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pet.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pet.nome, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, value_to_be_deleted) == 0))) {
//        *pet = aux->prox;
//        free(aux);
//        return;
//    }
//    while (aux != NULL) {
//        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pet.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pet.nome, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, value_to_be_deleted) == 0)) {
//            ant->prox = aux->prox;
//            free(aux);
//            return;
//        }
//        ant = aux;
//        aux = aux->prox;
//    }
//    printf("Erro ao DELETAR pet com %s igual a %s\n", column_to_be_deleted, value_to_be_deleted);
//}
//
//void delete(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
//    char tables[][20] = {
//            "pessoa",
//            "pet",
//            "tipo_pet"
//    };
//    char pessoa_columns[][20] = {"codigo", "nome", "fone", "endereco", "data_nascimento"};
//    char pet_columns[][20] = {"codigo", "nome", "codigo_pes", "codigo_tipo"};
//    char tipo_pet_columns[][20] = {"codigo", "nome"};
//    char column_to_be_deleted[MAX_LENGTH];
//    char value_to_be_deleted[MAX_LENGTH];
//    char destructuring_command[20][255];
//    int count = 0, validated = 0;
//    char *token = strtok(command, "(),'; ");
//    while (token != NULL && count < 20) {
//        strcpy(destructuring_command[count], token);
//        count++;
//        token = strtok(NULL, "(),'; ");
//    }
//    if(strcmp(destructuring_command[1], "from") != 0 && strcmp(destructuring_command[1], "FROM") != 0){
//        printf("Invalid Command -  erro: from!");
//        return;
//    }
//    for(int i = 0; i < 3; i++){
//        if(strcmp(destructuring_command[2], tables[i]) == 0){
//            validated = 1;
//        }
//    }
//    if(strcmp(destructuring_command[3], "where") != 0 && strcmp(destructuring_command[3], "WHERE") != 0){
//        printf("Invalid Command -  erro: where!");
//        return;
//    }
//    validated = 0;
//    if(strcmp(destructuring_command[1], "pessoa") == 0){
//        for(int i = 0; i < 5; i++){
//            if(strcmp(destructuring_command[3], pessoa_columns[i]) == 0){
//                validated = 1;
//            }
//        }
//        if(!validated){
//            printf("Error: column name - pessoa!");
//            return;
//        }
//    }
//    validated = 0;
//    if(strcmp(destructuring_command[1], "pet") == 0){
//        for(int i = 0; i < 4; i++){
//            if(strcmp(destructuring_command[3], pet_columns[i]) == 0){
//                validated = 1;
//            }
//        }
//        if(!validated){
//            printf("Error: column name - pet!");
//            return;
//        }
//    }
//    validated = 0;
//    if(strcmp(destructuring_command[1], "tipo_pet") == 0){
//        for(int i = 0; i < 2; i++){
//            if(strcmp(destructuring_command[3], tipo_pet_columns[i]) == 0){
//                validated = 1;
//            }
//        }
//        if(!validated){
//            printf("Error: column name - tipo_pet!");
//            return;
//        }
//    }
//    strcpy(column_to_be_deleted, destructuring_command[4]);
//    strcpy(value_to_be_deleted, destructuring_command[6]);
//    if(strcmp(destructuring_command[2], "pessoa") == 0){
//        delete_pessoa(pessoas, pets, column_to_be_deleted, value_to_be_deleted);
//    }else if(strcmp(destructuring_command[2], "pet") == 0){
//        delete_pet(pets, column_to_be_deleted, value_to_be_deleted);
//    }else if(strcmp(destructuring_command[2], "tipo_pet") == 0){
//        delete_tipo_pet(tipo_pets, column_to_be_deleted, value_to_be_deleted);
//    }else{
//        printf("Invalid Command: chamada da funcao delete!");
//    }
//}
//
//void destructuring_command(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
//    char destructuring_command[2][200];
//    int count = 0;
//
//    char command_copy[255];
//    strcpy(command_copy, command);
//
//    char *token = strtok(command_copy, "(),' ");
//    while (token != NULL && count < 2) {
//        strcpy(destructuring_command[count], token);
//        count++;
//        token = strtok(NULL, "(),' ");
//    }
//    if(strcmp(destructuring_command[0], "insert") == 0 || strcmp(destructuring_command[0], "INSERT") == 0){
//        insert(command, pessoas, pets, tipo_pets);
//    }else if(strcmp(destructuring_command[0], "select") == 0 || strcmp(destructuring_command[0], "SELECT") == 0){
//        select(command, pessoas, pets, tipo_pets);
//    }else if(strcmp(destructuring_command[0], "update") == 0 || strcmp(destructuring_command[0], "UPDATE") == 0){
//        update(command, pessoas, pets, tipo_pets);
//    }else if(strcmp(destructuring_command[0], "delete") == 0 || strcmp(destructuring_command[0], "DELETE") == 0){
//        delete(command, pessoas, pets, tipo_pets);
//    }else{
//        printf("Invalid Command identified in destructuring!");
//    }
//}
//
////Funções de verificação
//int verificar_codigo_pessoa(struct no_pessoa **l, char *codigo){
//    struct no_pessoa *aux = *l;
//    while(aux != NULL){
//        if(strcmp(aux->pessoa.codigo, codigo) == 0){
//            return 0;
//        }
//        aux = aux->prox;
//    }
//    return 1;
//}
//
//int verificar_codigo_pet(struct no_pet **l, char *codigo){
//    struct no_pet *aux = *l;
//    while(aux != NULL){
//        if(strcmp(aux->pet.codigo, codigo) == 0){
//            return 0;
//        }
//        aux = aux->prox;
//    }
//    return 1;
//}
//
//int verificar_codigo_tipo_pet(struct no_tipo_pet **l, char *codigo){
//    struct no_tipo_pet *aux = *l;
//    while(aux != NULL){
//        if(strcmp(aux->tipo_pet.codigo, codigo) == 0) return 0;
//        aux = aux->prox;
//    }
//    return 1;
//}
//
//int verificar_codigo_pessoa_para_cadastro_de_pet(struct no_pessoa **l, char *codigo){
//    struct no_pessoa *aux = *l;
//    while(aux != NULL){
//        if(strcmp(aux->pessoa.codigo, codigo) == 0) return 1;
//        aux = aux->prox;
//    }
//    return 0;
//}
//
//int verificar_codigo_tipo_pet_para_cadastro_de_pet(struct no_tipo_pet **l, char *codigo){
//    struct no_tipo_pet *aux = *l;
//    while(aux != NULL){
//        if(strcmp(aux->tipo_pet.codigo, codigo) == 0) return 1;
//        aux = aux->prox;
//    }
//    return 0;
//}
//
//int verificar_pelo_codigo_se_pode_deletar_pessoa(struct no_pet **l, char *codigo){
//    struct no_pet *aux = *l;
//    while(aux != NULL){
//        if(strcmp(aux->pet.codigo_pes, codigo) == 0) return 0;
//        aux = aux->prox;
//    }
//    return 1;
//}
//
//int comparar_data(char *data1, char *data2) {
//    int dia1, mes1, ano1;
//    int dia2, mes2, ano2;
//    sscanf(data1, "%d/%d/%d", &dia1, &mes1, &ano1);
//    sscanf(data2, "%d/%d/%d", &dia2, &mes2, &ano2);
//    if (ano1 < ano2) return -1;
//    if (ano1 > ano2) return 1;
//    if (mes1 < mes2) return -1;
//    if (mes1 > mes2) return 1;
//    if (dia1 < dia2) return -1;
//    if (dia1 > dia2) return 1;
//    return 0;
//}
//
//void ler_comandos_do_usuario(struct fila_comando **fila){
//    FILE *file;
//    char line[MAX_LENGTH];
//    char *commands[MAX_COMMANDS];
//    int count = 0;
//    file = fopen("comandos.txt", "r");
//    if (file == NULL) {
//        printf("Erro ao abrir o arquivo.\n");
//        return;
//    }
//    while (fgets(line, sizeof(line), file) != NULL) {
//        if (line[strlen(line) - 1] == '\n') {
//            line[strlen(line) - 1] = '\0';
//        }
//        if (line[strlen(line) - 1] == ';') {
//            if (count < MAX_COMMANDS) {
//                commands[count] = malloc(strlen(line) + 1);
//                strcpy(commands[count], line);
//                count++;
//            } else {
//                printf("\nNumero maximo de comandos atingido.");
//                break;
//            }
//        }else{
//            printf("\nO comando precisa ter ; no final!");
//        }
//    }
//    fclose(file);
//    for (int i = 0; i < count; i++) {
//        fila_iniciar(fila, commands[i]);
//        free(commands[i]);
//    }
//}
//
