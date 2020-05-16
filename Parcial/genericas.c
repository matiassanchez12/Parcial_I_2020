
#include "genericas.h"
int mainMenu(int* option)
{
    int retorno = 0;
    if(option != NULL)
    {
        printf(">> Bienvenido al menu principal<<\n");
        printf("\n[1] Menu ABM de CLIENTES");
        printf("\n[2] Menu ABM de MASCOTAS");
        printf("\n[3] Menu INFORMES");
        printf("\n[4] Salir del programa");
        if(utn_getNumber(option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 4, 2))
        {
            retorno = 1;
        }
    }
    return retorno;
}

void gen_checkReturnWithIf(int function, char* msgAllRight, char* msgError)
{
    if(function)
    {
        printf("%s", msgAllRight);
    }
    else
    {
        printf("%s", msgError);
    }
}
void gen_checkReturnWithSwitch(int function, char* msgAllRight, char* msgCancelOp, char* msgError)
{
    switch(function)
    {
    case -1:
        printf("%s", msgError);
        break;

    case 0:
        printf("%s", msgCancelOp);
        break;

    case 1:
        printf("%s", msgAllRight);
        break;
    }
}
