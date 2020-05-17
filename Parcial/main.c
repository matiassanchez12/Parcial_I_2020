#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericas.h"
#include "cliente-mascota.h"

#define QUANTITY_CLIENTES 6
#define QUANTITY_MASCOTAS 11
/***
*FALTA:
** HACER UNA BAJA EN CASCADA DE EMPLEADOS
***/
int main()
{
    int option;
    int idCliente = 0;
    int idMascotas = 0;
    eInformeCantidad listInformes[QUANTITY_CLIENTES];
    eCliente listClientes[QUANTITY_CLIENTES];
    eMascota listMascotas[QUANTITY_MASCOTAS];

    if(cli_initializer(listClientes, QUANTITY_CLIENTES) && masc_initializer(listMascotas, QUANTITY_MASCOTAS))
    {
        do
        {
            system("cls");
            masc_hardCodear(listMascotas, QUANTITY_MASCOTAS);
            cli_hardCodear(listClientes, QUANTITY_CLIENTES);
            info_contMascotasDeCliente(listClientes, QUANTITY_CLIENTES, listMascotas, QUANTITY_MASCOTAS, listInformes);
            if(mainMenu(&option))
            {
                switch(option)
                {
                case 1:
                    cli_menuEntity("\n>> MENU DE CLIENTES\n\n", listClientes, QUANTITY_CLIENTES, &idCliente);
                    break;
                case 2:
                    masc_menuEntity("\n>> MENU DE MASCOTAS\n\n", listMascotas, QUANTITY_MASCOTAS, &idMascotas, listClientes, QUANTITY_CLIENTES);
                    break;
                case 3:
                    info_menuEntity("\n>> MENU INFORMES\n\n", listMascotas, QUANTITY_MASCOTAS, listClientes, QUANTITY_CLIENTES, listInformes);
                    break;
                case 4:
                    printf("\n\n Saliendo del programa. Hasta luego.. :)\n");
                }
            }
        }
        while(option != 4);
    }

    return 0;
}
