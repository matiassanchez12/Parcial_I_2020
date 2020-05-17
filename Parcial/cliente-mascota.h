
///MOSTRAR ID Y NOMBRE DEL CLI CON LOS DATOS DE LAS MASC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "mascota.h"
void info_menuEntity(char* msgTitleMenu, eMascota* listMascotas, int lenMascotas ,eCliente* listClientes, int lenClientes);
void info_mostrarClienteConMascotas(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
int info_sortAndPrint(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
void info_mostrarClienteConMasDeUnaMascota(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
void info_mostrarClienteConMascotasMayoresAtres(eCliente* listClientes, int lenClientes, eMascota* listMascotas, int lenMascotas);
