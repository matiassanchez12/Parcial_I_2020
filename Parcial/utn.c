
#include "utn.h"
///****************************************************///
///DECLARACION FUNCIONES ESTATICAS
static int getString(char* str, int longitud);///NUEVO SCANF
///TOMAR Y VALIDAR PALABRAS
static int get_ValidInt(int* pResult);
static int get_ValidFloat(float* pResult);
static int get_ValidString(char* pResult, int tam);
static int get_ValidChar(char* pResult);
static int get_ValidAlphanumeric(char* pResult, int tam);
static int get_ValidTelephone(char* pResult, int tam);
static int get_ValidDni(int* pResult);
static int get_ValidEmail(char* pResult, int tam);
static int get_ValidCuit(char* pResult, int tam);
static int get_ValidDireccion(char* pResult, int tam);
///VALIDACIONES
static int isNumber(char* str);
static int isNumberFloat(char* str);
static int isString(char* str);
static int isAlphaNumeric(char* str);
static int isDireccion(char* str);
static int isTelephone(char* str);
static int isEmail(char* str);
static int isCuit(char* str);
///****************************************************///

static int getString(char* str, int longitud) /// SCANF
{
    int retorno = 0; ///ERROR
    char bufferString[4000];
    if(str != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString),stdin) != NULL && bufferString[0] != '\n')
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            strncpy(str, bufferString, longitud);
            retorno  = 1;
        }
    }
    return retorno;
}
static int get_ValidString(char* pResult, int tam) ///TOMAR ORACION
{
    int retorno = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isString(aux) && strlen(aux)<tam)
        {
            strcpy(pResult, aux);
            retorno = 1;
        }
    }
    return retorno;
}
static int get_ValidFloat(float* pResult) ///TOMA FLOAT
{
    int retorno = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isNumberFloat(aux) != 0)
    {
        *pResult = atof(aux);
        retorno = 1;
    }
    return retorno;
}
static int get_ValidInt(int* pResult) ///TOMA INT
{
    int retorno = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isNumber(aux))
    {
        *pResult = atoi(aux);
        retorno = 1;
    }
    return retorno;
}
static int get_ValidChar(char* pResult) ///TOMA CHAR
{
    int retorno = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isString(aux))
    {
        ///INGRESO UNA LETRA O VARIAS
        if(strlen(aux) == 1)
        {
            ///INGRESO SOLO UNA LETRA Y RETORNO 1
            *pResult = aux[0];
            retorno = 1;
        }
    }
    return retorno;///ERROR INGRESO MUCHAS LETRAS
}
static int get_ValidAlphanumeric(char* pResult, int tam)
{
    int retorno = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isAlphaNumeric(aux) && strlen(aux)<tam)
        {
            printf("Aux: %s ", aux);
            strcpy(pResult, aux);
            retorno = 1;
        }
    }
    return retorno;
}
static int get_ValidDireccion(char* pResult, int tam)
{
    int retorno = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isDireccion(aux) && strlen(aux)<tam)
        {
            strcpy(pResult, aux);
            retorno = 1;
        }
    }
    return retorno;
}
static int get_ValidTelephone(char* pResult, int tam)
{
    int retorno = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isTelephone(aux) && strlen(aux)<tam)
        {
            strcpy(pResult, aux);
            retorno = 1;
        }
    }
    return retorno;
}
static int get_ValidDni(int* pResult)
{
    int retorno = 0;
    char aux[200];
    if(getString(aux, sizeof(aux)) && isNumber(aux))
    {
        *pResult = atoi(aux);
        retorno = 1;
    }
    return retorno;
}
static int get_ValidEmail(char* pResult, int tam)
{
    int retorno = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isEmail(aux) && strlen(aux)<tam)
        {
            strcpy(pResult, aux);
            retorno = 1;
        }
    }
    return retorno;
}
static int get_ValidCuit(char* pResult, int tam)
{
    int retorno = 0;
    char aux[4000];

    if(pResult != NULL)
    {
        if(getString(aux, sizeof(aux)) && isCuit(aux) && strlen(aux)<tam)
        {
            strcpy(pResult, aux);
            retorno = 1;
        }
    }
    return retorno;
}

static int isNumber(char* str) ///VERIFICA SI ES SOLO NUMEROS, SINO DEVUELVE 0
{
    int retorno = 1;
    int i = 0;
    while(str[i] != '\0')
    {
        if(i == 0 && (str[i] == '+' || str[i] == '-'))
        {
            i++;
            continue;
        }
        if(str[i] > '9' || str[i] < '0')
        {
            retorno = 0;///ERROR TERMINA BUCLE
            break;
        }
        i++;
    }
    return retorno; ///TODOS NUMEROS : OK
}
static int isNumberFloat(char* str) ///VERIFICA SI ES SOLO NUMEROS FLOAT, SINO DEVUELVE 0
{
    int retorno = 1;
    int i = 0;
    if(str[0] == '-')
    {
        i = 1;
    }
    while(str[i] != '\0')
    {
        if (str[i] == '.')
        {
            i++;
            continue;
        }
        if(str[i] < '0' || str[i] > '9')
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}
static int isString(char* str) ///VERIFICA SI ES SOLO LETRAS, SINO DEVUELVE 0
{
    int retorno = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            retorno = 0;///ERROR
            break;
        }
        i++;
    }
    return retorno; ///TODO OK
}
static int isAlphaNumeric(char* str) ///VERIFICA SI ES ALFANUMERICO, SINO DEVUELVE 0
{
    int retorno = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '1' || str[i] > '9'))
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno; ///TODO OK
}

static int isDireccion(char* str) ///VERIFICA SI ES ALFANUMERICO, SINO DEVUELVE 0
{
    int retorno = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '1' || str[i] > '9'))
        {
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno; ///TODO OK
}

static int isTelephone(char* str) ///VERIFICA SI ES UN TELEFONO, SINO DEVUELVE 0
{
    int retorno = 1;
    int i=0;
    int count = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '-')
        {
        count ++;
        }
        if((str[i] != '-') && (str[i] > '9' || str[i] < '0'))
        {
            retorno = 0;
            break;
        }
        i++;
    }
    if(count != 1)
    {
        retorno = 0;
    }
    return retorno; ///TODO OK
}

static int isEmail(char* str) ///VERIFICA SI ES UN EMAIL, SINO DEVUELVE 0
{
    int retorno = 1;
    int i=0;
    int count = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '@' || str[i] == '.')
        {
        count ++;
        }
        if((str[i] != '@') && (str[i] != '.') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '1' || str[i] > '9'))
        {
            retorno = 0;
            break;
        }
        i++;
    }
    if(count != 2)
    {
        retorno = 0;
    }
    return retorno; ///TODO OK
}

static int isCuit(char* str) ///VERIFICA SI ES UN EMAIL, SINO DEVUELVE 0
{
    int retorno = 1;
    int i=0;
    int count = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '-')
        {
        count ++;
        }
        if((str[i] != '-') && (str[i] < '1' || str[i] > '9'))
        {
            retorno = 0;
            break;
        }
        i++;
    }
    if(count != 2)
    {
        retorno = 0;
    }
    return retorno; ///TODO OK
}

int utn_getNumber(int* pResult, char* msg,char* msgError, int min, int max, int attemps)
{
    int retorno = 0;
    int aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && min <= max && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidInt(&aux) && aux <= max && aux >= min)
            {
                *pResult = aux;
                retorno  = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
int utn_getNumberFloat(float* pResult,char* msg,char* msgError,float min, float max, int attemps)
{
    int retorno = 0;
    float aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && min <= max && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidFloat(&aux) && aux <= max && aux >= min)
            {
                *pResult = aux;
                retorno  = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
int utn_getChar(char* pResult, char* msg,char* msgError, int attemps)
{
    int retorno = 0;
    char aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidChar(&aux)) ///SI ES ERROR ES PORQUE INGRESO MAS DE UNA LETRA O INGRESO NUMEROS
            {
                *pResult = aux;
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
int utn_getString(char* pResult, int lenght, char* msg,char* msgError, int attemps)
{
    int retorno = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidString(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
int utn_getOnlyTwoChars(char* pResult, char* msg, char* msgError, char charOne, char charTwo, int attemps)
{
    int retorno = 0;
    char aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidChar(&aux)&& (aux == charOne || aux == charTwo))
            {
                *pResult = aux;
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
int utn_getAlphanumeric(char* pResult,int lenght, char* msg,char* msgError, int attemps)
{
    int retorno = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidAlphanumeric(aux, sizeof(aux))  &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
int utn_getDireccion(char* pResult,int lenght,char* msg,char* msgError, int attemps)
{
    int retorno = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidDireccion(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
int utn_getTelephone(char* pResult,int lenght,char* msg,char* msgError, int attemps)
{
    int retorno = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidTelephone(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}

int utn_getDni(int* pResult, char* msg,char* msgError, int min, int max, int attemps)
{
    int retorno = 0;
    int aux;
    if(pResult != NULL && msg != NULL && msgError != NULL && min <= max && attemps >= 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);
            if(get_ValidDni(&aux) && aux <= max && aux >= min )
            {
                *pResult = aux;
                retorno  = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}

int utn_getEmail(char* pResult,int lenght,char* msg,char* msgError, int attemps)
{
    int retorno = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidEmail(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}

int utn_getCuit(char* pResult,int lenght, char* msg,char* msgError, int attemps)
{
    int retorno = 0;
    char aux[4000];
    if(pResult != NULL && msg != NULL && msgError != NULL && attemps > 0)
    {
        while(attemps >= 0)
        {
            attemps --;
            printf("%s", msg);

            if(get_ValidCuit(aux, sizeof(aux)) &&  strlen(aux) <= lenght)
            {
                strcpy(pResult, aux);
                retorno = 1;
                break;
            }
            printf("%s", msgError);
        }
    }
    return retorno;
}
