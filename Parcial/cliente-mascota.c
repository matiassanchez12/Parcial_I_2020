#include "cliente-mascota.h"

void info_menuEntity(char* msgTitleMenu, eMascota* listMascotas, int lenMascotas,eCliente* listClientes, int lenClientes)
{
    int option;
    do
    {
        system("cls");
        printf("%s", msgTitleMenu);
        printf("\n[1] INFORMAR DUENIOS CON SUS MASCOTAS");
        printf("\n[2] INFORMAR MASCOTAS CON SUS DUENIOS, ORDENADAS POR TIPO");
        printf("\n[3] INFORMAR DUENIOS CON MAS DE UNA MASCOTA");
        printf("\n[4] INFORMAR DUENIOS CON MASCOTAS MAYORES A 3 ANIOS");
        printf("\n[5] INFORMAS MASCOTAS DE UN TIPO DETERMINADO");
        printf("\n[6] ");
        printf("\n[7] VOLVER AL MENU PRINCIPAL\n");
        if(utn_getNumber(&option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 7, 2))
        {
            switch(option)
            {
            case 1:
                info_mostrarClienteConMascotas(listClientes, lenClientes, listMascotas, lenMascotas);
                break;
            case 2:
                gen_checkReturnWithIf(info_sortAndPrint(listClientes, lenClientes, listMascotas, lenMascotas), "\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 3:
                info_mostrarClienteConMasDeUnaMascota(listClientes, lenClientes, listMascotas, lenMascotas);
                break;
            case 4:
                info_mostrarClienteConMascotasMayoresAtres(listClientes, lenClientes, listMascotas, lenMascotas);
                break;
            case 5:
                gen_checkReturnWithIf(masc_PrintForType(listMascotas, lenMascotas, listClientes, lenClientes),"\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 6:
                break;
            case 7:
                break;
            }
        }
        system("pause");
    }
    while(option != 7);
}

void info_mostrarClienteConMascotas(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas)
{
    int i;
    int j;
    int count;
    printf("\n---------------------------------------------------------------------------------------------------------");
    printf("\n   ID CLIENTE\t\tNOMBRE DEL CLIENTE\t\tID MASCOTA\t\tNOMBRE DE LA MASCOTA/S");
    printf("\n---------------------------------------------------------------------------------------------------------");
    for(i = 0; i < lenClientes; i++)
    {
        if(listClientes[i].isEmpty == 1)
        {
            continue;
        }
        count = 0;
        printf("\n\t%d   \t%15s", listClientes[i].id, listClientes[i].nombre);
        for(j = 0; j < lenMascotas; j++)
        {
            if(listClientes[i].isEmpty != 1 && listMascotas[j].isEmpty != 1)
            {
                if(listClientes[i].id == listMascotas[j].idDuenio)
                {
                    if(count > 0)
                    {
                        printf("\t\t\t\t\t\t\t  %d\t\t %15s\n", listMascotas[j].id, listMascotas[j].nombre);
                    }
                    else
                    {
                        printf("\t\t\t\t  %d\t\t %15s\n", listMascotas[j].id, listMascotas[j].nombre);
                    }
                    count ++;
                }
            }
        }
        printf("---------------------------------------------------------------------------------------------------------");
    }
    printf("\n");
}

int info_sortAndPrint(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas)
{
    int retorno = 0;
    if(listClientes != NULL && lenClientes >0 && listMascotas != NULL && lenMascotas > 0 && masc_Sort(listMascotas, lenMascotas))
    {
        printf("\n---------------------------------------------------------------------------------------------------------|");
        printf("\n>> Mostrando listado ordenado por el tipo de mascota.. >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|\n");
        if(masc_PrintList(listMascotas, lenMascotas, listClientes, lenClientes))
        {
            retorno = 1;
        }
    }


    return retorno;
}

void info_mostrarClienteConMasDeUnaMascota(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas)
{
    int i;
    int j;
    int flag = 0;
    int count;
    printf("\n---------------------------------------------------------------------------------------------------------");
    printf("\n   ID CLIENTE\t    NOMBRE DEL CLIENTE\t\tID MASCOTA\tNOMBRE DE LAS MASCOTAS\tCANTIDAD DE MASCOTAS");
    printf("\n---------------------------------------------------------------------------------------------------------");
    for(i = 0; i < lenClientes; i++)
    {
        flag = 0;
        count = 0;
        if(listClientes[i].isEmpty == 1)
        {
            continue;
        }

        for(j = 0; j < lenMascotas; j++)
        {
            if(listClientes[i].isEmpty != 1 && listMascotas[j].isEmpty != 1)
            {
                if(listClientes[i].id == listMascotas[j].idDuenio)
                {
                    count ++;
                }
            }
        }

        if(count > 1)
        {
            printf("\n\t%d   \t%15s", listClientes[i].id, listClientes[i].nombre);
            for(j = 0; j < lenMascotas; j++)
            {
                if(listClientes[i].id == listMascotas[j].idDuenio)
                {
                    if(flag == 1)
                    {
                        printf("\t\t\t\t\t\t  %d\t %15s\t\t\t%d\n", listMascotas[j].id, listMascotas[j].nombre, count);
                    }
                    else
                    {
                        printf("\t\t\t  %d\t %15s\t\t\t%d\n", listMascotas[j].id, listMascotas[j].nombre, count);
                    }
                    flag = 1;
                }
            }
            printf("---------------------------------------------------------------------------------------------------------");
        }
    }
    printf("\n");
}

void info_mostrarClienteConMascotasMayoresAtres(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas)
{
    int i;
    int j;
    printf("\n|---------------------------------------------------------------------------------------------------------|");
    printf("\n|>> Listando mascotas mayores a 3 anios.. >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|");
    printf("\n|---------------------------------------------------------------------------------------------------------|");
    printf("\n|   ID CLIENTE\t    NOMBRE DEL CLIENTE\t\tID MASCOTA\tNOMBRE DE LAS MASCOTAS\t\t\t  |");
    printf("\n|---------------------------------------------------------------------------------------------------------|\n");
    for(i = 0; i < lenClientes; i++)
    {
        if(listClientes[i].isEmpty == 1)
        {
            continue;
        }

        for(j = 0; j < lenMascotas; j++)
        {
            if(listMascotas[j].isEmpty == 1)
            {
                continue;
            }
            if(listClientes[i].id == listMascotas[j].idDuenio && listMascotas[j].edad > 3)
            {
                printf("|\t%d   \t%15s\t\t\t  %d\t\t %15s\t\t\t\t  |\n", listClientes[i].id, listClientes[i].nombre, listMascotas[j].id, listMascotas[j].nombre);
                printf("|---------------------------------------------------------------------------------------------------------|\n");
            }
        }

    }

    printf("\n");
}

