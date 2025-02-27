#include "Utils.h"

void fila_iniciar(struct fila_comando **fila, char *comando){
    struct fila_comando *new_comando = malloc(sizeof(struct fila_comando));
    if (new_comando == NULL) {
        printf("Erro ao alocar memória para o novo comando.\n");
        return;
    }
    strcpy(new_comando->comando.comando, comando);
    new_comando->prox = NULL;
    if(!(*fila)){
        *fila = new_comando;
    }else{
        struct fila_comando *aux = *fila;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = new_comando;
    }
}

void fila_executar(struct fila_comando *fila, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
    struct fila_comando *aux;
    while (fila != NULL) {
        aux = fila;
        destructuring_command(aux->comando.comando, pessoas, pets, tipos_pet);
        fila = (fila)->prox;
        free(aux);
    }
}

void write_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
    write_pessoas_bin(pessoas);
    write_pet_bin(pets);
    write_tipo_pet_bin(tipos_pet);
}

void read_all_files(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
    read_pessoa_bin(pessoas);
    read_pet_bin(pets);
    read_tipo_pet_bin(tipos_pet);
}

void ler_comandos_do_usuario(struct fila_comando **fila){
    FILE *file;
    char line[MAX_LENGTH];
    char *commands[MAX_COMMANDS];
    int count = 0;
    file = fopen("comandos.txt", "r");
    if (file == NULL) {
        printf("\nErro ao abrir o arquivo de comandos. Ele sera criado. Insira os comandos nele e tente novamente");
        file = fopen("comandos.txt", "w");
        return;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        if (line[strlen(line) - 1] == ';') {
            if (count < MAX_COMMANDS) {
                commands[count] = malloc(strlen(line) + 1);
                strcpy(commands[count], line);
                count++;
            } else {
                printf("\nNumero maximo de comandos atingido.");
                break;
            }
        }
    }
    fclose(file);
    for (int i = 0; i < count; i++) {
        fila_iniciar(fila, commands[i]);
        free(commands[i]);
    }
}

void liberar_todas_as_listas(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
    liberar_lista_pessoas(pessoas);
    liberar_lista_pets(pets);
    liberar_lista_tipo_pet(tipos_pet);
}

void lista_filtrada_a_ser_ordenada(
        struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets,
        char *tabela_order_by,
        char *coluna_a_ser_filtrada,
        char *valor_a_ser_filtrado,
        char *coluna_a_ser_ordenada) {

    if (strcmp(tabela_order_by, "pessoa") == 0) {
        struct no_pessoa *lista_a_ser_filtrada = NULL;
        struct no_pessoa *aux = *pessoas;

        while (aux != NULL) {
            if ((strcmp(coluna_a_ser_filtrada, "codigo") == 0 && strcmp(aux->pessoa.codigo, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "nome") == 0 && strcmp(aux->pessoa.nome, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "fone") == 0 && strcmp(aux->pessoa.fone, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "endereco") == 0 && strcmp(aux->pessoa.endereco, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, valor_a_ser_filtrado) == 0)) {

                struct no_pessoa *novo = malloc(sizeof(struct no_pessoa));
                novo->pessoa = aux->pessoa;
                novo->prox = lista_a_ser_filtrada;
                if (lista_a_ser_filtrada) lista_a_ser_filtrada->ant = novo;
                lista_a_ser_filtrada = novo;
            }
            aux = aux->prox;
        }
        select_order_pessoa(&lista_a_ser_filtrada, coluna_a_ser_ordenada);
        liberar_lista_pessoas(&lista_a_ser_filtrada);
    } else if (strcmp(tabela_order_by, "pet") == 0) {
        struct no_pet *lista_filtrada_pet = NULL;
        struct no_pet *aux = *pets;
        while (aux != NULL) {
            if ((strcmp(coluna_a_ser_filtrada, "codigo") == 0 && strcmp(aux->pet.codigo, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "nome") == 0 && strcmp(aux->pet.nome, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "codigo_pes") == 0 && strcmp(aux->pet.codigo_pes, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "codigo_tipo") == 0 && strcmp(aux->pet.codigo_tipo, valor_a_ser_filtrado) == 0)) {
                struct no_pet *novo = malloc(sizeof(struct no_pet));
                novo->pet = aux->pet;
                novo->prox = lista_filtrada_pet;
                lista_filtrada_pet = novo;
            }
            aux = aux->prox;
        }
        select_order_pet(&lista_filtrada_pet, coluna_a_ser_ordenada);
        liberar_lista_pets(&lista_filtrada_pet);
    } else if (strcmp(tabela_order_by, "tipo_pet") == 0) {
        struct no_tipo_pet *lista_filtrada_tipo = NULL;
        struct no_tipo_pet *aux = *tipo_pets;
        while (aux != NULL) {
            if ((strcmp(coluna_a_ser_filtrada, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, valor_a_ser_filtrado) == 0) ||
                (strcmp(coluna_a_ser_filtrada, "nome") == 0 && strcmp(aux->tipo_pet.nome, valor_a_ser_filtrado) == 0)) {
                struct no_tipo_pet *novo = malloc(sizeof(struct no_tipo_pet));
                novo->tipo_pet = aux->tipo_pet;
                novo->prox = lista_filtrada_tipo;
                lista_filtrada_tipo = novo;
            }
            aux = aux->prox;
        }
        select_order_tipo_pet(&lista_filtrada_tipo, coluna_a_ser_ordenada);
        liberar_lista_tipo_pet(&lista_filtrada_tipo);
    } else {
        printf("\nErro ao filtrar lista!");
    }
}

void insert(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
    struct columns columns[5] = {0};
    char tables[][20] = {
            "pessoa",
            "pet",
            "tipo_pet"
    };
    char destructuring_command[20][255];
    char cpy_comando[255];
    strcpy(cpy_comando, command);
    int count = 0, intervalo = 0, verificated = 0;
    char *token = strtok(cpy_comando, "(),' ");
    while (token != NULL && count < 20) {
        strcpy(destructuring_command[count], token);
        if (strcmp(destructuring_command[count], "values") == 0 || strcmp(destructuring_command[count], "VALUES") == 0) {
            for(int i = 0; i < count; i++){
                if(strcmp(destructuring_command[i], "pessoa") == 0){
                    verificated = 1;
                }
            }
            if(verificated){
                count++;
                break;
            }
        }
        count++;
        token = strtok(NULL, "(),' ");
    }
    for(int i = 3; i < count; i++){
        if(strcmp(destructuring_command[i], "values") == 0 || strcmp(destructuring_command[i], "VALUES") == 0){
            break;
        }
        intervalo++;
    }
    if(strcmp(destructuring_command[2], "pessoa") == 0){
        token = strtok(NULL, "()'");
        while (token != NULL && count < 20) {
            strcpy(destructuring_command[count], token);

            count++;
            token = strtok(NULL, "()'");
        }
        for (int i = intervalo + 4; i < count; i++) {
            if (destructuring_command[i][0] == ',' && strlen(destructuring_command[i]) <= 2) {
                for (int j = i; j < count - 1; j++) {
                    strcpy(destructuring_command[j], destructuring_command[j + 1]);
                }
                count--;
                i--;
            }
        }
    }
    if(strcmp(destructuring_command[1], "into") == 0 || strcmp(destructuring_command[1], "INTO") == 0){
        for(int j = 0; j < 3; j++){
            if(strcmp(destructuring_command[2], tables[j]) == 0) {
                count = 0;
                for(int k = 3; k < intervalo + 3; k++){
                    columns[count].filled = 1;
                    strcpy(columns[count].name,destructuring_command[k]);
                    strcpy(columns[count].value,destructuring_command[k+intervalo+1]);
                    count++;
                }
            }
        }
    }
    if(strcmp(destructuring_command[2], "pessoa") == 0) {
        for (int i = 0; i < intervalo; i++) {
            if (strcmp(columns[i].name, "codigo") == 0) {
                int len = strlen(columns[i].value);
                int writeIndex = 0;
                for (int j = 0; j < len; j++) {
                    if (columns[i].value[j] != ',' && columns[i].value[j] != ' ') {
                        columns[i].value[writeIndex++] = columns[i].value[j];
                    }
                }
                columns[i].value[writeIndex] = '\0';
            }
        }
    }
    if(strcmp(destructuring_command[2], "pessoa") == 0){
        inserir_pessoa(columns, pessoas);
    }else if(strcmp(destructuring_command[2], "pet") == 0){
        inserir_pet(columns, pets, pessoas, tipo_pets);
    }else{
        inserir_tipo_pet(columns, tipo_pets);
    }
}

void select(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
    char destructuring_command[20][255];
    int count = 0;

    char *token = strtok(command, "(),'; ");
    while (token != NULL && count < 20) {
        strcpy(destructuring_command[count], token);
        count++;
        token = strtok(NULL, "(),'; ");
    }

    if(count == 4){
        if(strcmp(destructuring_command[3], "pessoa") == 0){
            imprimir_lista_pessoa(*pessoas);
            return;
        }else if(strcmp(destructuring_command[3], "pet") == 0){
            imprimir_lista_pet(*pets);
            return;
        }else if(strcmp(destructuring_command[3], "tipo_pet") == 0){
            imprimir_lista_tipo_pet(*tipo_pets);
            return;
        }else{
            printf("\nError ao chamar funcao select\n");
            return;
        }
    }

    if((strcmp(destructuring_command[4], "where") == 0 || strcmp(destructuring_command[4], "WHERE") == 0)
       &&(strcmp(destructuring_command[8], "order") == 0 || strcmp(destructuring_command[8], "ORDER") == 0)
       && (strcmp(destructuring_command[9], "by") == 0 || strcmp(destructuring_command[9], "BY") == 0)){
        char tabela_order_by[MAX_LENGTH];
        strcpy(tabela_order_by, destructuring_command[3]);
        char coluna_a_ser_filtrada[MAX_LENGTH];
        strcpy(coluna_a_ser_filtrada, destructuring_command[5]);
        char valor_a_ser_filtrado[MAX_LENGTH];
        strcpy(valor_a_ser_filtrado, destructuring_command[7]);
        char coluna_a_ser_ordenada[MAX_LENGTH];
        strcpy(coluna_a_ser_ordenada, destructuring_command[10]);
        lista_filtrada_a_ser_ordenada(pessoas, pets, tipo_pets,tabela_order_by, coluna_a_ser_filtrada, valor_a_ser_filtrado,coluna_a_ser_ordenada);
        return;
    }

    if((strcmp(destructuring_command[4], "order") == 0 || strcmp(destructuring_command[4], "ORDER") == 0)
       && (strcmp(destructuring_command[5], "by") == 0 || strcmp(destructuring_command[5], "BY") == 0)){
        char column_order_by[MAX_LENGTH];
        strcpy(column_order_by, destructuring_command[6]);
        if(strcmp(destructuring_command[3], "pessoa") == 0){
            select_order_pessoa(pessoas, column_order_by);
            return;
        }else if(strcmp(destructuring_command[3], "pet") == 0){
            select_order_pet(pets, column_order_by);
            return;
        }else if(strcmp(destructuring_command[3], "tipo_pet") == 0){
            select_order_tipo_pet(tipo_pets, column_order_by);
            return;
        }else{
            printf("\nERROR SELECT BY ORDER\n");
        }
    }
    char column[MAX_LENGTH];
    char value[MAX_LENGTH];
    strcpy(column, destructuring_command[5]);
    strcpy(value, destructuring_command[7]);
    if(strcmp(destructuring_command[1], "*") != 0){
        printf("\nComando Invalido Select(error: *)!");
        return;
    }
    if(strcmp(destructuring_command[2], "from") != 0 && strcmp(destructuring_command[2], "FROM") != 0){
        printf("\nComando Invalido Select(error: from or FROM)!");
        return;
    }
    if(strcmp(destructuring_command[3], "pessoa") == 0){
        select_pessoa(pessoas, column, value);
    }else if(strcmp(destructuring_command[3], "pet") == 0){
        select_pet(pets, column, value);
    }else if(strcmp(destructuring_command[3], "tipo_pet") == 0){
        select_tipo_pet(tipo_pets, column, value);
    }else{
        printf("\nError ao chamar funcao select\n");
    }
}

void update(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
    char tables[][20] = {
            "pessoa",
            "pet",
            "tipo_pet"
    };

    char pessoa_columns[][20] = {"codigo", "nome", "fone", "endereco", "data_nascimento"};
    char pet_columns[][20] = {"codigo", "nome", "codigo_pes", "codigo_tipo"};
    char tipo_pet_columns[][20] = {"codigo", "nome"};
    char coluna_pesquisada[MAX_LENGTH];
    char valor_pesquisado[MAX_LENGTH];
    char coluna_a_ser_alterada[MAX_LENGTH];
    char valor_a_ser_alterado[MAX_LENGTH];
    char destructuring_command[20][255];
    int count = 0, validated = 0;
    char *token = strtok(command, "(),'; ");
    while (token != NULL && count < 20) {
        strcpy(destructuring_command[count], token);
        count++;
        token = strtok(NULL, "(),'; ");
    }
    for(int i = 0; i < 3; i++){
        if(strcmp(destructuring_command[1], tables[i]) == 0){
            validated = 1;
        }
    }
    if(!validated){
        printf("Error: table name!");
        return;
    }
    validated = 0;
    if(strcmp(destructuring_command[1], "pessoa") == 0){
        for(int i = 0; i < 5; i++){
            if(strcmp(destructuring_command[3], pessoa_columns[i]) == 0){
                validated = 1;
            }
        }
        if(!validated){
            printf("Error: column name - pessoa!");
            return;
        }
    }
    validated = 0;
    if(strcmp(destructuring_command[1], "pet") == 0){
        for(int i = 0; i < 4; i++){
            if(strcmp(destructuring_command[3], pet_columns[i]) == 0){
                validated = 1;
            }
        }
        if(!validated){
            printf("Error: column name - pet!");
            return;
        }
    }
    validated = 0;
    if(strcmp(destructuring_command[1], "tipo_pet") == 0){
        for(int i = 0; i < 2; i++){
            if(strcmp(destructuring_command[3], tipo_pet_columns[i]) == 0){
                validated = 1;
            }
        }
        if(!validated){
            printf("Error: column name - tipo_pet!");
            return;
        }
    }
    if(strcmp(destructuring_command[6], "where") == 0 && strcmp(destructuring_command[6], "WHERE") == 0){
        printf("Error: where");
        return;
    }
    strcpy(coluna_pesquisada, destructuring_command[7]);
    strcpy(valor_pesquisado, destructuring_command[9]);
    strcpy(coluna_a_ser_alterada, destructuring_command[3]);
    strcpy(valor_a_ser_alterado, destructuring_command[5]);
    if(strcmp(destructuring_command[1], "pessoa") == 0){
        update_pessoa(pessoas,
                      coluna_pesquisada,valor_pesquisado,coluna_a_ser_alterada,valor_a_ser_alterado);
    }else if(strcmp(destructuring_command[1], "pet") == 0){
        update_pet(pets,tipo_pets,pessoas,coluna_pesquisada,valor_pesquisado,coluna_a_ser_alterada,valor_a_ser_alterado);
    }else if(strcmp(destructuring_command[1], "tipo_pet") == 0) {
        update_tipo_pet(tipo_pets,coluna_pesquisada,valor_pesquisado,coluna_a_ser_alterada,valor_a_ser_alterado);
    }else{
        printf("\nProblema ao chamar funcao update!");
    }
}

void delete(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
    char tables[][20] = {
            "pessoa",
            "pet",
            "tipo_pet"
    };
    char pessoa_columns[][20] = {"codigo", "nome", "fone", "endereco", "data_nascimento"};
    char pet_columns[][20] = {"codigo", "nome", "codigo_pes", "codigo_tipo"};
    char tipo_pet_columns[][20] = {"codigo", "nome"};
    char column_to_be_deleted[MAX_LENGTH];
    char value_to_be_deleted[MAX_LENGTH];
    char destructuring_command[20][255];
    int count = 0, validated = 0;
    char *token = strtok(command, "(),'; ");
    while (token != NULL && count < 20) {
        strcpy(destructuring_command[count], token);
        count++;
        token = strtok(NULL, "(),'; ");
    }
    if(strcmp(destructuring_command[1], "from") != 0 && strcmp(destructuring_command[1], "FROM") != 0){
        printf("\nComando Invalido Delete(erro: from)!");
        return;
    }
    for(int i = 0; i < 3; i++){
        if(strcmp(destructuring_command[2], tables[i]) == 0){
            validated = 1;
        }
    }
    if(strcmp(destructuring_command[3], "where") != 0 && strcmp(destructuring_command[3], "WHERE") != 0){
        printf("\nComando Invalido Delete(erro: where)!");
        return;
    }
    validated = 0;
    if(strcmp(destructuring_command[1], "pessoa") == 0){
        for(int i = 0; i < 5; i++){
            if(strcmp(destructuring_command[3], pessoa_columns[i]) == 0){
                validated = 1;
            }
        }
        if(!validated){
            printf("Error: column name - pessoa!");
            return;
        }
    }
    validated = 0;
    if(strcmp(destructuring_command[1], "pet") == 0){
        for(int i = 0; i < 4; i++){
            if(strcmp(destructuring_command[3], pet_columns[i]) == 0){
                validated = 1;
            }
        }
        if(!validated){
            printf("Error: column name - pet!");
            return;
        }
    }
    validated = 0;
    if(strcmp(destructuring_command[1], "tipo_pet") == 0){
        for(int i = 0; i < 2; i++){
            if(strcmp(destructuring_command[3], tipo_pet_columns[i]) == 0){
                validated = 1;
            }
        }
        if(!validated){
            printf("Error: column name - tipo_pet!");
            return;
        }
    }
    strcpy(column_to_be_deleted, destructuring_command[4]);
    strcpy(value_to_be_deleted, destructuring_command[6]);
    if(strcmp(destructuring_command[2], "pessoa") == 0){
        delete_pessoa(pessoas, pets, column_to_be_deleted, value_to_be_deleted);
    }else if(strcmp(destructuring_command[2], "pet") == 0){
        delete_pet(pets, column_to_be_deleted, value_to_be_deleted);
    }else if(strcmp(destructuring_command[2], "tipo_pet") == 0){
        delete_tipo_pet(tipo_pets, column_to_be_deleted, value_to_be_deleted);
    }else{
        printf("Comando Invalido Delete: chamada da funcao delete!");
    }
}

void destructuring_command(char *command, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipo_pets){
    char destructuring_command[2][200];
    int count = 0;

    char command_copy[255];
    strcpy(command_copy, command);

    char *token = strtok(command_copy, "(),' ");
    while (token != NULL && count < 2) {
        strcpy(destructuring_command[count], token);
        count++;
        token = strtok(NULL, "(),' ");
    }
    if(strcmp(destructuring_command[0], "insert") == 0 || strcmp(destructuring_command[0], "INSERT") == 0){
        insert(command, pessoas, pets, tipo_pets);
    }else if(strcmp(destructuring_command[0], "select") == 0 || strcmp(destructuring_command[0], "SELECT") == 0){
        select(command, pessoas, pets, tipo_pets);
    }else if(strcmp(destructuring_command[0], "update") == 0 || strcmp(destructuring_command[0], "UPDATE") == 0){
        update(command, pessoas, pets, tipo_pets);
    }else if(strcmp(destructuring_command[0], "delete") == 0 || strcmp(destructuring_command[0], "DELETE") == 0){
        delete(command, pessoas, pets, tipo_pets);
    }else{
        printf("Comando Invalido identificado na desestruturacao!");
    }
}

int verificar_codigo_pessoa(struct no_pessoa **l, char *codigo){
    struct no_pessoa *aux = *l;
    while(aux != NULL){
        if(strcmp(aux->pessoa.codigo, codigo) == 0){
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

int verificar_codigo_pet(struct no_pet **l, char *codigo){
    struct no_pet *aux = *l;
    while(aux != NULL){
        if(strcmp(aux->pet.codigo, codigo) == 0){
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}

int verificar_codigo_tipo_pet(struct no_tipo_pet **l, char *codigo){
    struct no_tipo_pet *aux = *l;
    while(aux != NULL){
        if(strcmp(aux->tipo_pet.codigo, codigo) == 0) return 0;
        aux = aux->prox;
    }
    return 1;
}

int verificar_codigo_pessoa_para_cadastro_de_pet(struct no_pessoa **l, char *codigo){
    struct no_pessoa *aux = *l;
    while(aux != NULL){
        if(strcmp(aux->pessoa.codigo, codigo) == 0) return 1;
        aux = aux->prox;
    }
    return 0;
}

int verificar_codigo_tipo_pet_para_cadastro_de_pet(struct no_tipo_pet **l, char *codigo){
    struct no_tipo_pet *aux = *l;
    while(aux != NULL){
        if(strcmp(aux->tipo_pet.codigo, codigo) == 0) return 1;
        aux = aux->prox;
    }
    return 0;
}

int verificar_pelo_codigo_se_pode_deletar_pessoa(struct no_pet **l, char *codigo){
    struct no_pet *aux = *l;
    while(aux != NULL){
        if(strcmp(aux->pet.codigo_pes, codigo) == 0) return 0;
        aux = aux->prox;
    }
    return 1;
}

int comparar_data(char *data1, char *data2) {
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;
    sscanf(data1, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(data2, "%d/%d/%d", &dia2, &mes2, &ano2);
    if (ano1 < ano2) return -1;
    if (ano1 > ano2) return 1;
    if (mes1 < mes2) return -1;
    if (mes1 > mes2) return 1;
    if (dia1 < dia2) return -1;
    if (dia1 > dia2) return 1;
    return 0;
}

void executar_comandos(struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet, struct fila_comando **fila_comando){
    read_all_files(pessoas, pets, tipos_pet);
    ler_comandos_do_usuario(fila_comando);
    fila_executar(*fila_comando, pessoas, pets, tipos_pet);
    write_all_files(pessoas, pets, tipos_pet);
    liberar_todas_as_listas(pessoas, pets, tipos_pet);
}