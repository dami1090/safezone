 #ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "ArrayList.h"

 typedef struct{
     int producto;
     char descrip[51];
     int cantidad;
 }Deposito;

Deposito* deps_new(void);
int getProducto(Deposito* this);
int getDescrip(Deposito* this,char* desc);
int getCantidad(Deposito* this);
int setProducto(Deposito* this, char* producto);
int setDescrip(Deposito* this, char* descrip);
int setCantidad(Deposito* this, char* cant);
int setEnteroCantidad(Deposito* this, int cant);
void deps_print(Deposito* this);
void mostrarMuchos(ArrayList* this);
int moverProducto(ArrayList* depo0, ArrayList* depo1);
int sacarProducto(ArrayList* depo0, ArrayList* depo1);
int AgregarProducto(ArrayList* depo0, ArrayList* depo1);
int buscar(int producto,ArrayList* depo0, ArrayList* depo1);
#endif
