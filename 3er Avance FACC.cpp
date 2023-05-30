
#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
#include <fstream>
#include <windows.h>
#include <limits>

using namespace std;

int i, k, c, q, p, l, a, u, r, t, n, z, f;
int nv, vna;
char entrada[100];

struct Tienda
{
    int numero;
    string Nombre;
    string Desc;
    string Carac;
    string Gene;
    string Clasi;
    string Con;
    int NumeroDeModificacion;
    int NumeroDeBaja;
    int ano;
    int mes;
    int dia;
    float Precio;
    float Imp;
    float ConIva;
};

struct Tienda dato[100];

void Alta();
void fecha();
void modificar();
void fechan();
void Lista();
void Eliminar();
void Salir();
void guardar();
void mostrarDguardados();
void valcarac(string);
bool vnume(char texto[100]);

int main()
{
    mostrarDguardados();

    int opcion;
    do {
        //system("cls");
        cout << "\n\t * ** MENU DE OPCIONES * ** \n";
        cout << "1.-Alta de articulos \n";
        cout << "2.-Modificacion de articulos \n";
        cout << "3.-Baja de articulos \n";
        cout << "4.-Lista de articulos \n";
        cout << "5.-Limpiar pantalla \n";
        cout << "6.-Salir \n";
        cin >> opcion;

        if (opcion <= 0 || opcion >= 7)
        {
            cout << "Opcion incorrecta";  system("pause"); system("cls");
        }

    } while (opcion <= 0 || opcion >= 7);

    switch (opcion) {
    case 1:
        Alta();
        return main();
        break;
    case 2:
        modificar();
        return main();
        break;
    case 3:
        Eliminar();
        return main();
        break;
    case 4:
        Lista();
        return main();
        break;
    case 5:
        system("cls");
        return main();
        break;
    case 6:
        Salir();
        break;
    }
}

void Alta()
{
    int cr;
    cr = 0;
    do {
        cout << "Cuantos quiere registrar: ";
        cin >> entrada;

        if (vnume(entrada))
        {
            cr = stoi(entrada);
        }
        else
        {
            cout << "\nEscribe solo numeros";
        }
        if (cr <= 0)
        {
            cout << "\nError en el numero, no puede ser negativo.." << endl; system("pause");
        }

    } while (cr <= 0);

    for (i = 0; i < cr; i++)
    {
        do
        {
            do {
                cout << "\nIngrese el numero de articulo \n";
                cin >> entrada;
                if (vnume(entrada))
                {
                    dato[i].numero = stoi(entrada);
                }
                else
                {
                    cout << "\nEscribe solo numeros";
                }

                if (dato[i].numero <= 0)
                {
                    cout << "\nNumero invalido, \n";
                    cout << "\nIntente de nuevo \n";
                }
                f = 0;
                vna = dato[i].numero;
                for (z = 0; z < i; z++)
                {
                    if (vna == dato[z].numero)
                    {
                        cout << "Ese numero ya esta agendado, Nose puede repetir numeros de articulos." << endl;
                        f++;
                    }
                }
            } while (f == 1);

        } while (dato[i].numero <= 0);

        fflush(stdin);

        do
        {
            printf("\nIngrese el nombre del articulo \n");
            cin.ignore();
            getline(cin, dato[i].Nombre);
            valcarac(dato[i].Nombre);

        } while (c != 0);

        printf("\nIngrese la fecha de lanzamiento del articulo \n");
        fecha();

        do
        {
            printf("\nIngrese la descripcion del articulo \n");
            cin.ignore();
            getline(cin, dato[i].Desc);
            valcarac(dato[i].Desc);

        } while (c != 0);

        //do {
        printf("\nIngrese las caracteristicas del articulo \n");
        getline(cin, dato[i].Carac);
        valcarac(dato[i].Carac);
        // } while (c != 0);

        do
        {
            printf("\nIngrese el genero \n");
            getline(cin, dato[i].Gene);
            valcarac(dato[i].Gene);
        } while (c != 0);

        // do {
        printf("\nIngrese la clasificacion del articulo \n");
        getline(cin, dato[i].Clasi);
        valcarac(dato[i].Clasi);
        //  } while (c != 0);

        do
        {
            printf("\nIngrese la consola \n");
            getline(cin, dato[i].Con);
            valcarac(dato[i].Con);
        } while (c != 0);


        do
        {
            printf("\nIngrese el precio del articulo \n");
            cin >> entrada;
            if (vnume(entrada))
            {
                dato[i].Precio = stoi(entrada);
            }
            else
            {
                cout << "\nEscribe solo numeros";
            }
            if (dato[i].Precio <= 0)
            {
                printf("\nPrecio invalido, \n");
                printf("\nIntente de nuevo \n");
            }

        } while (dato[i].Precio <= 0);
        dato[i].Imp = dato[i].Precio * 0.16;
        dato[i].ConIva = dato[i].Precio + dato[i].Imp;
        cout << "Iva: " << dato[i].Imp << endl;
        cout << "\nPrecio con iva: " << dato[i].ConIva << endl;
    }
}

void fecha()
{
    do
    {
        printf("\nA%co:", 164);
        cin >> entrada;
        if (vnume(entrada))
        {
            dato[i].ano = stoi(entrada);
        }
        else
        {
            cout << "\nEscribe solo numeros";
        }

        if ((dato[i].ano < 1960 || dato[i].ano > 2023))
        {
            cout << "\nError en el numero ingresado" << endl; system("pause");
        }

    } while ((dato[i].ano < 1960 || dato[i].ano > 2023));


    do
    {
        cout << "\nMes:";
        cin >> entrada;
        if (vnume(entrada))
        {
            dato[i].mes = stoi(entrada);
        }
        else
        {
            cout << "\nEscribe solo numeros";
        }
        if ((dato[i].mes <= 0 || dato[i].mes > 12))
        {
            cout << "\nError en el numero ingresado" << endl; system("pause");
        }

    } while ((dato[i].mes <= 0 || dato[i].mes > 12));

    switch (dato[i].mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        do
        {
            cout << "\nDia: ";
            cin >> entrada;
            if (vnume(entrada))
            {
                dato[i].dia = stoi(entrada);
            }
            else
            {
                cout << "\nEscribe solo numeros";
            }
            if ((dato[i].dia <= 0 || dato[i].dia > 31))
            {
                cout << "\nError en el numero ingresado" << endl; system("pause");
            }

        } while ((dato[i].dia <= 0 || dato[i].dia > 31));
        break;

    case 2:
        do
        {
            cout << "\nDia: ";
            cin >> entrada;
            if (vnume(entrada))
            {
                dato[i].dia = stoi(entrada);
            }
            else
            {
                cout << "\nEscribe solo numeros";
            }
            if ((dato[i].dia <= 0 || dato[i].dia > 28))
            {
                cout << "\nError en el numero ingresado" << endl; system("pause");
            }

        } while ((dato[i].dia <= 0 || dato[i].dia > 28));
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        do
        {
            cout << "\nDia: ";
            cin >> entrada;
            if (vnume(entrada))
            {
                dato[i].dia = stoi(entrada);
            }
            else
            {
                cout << "\nEscribe solo numeros";
            }
            if ((dato[i].dia <= 0 || dato[i].dia > 30))
            {
                cout << "\nError en el numero ingresado" << endl; system("pause");
            }
        } while ((dato[i].dia <= 0 || dato[i].dia > 30));
        break;
    }
}

void modificar() {

    int ndm;
    do
    {
        system("cls");
        printf("Ingrese el numero del articulo a modificar\n");
        cin >> entrada;

        if (vnume(entrada))
        {
            ndm = stoi(entrada);
        }
        else
        {
            cout << "\nEscribe solo numeros";
        }
        if (ndm < 0)
        {
            cout << "\nError en el numero" << endl; system("pause");
        }
    } while (ndm < 0);


    for (k = 0; k < 100; k++)
    {

        if (ndm == dato[k].numero) {
            int pp;
            pp = 0;
            system("cls");
            cout << "1.Numero de articulo \n2.Nombre de articulo \n3.fecha de lanzamiento del articulo \n4.descripcion del articulo \n5.caracteristicas del articulo \n6.genero \n7.clasificacion del articulo \n8.consola \n9.precio del articulo \n\n opcion: ";
            cin >> pp;
            if (pp <= 0 || pp > 9) { cout << "\nError en el numero"; system("pause"); }


            switch (pp)
            {
            case 1:
                do
                {
                    printf("\nIngrese el numero de articulo \n");
                    cin >> entrada;
                    if (vnume(entrada))
                    {
                        dato[k].numero = stoi(entrada);
                    }
                    else
                    {
                        cout << "\nEscribe solo numeros";
                    }
                    if (dato[k].numero < 0)
                    {
                        printf("Numero invalido, \n");
                        printf("Intente de nuevo \n");
                    }
                } while (dato[k].numero < 0);
                break;

            case 2:
                do
                {
                    printf("Ingrese el nombre del articulo \n");
                    cin >> dato[k].Nombre;
                    valcarac(dato[k].Nombre);
                } while (c != 0);
                break;

            case 3:
                printf("Ingrese la fecha de lanzamiento del articulo \n");
                fechan();
                break;

            case 4:
                do
                {
                    printf("Ingrese la  descripcion del articulo\n");
                    cin >> dato[k].Desc;
                    valcarac(dato[k].Desc);

                } while (c != 0);
                break;

            case 5:
                printf("Ingrese las caracteristicas del articulo \n");
                cin >> dato[k].Carac;
                break;

            case 7:
                printf("Ingrese la clasificacion del articulo \n");
                cin >> dato[k].Clasi;
                break;

            case 8:
                do
                {
                    printf("Ingrese la consola \n");
                    cin >> dato[k].Con;
                    valcarac(dato[k].Con);

                } while (c != 0);
                break;

            case 9:
                do
                {
                    printf("\n Ingrese el precio del articulo \n");
                    cin >> entrada;
                    cin.ignore();

                    if (vnume(entrada))
                    {
                        dato[k].Precio = stoi(entrada);
                    }
                    else
                    {
                        cout << "\nEscribe solo numeros";
                    }
                    if (dato[k].Precio < 0)
                    {
                        printf("Precio invalido, \n");
                        printf("Intente de nuevo \n");
                    }

                } while (dato[k].Precio < 0);
                dato[k].Imp = dato[k].Precio * 0.16;
                dato[k].ConIva = dato[k].Precio + dato[k].Imp;
                break;

            case 6:
                do
                {
                    printf("Ingrese el genero \n");
                    cin >> dato[k].Gene;
                    valcarac(dato[k].Gene);

                } while (c != 0);
                break;
            }
        }
    }
}

void fechan()
{
    do
    {
        cout << "\nAno:";
        cin >> entrada;
        if (vnume(entrada))
        {
            dato[k].ano = stoi(entrada);
        }
        else
        {
            cout << "\nEscribe solo numeros";
        }
        if ((dato[k].ano < 1960 || dato[k].ano > 2023))
        {
            cout << "\nError en el numero ingresado" << endl; system("pause");
        }
    } while ((dato[k].ano < 1960 || dato[k].ano > 2023));

    do {
        cout << "\nMes";
        cin >> entrada;
        if (vnume(entrada))
        {
            dato[k].mes = stoi(entrada);
        }
        else {
            cout << "\nEscribe solo numeros";
        }
        if ((dato[k].mes <= 0 || dato[k].mes > 12))
        {
            cout << "\nError en el numero ingresado" << endl; system("pause");
        }
    } while ((dato[k].mes <= 0 || dato[k].mes > 12));

    switch (dato[k].mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        do {
            cout << "\nDia:";
            cin >> entrada;
            if (vnume(entrada))
            {
                dato[k].dia = stoi(entrada);
            }
            else
            {
                cout << "\nEscribe solo numeros";
            }
            if ((dato[k].dia <= 0 || dato[k].dia > 31))
            {
                cout << "\nError en el numero ingresado" << endl; system("pause");
            }
        } while ((dato[k].dia <= 0 || dato[k].dia > 31));
        break;

    case 2:
        do
        {
            cout << "\nDia:";
            cin >> entrada;
            if (vnume(entrada))
            {
                dato[k].dia = stoi(entrada);
            }
            else
            {
                cout << "\nEscribe solo numeros";
            }

            if ((dato[k].dia <= 0 || dato[k].dia > 28))
            {
                cout << "\nError en el numero ingresado" << endl; system("pause");
            }
        } while ((dato[k].dia <= 0 || dato[k].dia > 28));
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        do {
            cout << "\nDia:";
            cin >> entrada;
            if (vnume(entrada))
            {
                dato[k].dia = stoi(entrada);
            }
            else
            {
                cout << "\nEscribe solo numeros";
            }

            if ((dato[k].dia <= 0 || dato[k].dia > 30)) { cout << "\nError en el numero ingresado" << endl; system("pause"); }
        } while ((dato[k].dia <= 0 || dato[k].dia > 30));
    }
}


void Lista() {
    cout << "------------------------------------------------------------------------------------------------" << endl;
    nv = 0;
    for (u = 0; u < i; u++)
    {
        if (nv != dato[u].numero)
        {
            cout << "\nNumero de articulo: " << dato[u].numero << endl;

            cout << "\nIngrese el nombre del articulo: " << dato[u].Nombre << endl;

            cout << "\nFecha de lanzamiento del articulo: " << dato[u].dia << "/" << dato[u].mes << "/" << dato[u].ano << endl;

            cout << "\nDescripcion del articulo: " << dato[u].Desc << endl;

            cout << "\nIngrese las caracteristicas del articulo: " << dato[u].Carac << endl;

            cout << "\nGenero: " << dato[u].Gene << endl;

            cout << "\nClasificacion del articulo: " << dato[u].Clasi << endl;

            cout << "\nConsola: " << dato[u].Con << endl;

            cout << "\nPrecio del articulo: " << dato[u].Precio << endl;

            cout << "\nIva: " << dato[u].Imp << endl;

            cout << "\nPrecio con iva: " << dato[u].ConIva << endl;

            cout << "------------------------------------------------------------------------------------------------" << endl;
        }
    }
    cout << endl;
    system("pause");
}

void Eliminar()
{
    int endm;
    do
    {
        system("cls");
        printf("Ingrese el numero del articulo a eliminar\n");
        cin >> entrada;
        if (vnume(entrada))
        {
            endm = stoi(entrada);
        }
        else
        {
            cout << "\nEscribe solo numeros";
        }
        if (endm < 0)
        {
            cout << "\nError en el numero" << endl; system("pause");
        }
    } while (endm < 0);

    for (r = 0; r < i; r++)
    {
        if (endm == dato[r].numero)
        {
            dato[r].numero = 0;
            dato[r].Nombre = " ";
            dato[r].dia = 0;
            dato[r].mes = 0;
            dato[r].ano = 0;
            dato[r].Desc = " ";
            dato[r].Carac = " ";
            dato[r].Gene = " ";
            dato[r].Clasi = " ";
            dato[r].Con = " ";
            dato[r].Precio = 0;
            dato[r].Imp = 0;
            dato[r].ConIva = 0;
            cout << "\nHa sido eliminadaaa." << endl;
            system("pause");
        }
    }
}

void Salir()
{
    cout << endl << endl;
    cout << "Gracias \nSaliendoo.." << endl << endl;
    system("pause");

    guardar();
}

void valcarac(string v)
{
    c = 0;
    int n = 0;
    char b;
    for (n; n < v.size(); n++)
    {
        b = v[n];
        if (isalpha(b) == 0) { // verifica si que no es una letra

            if (isspace(b) == 0) { // verifica si el caracter es un espacio en blanco

                c++;
            }
        }
    }
    if (c != 0)
    {
        cout << "Error, ingrese el dato de nuevo " << endl;
    }
}

bool vnume(char texto[100])
{
    int val, cont, comp;
    cont = 0;
    string suplente;
    char letra;

    suplente = texto;

    comp = suplente.length();

    int gg, hh;
    int ini = 48;
    int fin = 57;
    for (gg = 0; gg <= comp; gg++)
    {
        letra = texto[gg];
        val = letra;

        for (hh = ini; hh <= fin; hh++)
        {
            if (val == hh)
            {

                cont++;
            }
        }

    }
    if (comp == cont)
    {

        return true;
    }
    else
    {
        return false;
    }
}

void guardar() {
    ofstream archivo("datos.txt", ios::out);
    if (archivo)
    {
        for (t = 0; t < i; t++) {

            archivo << dato[t].numero << "\t";
            archivo << dato[t].Nombre << "\t";
            archivo << dato[t].ano << "\t";
            archivo << dato[t].mes << "\t";
            archivo << dato[t].dia << "\t";
            archivo << dato[t].Desc << "\t";
            archivo << dato[t].Carac << "\t";
            archivo << dato[t].Gene << "\t";
            archivo << dato[t].Clasi << "\t";
            archivo << dato[t].Con << "\t";
            archivo << dato[t].Precio << "\t";
            archivo << dato[t].Imp << "\t";
            archivo << dato[t].ConIva << "\t";
            archivo << endl;
        }
    }
    else { cout << "\n\nEl archivo no existe o no ha sido creado"; }
}

void mostrarDguardados()
{
    ifstream archivo_ent("datos.txt", ios::in);
    if (archivo_ent)
    {
        while (!archivo_ent.eof()) {

            archivo_ent >> dato[i].numero;
            archivo_ent >> dato[i].Nombre;
            archivo_ent >> dato[i].ano;
            archivo_ent >> dato[i].mes;
            archivo_ent >> dato[i].dia;
            archivo_ent >> dato[i].Desc;
            archivo_ent >> dato[i].Carac;
            archivo_ent >> dato[i].Gene;
            archivo_ent >> dato[i].Clasi;
            archivo_ent >> dato[i].Con;
            archivo_ent >> dato[i].Precio;
            archivo_ent >> dato[i].Imp;
            archivo_ent >> dato[i].ConIva;
        }
        i++;
    }
}