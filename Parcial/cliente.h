#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "genericas.h"

#define CLI_LENNOMBRE 15
#define CLI_LENAPELLIDO 15
#define CLI_LENLOCALIDAD 15
#define CLI_LENTELEFONO 10

typedef struct
{
    int id;
    char nombre[CLI_LENNOMBRE];
    char apellido[CLI_LENAPELLIDO];
    char localidad[CLI_LENLOCALIDAD];
    char telefono[CLI_LENTELEFONO];
    int edad;
    char sexo;
    int isEmpty; /// 0 = LLENO 1 = VACIO
}eCliente;

void cli_menuEntity(char* msgTitleMenu, eCliente* list, int lenghtList, int* id);

void cli_hardCodear(eCliente* list, int tam);
int cli_initializer(eCliente* list, int len);
int cli_Add(eCliente* list,int len, int* id);
int cli_Modify(eCliente* list, int len);
int cli_Remove(eCliente* list, int len);
int cli_PrintList(eCliente* list, int len);
int cli_findIndexEmpty(eCliente* list, int len);
int cli_findById(eCliente* list, int len,int codigo);
void cli_swapForSort(eCliente* list, int iControl);
int cli_getOneData(eCliente* getOne, int id, char* msg);
