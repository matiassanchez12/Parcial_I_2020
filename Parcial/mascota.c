#include "mascota.h"

void masc_menuEntity(char* msgTitleMenu, eMascota* list, int lenghtList, int* id, eCliente* listCliente, int lenCliente)
{
    int option;
    do
    {
        system("cls");
        printf("%s", msgTitleMenu);
        printf("\n[1] ALTA");
        printf("\n[2] BAJA");
        printf("\n[3] MODIFICAR");
        printf("\n[4] LISTAR");
        printf("\n[5] VOLVER AL MENU PRINCIPAL\n");
        if(utn_getNumber(&option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 5, 2))
        {
            switch(option)
            {
            case 1:
                gen_checkReturnWithSwitch(masc_Add(list, lenghtList, id, listCliente, lenCliente), "\n\nAccion finalizada con exito!", "\n\nNo se logro ejecutar con exito..", "\n\nError. No hay mas espacio");
                break;
            case 2:
                gen_checkReturnWithSwitch(masc_Remove(list, lenghtList, listCliente, lenCliente), "\n\nAccion finalizada con exito!", "\n\nAccion cancelada..", "\n\nError. No se encontraron datos");
                break;
            case 3:
                gen_checkReturnWithSwitch(masc_Modify(list, lenghtList, listCliente, lenCliente), "\n\nAccion finalizada con exito!", "\n\nAccion cancelada..", "\n\nError. No se encontraron datos");
                break;
            case 4:
                gen_checkReturnWithIf(masc_PrintList(list, lenghtList, listCliente, lenCliente), "\n\nAccion finalizada con exito!", "\n\nError. No se encontraron datos");
                break;
            }
        }
        system("pause");
    }
    while(option != 5);
}
int masc_initializer(eMascota* list, int len)
{
    int retorno = 0;
    int i;
    if(list != NULL && len > 0)
    {
        retorno = 1;
        for(i = 0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;///ERROR
}
int masc_Add(eMascota* listMascotas,int lenMascotas, int* id, eCliente* listCliente, int lenCliente)
{
    int retorno = -1;
    eMascota auxMascota;
    int index;
    index = masc_findIndexEmpty(listMascotas, lenMascotas);
    printf(">>Menu de altas");
    if(listMascotas != NULL && lenMascotas > 0 && index < lenMascotas && index >= 0 && id != NULL)
    {
        retorno = 0;
        if(masc_getOneData(&auxMascota, *id, "\nIngresar datos\n", listCliente, lenCliente) == 1)
        {
            retorno = 1;
            listMascotas[index] = auxMascota;
            (*id)++;
        }
    }
    return retorno;
}
void masc_hardCodear(eMascota* list, int len)
{
    int id[11]= {1,2,3,4,5,6,7,8,9,10,11};
    char nombre[11][MAS_LENNOMBRE]= {"gata1","gata2","Perro1","Perro2","Gato3","Pitbull","Iguana","Labrador","gato4","gato5","Bulldog"};
    char raza[11][MAS_LENRAZA]= {"Siames","Siames","Salchicha","Salchicha","Siames","Pitbull","Mexicana","Labrador","Siames","Siames","Bulldog"};
    int tipo[11]= {1,1,0,0,1,0,2,0,1,1,0};
    int edad[11]= {10,3,5,3,2, 2, 3, 13, 3, 2, 10};
    char sexo[11]= {'f','f','m','m','m','m','f','m','m','m','f'};
    float peso[11]= {11.2,11.3,11.2,21.2,5.3,21.2,5.3,52.3,5.3,3.2,5.3,};
    int idDuenio[11]= {1,1,2,2,2,3,3,4,5,5,5};
    int i;
    for(i=0; i<11; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].nombre, nombre[i]);
        strcpy(list[i].raza, raza[i]);
        list[i].tipo = tipo[i];
        list[i].edad = edad[i];
        list[i].sexo = sexo[i];
        list[i].peso = peso[i];
        list[i].idDuenio = idDuenio[i];
        list[i].isEmpty = 0;
    }
}
///-1 no se pudo encontrar id, 0 accion cancelada, 1 todo ok

int masc_Modify(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente)
{
    int retorno = -1;
    char confirm;
    eMascota auxMascota;
    int id;
    int index;
    printf(">>Menu de modificaciones\n");
    masc_PrintList(listMascotas, lenMascotas, listCliente,lenCliente);
    if(listMascotas != NULL && lenMascotas > 0 && utn_getNumber(&id, "\n\nIngresar un id: ", "Error, fuera de rango.", 0, 10000, 2))
    {
        index = masc_findById(listMascotas, lenMascotas, id);
        if(index >= 0 && listMascotas[index].isEmpty != 1)
        {
            retorno = 0;
            if(masc_getOneDataModify(&auxMascota, id, "\nIngresar nuevos datos\n") == 1)
            {
                printf("\nRealizar modificacion? [s] o [n]");
                if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion:", "Error solo [s] o [n].", 's', 'n', 2)
                        && confirm == 's')
                {
                    auxMascota.idDuenio = listMascotas[index].idDuenio;
                    listMascotas[index] = auxMascota;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}

int masc_Remove(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente)
{
    int retorno = -1;
    char confirm;
    int id;
    int index;
    printf("\n>>Menu de bajas\n\n");
    masc_PrintList(listMascotas, lenMascotas, listCliente, lenCliente);
    if(listMascotas != NULL && lenMascotas > 0 && utn_getNumber(&id, "\n\nIngresar un id: ", "Error, fuera de rango.", 0, 10000, 2))
    {
        index = masc_findById(listMascotas, lenMascotas, id);
        if(index >= 0 && listMascotas[index].isEmpty != 1)
        {
            retorno = 0;
            printf("\n\nSeguro desea realizar la baja? [s] o [n] ");
            if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion: ", "Error solo [s] o [n].", 's', 'n', 2)
                    && confirm == 's')
            {
                listMascotas[index].isEmpty = 1;
                retorno = 1;
            }
        }
    }
    return retorno;
}

int masc_Sort(eMascota* list, int len)
{
    int retorno = 0;
    int flagSwap;
    int i;
    int auxiliarCmp;
    if(list !=NULL && len > 0)
    {
        retorno = 1;
        do
        {
            flagSwap = 0;
            for(i=0; i<len-1; i++)
            {
                if(list[i].isEmpty == 1 || list[i+1].isEmpty == 1)
                {
                    continue;
                }
                auxiliarCmp = strcmp(MAS_TIPOS[list[i].tipo],MAS_TIPOS[list[i+1].tipo]);
                if(auxiliarCmp > 0)
                {
                    flagSwap = 1;
                    masc_swapForSort(list, i);
                }
            }
            len--;
        }
        while(flagSwap);
    }


    return retorno;
}

int masc_PrintList(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente)
{
    int retorno = 0;
    int i;
    int index;
    if(listMascotas != NULL && lenMascotas > 0)
    {
        retorno = 1;
        printf("--------------------------------------------------------------------------------------------------------\n");
        printf("| ID\t\tNOMBRE\t\t   TIPO\t\tRAZA\tEDAD\tSEXO\tPESO\t|    NOMBRE DEL DUENIO   |");
        printf("\n--------------------------------------------------------------------------------------------------------");
        for(i=0; i<lenMascotas; i++)
        {
            index = cli_findById(listCliente, lenCliente, listMascotas[i].idDuenio);
            if(listMascotas[i].isEmpty == 0)
            {
                printf("\n| %d\t%15s\t%15s", listMascotas[i].id, listMascotas[i].nombre,MAS_TIPOS[listMascotas[i].tipo]);
                printf("\t   %10s\t %d\t%c\t%.2f", listMascotas[i].raza, listMascotas[i].edad, listMascotas[i].sexo, listMascotas[i].peso);
                if(index >= 0)
                {
                    printf("\t|%15s\t|", listCliente[index].nombre);
                }
                else
                {
                    printf("No se encontro dueño para el animal.");
                }
            }
        }
        printf("\n---------------------------------------------------------------------------------------------------------\n");
    }
    return retorno;
}
int masc_findById(eMascota* list, int len,int id)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i ++)
        {
            if(list[i].id == id && list[i].isEmpty != 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int masc_findIndexEmpty(eMascota* list, int tam)
{
    int retorno = -1;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void masc_swapForSort(eMascota* list, int iControl)
{
    eMascota auxMascota;

    auxMascota = list[iControl];
    list[iControl] = list[iControl+1];
    list[iControl+1] = auxMascota;
}


int masc_getOneData(eMascota* getOne, int id, char* msg, eCliente* listCliente, int lenCliente)
{
    int retorno = 0;
    printf("%s", msg);
    if(utn_getString(getOne->nombre, MAS_LENNOMBRE, "\nIngresar un nombre: ", "Error. Dato invalido.", 2)
            && utn_getString(getOne->raza, MAS_LENRAZA, "\nIngresar un raza: ", "Error. Dato invalido.", 2)
            && utn_getNumber(&getOne->edad, "Ingresar edad: ", "Error, fuera de rango.", 0, 120, 3)
            && utn_getNumberFloat(&getOne->peso, "Ingresar peso: ", "Error, fuera de rango.", 0, 10000, 3)
            && utn_getOnlyTwoChars(&getOne->sexo, "Ingresar sexo [f] o [m]", "Error. Solo [f] o [m].", 'f', 'm', 3)
            && utn_getNumber(&getOne->tipo, "\nIngresar tipo de mascora \n[0]PERRO\n[1]GATO\n[2]RARO\nIngresar tipo: ", "Error, fuera de rango.", 0, 3, 3))
    {
        printf("\nLISTADO DE DUEniOS DISPONIBLES\n");
        cli_PrintList(listCliente, lenCliente);
        if(utn_getNumber(&getOne->idDuenio, "\nIngresar ID del duenio: ", "Error, fuera de rango.", 0, 10000, 3)
                && cli_findById(listCliente, lenCliente, getOne->idDuenio) >= 0)
        {
            getOne->id = id;
            getOne->isEmpty = 0;
            retorno = 1;
        }

    }
    return retorno;
}

int masc_getOneDataModify(eMascota* getOne, int id, char* msg)
{
    int retorno = 0;
    printf("%s", msg);
    if(utn_getString(getOne->nombre, MAS_LENNOMBRE, "\nIngresar un nombre: ", "Error. Dato invalido.", 2)
            && utn_getString(getOne->raza, MAS_LENRAZA, "\nIngresar un raza: ", "Error. Dato invalido.", 2)
            && utn_getNumber(&getOne->edad, "Ingresar edad: ", "Error, fuera de rango.", 0, 120, 3)
            && utn_getNumberFloat(&getOne->peso, "Ingresar peso: ", "Error, fuera de rango.", 0, 10000, 3)
            && utn_getOnlyTwoChars(&getOne->sexo, "Ingresar sexo [f] o [m]", "Error. Solo [f] o [m].", 'f', 'm', 3)
            && utn_getNumber(&getOne->tipo, "\nIngresar tipo de mascora \n[0]PERRO\n[1]GATO\n[2]RARO\nIngresar tipo: ", "Error, fuera de rango.", 0, 3, 3))
    {
        getOne->id = id;
        getOne->isEmpty = 0;
        retorno = 1;
    }
    return retorno;
}

int masc_PrintForType(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente)
{
    int retorno = 0;
    int i;
    int index;
    int type;
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf(">> Listar mascotas segun un tipo >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("\nQue tipo de mascota que desea mostrar?\n[0]PERRO\n[1]GATO\n[2]RARO\n[3]Salir\n");
    if(listMascotas != NULL && lenMascotas > 0
            && utn_getNumber(&type, "Ingrese una opcion: ", "Error, ingresar (0 / 1 / 2 / 3).", 0, 3, 3) && type != 3)
    {
        retorno = 1;
        printf("| ID\t\tNOMBRE\t\t   TIPO\t\tRAZA\tEDAD\tSEXO\tPESO\t|    NOMBRE DEL DUENIO   |");
        printf("\n--------------------------------------------------------------------------------------------------------");
        for(i=0; i<lenMascotas; i++)
        {
            index = cli_findById(listCliente, lenCliente, listMascotas[i].idDuenio);
            if(listMascotas[i].isEmpty == 0 && listMascotas[i].tipo == type)
            {
                printf("\n| %d\t%15s\t%15s", listMascotas[i].id, listMascotas[i].nombre,MAS_TIPOS[listMascotas[i].tipo]);
                printf("\t   %10s\t %d\t%c\t%.2f", listMascotas[i].raza, listMascotas[i].edad, listMascotas[i].sexo, listMascotas[i].peso);
                if(index >= 0)
                {
                    printf("\t|%15s\t|", listCliente[index].nombre);
                }
                else
                {
                    printf("No se encontro dueño para el animal.");
                }
            }
        }
        // printf("\n---------------------------------------------------------------------------------------------------------\n");
    }
    return retorno;
}
