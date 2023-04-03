#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using  namespace std;
struct Tienda 
{
   string Nombre, Desc, Gene, Clasi, Con;
   float ConIva, Imp, Precio;
   int Numero;
};

int main()
{
    Tienda data[3];
    int opcion;
    do {
        printf(" \n\t * **MENU DE OPCIONES * ** \n");
        printf("1.-Alta de articulos \n");
        printf("2.-Modificacion de articulos \n");
        printf("3.-Baja de articulos \n");
        printf("4.-Lista de articulos \n");
        printf("5.-Limpiar pantalla \n");
        printf("6.-Salir \n");
        scanf_s("%d", &opcion);
        switch (opcion)
        {
        case 1: //Dar de alta//
            for (int i = 0; i < 3; i++)
            {
                cin.ignore();
                printf("\nIngrese el numero de articulo \n");
                scanf_s("%d", &data[i].Numero);
                cin.ignore();
                printf("Ingrese el nombre del articulo \n");
                getline(cin, data[i].Nombre);
                printf("Ingrese la descripcion del articulo \n");
                getline(cin, data[i].Desc);
                printf("Ingrese el genero \n");
                getline(cin, data[i].Gene);
                printf("Ingrese la clasificacion del articulo \n");
                getline(cin, data[i].Clasi);
                printf("Ingrese la consola \n");
                getline(cin, data[i].Con);
                printf("Ingrese el precio del articulo \n");
                scanf_s("%f", &data[i].Precio);
                data[i].Imp = data[i].Precio * 0.16;
                data[i].ConIva = data[i].Precio + data[i].Imp;
            }
            break;
        case 2://Modificar//
            break;
            
        case 3://Dar de Baja//
            break;

        case 4://Lista//
            for (int i = 0; i < 3; i++)
            {
                printf("\nNumero de articulo: %d \n", data[i].Numero);
                printf("Nombre del articulo: %s \n", data[i].Nombre.c_str());
                printf("Genero: %s \n", data[i].Gene.c_str());
                printf("Clasificacion: %s \n", data[i].Clasi.c_str());
                printf("Consola: %s \n", data[i].Con.c_str());
                printf("Precio: %f \n", data[i].Precio);
                printf("Impuesto: %f \n", data[i].Imp);
                printf("Total: %f \n", data[i].ConIva);
            }
            break;
            
        case 5://Limpiar pantalla//
            system("cls");
            break;
            
        case 6://SALIR//
            exit(1);
            break;
        default:
            printf("Opcion invalida \n");
            break;
        }
    } while (opcion != 6);
}