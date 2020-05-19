#include "mascota.h"
/** \brief despliega un menu propio de la entidad mascota
 *
 * \param msgTitleMenu char* titulo que aparece en la parte superior del menu
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int cantidad maxima del array de mascotas
 * \param listClientes eCliente* listado de clientes
 * \param lenClientes int cantidad maxima del array de clientes
 * \param id int* listado de informes
 * \return void
 *
 */
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
/** \brief Inicializa el array de mascotas colocando isEmpty = 1 a cada elemento
 *
 * \param list eMascota* lista de mascotas
 * \param len int tamaño limite del array
 * \return int 1 se inicializo el array con exito, caso contrario 0
 *
 */
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
/** \brief Da de alta una mascota
 *
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array
 * \param id int* puntero al id de mascotas
 * \param listCliente eCliente* listado de clientes
 * \param lenCliente int tamaño limite del array
 * \return int -1 Error, 0 Accion cancelada, 1 alta exitosa
 *
 */
int masc_Add(eMascota* listMascotas,int lenMascotas, int* id, eCliente* listCliente, int lenCliente, eRaza* listRazas)
{
    int retorno = -1;
    eMascota auxMascota;
    int index;
    index = masc_findIndexEmpty(listMascotas, lenMascotas);
    printf(">>Menu de altas");
    if(listMascotas != NULL && lenMascotas > 0 && index < lenMascotas && index >= 0 && id != NULL)
    {
        retorno = 0;
        if(masc_getOneData(&auxMascota, *id, "\nIngresar datos\n", listCliente, lenCliente, listRazas) == 1)
        {
            retorno = 1;
            listMascotas[index] = auxMascota;
            (*id)++;
        }
    }
    return retorno;
}
/** \brief Carga el array de mascotas automaticamente
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \return void
 *
 */
void masc_hardCodear(eMascota* list, int len)
{
    int id[11]= {1,2,3,4,5,6,7,8,9,10,11};
    char nombre[11][MAS_LENNOMBRE]= {"gata1","gata2","Perro1","Perro2","Gatubelo","Pitbull","Iguana","Baco","Mishito","Pino","Bulldog"};
    char raza[11][MAS_LENRAZA]= {"Siames","Siames","Salchicha","Salchicha","Siames","Pitbull","Iguana","Labrador","Siames","Siames","Bulldog"};
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
/** \brief Modifica una mascota a eleccion del usuario
 *
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array de mascotas
 * \param listCliente eCliente* listado de clientes
 * \param lenCliente int tamaño limite del array de clientes
 * \return int -1 Error, 0 Accion cancelada, 1 Se modifico con exito!
 *
 */
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

/** \brief Elimita una mascota poniendo el campo isEmpty = 1
 *
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array de mascotas
 * \param listCliente eCliente* listado de clientes
 * \param lenCliente int tamaño limite del array de clientes
  * \return int -1 Error, 0 Accion cancelada, 1 Se elimino con exito!
 *
 */
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
/** \brief Ordena el array de mascotas
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \return int 0 Error, 1 Ordenado con exito
 *
 */
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

/** \brief Imprime el listado de mascotas
 *
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array de mascotas
 * \param listCliente eCliente* listado de clientes
 * \param lenCliente int tamaño limite del array de clientes
 * \return int 0 Error, 1 se imprimio exitosamente.
 *
 */
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
            if(index != -1 && listMascotas[i].isEmpty == 0)
            {
                printf("\n| %d\t%15s\t%15s", listMascotas[i].id, listMascotas[i].nombre,MAS_TIPOS[listMascotas[i].tipo]);
                printf("\t   %10s\t %d\t%c\t%.2f", listMascotas[i].raza, listMascotas[i].edad, listMascotas[i].sexo, listMascotas[i].peso);
                if(index >= 0)
                {
                    printf("\t|%15s\t|", listCliente[index].nombre);
                }
                else
                {
                    printf("\t|\tDADO DE BAJA\t|");
                }
            }
        }
        printf("\n---------------------------------------------------------------------------------------------------------\n");
    }
    return retorno;
}

/** \brief Verifica la existencia de un elemento mediante su Id
 *
 * \param list eMascota* listado de mascotas
 * \param len int tamaño limite del array
 * \param id int id de la mascota a ser verificado
 * \return int En caso de existir devuelve el ID, caso contrario -1 Id inexistente.
 *
 */
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
/** \brief Busca el primer espacio libre del array (isEmpty = 1)
 *
 * \param list eMascota* listado de mascotas
 * \param tam int cantidad limite del array
 * \return int -1 No se encontro lugar libre, caso contrario devuelve el Index del elemento
 *
 */
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
/** \brief Realiza la accion de swap
 *
 * \param list eMascota* listado de mascotas
 * \param iControl int variable de control
 * \return void
 *
 */
void masc_swapForSort(eMascota* list, int iControl)
{
    eMascota auxMascota;

    auxMascota = list[iControl];
    list[iControl] = list[iControl+1];
    list[iControl+1] = auxMascota;
}


/** \brief Toma los datos de una mascota para ser pasados a la funcion 'Add'
 *
 * \param getOne eMascota* auxiliar donde seran guardados los datos
 * \param id int id de la mascota
 * \param msg char* mensaje de introduccion para el usuario
 * \param listCliente eCliente* listado de clientes
 * \param lenCliente int tamaño limite del array clientes
 * \return int 0 Error, 1 Se cargaron los datos con exito.
 *
 */
 /*
int masc_getOneData(eMascota* getOne, int id, char* msg, eCliente* listCliente, int lenCliente)
{
 int retorno = 0;
 printf("%s", msg);
 if(utn_getString(getOne->nombre, MAS_LENNOMBRE, "\nIngresar un nombre: ", "Error. Dato invalido.", 2)
         && utn_getString(getOne->raza, MAS_LENRAZA, "\nIngresar un raza: ", "Error. Dato invalido.", 2)
         && utn_getNumber(&getOne->edad, "Ingresar edad: ", "Error, fuera de rango.", 0, 120, 3)
         && utn_getNumberFloat(&getOne->peso, "Ingresar peso: ", "Error, fuera de rango.", 0, 10000, 3)
         && utn_getOnlyTwoChars(&getOne->sexo, "Ingresar sexo [f] o [m]", "Error. Solo [f] o [m].", 'f', 'm', 3)
         && utn_getNumber(&getOne->tipo, "\nIngresar tipo de mascora \n[0]PERRO\n[1]GATO\n[2]RARO\nIngresar tipo: ", "Error, fuera de rango.", 0, 2, 3))
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
*/

/** \brief Toma los datos de una mascota para ser reemplazados por los del listado
 *
 * \param getOne eMascota* auxiliar donde se guardaran los datos
 * \param id int id de la mascota
 * \param msg char* mensaje de introduccion para el usuario
 * \return int 0 Error, 1 Se cargaron los datos con exito.
 *
 */
int masc_getOneDataModify(eMascota* getOne, int id, char* msg)
{
    int retorno = 0;
    printf("%s", msg);
    if(utn_getString(getOne->nombre, MAS_LENNOMBRE, "\nIngresar un nombre: ", "Error. Dato invalido.", 2)
            && utn_getString(getOne->raza, MAS_LENRAZA, "\nIngresar un raza: ", "Error. Dato invalido.", 2)
            && utn_getNumber(&getOne->edad, "\nIngresar edad: ", "Error, fuera de rango.", 0, 120, 3)
            && utn_getNumberFloat(&getOne->peso, "\nIngresar peso: ", "Error, fuera de rango.", 0, 10000, 3)
            && utn_getOnlyTwoChars(&getOne->sexo, "\nIngresar sexo [f] o [m]", "Error. Solo [f] o [m].", 'f', 'm', 3)
            && utn_getNumber(&getOne->tipo, "\nIngresar tipo de mascora \n[0]PERRO\n[1]GATO\n[2]RARO\nIngresar tipo: ", "Error, fuera de rango.", 0, 3, 3))
    {
        getOne->id = id;
        getOne->isEmpty = 0;
        retorno = 1;
    }
    return retorno;
}

/** \brief Muestra un menu de opciones para listar solo un determinado tipo de mascotas
 *
 * \param listMascotas eMascota* listado de mascotas
 * \param lenMascotas int tamaño limite del array mascotas
 * \param listCliente eCliente* listado de clientes
 * \param lenCliente int tamaño limite del array clientes
 * \return int 0 Error, 1 Listado mostrado con exito!.
 *
 */
int masc_PrintForType(eMascota* listMascotas, int lenMascotas, eCliente* listCliente, int lenCliente)
{
    int retorno = 0;
    int i;
    int index;
    int type;

    do
    {
        system("cls");
        printf("\n--------------------------------------------------------------------------------------------------------\n");
        printf(">> Listar mascotas segun un tipo >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("--------------------------------------------------------------------------------------------------------\n");
        printf("\nQue tipo de mascota que desea mostrar?\n[0]PERRO\n[1]GATO\n[2]RARO\n[3]Salir\n");
        if(listMascotas != NULL && lenMascotas > 0
                && utn_getNumber(&type, "\nIngrese una opcion: ", "Error, ingresar (0 / 1 / 2 / 3).", 0, 3, 3) && type != 3)
        {
            retorno = 1;
            printf("\n--------------------------------------------------------------------------------------------------------");
            printf("\n| ID\t\tNOMBRE\t\t   TIPO\t\tRAZA\tEDAD\tSEXO\tPESO\t|    NOMBRE DEL DUENIO   |");
            printf("\n--------------------------------------------------------------------------------------------------------");
            for(i=0; i<lenMascotas; i++)
            {
                index = cli_findById(listCliente, lenCliente, listMascotas[i].idDuenio);
                if(index != -1 && listMascotas[i].tipo == type)
                {
                    printf("\n| %d\t%15s\t%15s", listMascotas[i].id, listMascotas[i].nombre,MAS_TIPOS[listMascotas[i].tipo]);
                    printf("\t   %10s\t %d\t%c\t%.2f", listMascotas[i].raza, listMascotas[i].edad, listMascotas[i].sexo, listMascotas[i].peso);
                    if(index >= 0)
                    {
                        printf("\t|%15s\t|", listCliente[index].nombre);
                    }
                    else
                    {
                        printf("\t|\tDADO DE BAJA\t|");
                    }
                }
            }
            printf("\n---------------------------------------------------------------------------------------------------------\n\n");
            system("pause");
        }
    }while(type != 3);

    if(type == 3)
    {
        retorno = 1;
    }
    return retorno;
}

/** \brief Imprime el listado de razas segun su tipo
 *
 * \param tipo int el tipo de raza
 * \return void
 *
 */
void masc_printRazas(int tipo)
{
    int i;
    switch(tipo)
    {
    case 0:
        printf("\n>> Listado de razas de PERROS disponibles: \n");
        for(i = 0; i < MAS_LENRAZA_PERRO; i ++)
        {
            printf("\n[*] %s", MAS_RAZA_PERRO[i]);
        }
        break;
    case 1:
        printf("\n>> Listado de razas de GATOS disponibles:\n");
        for(i = 0; i < MAS_LENRAZA_GATO; i ++)
        {
            printf("\n[*] %s", MAS_RAZA_GATO[i]);
        }
        break;
    case 2:
        printf("\n>> Listado de razas RARAS disponibles: \n");
        for(i = 0; i < MAS_LENRAZA_RARO; i ++)
        {
            printf("\n[*] %s", MAS_RAZA_RARO[i]);
        }
        break;
    }
    printf("\n");
}

/** \brief Verifica la existencia de la raza indicada por el usuario
 *
 * \param tipo int tipo de raza
 * \param raza char* nombre de la raza indicada
 * \return int 1 El nombre de la raza existe, caso contrario 0.
 *
 */
int masc_findRazaByType(int tipo, char* raza)
{
    int retorno = 0;
    int i;
    switch(tipo)
    {
    case 0:
        for(i = 0; i < MAS_LENRAZA_PERRO; i++)
        {
            if(strcmpi(raza, MAS_RAZA_PERRO[i]) == 0)
            {
                retorno = 1;
                printf("\n** RAZA CARGADA CON EXITO **!\n");
                break;
            }
        }
        break;
    case 1:
        for(i = 0; i < MAS_LENRAZA_GATO; i++)
        {
            if(strcmpi(raza, MAS_RAZA_GATO[i]) == 0)
            {
                retorno = 1;
                printf("\n** RAZA CARGADA CON EXITO **!\n");
                break;
            }
        }
        break;
    case 2:
        for(i = 0; i < MAS_LENRAZA_RARO; i++)
        {
            if(strcmpi(raza, MAS_RAZA_RARO[i]) == 0)
            {
                retorno = 1;
                printf("\n** RAZA CARGADA CON EXITO **!\n");
                break;
            }
        }
        break;
    }
    if(retorno == 0)
    {
        printf("\nERROR: no se encontro la raza ingresada. Vuelva a intentarlo.\n");
    }
    return retorno;
}

/** \brief Toma los datos de una mascota para ser pasados a la funcion 'Add'
 *
 * \param getOne eMascota* auxiliar donde seran guardados los datos
 * \param id int id de la mascota
 * \param msg char* mensaje de introduccion para el usuario
 * \param listCliente eCliente* listado de clientes
 * \param lenCliente int tamaño limite del array clientes
 * \return int 0 Error, 1 Se cargaron los datos con exito.
 *
 */
int masc_getOneData(eMascota* getOne, int id, char* msg, eCliente* listCliente, int lenCliente, eRaza* getRaza)
{
    int retorno = 0;
    printf("%s", msg);
    if(utn_getString(getOne->nombre, MAS_LENNOMBRE, "\nIngresar un nombre: ", "Error. Dato invalido.", 2)
            && utn_getNumber(&getOne->edad, "\nIngresar edad: ", "Error, fuera de rango.", 0, 120, 3)
            && utn_getNumberFloat(&getOne->peso, "\nIngresar peso: ", "Error, fuera de rango.", 0, 10000, 3)
            && utn_getOnlyTwoChars(&getOne->sexo, "\nIngresar sexo [f] o [m]", "Error. Solo [f] o [m].", 'f', 'm', 3)
            && utn_getNumber(&getOne->tipo, "\nIngresar tipo de mascota \n[0]PERRO\n[1]GATO\n[2]RARO\nIngresar tipo: ", "Error, fuera de rango.", 0, 2, 3))
    {
        system("cls");
        masc_printRazas(getOne->tipo);
        if(utn_getString(getRaza->nombreDeRaza, MAS_LENRAZA, "\n > Ingresar la raza del animal: ", "Error. Dato invalido.", 2)
           && (utn_getDireccion(getRaza->pais, MAS_LENRAZA, "\n > Ingresar el pais de la raza: ", "Error. Dato invalido.", 2)
           && masc_findRazaByType(getOne->tipo, getRaza->pais))
        {
            cli_PrintList(listCliente, lenCliente);
            if(utn_getNumber(&getOne->idDuenio, "\nIngresar ID del duenio: ", "Error, fuera de rango.", 0, 10000, 3)
                    && cli_findById(listCliente, lenCliente, getOne->idDuenio) >= 0)
            {
                getOne->raza = getRaza->nombreDeRaza;
                getRaza->idMascota = id;
                getOne->id = id;
                getOne->isEmpty = 0;
                retorno = 1;
            }
        }
    }
    return retorno;
}

