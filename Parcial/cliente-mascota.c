#include "cliente-mascota.h"

///PROMEDIOS
static int promEdadMascotasPorTipo(eMascota* list, int len);
static int countEdadMascotasPorTipo(eMascota* list, int len, int tipo);
static int acumEdadMascotasPorTipo(eMascota* list, int len, int tipo);
static int promEdadMascotas(eMascota* list, int len);
static int countEdadMascotas(eMascota* list, int len);
static int acumEdadMascotas(eMascota* list, int len);

void info_menuEntity(char* msgTitleMenu, eMascota* listMascotas, int lenMascotas,eCliente* listClientes, int lenClientes, eInformeCantidad* listInformes)
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
        printf("\n[6] MENU DE ORDENAMIENTOS:\n ->> 1. Clientes ordenados por cantidad de mascotas\n ->> 2. Clientes ordenados por cantidad de mascotas y nombre");
        printf("\n[7] MENU DE PROMEDIOS:\n ->> 1. Promedio de edad entre las mascotas\n ->> 2. Promedio de edad entre las mascotas, por tipo ");
        printf("\n[8] VOLVER AL MENU PRINCIPAL\n");
        if(utn_getNumber(&option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 8, 2))
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
                gen_checkReturnWithIf(info_menuParaMostrarClientesOrdenados(listInformes, lenClientes),"\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 7:
                gen_checkReturnWithIf( info_menuPromediarEdadMascotas(listMascotas, lenMascotas),"\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            }
        }
        system("pause");
    }
    while(option != 8);
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

void info_contMascotasDeCliente(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas, eInformeCantidad* arrayDeInformes)
{
    int i;
    int j;
    int count;
    for(i = 0; i < lenClientes; i++)
    {
        count = 0;
        arrayDeInformes[i].isEmpty = 0;
        for(j = 0; j < lenMascotas; j++)
        {
            if(listClientes[i].isEmpty == 1)
            {
                arrayDeInformes[i].isEmpty = 1;
                continue;
            }
            if(listClientes[i].id == listMascotas[j].idDuenio && listMascotas[j].isEmpty != 1)
            {
                count ++;
            }
        }
        strcpy(arrayDeInformes[i].nombreCliente, listClientes[i].nombre);
        arrayDeInformes[i].idCliente = listClientes[i].id;
        arrayDeInformes[i].cantidadMascotas = count;
    }
}

int info_sortClientePorCantidad(eInformeCantidad* listInformes, int lenClientes)
{
    int retorno = 0;
    eInformeCantidad auxInforme;
    int flagSwap;
    int i;
    if(listInformes != NULL && lenClientes > 0)
    {
        retorno = 1;
        do
        {
            flagSwap = 0;
            for(i=0; i<lenClientes-1; i++)
            {
                if(listInformes[i].isEmpty == 1 || listInformes[i+1].isEmpty == 1)
                {
                    continue;
                }
                if(listInformes[i].cantidadMascotas > listInformes[i+1].cantidadMascotas)
                {
                    retorno = 1;
                    flagSwap = 1;
                    auxInforme = listInformes[i];
                    listInformes[i] = listInformes[i+1];
                    listInformes[i+1] = auxInforme;
                }
            }
            lenClientes--;
        }
        while(flagSwap);
    }

    return retorno;
}

int info_sortClientePorCantidadYNombre(eInformeCantidad* listInformes, int lenClientes)
{
    int retorno = 0;
    int flagSwap;
    eInformeCantidad auxInforme;
    int i;
    int auxiliarCmp;
    if(listInformes != NULL && lenClientes > 0)
    {
        retorno = 1;
        do
        {
            flagSwap = 0;
            for(i=0; i<lenClientes-1; i++)
            {
                if(listInformes[i].isEmpty == 1 || listInformes[i+1].isEmpty == 1)
                {
                    continue;
                }
                auxiliarCmp = strcmp(listInformes[i].nombreCliente,listInformes[i+1].nombreCliente);

                if( listInformes[i].cantidadMascotas > listInformes[i+1].cantidadMascotas ||
                        ( listInformes[i].cantidadMascotas == listInformes[i+1].cantidadMascotas
                          && auxiliarCmp > 0))
                {

                    flagSwap = 1;
                    auxInforme = listInformes[i];
                    listInformes[i] = listInformes[i+1];
                    listInformes[i+1] = auxInforme;
                }
            }
            lenClientes--;
        }
        while(flagSwap);
    }
    return retorno;
}

int info_menuParaMostrarClientesOrdenados(eInformeCantidad* listInformes, int lenListClientes)
{
    int retorno = 0;
    int option;

    do
    {
        system("cls");
        printf("\n>> Menu para mostrar clientes ordenados >> \n\nElija un tipo de ordenamiento\n\n[1]Ordenar a los duenios por cantidades de mascotas\n[2]Ordenar a los duenios por cantidades de mascotas y por orden alfabetico de los nombres\n[3]Volver al menu principal");
        if(utn_getNumber(&option, "\nIngresar una opcion: ", "Error, fuera de rango.", 1, 3, 3))
        {
            switch(option)
            {
            case 1 :
                if(info_sortClientePorCantidad(listInformes, lenListClientes))
                {
                    printf("\n|----------------------------------------------------------------------------------------------------|");
                    printf("\n >> Mostrando clientes ordenados por cantidad de mascotas..\n");
                    info_printListClientes(listInformes, lenListClientes);
                    system("pause");
                    retorno = 1;
                }
                break;
            case 2:
                if(info_sortClientePorCantidadYNombre(listInformes, lenListClientes))
                {
                    printf("\n|----------------------------------------------------------------------------------------------------|");
                    printf("\n >> Mostrando clientes ordenados por cantidad de mascotas y nombre..\n");
                    info_printListClientes(listInformes, lenListClientes);
                    system("pause");
                    retorno = 1;
                }
                break;
            case 3:
                retorno = 1;
            }
        }
    }
    while(option != 3);

    return retorno;
}

void info_printListClientes(eInformeCantidad* list, int len)
{
    int i;
    if(list != NULL && len > 0)
    {
        printf("|----------------------------------------------------------------------------------------------------|");
        printf("\n|>> LISTADO DE CLIENTES >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|");
        printf("\n|----------------------------------------------------------------------------------------------------|\n");
        printf(" |ID\t\tNOMBRE\t\tCANTIDAD DE MASCOTAS\t|");
        printf("\n|----------------------------------------------------------------------------------------------------|");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printf("\n|%d\t%15s\t\t\t%d\t\t| ", list[i].idCliente, list[i].nombreCliente, list[i].cantidadMascotas);
            }
        }
        printf("\n|---------------------------------------------------------------------------------------------------|\n");
    }
}

int info_menuPromediarEdadMascotas(eMascota* list, int len)
{
    int retorno = 0;
    int option;

    do
    {
        system("cls");
        printf("\n>> Menu de promedios >> \n\nQue informe desea?\n\n[1] El promedio de edad entre las mascotas \n[2] El promedio de edad entre las mascotas, por tipo \n[3] Volver al menu principal");
        if(utn_getNumber(&option, "\n\nIngresar una opcion: ", "Error, fuera de rango.", 1, 3, 3))
        {
            switch(option)
            {
            case 1 :
                if(promEdadMascotas(list, len))
                {
                    retorno = 1;
                    system("pause");
                }
                break;
            case 2:
                if(promEdadMascotasPorTipo(list, len))
                {
                    retorno = 1;
                    system("pause");
                }
                break;
            case 3:
                retorno = 1;
            }
        }
    }
    while(option != 3);

    return retorno;
}

static int promEdadMascotasPorTipo(eMascota* list, int len)
{
    int ret = 0;
    int countEdadMascota;
    int acumEdadMascota;
    float promEdad;
    int tipo;
    printf("\n======================================================================================");
    printf("\n>> Seleccione un tipo de mascota para calcular un promedio de edades >>\n[0]PERRO\n[1]GATO\n[2]RARO\n[3]Salir\n\n");
    if(list != NULL && len > 0 && utn_getNumber(&tipo, "Ingresar una opcion: ", "Error, fuera de rango.", 0, 3, 4) && tipo != 3)
    {
        countEdadMascota = countEdadMascotasPorTipo(list, len, tipo);
        acumEdadMascota = acumEdadMascotasPorTipo(list, len, tipo);
        if(countEdadMascota != -1 && acumEdadMascota != -1)
        {
            printf("\n=============================>> Informe solicitado <<================================\n");
            ret = 1;
            printf("\n COUNT : %d ACUM : %d", countEdadMascota, acumEdadMascota);
            promEdad =  (float) acumEdadMascota / countEdadMascota;
            printf("\n\n> El promedio de edad entre mascotas del tipo: [%s] , es: [%.2f].\n", MAS_TIPOS[tipo], promEdad);
            printf("\n=====================================================================================\n");
        }
        else
        {
            printf("\nError: No hay suficientes datos para esta operacion. ");
        }
    }
    if(tipo == 3)
    {
        printf("\nVolviendo al menu de informes..\n");
        ret = 1;
    }
    return ret;
}
static int countEdadMascotasPorTipo(eMascota* list, int len, int tipo)
{
    int ret = -1;
    int i;
    int count = 0;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].tipo == tipo)
            {
                count ++;
            }
        }
    }
    ret = count;

    return ret;
}

static int acumEdadMascotasPorTipo(eMascota* list, int len, int tipo)
{
    int ret = -1;
    int i;
    int acum = 0;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0  && list[i].tipo == tipo)
            {
                acum = acum + list[i].edad;
            }
        }
    }
    ret = acum;

    return ret;
}

static int promEdadMascotas(eMascota* list, int len)
{
    int ret = 0;
    int countEdadMascota;
    int acumEdadMascota;
    float promEdad;
    if(list != NULL && len > 0)
    {
        countEdadMascota = countEdadMascotas(list, len);
        acumEdadMascota = acumEdadMascotas(list, len);
        if(countEdadMascota != -1 && acumEdadMascota != -1)
        {
            ret = 1;
            printf("\n=============================>> Informe solicitado <<================================\n");
            promEdad =  (float) acumEdadMascota / countEdadMascota;
            printf("\n\n> El promedio de edad entre mascotas es: [%.2f].\n", promEdad);
            printf("\n=====================================================================================\n");
        }
        else
        {
            printf("\nError: No hay suficientes datos para esta operacion. ");
        }
    }

    return ret;
}

static int countEdadMascotas(eMascota* list, int len)
{
    int ret = -1;
    int i;
    int count = 0;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {

            if(list[i].isEmpty == 0)
            {
                count ++;
            }
        }
    }
    ret = count;

    return ret;
}

static int acumEdadMascotas(eMascota* list, int len)
{
    int ret = -1;
    int i;
    int acum = 0;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                acum = acum + list[i].edad;
            }
        }
    }
    ret = acum;

    return ret;
}
