
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "mascota.h"

typedef struct
{
    int idCliente;
    char nombreCliente[50];
    int cantidadMascotas;
    int isEmpty;
}eInformeCantidad;

void info_menuEntity(char* msgTitleMenu, eMascota* listMascotas, int lenMascotas,eCliente* listClientes, int lenClientes, eInformeCantidad* listInformes);
void info_mostrarClienteConMascotas(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
int info_sortAndPrint(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
void info_mostrarClienteConMasDeUnaMascota(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
void info_mostrarClienteConMascotasMayoresAtres(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
void info_contMascotasDeCliente(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas, eInformeCantidad* arrayDeInformes);

void info_printListClientes(eInformeCantidad* list, int len);
int info_sortClientePorCantidad(eInformeCantidad* listInformes, int lenClientes);
int info_sortClientePorCantidadYNombre(eInformeCantidad* listInformes, int lenClientes);
int info_menuParaMostrarClientesOrdenados(eInformeCantidad* listInformes, int lenListClientes);
void info_ListarDueñosconMascotasDelMismoSexo(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
int info_menuPromediarEdadMascotas(eMascota* list, int len);

int info_bajaEnCascadaCliente(eCliente* list, int len, eMascota* listMascotas, int lenMascotas);
