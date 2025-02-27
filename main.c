#include "Utils.h"

int main() {

    struct no_pessoa *pessoas = NULL;
    struct no_pet *pets = NULL;
    struct no_tipo_pet *tipos_pet = NULL;
    struct fila_comando *fila_comandos = NULL;

    executar_comandos(&pessoas, &pets, &tipos_pet, &fila_comandos);

    return 0;
}