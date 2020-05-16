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
    printf("\n---------------------------------------------------------------------------------------------------------");
    for(i = 0; i < lenClientes; i++)
    {
     printf("\n Cliente %s con ID: %d le pertenecen las siguientes mascotas", listClientes[i].nombre, listClientes[i].id);
     printf("\n---------------------------------------------------------------------------------------------------------");
     printf("\n   ID MASCOTA\t\tNOMBRE");
        for(j = 0; j < lenMascotas; j++)
        {

            if(listClientes[i].isEmpty != 1 && listMascotas[j].isEmpty != 1)
            {
                if(listClientes[i].id == listMascotas[j].idDuenio)
                {
                    printf("\n\t%d   \t%15s",listMascotas[j].idDuenio, listMascotas[j].nombre);
                }
            }
        }
    printf("\n---------------------------------------------------------------------------------------------------------");
    }
    printf("\n");
 }
