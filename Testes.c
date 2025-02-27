//
// Created by nando on 23/01/2025.
//

//void teste(){
//    strcat(destructuring_command[2], destructuring_command[3]);
//    strcat(destructuring_command[2], destructuring_command[4]);
//
//    strcat(destructuring_command[5], destructuring_command[6]);
//    strcat(destructuring_command[5], destructuring_command[7]);

//    char values[20];
//
//    strcpy(values,destructuring_command[5]);
//
//    char destructuring_values[6][255];
//    char *token1 = strtok(values, "(), ");
//    count = 0;
//    while (token1 != NULL && count < 6) {
//        strcpy(destructuring_values[count], token1);
//        count++;
//        token1 = strtok(NULL, "(), ");
//    }
//
//    int command = -1;
//
//    char commands[][255] = {
//            "insert",
//            "select",
//            "update",
//            "delete"
//    };
//    char tables_names[][255] = {
//            "pessoa(codigo,nome,fone)",
//            "pet(codigo,codigo_cli,nome,codigo_tipo)",
//            "tipo_pet(codigo,descricao)"
//    };

//    printf("%s\n", destructuring_command[0]);
//    printf("%s %s %d %d\n", destructuring_command[2], tables_names[0],
//           strlen(destructuring_command[2]), strlen(tables_names[0]));
//    if(strcmp(destructuring_command[0], commands[0]) == 0 && strcmp(destructuring_command[1], "into") == 0){
//        if(strlen(destructuring_command[2]) == strlen(tables_names[0])){
//            if(strlen(destructuring_values[0]) ==  strlen("values")){
//                int id = atoi(destructuring_values[1]);
//                char name[100];
//                char number_phone[20];
//                int j = 0;
//                for (int i = 0; i < strlen(destructuring_values[2]); i++) {
//                    if (destructuring_values[2][i] != '\'') {
//                        name[j++] = destructuring_values[2][i];
//                    }
//                }
//                name[j] = '\0';
//
//                j = 0;
//                for (int i = 0; i < strlen(destructuring_values[3]); i++) {
//                    if (destructuring_values[3][i] != '\'') {
//                        number_phone[j++] = destructuring_values[3][i];
//                    }
//                }
//                number_phone[j] = '\0';
//                strcpy(number_phone,  destructuring_values[3]);
//                printf("Insert Into pessoa(codigo,nome,fone) values(%d, %s, %s)!\n", id, name, number_phone);
//            }
//        }else if(strlen(destructuring_command[2]) == strlen(tables_names[1])){
//            printf("Insert into pet(...)\n");
//        }else{
//            printf("Insert into tipo_pet(...)\n");
//        }
//        command = 0;
//    }
//    if (command >= 0) {
//        printf("The command is %s\n", commands[command]);
//    } else {
//        printf("Invalid Command!\n");
//    }

//    printf("Tokens extraídos:\n");
//    for (int i = 0; i < count; i++) {
//        printf("[%d]: %s\n", i, destructuring_command[i]);
//    }

//void inserir_final(struct columns columns[]){
//    for(int i = 0; i < 5; i++){
//        if(columns[i].filled == 1){
//            printf("%s: %s\n", columns[i].name, columns[i].value);
//        }
//    }
//}

//    printf("Codigo: %s\nNome: %s\nData de nascimento: %s\nFone: %s\nEndereco: %s\n",
//           nova_pessoa.codigo, nova_pessoa.nome, nova_pessoa.data_nascimento, nova_pessoa.fone, nova_pessoa.endereco);


//};


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define MAX_COLUMNS 10
//#define MAX_LENGTH 255
//
//struct pessoa{
//    int codigo;
//    char nome[255];
//    char fone[255];
//    char endereco[255];
//    char data_nascimento[255];
//};
//
//struct no_pessoa{
//    struct no_pessoa *prox;
//    struct pessoa pessoa;
//};
//
//struct columns{
//    char name[20];
//    char value[30];
//    int filled;
//};
//
//void inserir_final(struct columns columns[], struct no_pessoa **lista) {
//    struct no_pessoa *nova_pessoa = malloc(sizeof(struct no_pessoa));
//    if (!nova_pessoa) {
//        fprintf(stderr, "Erro: Falha ao alocar memória.\n");
//        return;
//    }
//
//    memset(&nova_pessoa->pessoa, 0, sizeof(nova_pessoa->pessoa));
//
//    for (int i = 0; i < 5; i++) {
//        if (!columns[i].filled) continue;
//
//        if (strcmp(columns[i].name, "codigo") == 0) {
//            nova_pessoa->pessoa.codigo = atoi(columns[i].value);
//        } else if (strcmp(columns[i].name, "nome") == 0) {
//            strncpy(nova_pessoa->pessoa.nome, columns[i].value, sizeof(nova_pessoa->pessoa.nome) - 1);
//        } else if (strcmp(columns[i].name, "fone") == 0) {
//            strncpy(nova_pessoa->pessoa.fone, columns[i].value, sizeof(nova_pessoa->pessoa.fone) - 1);
//        } else if (strcmp(columns[i].name, "endereco") == 0) {
//            strncpy(nova_pessoa->pessoa.endereco, columns[i].value, sizeof(nova_pessoa->pessoa.endereco) - 1);
//        } else if (strcmp(columns[i].name, "data_nascimento") == 0) {
//            strncpy(nova_pessoa->pessoa.data_nascimento, columns[i].value, sizeof(nova_pessoa->pessoa.data_nascimento) - 1);
//        }
//    }
//
//    nova_pessoa->prox = *lista;
//    *lista = nova_pessoa;
//}
//
//
//void imprir_lista(struct no_pessoa **l){
//    struct no_pessoa *aux = *l;
//
//    if(!aux) return;
//
//    printf("---------Valores:---------\n");
//    while(aux != NULL){
//        printf("Codigo: %d\n", aux->pessoa.codigo);
//        printf("Nome: %s\n", aux->pessoa.nome);
//        printf("Data de nascimento: %s\n", aux->pessoa.data_nascimento);
//        printf("Fone: %s\n", aux->pessoa.fone);
//        printf("Endereco: %s\n", aux->pessoa.endereco);
//        printf("--------------------------\n");
//        aux = aux->prox;
//    }
//}
//
//
//void insert(char *command, struct no_pessoa **l){
//
//    struct columns columns[5] = {0};
//
//    char tables[][20] = {
//            "pessoa",
//            "pet",
//            "tipo_pet"
//    };
//
//    char destructuring_command[20][255];
//    int count = 0;
//
//    char *token = strtok(command, "(),' ");
//    while (token != NULL && count < 20) {
//        strcpy(destructuring_command[count], token);
//        count++;
//        token = strtok(NULL, "(),' ");
//    }
//
//    if(strcmp(destructuring_command[1], "into") == 0){
//        for(int j = 0; j < 3; j++){
//            if(strcmp(destructuring_command[2], tables[j]) == 0) {
//                if(strcmp(destructuring_command[6], "values") == 0){
//                    count = 0;
//                    for(int k = 3; k < 6; k++){
//                        columns[count].filled = 1;
//                        strcpy(columns[count].name,destructuring_command[k]);
//                        strcpy(columns[count].value,destructuring_command[k+4]);
//                        count++;
//                    }
//                }
//                if(strcmp(destructuring_command[7], "values") == 0){
//                    count = 0;
//                    for(int k = 3; k < 7; k++){
//                        columns[count].filled = 1;
//                        strcpy(columns[count].name,destructuring_command[k]);
//                        strcpy(columns[count].value,destructuring_command[k+5]);
//                        count++;
//                    }
//                }
//                if(strcmp(destructuring_command[8], "values") == 0){
//                    count = 0;
//                    for(int k = 3; k < 8; k++){
//                        columns[count].filled = 1;
//                        strcpy(columns[count].name,destructuring_command[k]);
//                        strcpy(columns[count].value,destructuring_command[k+6]);
//                        count++;
//                    }
//                }
//            }
//        }
//    }
//
//    inserir_final(columns, l);
//}
//
//
//void select(char *command){
//    char tables[][100] = {
//            "pessoa(codigo, nome, fone, endereco, data_nascimento)",
//            "pet(codigo, codigo_pes, nome, codigo_tipo)",
//            "tipo_pet(codigo, nome)"
//    };
//    printf("Comando Select: %s", command);
//}
//
//void update(char *command){
//    char tables[][100] = {
//            "pessoa(codigo, nome, fone, endereco, data_nascimento)",
//            "pet(codigo, codigo_pes, nome, codigo_tipo)",
//            "tipo_pet(codigo, nome)"
//    };
//    printf("Comando Update: %s", command);
//}
//
//void delete(char *command){
//    char tables[][100] = {
//            "pessoa(codigo, nome, fone, endereco, data_nascimento)",
//            "pet(codigo, codigo_pes, nome, codigo_tipo)",
//            "tipo_pet(codigo, nome)"
//    };
//    printf("Comando Delete: %s", command);
//}
//
//void destructuring_command(char *command, struct no_pessoa **l){
//    char destructuring_command[20][200];
//    int count = 0;
//
//    char command_copy[sizeof(command)];
//    strcpy(command_copy, command);
//
//    char *token = strtok(command_copy, " ");
//    while (token != NULL && count < 20) {
//        strcpy(destructuring_command[count], token);
//        count++;
//        token = strtok(NULL, " ");
//    }
//
//    if(strcmp(destructuring_command[0], "insert") == 0){
//        insert(command, l);
//    }else if(strcmp(destructuring_command[0], "select") == 0){
//        select(command);
//    }else if(strcmp(destructuring_command[0], "update") == 0){
//        update(command);
//    }else if(strcmp(destructuring_command[0], "delete") == 0){
//        delete(command);
//    }else{
//        printf("Comando Inválido!");
//    }
//}
//
//
//int main() {
//
//    struct no_pessoa *l = NULL;
//
//    char command1[] = "insert into pessoa(codigo, nome, data_nascimento, endereco) values(1, 'Maria', '27/07/2002', 'Natal');";
//    char command2[] = "insert into pessoa(codigo, nome, fone, endereco, data_nascimento) values(2, 'Paulo', 'Fortaleza', '99990000', '14/02/2001');";
//    char command3[] = "insert into pessoa(codigo, nome, fone, endereco, data_nascimento) values(3, 'Roberta', '14/02/2001', '77779999', '08/01/2000');";
//
//    destructuring_command(command1, &l);
//    destructuring_command(command2, &l);
//    destructuring_command(command3, &l);
//
//    imprir_lista(&l);
//
//
//    return 0;
//}

//    char *token = strtok(command, "(),' ");
//    while (token != NULL && count < 20) {
//        strcpy(destructuring_command[count], token);
//        count++;
//        token = strtok(NULL, "(),' ");
//    }

//    if(strcmp(destructuring_command[1], "into") == 0){
//        for(int j = 0; j < 3; j++){
//            if(strcmp(destructuring_command[2], tables[j]) == 0) {
//                if(strcmp(destructuring_command[6], "values") == 0){
//                    count = 0;
//                    for(int k = 3; k < 6; k++){
//                        columns[count].filled = 1;
//                        strcpy(columns[count].name,destructuring_command[k]);
//                        strcpy(columns[count].value,destructuring_command[k+4]);
//                        count++;
//                    }
//                }
//                if(strcmp(destructuring_command[7], "values") == 0){
//                    count = 0;
//                    for(int k = 3; k < 7; k++){
//                        columns[count].filled = 1;
//                        strcpy(columns[count].name,destructuring_command[k]);
//                        strcpy(columns[count].value,destructuring_command[k+5]);
//                        count++;
//                    }
//                }
//                if(strcmp(destructuring_command[8], "values") == 0){
//                    count = 0;
//                    for(int k = 3; k < 8; k++){
//                        columns[count].filled = 1;
//                        strcpy(columns[count].name,destructuring_command[k]);
//                        strcpy(columns[count].value,destructuring_command[k+6]);
//                        count++;
//                    }
//                }
//            }
//        }
//    }

//int count2=0;
//for(int i = index+2; i < count-1; i++){
//strcpy(values_request[i], destructuring_command[i]);
//printf("%s\n", values_request[i]);
//count2++;
//}
//
//
//for(int i = 0; i < 3; i++){
//if(strcmp(destructuring_command[2], tables[i].name) == 0){
//for(int j = 0; j < count2; j++){
//strcpy(columns_request[j], destructuring_command[3+j]);
//printf("%s\n", columns_request[j]);
//}
//}
//}
//
//    for(int i = 0; i < count2; i++){
//        printf("%s: %s\n", columns_request[i], values_request[i]);
//    }


//    char *token = strtok(command, "(),' ");
//    while (token != NULL && count < 30) {
//        strcpy(destructuring_command[count], token);
//        if(count == 2){
//            for(int i = 0; i < 3; i++){
//                if(strcmp(destructuring_command[count], tables[i].name) == 0){
//                    int j = 0;
//                    for(int k = count+1; k < (count + tables[i].numbers_of_columns + 1); k++){
//                        strcpy(destructuring_command[k], tables[i].columns[j].name);
//                        token = strtok(NULL, "(),' ");
//                        j++;
//                    }
//                    count += tables[i].numbers_of_columns;
//                    index = count;
//                }
//            }
//        }
//        count++;
//        token = strtok(NULL, "(),' ");
//    }
//
//    printf("\n\n");


//void fila_executar_segundo_teste(struct fila_comando *fila, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet);

//void fila_executar_segundo_teste(struct fila_comando *fila, struct no_pessoa **pessoas, struct no_pet **pets, struct no_tipo_pet **tipos_pet){
//    if(!fila) return;
//    struct fila_comando *aux = fila;
//    destructuring_command(aux->comando, pessoas, pets, tipos_pet);
//    fila = fila->prox;
//    free(aux);
//}

//void fila_imprimir(struct fila_comando *fila);

//void fila_imprimir(struct fila_comando *fila) {
//    if (fila == NULL) {
//        printf("A fila esta vazia.\n");
//        return;
//    }
//    struct fila_comando *aux = fila;
//    while (aux != NULL) {
//        printf("Comando: %s\n", aux->comando);
//        aux = aux->prox;
//    }
//}

//void delete_fila(struct fila_comando **fila);


//void delete_fila(struct fila_comando **fila) {
//    struct fila_comando *aux;
//    while (*fila) {
//        aux = *fila;
//        *fila = (*fila)->prox;
//        free(aux);
//    }
//}

//struct columns columns[5] = {0};
//char tables[][20] = {
//        "pessoa",
//        "pet",
//        "tipo_pet"
//};
//char destructuring_command[20][255];
//int count = 0;
//int intervalo = 0;
//char *token = strtok(command, "(),' ");
//while (token != NULL && count < 20) {
//strcpy(destructuring_command[count], token);
//count++;
//token = strtok(NULL, "(),' ");
//}
//for(int i = 3; i < count; i++){
//if(strcmp(destructuring_command[i], "values") == 0 || strcmp(destructuring_command[i], "VALUES") == 0){
//break;
//}
//intervalo++;
//}
//if(strcmp(destructuring_command[1], "into") == 0 || strcmp(destructuring_command[1], "INTO") == 0){
//for(int j = 0; j < 3; j++){
//if(strcmp(destructuring_command[2], tables[j]) == 0) {
//count = 0;
//for(int k = 3; k < intervalo + 3; k++){
//columns[count].filled = 1;
//strcpy(columns[count].name,destructuring_command[k]);
//strcpy(columns[count].value,destructuring_command[k+intervalo+1]);
//count++;
//}
//}
//}
//}
//}else{
//printf("Comando Invalido: error: data!");


//void fila_imprimir(struct fila_comando *fila) {
//    if (fila == NULL) {
//        printf("A fila esta vazia.\n");
//        return;
//    }
//    struct fila_comando *aux = fila;
//    while (aux != NULL) {
//        printf("Comando: %s\n", aux->comando);
//        aux = aux->prox;
//    }
//}



//void fila_imprimir(struct fila_comando *fila);
//void ler_comandos_do_usuario1();
//void ler_do_arquivo_os_comandos_do_usuario(struct fila_comando **fila);

//void ler_comandos_do_usuario1() {
//    FILE *arquivo = fopen("arquivo_comandos.bin", "wb");
//    if (arquivo == NULL) {
//        perror("Erro ao abrir arquivo!");
//        return;
//    }
//    printf("Arquivo binario aberto para escrita!\n");
//
//    int qtd_comandos;
//    printf("Quantos comandos voce deseja inserir no Arquivo de Comando?\n");
//    printf("Digite aqui: ");
//    scanf("%d", &qtd_comandos);
//    while (getchar() != '\n');
//
//    fwrite(&qtd_comandos, sizeof(int), 1, arquivo);
//
//    Comando cmd;
//
//    for (int i = 0; i < qtd_comandos; i++) {
//        printf("Digite o comando[%d]: ", i + 1);
//        fgets(cmd.comando, sizeof(cmd.comando), stdin);
//
//        int tam = strlen(cmd.comando);
//        if (tam > 0 && cmd.comando[tam - 1] == '\n') {
//            cmd.comando[tam - 1] = '\0';
//        }
//
//        fwrite(&cmd, sizeof(Comando), 1, arquivo);
//    }
//
//    fclose(arquivo);
//    printf("Comandos salvos no arquivo com sucesso!\n");
//}

//void ler_do_arquivo_os_comandos_do_usuario(struct fila_comando **fila){
//    FILE *arquivo = fopen("arquivo_comandos.bin", "rb");
//    if (arquivo == NULL) {
//        perror("Erro ao abrir o arquivo para leitura!");
//        return;
//    }
//    printf("Arquivo binario aberto para leitura!\n");
//
//    int qtd_comandos;
//    fread(&qtd_comandos, sizeof(int), 1, arquivo);
//    printf("\nLendo %d comandos do arquivo binario:\n", qtd_comandos);
//
//    Comando cmd;
//
//    for (int i = 0; i < qtd_comandos; i++) {
//        fread(&cmd, sizeof(Comando), 1, arquivo);
//        fila_iniciar(fila, cmd.comando);
//    }
//
//    fclose(arquivo);
//}
//
//void read_pessoa_bin(struct no_pessoa **l) {
//    FILE *arquivo_pessoas = fopen("arquivo_pessoas.bin", "rb");
//    if (!arquivo_pessoas) {
//        printf("Problema ao abrir arquivo Pessoa para leitura!\n");
//        return;
//    }
//    struct pessoa p;
//    struct no_pessoa *ultimo = NULL; // Para manter a ordem original
//    while (fread(&p, sizeof(struct pessoa), 1, arquivo_pessoas) == 1) {
//        struct no_pessoa *person_read_from_file = malloc(sizeof(struct no_pessoa));
//        if (!person_read_from_file) {
//            perror("Erro ao alocar memória");
//            fclose(arquivo_pessoas);
//            return;
//        }
//        memcpy(&person_read_from_file->pessoa, &p, sizeof(struct pessoa));
//        person_read_from_file->prox = NULL;
//        if (*l == NULL) {
//            *l = person_read_from_file;
//            ultimo = person_read_from_file;
//        } else {
//            ultimo->prox = person_read_from_file;
//            ultimo = person_read_from_file;
//        }
//    }
//    fclose(arquivo_pessoas);
//}

//void read_tipo_pet_bin(struct no_tipo_pet **l){
//    FILE *arquivo_tipo_pet = fopen("arquivo_tipos_pet.bin", "rb");
//    if (!arquivo_tipo_pet) {
//        printf("Problema ao abrir arquivo Tipo Pet para leitura!\n");
//        return;
//    }
//    struct tipo_pet p;
//    struct no_tipo_pet *ultimo = NULL;
//    while (fread(&p, sizeof(struct tipo_pet), 1, arquivo_tipo_pet) == 1) {
//        struct no_tipo_pet *type_pet_read_from_file = malloc(sizeof(struct no_tipo_pet));
//        if (!type_pet_read_from_file) {
//            printf("Erro ao alocar memória");
//            fclose(arquivo_tipo_pet);
//            return;
//        }
//        memcpy(&type_pet_read_from_file->tipo_pet, &p, sizeof(struct tipo_pet));
//        type_pet_read_from_file->prox = NULL;
//        type_pet_read_from_file->ant = ultimo;
//        if (*l == NULL) {
//            *l = type_pet_read_from_file;
//            ultimo = type_pet_read_from_file;
//        } else {
//            ultimo->prox = type_pet_read_from_file;
//            ultimo = type_pet_read_from_file;
//        }
//    }
//}

//void read_pet_bin(struct no_pet **l){
//    FILE *arquivo_pet = fopen("arquivo_pets.bin", "rb");
//    if (!arquivo_pet) {
//        printf("Problema ao abrir arquivo Pet para leitura!\n");
//        return;
//    }
//    struct pet p;
//    struct no_pet *ultimo = NULL;
//    while (fread(&p, sizeof(struct pet), 1, arquivo_pet) == 1) {
//        struct no_pet *pet_read_from_file = malloc(sizeof(struct no_pet));
//        if (!pet_read_from_file) {
//            perror("Erro ao alocar memória");
//            fclose(arquivo_pet);
//            return;
//        }
//        memcpy(&pet_read_from_file->pet, &p, sizeof(struct pet));
//        pet_read_from_file->prox = NULL;
//
//        if (*l == NULL) {
//            *l = pet_read_from_file;
//            ultimo = pet_read_from_file;
//        } else {
//            ultimo->prox = pet_read_from_file;
//            ultimo = pet_read_from_file;
//        }
//    }
//}

//void delete_pessoa(struct no_pessoa **pessoas, struct no_pet **pets, char *column_to_be_deleted, char *value_to_be_deleted) {
//    if (!(*pessoas)) return;
//    struct no_pessoa *aux = *pessoas, *ant = NULL;
//    while (aux != NULL &&
//           ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pessoa.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pessoa.nome, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "fone") == 0 && strcmp(aux->pessoa.fone, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "endereco") == 0 && strcmp(aux->pessoa.endereco, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, value_to_be_deleted) == 0))) {
//
//        *pessoas = aux->prox;
//        free(aux);
//        return;
//    }
//    while (aux != NULL) {
//        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->pessoa.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->pessoa.nome, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "fone") == 0 && strcmp(aux->pessoa.fone, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "endereco") == 0 && strcmp(aux->pessoa.endereco, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "data_nascimento") == 0 && strcmp(aux->pessoa.data_nascimento, value_to_be_deleted) == 0)) {
//            if(verificar_pelo_codigo_se_pode_deletar_pessoa(pets, aux->pessoa.codigo)){
//                ant->prox = aux->prox;
//                free(aux);
//                return;
//            }else{
//                printf("\nNao foi possivel deletar pessoas porque ela tem pet!\n");
//            }
//        }
//        ant = aux;
//        aux = aux->prox;
//    }
//    printf("Erro ao DELETAR pessoa com %s igual a %s\n", column_to_be_deleted, value_to_be_deleted);
//}

//void delete_tipo_pet(struct no_tipo_pet **tipos_pet, char *column_to_be_deleted, char *value_to_be_deleted){
//    if(!(*tipos_pet)) return;
//    struct no_tipo_pet *aux = *tipos_pet, *ant = NULL;
//    while (aux != NULL &&
//           ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->tipo_pet.nome, value_to_be_deleted) == 0))) {
//        *tipos_pet = aux->prox;
//        free(aux);
//        return;
//    }
//    while (aux != NULL) {
//        if ((strcmp(column_to_be_deleted, "codigo") == 0 && strcmp(aux->tipo_pet.codigo, value_to_be_deleted) == 0) ||
//            (strcmp(column_to_be_deleted, "nome") == 0 && strcmp(aux->tipo_pet.nome, value_to_be_deleted) == 0))  {
//            ant->prox = aux->prox;
//            free(aux);
//            return;
//        }
//        ant = aux;
//        aux = aux->prox;
//    }
//    printf("Erro ao DELETAR tipo pet com %s igual a %s\n", column_to_be_deleted, value_to_be_deleted);
//}

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

//void ler_comandos_do_usuario1(struct fila_comando **fila){
//    FILE *file = fopen("comandos.txt", "r");  // Abre o arquivo para leitura
//    if (!file) {
//        perror("Erro ao abrir o arquivo");
//        return;
//    }
//    char *sql_commands[MAX_CMDS];  // Array para armazenar comandos SQL
//    char line[MAX_LINE];
//    int cmd_index = 0;
//    sql_commands[cmd_index] = malloc(MAX_LINE);
//    sql_commands[cmd_index][0] = '\0';  // Inicializa string vazia
//    while (fgets(line, sizeof(line), file)) {
//        if (line[0] == '\n' || line[0] == '\r') continue;  // Ignora linhas vazias
//        // Remove o caractere de nova linha (\n)
//        line[strcspn(line, "\r\n")] = '\0';
//        strcat(sql_commands[cmd_index], line); // Concatena linha ao comando atual
//        // Se encontrar um ponto-e-vírgula, significa que o comando terminou
//        if (strchr(line, ';')) {
//            if (strchr(sql_commands[cmd_index], ';') == NULL) {
//                printf("Comando inválido (sem ponto-e-vírgula). Pulando...\n");
//                sql_commands[cmd_index][0] = '\0';
//                continue;
//            }
//            cmd_index++;
//            sql_commands[cmd_index] = malloc(MAX_LINE);
//            sql_commands[cmd_index][0] = '\0';
//        }
//    }
//    fclose(file);
//    // Exibe os comandos SQL lidos
//    for (int i = 0; i < cmd_index; i++) {
//        fila_iniciar(fila, sql_commands[i]);
//        free(sql_commands[i]);  // Libera memória alocada
//    }
//}

//void imprimir_todas_as_listas(struct no_pessoa *pessoas, struct no_pet *pets, struct no_tipo_pet *tipos_pet);