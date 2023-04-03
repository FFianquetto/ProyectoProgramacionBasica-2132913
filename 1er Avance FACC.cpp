#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float iva, num, pre, total;
    int opcion;
    char des[100], ge[20], cla[20], con[20];
    
    cout << "\t ***MENU DE OPCIONES***" << endl; 
    cout << "1.-Alta de articulos" << endl;
    cout << "2.-Modelos de articulos" << endl;
    cout << "3.-Baja de articulos" << endl;
    cout << "4.-Lista de articulos" << endl;
    cout << "5.-Limpiar Pantalla" << endl;
    cout << "6.-Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "Ingrese el numero del articulo" << endl;
        cin >> num;
        if (0>=num)
        {
         cout << "Numero invalido"<< endl;
        }
        else 
        {
         cout << "Descripción del articulo" << endl;
         cin >> des;
         cout << "Genero del articulo" << endl;
         cin >> ge;
         cout << "Clasficiacion del articulo" << endl;
         cin >> cla;
         cout << "Consola del articulo" << endl;
         cin >> con;
         cout << "Precio del articulo" << endl;
         cin >> pre;
         iva = pre*0.16;
         cout << "Impuesto del articulo: " << iva << endl;
         cout << "" << endl;
         total = iva + pre;
         cout << "Total del articulo: " << total << endl;
         
        }
    
        break;
    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        system("cls"); // limpiar pantalla
        return main();
        break;
    case 6:
        exit(1); // cierra la pantalla
        break;
        
        

    }
  
}
