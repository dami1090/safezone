#include "deposito.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayList.h"

Deposito* deps_new(void)
{
    Deposito* returnAux;
    Deposito* aux;
    aux = (Deposito*)calloc(1,sizeof(Deposito));
    if(aux!=NULL)
    {
        returnAux=aux;
    }
    return returnAux;
}

int getProducto(Deposito* this)
{
    return this->producto;
}

int getDescrip(Deposito* this,char* desc)
{

    strcpy(desc,this->descrip);
    return 0;
}

int getCantidad(Deposito* this)
{
    return this->cantidad;
}
int setProducto(Deposito* this, char* producto)
{
    this->producto=atoi(producto);
    return 0;
}

int setDescrip(Deposito* this, char* descrip)
{
    strcpy(this->descrip,descrip);
    return 0;
}

int setCantidad(Deposito* this, char* cant)
{
    this->cantidad=atoi(cant);
    return 0;
}
int setEnteroCantidad(Deposito* this, int cant)
{
    this->cantidad=cant;
    return 0;
}


void deps_print(Deposito* this)
{
    printf("%d\t%-15s\t%d\n",this->producto,this->descrip,this->cantidad);
}

void mostrarMuchos(ArrayList* this)
{
    int i;
    void* aux;
    for(i=0; i<this->len(this); i++)
    {
        if(!(i%250))
        {
            system("pause");
        }
        aux=(Deposito*)this->get(this,i);
        deps_print(aux);
    }
    return;
}

int moverProducto(ArrayList* depo0, ArrayList* depo1)
{
    int resp,i;
    int auxNum;
    int flag=0;
    Deposito* aux0;
    Deposito* aux1;
    printf("\ningrese el num de deposito origen: [1|2]\n");
    setbuf(stdin,NULL);
    scanf("%d",&resp);
    if(resp==1)
    {
        printf("\n ingrese el numero del Producto que desea mover:\n");
        setbuf(stdin,NULL);
        scanf("%d",&auxNum);

        for(i=0;i<depo0->len(depo0);i++)
        {
            aux0=(Deposito*)depo0->get(depo0,i);
            if(auxNum==getProducto(aux0))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n No se encontro el producto en este deposito\n");
        }
        else
        {

            depo1->add(depo1,aux0);
            depo0->remove(depo0,i);
        }

    }
    else if(resp==2)
    {


    printf("\n ingrese el numero del Producto ue desea mover:\n");
        setbuf(stdin,NULL);
        scanf("%d",&auxNum);
        for(i=0;i<depo1->len(depo1);i++)
        {
            aux1=(Deposito*)depo1->get(depo1,i);
            if(auxNum==getProducto(aux1))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("\n No se encontro el producto en este deposito\n");
        }
        else
        {

            depo0->add(depo0,aux1);
            depo1->remove(depo1,i);
        }



    }
    else
    {
        printf("\nERROR al ingresar numero de deposito\n");
        system("pause");
        system("cls");
    }

    return 0;
}



int AgregarProducto(ArrayList* depo0, ArrayList* depo1)
{
    int resp,aux,i;
    int suma=0;
    Deposito* prod;

    printf("\n ingrese el numero de producto que desea agregar: \n");
    setbuf(stdin,NULL);
    scanf("%d",&resp);
    aux=buscar(resp,depo0,depo1);
    if(aux==0)
    {
        for(i=0;i<depo0->len(depo0);i++)
        {
            prod=(Deposito*)depo0->get(depo0,i);
            if(resp==getProducto(prod))
            {
                break;
            }
        }
        printf("\n ingrese la cantidad de stock a agregar:\n");
        setbuf(stdin,NULL);
        scanf("%d",&suma);
        //prod->cantidad=prod->cantidad+suma;
        setEnteroCantidad(prod, prod->cantidad+suma);
        depo0->set(depo0,i,prod);
    }
    else if(aux==1)
    {
         for(i=0;i<depo1->len(depo1);i++)
        {
            prod=(Deposito*)depo1->get(depo1,i);
            if(resp==getProducto(prod))
            {
                break;
            }
        }
        printf("\n ingrese la cantidad de stock a agregar:\n");
        setbuf(stdin,NULL);
        scanf("%d",&suma);
        //prod->cantidad=prod->cantidad+suma;
        setEnteroCantidad(prod, prod->cantidad+suma);
        depo1->set(depo1,i,prod);
    }
    else
    {
        printf("\n primero liste los depositos y corrobore los numeros\n");
        system("pause");
    }

   return 0;
}

int buscar(int resp,ArrayList* depo0, ArrayList* depo1)
{
    int i,flag=0,retorno=-1;
    Deposito* auxPro;
    for(i=0;i<depo0->len(depo0);i++)
    {
        auxPro=(Deposito*)depo0->get(depo0,i);
        if(resp == getProducto(auxPro))
        {
            flag=1;
            retorno=0;
            break;
        }

    }
    if(retorno!=0)
    {
        for(i=0; i<depo1->len(depo1); i++)
        {
            auxPro=(Deposito*)depo1->get(depo1,i);
            if(resp == getProducto(auxPro))
            {
                flag=1;
                retorno=1;
                break;
            }

        }
    }
    if(flag==0)
    {
        printf("\nno se encunetra el producto en ningun deposito\n");
        system("pause");
    }

    return retorno;
}

int sacarProducto(ArrayList* depo0, ArrayList* depo1)
{

    int resp,aux,i;
    int resta=0;
    Deposito* prod;

    printf("\n ingrese el numero de producto que desea descontar: \n");
    setbuf(stdin,NULL);
    scanf("%d",&resp);
    aux=buscar(resp,depo0,depo1);
    if(aux==0)
    {
        for(i=0;i<depo0->len(depo0);i++)
        {
            prod=(Deposito*)depo0->get(depo0,i);
            if(resp==getProducto(prod))
            {
                break;
            }
        }
        printf("\n ingrese la cantidad de stock a descontar:\n");
        setbuf(stdin,NULL);
        scanf("%d",&resta);
        if(resta>getCantidad(prod))
        {
            printf("\n la cantidad actual es menor(%d) a la  intenta descontar\n",prod->cantidad);
            system("pause");
        }
        else
        {
            //prod->cantidad=prod->cantidad-resta;
            setEnteroCantidad(prod, prod->cantidad-resta);
            depo0->set(depo0,i,prod);
        }


    }
    else if(aux==1)
    {
         for(i=0;i<depo1->len(depo1);i++)
        {
            prod=(Deposito*)depo1->get(depo1,i);
            if(resp==getProducto(prod))
            {
                break;
            }
        }
        printf("\n ingrese la cantidad de stock a descontar:\n");
        setbuf(stdin,NULL);
        scanf("%d",&resta);
        if(resta>getCantidad(prod))
        {
            printf("\n la cantidad actual es menor(%d) a la  intenta descontar\n",prod->cantidad);
            system("pause");
        }
        else
        {
            //prod->cantidad=prod->cantidad-resta;
            setEnteroCantidad(prod, prod->cantidad-resta);
            depo1->set(depo1,i,prod);
        }
    }
    else
    {
        printf("\n primero liste los depositos y corrobore los numeros\n");
        system("pause");
    }

   return 0;
}
