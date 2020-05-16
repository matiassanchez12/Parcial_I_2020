#include "cliente-mascota.h"

void info_menuEntity(char* msgTitleMenu, eMascota* list, int lenghtList ,eCliente* listClientes, int lenClientes)
{
    int option;
    do
    {
        system("cls");
        printf("%s", msgTitleMenu);
        printf("\n[1] INFORMAR DUENiOS CON SUS MASCOTAS");
        printf("\n[2] ");
        printf("\n[3] ");
        printf("\n[4] ");
        printf("\n[5] VOLVER AL MENU PRINCIPAL\n");
        if(utn_getNumber(&option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 5, 2))
        {
            switch(option)
            {
            case 1:
                info_mostrarClienteConMascotas(listClientes, lenClientes, list, lenghtList);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            }
        }
        system("pause");
    }while(option != 5);
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
