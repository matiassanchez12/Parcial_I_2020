#include "cliente-mascota.h"

///PROMEDIOS
static int promEdadMascotasPorTipo(eMascota* list, int len);
static int countEdadMascotasPorTipo(eMascota* list, int len, int tipo);
static int acumEdadMascotasPorTipo(eMascota* list, int len, int tipo);
static int promEdadMascotas(eMascota* list, int len);
static int countEdadMascotas(eMascota* list, int len);
static int acumEdadMascotas(eMascota* list, int len);
///18
static int porceClientesSegunSexo(eCliente* list, int len);
static int promClientesSegunSexo(eCliente* list, int len);
static int countTodosLosClientes(eCliente* list, int len);
static int countClientesPorSexo(eCliente* list, int len, char sexo);

/** \brief Calcula el promedio de edad de mascotas de un solo tipo
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \return int 1 Promedio calculado con exito, caso contrario 0.
 *
 */
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
/** \brief cuenta la cantidad de mascotas de un tipo
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del listado de mascotas
 * \param tipo int tipo de mascota
 * \return int Devuelve >= 0 caso de haber contado con exito, caso contrario -1.
 *
 */
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

/** \brief Acumula la edad de mascotas de un tipo
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \param tipo int tipo de mascota
 * \return int Devuelve >= 0 caso de haber acumulado con exito, caso contrario -1.
 *
 */
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

/** \brief Calcula el promedio de edad de las mascotas
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \return int retorna 1 promedio calculado con exito, caso contrario 0.
 *
 */
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

/** \brief Cuenta edades de las mascotas
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \return int Devuelve >= 0 caso de contar exitosamente, caso contrario 0.
 *
 */
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

/** \brief Acumula edades de las mascotas
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \return int Devuelve >= 0 caso de contar exitosamente, caso contrario 0.
 *
 */
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

/** \brief Calcula el promedio de clientes de ambos sexos
 *
 * \param list eCliente* listado de clientes
 * \param len int tamaño limite del array
 * \return int Devuelve 1 promedio calculado exitosamente, caso contrario 0.
 *
 */
static int promClientesSegunSexo(eCliente* list, int len)
{
    int ret = 0;
    int totalDeClientes;
    int countClienteF;
    int countClienteM;
    float promM;
    float promF;
    if(list != NULL && len > 0)
    {
        printf("\n-------------------------------------------------------------------------------------");
        printf("\n||||||||||||| >> Mostrando el promedio de clientes segun el sexo.. >> |||||||||||||||");
        printf("\n-------------------------------------------------------------------------------------\n");
        printf("-------------------------------------------------------------------------------------");
        totalDeClientes = countTodosLosClientes(list, len);
        countClienteF = countClientesPorSexo(list, len, 'f');
        countClienteM = countClientesPorSexo(list, len, 'm');
        if(countClienteF != -1 && countClienteM != -1 && totalDeClientes != -1)
        {
            ret = 1;
            printf("\n=============================>> Informe solicitado <<================================\n");
            promF =  (float) totalDeClientes / countClienteF;
            printf("\n\n> El promedio de CLIENTAS es: [%.2f].\n", promF);
            promM =  (float) totalDeClientes / countClienteM;
            printf("\n\n> El promedio de CLIENTES es: [%.2f].\n", promM);
            printf("\n=====================================================================================\n");
        }
        else
        {
            printf("\nError: No hay suficientes datos para esta operacion. ");
        }
    }

    return ret;
}

///OPCION C PORCENTAJE
/** \brief Calcula el porcentaje de clientes de ambos sexos
 *
 * \param list eCliente* listado de clientes
 * \param len int tamaño limite del array
 * \return int Devuelve 1 porcentaje calculado exitosamente, caso contrario 0.
 *
 */
static int porceClientesSegunSexo(eCliente* list, int len)
{
    int ret = 0;
    int totalDeClientes;
    int countClienteF;
    float porceF;
    if(list != NULL && len > 0)
    {
        printf("\n-------------------------------------------------------------------------------------");
        printf("\n|||||||||||| >> Mostrando el procentaje de clientas.. >> ||||||||||||||");
        printf("\n-------------------------------------------------------------------------------------\n");
        printf("-------------------------------------------------------------------------------------");
        totalDeClientes = countTodosLosClientes(list, len);
        countClienteF = countClientesPorSexo(list, len, 'f');
        if(countClienteF != -1 && countClienteM != -1 && totalDeClientes != -1)
        {
            ret = 1;
            printf("\n=============================>> Informe solicitado <<================================\n");
            porceF =  ((float) countClienteF * 100) / totalDeClientes;
            printf("\n\n> El porcentaje de CLIENTES mujeres es: [%% %.2f].\n", porceF);
            printf("\n=====================================================================================\n");
        }
        else
        {
            printf("\nError: No hay suficientes datos para esta operacion. ");
        }
    }

    return ret;
}
/** \brief Cuenta los clientes de un solo sexo
 *
 * \param list eCliente* listado de clientes
 * \param len int tamaño limite del array
 * \param sexo char el sexo a contar
 * \return int Devuelve >= 0 caso de conteo exitoso, caso contrario -1.
 *
 */
static int countClientesPorSexo(eCliente* list, int len, char sexo)
{
    int ret = -1;
    int i;
    int count = 0;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].sexo == sexo)
            {
                count ++;
            }
        }
    }
    ret = count;

    return ret;
}

/** \brief Cuenta todos los clientes
 *
 * \param list eCliente* listado de clientes
 * \param len int tamaño limite del cliente
 * \return int Devuelve >= 0 caso de conteo exitoso, caso contrario -1.
 *
 */
static int countTodosLosClientes(eCliente* list, int len)
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

/** \brief despliega un menu propio de la entidad informes
 *
 * \param msgTitleMenu char* titulo que aparece en la parte superior del menu
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int cantidad maxima del array de mascotas
 * \param listClientes eCliente* listado de clientes
 * \param lenClientes int cantidad maxima del array de clientes
 * \param listInformes eInformeCantidad* listado de informes
 * \return void
 *
 */
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
        printf("\n[5] MENU DE MOSTRAR MASCOTAS DE UN TIPO:\n ->> 0. Perro\n ->> 1. Gato\n ->> 2. Raro");
        printf("\n[6] MENU DE ORDENAMIENTOS:\n ->> 1. Clientes ordenados por cantidad de mascotas\n ->> 2. Clientes ordenados por cantidad de mascotas y nombre");
        printf("\n[7] MENU DE PROMEDIOS:\n ->> 1. Promedio de edad entre las mascotas\n ->> 2. Promedio de edad entre las mascotas, por tipo ");
        printf("\n[8] INFORMAR EL PROMEDIO ACTUAL DE CLIENTES Y CLIENTAS");
        printf("\n[9] INFORMAR EL PORCENTAJE ACTUAL DE CLIENTES Y CLIENTAS");
        printf("\n[10] INFORMAR 19");
        printf("\n[11] En proceso");
        printf("\n[12] VOLVER AL MENU PRINCIPAL\n");
        if(utn_getNumber(&option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 12, 2))
        {
            switch(option)
            {
            case 1:
                system("cls");
                info_mostrarClienteConMascotas(listClientes, lenClientes, listMascotas, lenMascotas);
                break;
            case 2:
                system("cls");
                gen_checkReturnWithIf(info_sortAndPrint(listClientes, lenClientes, listMascotas, lenMascotas), "\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 3:
                system("cls");
                info_mostrarClienteConMasDeUnaMascota(listClientes, lenClientes, listMascotas, lenMascotas);
                break;
            case 4:
                system("cls");
                info_mostrarClienteConMascotasMayoresAtres(listClientes, lenClientes, listMascotas, lenMascotas);
                break;
            case 5:
                gen_checkReturnWithIf(masc_PrintForType(listMascotas, lenMascotas, listClientes, lenClientes),"\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 6:
                info_contMascotasDeCliente(listClientes, lenClientes, listMascotas, lenMascotas, listInformes);
                gen_checkReturnWithIf(info_menuParaMostrarClientesOrdenados(listInformes, lenClientes),"\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 7:
                gen_checkReturnWithIf( info_menuPromediarEdadMascotas(listMascotas, lenMascotas),"\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 8:
                system("cls");
                gen_checkReturnWithIf(promClientesSegunSexo(listClientes, lenClientes), "\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 9:
                system("cls");
                gen_checkReturnWithIf(porceClientesSegunSexo(listClientes, lenClientes), "\nFinalizado exitosamente!\n", "\nError, algo salio mal..\n");
                break;
            case 10:
                info_ListarDueñosconMascotasDelMismoSexo(listClientes, lenClientes, listMascotas, lenMascotas);
                break;
            case 11:
                break;
            }
        }
        system("pause");
    }
    while(option != 12);
}

/** \brief muestra los clientes con sus mascotas
 *
 * \param listClientes eCliente* listado de clientes
 * \param lenClientes int tamaño limite del array clientes
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array mascotas
 * \return void
 *
 */
void info_mostrarClienteConMascotas(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas)
{
    int i;
    int j;
    int count;
    printf("\n---------------------------------------------------------------------------------------------------------");
    printf("\n||||||||||||||||||||||||||||||| >> Mostrando Cliente con sus mascotas.. >> |||||||||||||||||||||||||||||");
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

/** \brief Ordena por el tipo de mascota y muestra el listado de clientes
 *
 * \param listClientes eCliente* listado de clientes
 * \param lenClientes int tamaño limite del array clientes
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array mascotas
 * \return int Devuelve 1 si muestra y ordenado exitosamente,caso contrario 0.
 *
 */
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
/** \brief Muestra un listado de todos los clientes que tienen mas de una mascota
 *
 * \param listClientes eCliente* listado de clientes
 * \param lenClientes int tamaño limite del array clientes
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array mascotas
 * \return void
 *
 */
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

/** \brief muestra clientes con mascotas mayores a 3 años
 *
 * \param listClientes eCliente* listado de clientes
 * \param lenClientes int tamaño limite del array clientes
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array mascotas
 * \return void
 *
 */
void info_mostrarClienteConMascotasMayoresAtres(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas)
{
    int i;
    int j;
    printf("\n|---------------------------------------------------------------------------------------------------------|");
    printf("\n|>> Listando mascotas mayores a 3 anios.. >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|");
    printf("\n|---------------------------------------------------------------------------------------------------------|");
    printf("\n|   ID CLIENTE\t    NOMBRE DEL CLIENTE\t\tID MASCOTA\tNOMBRE DE LAS MASCOTAS\t\tEDAD\t  |");
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
                printf("|\t%d   \t%15s\t\t\t  %d\t\t %15s\t\t%2d\t  |\n", listClientes[i].id, listClientes[i].nombre, listMascotas[j].id, listMascotas[j].nombre, listMascotas[j].edad);
                printf("|---------------------------------------------------------------------------------------------------------|\n");
            }
        }
    }
    printf("\n");
}

/** \brief Cuenta las mascotas de cada cliente
 *
 * \param listClientes eCliente* listado de clientes
 * \param lenClientes int tamaño limite del array clientes
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array mascotas
 * \param arrayDeInformes eInformeCantidad* listado que informa las cantidades
 * \return void
 *
 */
void info_contMascotasDeCliente(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas, eInformeCantidad* arrayDeInformes)
{
    int i;
    int j;
    int count;
    for(i = 0; i < lenClientes; i++)
    {
        count = 0;
        arrayDeInformes[i].isEmpty = 0;

        if(listClientes[i].isEmpty == 1)
        {
            arrayDeInformes[i].isEmpty = 1;
            continue;
        }
        for(j = 0; j < lenMascotas; j++)
        {
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

/** \brief Ordena clientes por cantidad de mascotas
 *
 * \param listInformes eInformeCantidad* listado que informa las cantidades
 * \param lenClientes int tamaño limite del array clientes
 * \return int Devuelve 1 si ordeno correctamente, 0 caso contrario.
 *
 */
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

/** \brief Ordena clientes por cantidad de mascotas y sus nombres
 *
 * \param listInformes eInformeCantidad* listado que informa las cantidades
 * \param lenClientes int  tamaño limite del array clientes
 * \return int Devuelve 1 si ordeno correctamente, 0 caso contrario.
 *
 */
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

/** \brief Menu para mostrar ordenamientos por cantidad y nombre
 *
 * \param listInformes eInformeCantidad* listado que informa las cantidades
 * \param lenClientes int  tamaño limite del array clientes
 * \return int Devuelve 1 si ordeno correctamente, 0 caso contrario.
 *
 */
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

/** \brief Imprime listado de clientes con la cantidad de mascotas
 *
 * \param list eInformeCantidad* listado que informa las cantidades
 * \param len int  tamaño limite del array clientes
 * \return void
 *
 */
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

/** \brief menu para promediar edades de mascotas
 *
 * \param list eMascota* listado de mascotas
 * \param len int Tamaño limite del array mascotas
 * \return int 1 listado mostrado con exito, caso contrario 0.
 *
 */
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

/** \brief Se elimina un cliente y junto con el todos sus mascotas cargadas en el sistema
 *
 * \param list eCliente* listado de clientes
 * \param len int tamaño limite del array clientes
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array mascotas
 * \return int -1 Error, 0 Accion cancelada, 1 Eliminacion en casacada exitosa!.
 *
 */
int info_bajaEnCascadaCliente(eCliente* list, int len, eMascota* listMascotas, int lenMascotas)
{
    int retorno = -1;
    char confirm;
    int i;
    int id;
    int index;
    printf("\n>>Realizar baja en cascada de CLIENTES\n\n");
    if(cli_PrintList(list, len) && list != NULL && len > 0 && listMascotas != NULL && lenMascotas > 0
            && utn_getNumber(&id, "\n\nIngresar un id: ", "Error, fuera de rango.", 0, 10000, 2))
    {
        index = cli_findById(list, len, id);
        if(index >= 0)
        {
            retorno = 0;
            printf("\n>> Aviso: al dar de baja el cliente con nombre: [%s], se eliminaran las mascotas que le pertenecen. \n\n>> Realizar la baja?[s] o [n].", list[index].nombre);
            if(utn_getOnlyTwoChars(&confirm, "\n Ingresar una opcion: ", "Error solo [s] o [n].", 's', 'n', 2)
                    && confirm == 's')
            {
                for(i = 0; i < lenMascotas; i ++)
                {
                    if(list[index].id == listMascotas[i].idDuenio)
                    {
                        listMascotas[i].isEmpty = 1;
                    }
                }
                list[index].isEmpty = 1;
                retorno = 1;
            }
        }
    }
    return retorno;
}

/*
void info_ListarDueñosconMascotasDelMismoSexo(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas)
{
    int i;
    int j;
    int flag;
    for(i = 0; i < lenClientes; i++)
    {
        flag = 0;
        if(listClientes[i].isEmpty == 1)
        {
            continue;
        }
        for(j = 0; j < lenMascotas; j++)
        {
          if(listClientes[i].id == listMascotas[j].idDuenio)
          {
              if(listMascotas[j].sexo == listMascotas[j+1].sexo)
              {
                  flag = 1;
              }
          }
        }
    }
    printf("\nEl cliente [%s] tiene mascotas del mismo sexo!.", listClientes[i].nombre);
}*/
