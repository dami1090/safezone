#include <stdio.h>
#include <stdlib.h>
#include "deposito.h"
#include "ArrayList.h"
#include "Parser.h"
int main()
{
    char seguir='s';
    int opcion=0;
    int resp;
    ArrayList* listaDeposito0;
    ArrayList* listaDeposito1;
    while(seguir=='s')
    {
        printf("1- Cargar Productos\n");
        printf("2- Listar \n");
        printf("3- Mover a deposito\n");
        printf("4- Descontar producto \n");
        printf("5- Agregar producto\n");
        printf("6- Salir\n");

        setbuf(stdin,NULL);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            listaDeposito0=al_newArrayList();
            if(listaDeposito0!=NULL)
            {
                if(parser("dep0.csv",listaDeposito0)==1)
                {
                    printf("\n productos leidos de deposito 0\n");
                }
                else
                {
                    printf("\n Error al leer productos de deposito 0\n");
                }
            }
            else
            {
                printf("\nNo hay lugar para crear lista de productos de deposito 0\n");
            }
            listaDeposito1=al_newArrayList();
            if(listaDeposito1!=NULL)
            {
                if(parser("dep1.csv",listaDeposito1)==1)
                {
                    printf("\n productos leidos de deposito 1\n");
                }
                else
                {
                    printf("\n Error al leer productos de deposito 1\n");
                }
            }
            else
            {
                printf("\nNo hay lugar para crear lista de productos de deposito 1\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\nQue deposito desea listar? [1|2]\n");
            setbuf(stdin,NULL);
            scanf("%d",&resp);
            if(resp==1)
            {
                mostrarMuchos(listaDeposito0);
                system("pause");
                system("cls");
            }
            else if(resp==2)
            {
                mostrarMuchos(listaDeposito1);
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nERROR al ingresar numero de deposito\n");
                system("pause");
                system("cls");
            }
            break;
        case 3:

            moverProducto(listaDeposito0, listaDeposito1);
            generarArchivo("dep0.csv",listaDeposito0);
            generarArchivo("dep1.csv",listaDeposito1);
            system("pause");
            system("cls");
            break;
        case 4:
            sacarProducto(listaDeposito0,listaDeposito1);
            generarArchivo("dep0.csv",listaDeposito0);
            generarArchivo("dep1.csv",listaDeposito1);
            system("pause");
            system("cls");
            break;
        case 5:
            AgregarProducto(listaDeposito0,listaDeposito1);
            generarArchivo("dep0.csv",listaDeposito0);
            generarArchivo("dep1.csv",listaDeposito1);
            system("pause");
            system("cls");
            break;
        case 6:
            seguir = 'n';
            break;

        default:
            printf("opcion invalida");
            system("cls");
            break;
        }
    }
    return 0;
}
