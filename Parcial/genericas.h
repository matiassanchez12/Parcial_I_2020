
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

///TOTALMENTE GENERICAS
void gen_checkReturnWithSwitch(int function, char* msgAllRight, char* msgCancelOp, char* msgError);
void gen_checkReturnWithIf(int function, char* msgAllRight, char* msgError);
float gen_promedio(int count, int acum);
int mainMenu(int* option);
