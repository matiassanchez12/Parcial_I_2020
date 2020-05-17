#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericas.h"
#include "cliente-mascota.h"

#define QUANTITY_CLIENTES 6
#define QUANTITY_MASCOTAS 11
/***
*FALTA:
** AVERIGUAR SI TODOS LOS INFORMES SON EN FORMA DE LISTAS O SI PUEDEN SER EN MODO DE LECTURA.
***/
int main()
{
    int option;
    int idCliente = 0;
    int idMascotas = 0;
    eCliente listClientes[QUANTITY_CLIENTES];
    eMascota listMascotas[QUANTITY_MASCOTAS];

    if(cli_initializer(listClientes, QUANTITY_CLIENTES) && masc_initializer(listMascotas, QUANTITY_MASCOTAS))
    {
        do
        {
            system("cls");
            masc_hardCodear(listMascotas, QUANTITY_MASCOTAS);
            cli_hardCodear(listClientes, QUANTITY_CLIENTES);
            if(mainMenu(&option))
            {
                switch(option)
                {
                case 1:
                    cli_menuEntity("\n>>MENU DE CLIENTES\n\n", listClientes, QUANTITY_CLIENTES, &idCliente);
                    break;
                case 2:
                    masc_menuEntity("\n>>MENU DE MASCOTAS\n\n", listMascotas, QUANTITY_MASCOTAS, &idMascotas, listClientes, QUANTITY_CLIENTES);
                    break;
                case 3:
                    info_menuEntity("\nMENU INFORMES", listMascotas, QUANTITY_MASCOTAS, listClientes, QUANTITY_CLIENTES);
                    break;
                }
            }
        }
        while(option != 4);
    }

    return 0;
}
