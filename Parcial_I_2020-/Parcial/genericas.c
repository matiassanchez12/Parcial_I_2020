
#include "genericas.h"
/** \brief Imprime el menu principal del programa
 *
 * \param option int* opcion elegida por el usuario
 * \return int Devuelve 1 opcion tomada exitosamente, caso contrario 0.
 *
 */
int mainMenu(int* option)
{
    int retorno = 0;
    if(option != NULL)
    {
        printf(">> Bienvenido al menu principal<<\n");
        printf("\n[1] Menu ABM de CLIENTES");
        printf("\n[2] Menu ABM de MASCOTAS");
        printf("\n[3] Menu de INFORMES");
        printf("\n[4] Baja en cascada de CLIENTES");
        printf("\n[5] Salir del programa");
        if(utn_getNumber(option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 5, 2))
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Verifica el valor que retorna una funcion y imprime un mensaje
 *
 * \param function int funcion a verificar
 * \param msgAllRight char* Mensaje de exito (1)
 * \param msgError char* Mensaje de Error (0)
 * \return void
 *
 */
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

/** \brief Verifica el valor que retorna una funcion y imprime un mensaje
 *
 * \param function int funcion a verificar su retorno
 * \param msgAllRight char* Mensaje de exito (1)
 * \param msgError char* Mensaje de Error (-1)
 * \param msgCancelOp char* Mesaje de cancelacion(0)
 * \return void
 *
 */
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
