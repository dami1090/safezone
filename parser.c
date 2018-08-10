#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Parser.h"
#include "deposito.h"

int parser(char* fileName, ArrayList* lista)
{
    int retorno=0;
    char auxProducto[10],auxDescrip[100],auxCantidad[10];
    Deposito* deps;
    Deposito* aux;
    FILE* pFile;

    pFile=fopen(fileName,"r");

    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxProducto,auxDescrip,auxCantidad);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxProducto,auxDescrip,auxCantidad);
            aux=deps_new();
            if(aux!=NULL)
            {
                deps=aux;
                setProducto(deps,auxProducto);
                setDescrip(deps,auxDescrip);
                setCantidad(deps,auxCantidad);
                lista->add(lista,deps);
            }
            else
            {
                printf("\nNo hay mas espacio\n");
            }
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;// OK
}

int generarArchivo(char* fileName,ArrayList* lista)
{
    int retorno=0,i;
    FILE *fp;
    Deposito* auxElement;
    int auxProdu,auxCantidad;

    char auxDescrip[51];

    fp = fopen ( fileName, "w+" );
    if(fp!=NULL)
    {
        fprintf(fp,"producto,descrip,cantidad\n");
        for(i=0; i<lista->len(lista); i++)
        {
            auxElement=(Deposito*)lista->get(lista,i);
            /*fprintf(fp,"%d,",auxElement->producto);
            fprintf(fp,"%s,",auxElement->descrip);
            fprintf(fp,"%d\n",auxElement->cantidad);*/
            auxProdu=getProducto(auxElement);
            getDescrip(auxElement,auxDescrip);
            auxCantidad=getCantidad(auxElement);
            fprintf(fp,"%d,",auxProdu);
            fprintf(fp,"%s,",auxDescrip);
            fprintf(fp,"%d\n",auxCantidad);

        }
        retorno=1;
    }
    else
    {
        printf("\nNo pudo crearse el archivo\n");
    }
    fclose ( fp );

    return retorno;
}

