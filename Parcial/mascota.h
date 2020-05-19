#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "genericas.h"
#include "cliente.h"

#define MAS_LENNOMBRE 51
#define MAS_LENRAZA 51

#define MAS_LENRAZA_PERRO 4
#define MAS_LENRAZA_GATO 3
#define MAS_LENRAZA_RARO 7

static const char MAS_TIPOS[3][6] = {"PERRO", "GATO", "RARO"};
static const char MAS_RAZA_PERRO[MAS_LENRAZA_PERRO][15] = {"Pitbull", "Labrador", "Salchicha", "Bulldog"};
static const char MAS_RAZA_GATO[MAS_LENRAZA_GATO][10] = {"SIAMES", "ANGORA", "GATO PERSA"};
static const char MAS_RAZA_RARO[MAS_LENRAZA_RARO][10] = {"REPTIL","IGUANA", "CARPINCHO", "PELICANO", "AGUILA", "RATON", "RATA"};
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
int masc_Add(eMascota* listMascotas,int lenMascotas, int* id, eCliente* listCliente, int lenCliente);
int masc_Modify(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente);
int masc_Remove(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente);
int masc_Sort(eMascota* list, int len);
int masc_PrintList(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente);
int masc_findIndexEmpty(eMascota* list, int len);
int masc_findById(eMascota* list, int len,int codigo);
void masc_swapForSort(eMascota* list, int iControl);
int masc_getOneData(eMascota* getOne, int id, char* msg, eCliente* listCliente, int lenCliente);
int masc_getOneDataModify(eMascota* getOne, int id, char* msg);
///INFORMES
int masc_PrintForType(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente);

/// PUNTO 4 BIS
int masc_findRazaByType(int tipo, char* raza);
void masc_printRazas(int tipo);
