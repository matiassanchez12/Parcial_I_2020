#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "genericas.h"
#include "cliente.h"

#define MAS_LENNOMBRE 51
#define MAS_LENRAZA 51

static const char MAS_TIPOS[3][6] = {"PERRO", "GATO", "RARO"};

typedef struct
{
    int id;
    char nombre[MAS_LENNOMBRE];
    char raza[MAS_LENRAZA];
    int tipo;
    int edad;
    char sexo;
    float peso;
    int idDuenio;
    int isEmpty; /// 0 = LLENO 1 = VACIO
}eMascota;

void masc_menuEntity(char* msgTitleMenu, eMascota* list, int lenghtList, int* id, eCliente* listCliente, int lenCliente);

void masc_hardCodear(eMascota* list, int tam);
int masc_initializer(eMascota* list, int len);
int masc_Add(eMascota* list,int len, int* id, eCliente* listCliente, int lenCliente);
int masc_Modify(eMascota* list, int len, eCliente* listCliente, int lenCliente);
int masc_Remove(eMascota* list, int len, eCliente* listCliente, int lenCliente);
int masc_Sort(eMascota* list, int len);
int masc_PrintList(eMascota* list, int len, eCliente* listCliente, int lenCliente);
int masc_findIndexEmpty(eMascota* list, int len);
int masc_findById(eMascota* list, int len,int codigo);
void masc_swapForSort(eMascota* list, int iControl);
int masc_getOneData(eMascota* getOne, int id, char* msg, eCliente* listCliente, int lenCliente);
int masc_getOneDataModify(eMascota* getOne, int id, char* msg);

int masc_findIdInCliente(eCliente* list, int len, int idCliente);
