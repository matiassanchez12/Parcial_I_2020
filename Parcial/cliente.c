#include "cliente.h"

void cli_menuEntity(char* msgTitleMenu, eCliente* list, int lenghtList, int* id)
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
                 gen_checkReturnWithSwitch(cli_Add(list, lenghtList, id), "\n\nAccion finalizada con exito!", "\n\nAccion cancelada..", "\n\nError. No hay mas espacio");
                break;
            case 2:
                gen_checkReturnWithSwitch(cli_Remove(list, lenghtList), "\n\nAccion finalizada con exito!", "\n\nAccion cancelada..", "\n\nError. No se encontraron datos");
                break;
            case 3:
                gen_checkReturnWithSwitch(cli_Modify(list, lenghtList), "\n\nAccion finalizada con exito!", "\n\nAccion cancelada..", "\n\nError. No se encontraron datos");
                break;
            case 4:
                gen_checkReturnWithIf(cli_PrintList(list, lenghtList), "\n\nAccion finalizada con exito!", "\n\nError. No se encontraron datos");
                break;
            }
        }
        system("pause");
    }while(option != 5);
}
int cli_initializer(eCliente* list, int len)
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
int cli_Add(eCliente* list,int len, int* id)
{
    int retorno = -1;
    eCliente auxCliente;
    int index;
    index = cli_findIndexEmpty(list, len);
    printf(">>Menu de altas");
    if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
    {
        retorno = 0;
        if(cli_getOneData(&auxCliente, *id, "\nIngresar datos\n") == 1)
        {
            retorno = 1;
            list[index] = auxCliente;
            (*id)++;
        }
    }
    return retorno;
}
void cli_hardCodear(eCliente* list, int len)
{
    int id[5]= {1,2,3,4,5};
    char nombre[5][CLI_LENNOMBRE]= {"Graciela","Carlos","Martina","Luis","Roberto"};
    char apellido[5][CLI_LENAPELLIDO]= {"Sabato","Carabajal","Lopez","Gerez","Blanco"};
    char localidad[5][CLI_LENLOCALIDAD]= {"Lomas","Avellaneda","Guillon","Temperley","Adrogue"};
    char telefono[5][CLI_LENTELEFONO]= {"123-33","123-33","1233-333","123-333","123333"};
    int edad[5]= {50,55,30,22,45};
    char sexo[5]= {'f','m','f','m','m'};
    int i;
    for(i=0; i<5; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].nombre, nombre[i]);
        strcpy(list[i].apellido, apellido[i]);
        strcpy(list[i].localidad, localidad[i]);
        strcpy(list[i].telefono, telefono[i]);
        list[i].edad = edad[i];
        list[i].sexo = sexo[i];
        list[i].isEmpty = 0;
    }
}


int cli_Modify(eCliente* list, int len)
{
    int retorno = -1;
    char confirm;
    eCliente auxCliente;
    int id;
    int index;
    printf(">>Menu de modificaciones\n");

    if(cli_PrintList(list, len) && list != NULL && len > 0 && utn_getNumber(&id, "\n\nIngresar un id: ", "Error, fuera de rango.", 0, 10000, 2))
    {
        index = cli_findById(list, len, id);
        if(index >= 0 && list[index].isEmpty != 1)
        {
            retorno = 0;
            if(cli_getOneData(&auxCliente, id, "\nIngresar nuevos datos\n") == 1)
            {
                printf("\n>> Realizar modificacion? [s] o [n]");
                if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion:", "Error solo [s] o [n].", 's', 'n', 2)
                        && confirm == 's')
                {
                    list[index] = auxCliente;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}

int cli_Remove(eCliente* list, int len)
{
    int retorno = -1;
    char confirm;
    int id;
    int index;
    printf("\n>>Menu de bajas\n\n");
    if(cli_PrintList(list, len) && list != NULL && len > 0 && utn_getNumber(&id, "\n\nIngresar un id: ", "Error, fuera de rango.", 0, 10000, 2))
    {
        index = cli_findById(list, len, id);
        if(index >= 0)
        {
            retorno = 0;
            printf("\n\n>> Realizar la baja? [s] o [n].");
            if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion: ", "Error solo [s] o [n].", 's', 'n', 2)
                    && confirm == 's')
            {
                list[index].isEmpty = 1;
                retorno = 1;
            }
        }
    }
    return retorno;
}

int cli_PrintList(eCliente* list, int len)
{
    int retorno = 0;
    int i;
    if(list != NULL && len > 0)
    {
        retorno = 1;
        printf("\n|----------------------------------------------------------------------------------------------------|");
        printf("\n|>> LISTADO DE CLIENTES >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|");
        printf("\n|----------------------------------------------------------------------------------------------------|\n");
        printf(" |ID\t\tNOMBRE\t\tPELLIDO\t\tLOCALIDAD\tTELEFONO\tEDAD\tSEXO\t   |");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("\n |%d\t%15s\t%15s\t%15s\t     %10s\t\t%d\t %c\t   |", list[i].id, list[i].nombre, list[i].apellido, list[i].localidad, list[i].telefono, list[i].edad, list[i].sexo);
            }
        }
        printf("\n|---------------------------------------------------------------------------------------------------|\n");
    }
    return retorno;
}
int cli_findById(eCliente* list, int len,int id)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i ++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int cli_findIndexEmpty(eCliente* list, int tam)
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
void cli_swapForSort(eCliente* list, int iControl)
{
    eCliente auxCliente;

    auxCliente = list[iControl];
    list[iControl] = list[iControl+1];
    list[iControl+1] = auxCliente;
}


int cli_getOneData(eCliente* getOne, int id, char* msg)
{
    int retorno = 0;
    printf("%s", msg);
    if(utn_getString(getOne->nombre, CLI_LENNOMBRE, "\nIngresar un nombre: ", "Error. Dato invalido.", 2)
       && utn_getString(getOne->apellido, CLI_LENAPELLIDO, "\nIngresar apellido: ", "Error. Dato invalido.", 2)
        && utn_getTelephone(getOne->telefono, CLI_LENTELEFONO, "\nIngresar telefono: ", "Error. Dato invalido.", 2)
        && utn_getDireccion(getOne->localidad, CLI_LENLOCALIDAD, "\nIngresar localidad: ", "Error. Dato invalido.", 2)
        && utn_getNumber(&getOne->edad, "\nIngresar edad: ", "Error, fuera de rango.", 0, 120, 3)
        && utn_getOnlyTwoChars(&getOne->sexo, "Ingresar sexo [f] o [m]: " , "Error. Solo [f] o [m].", 'f', 'm', 3))
    {
        getOne->id = id;
        getOne->isEmpty = 0;
        retorno = 1;
    }
    return retorno;
}

