
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>//para controlar cadenas
#include <stdio.h>
//#include <windows.h>
//#include <ctype.h>
#include <fstream>


using namespace std;

int a;

struct videojuego {

    int id, anio;
    char nombre[100], genero[100], clasificacion[5];

}juego[150];

//void fin();
//void agregar (char producto[100][50], float pvp[100], int cantidad[100], int n);
//void eliminar(char producto[100][50], float pvp[100], int cantidad[100], int n);
//void mostrar(char producto[100][50], float pvp[100], int cantidad[100], int n);
//void menu(char producto[100][50], float pvp[100], int cantidad[100], int n);

int i = 0;
int contador, inventario;
int op, opc2, opc3, num, max = 3, id = 1, anioarticulo, articulo;
char d[100], b[100], c[100];
bool loop = true, encotrarjuego, repetir = true;
bool encontrarjuego = false;
float precio, psubtotal, piva, ptotal;
string strClasif = "";
string strGen = "";
string nombre;
string descripcion;

void agregar();
void mostrar();
void limpiar();
void eliminar();
void lista();

void main()
{
    while (loop)
    {
        cout << "\t\t1. Agregar articulo" << endl;
        cout << "\t\t2. Mostrar articulo" << endl;
        cout << "\t\t3. Eliminar articulo" << endl;
        cout << "\t\t4. Lista de articulos" << endl;
        cout << "\t\t5. Limpiar pantalla" << endl;
        cout << "\t\t0. SALIR" << endl;
        cout << "\t\Ingrese una opcion: ";

        cin >> op;

        switch (op)
        {
        case 1:
        {
            agregar();
            break;

        }
        case 2:
        {
            mostrar();
            break;
        }
        case 3:
        {
            eliminar();
            break;

        }
        case 4:
        {
            lista();
            break;
        }
        case 5:
        {
            loop = false;
            break;
        }
    deafult:
        {
            cout << "Error, intente nuevamente por favor \n\n\n";
            //limpiar();
            break;
            system("cls");
        }
        }
        return;
    }
}
void mostrar()
{
    cout << "Informacion guardada:" << endl;
    cout << "Juegos:" << juego[contador].nombre << endl;
    cout << "Genero:" << juego[contador].genero << endl;
    cout << "Clasificacion:" << juego[contador].clasificacion << endl;

}

void limpiar()
{
    cout << "¿Desea eleminar todo los mostrado en panatalla?" << endl;
    cin >> op;

    system("cls");

}

void eliminar() {
    int borrar;
    int i = 0;
    cout << "Ingrese el año del articulo a borrar\n";
    for (int i = 0; i <= 2; i++) {
        if (articulo[i].anioarticulo == NULL) {
            continue;
        }
        else {
            cout << articulo[i].anioarticulo << " - " << articulo[i].nombre << "\n";
        }
    }

    do {
        cin.clear();
        cin >> borrar;
        if (cin.fail()) {
            cout << "El año debe contener solo numeros\n";
            cout << "Ingrese el año del articulo a borrar\n";
        }
    } while (cin.fail());

    for (int i = 0; i <= 2; i++) {

        if (borrar == articulo[i].anioarticulo) {

            articulo[i].anioarticulo = articulo[i + 1].anioarticulo;
            articulo[i].nombre = articulo[i + 1].nombre;
            articulo[i].precio = articulo[i + 1].precio;
            articulo[i].contador = articulo[i + 1].contador;
            articulo[i].descripcion = articulo[i + 1].descripcion;
            articulo[i].genero = articulo[i + 1].genero;
            articulo[i].clasificacion = articulo[i + 1].clasificacion;

            articulo[i + 1].anioarticulo = NULL;
            articulo[i + 1].nombre = ' ';
            articulo[i + 1].descripcion = ' ';
            articulo[i + 1].genero = ' ';
            articulo[i + 1].clasificacion = ' ';
            articulo[i + 1].precio = NULL;
            articulo[i + 1].contador = NULL;

            return;
        }
    }

    cout << "El articulo no existe\n";
    system("pause");
    return;
}

    void agregar()
    {
        juego[contador].id = contador + 1;
        cout << "Agrega el nombre del juego: ";
        cin.getline(juego[contador].genero, 100, '\n');
        cout << "Agrega el tipo de genero: ";
        cin.getline(juego[contador].clasificacion, 5, '\n');
        cout << "Agrega el tipo de claficacion: ";
        cin.getline(juego[contador].clasificacion, 5, '\n');

       

        contador += 1;

        system("pause>null");
    }

    void lista()
    {
       /* string strClasif = "";
        string strGen = "";
        bool encontrarjuego = false*/;

        cout << "¿Como quieres obtener la lista?" << endl;
        cout << "1.Por clasificacion" << endl;
        cout << "2.Por genero" << endl;
        cout << "3.Imprimir toda la lista" << endl;

        cin >> op;

        
        switch (op)
        {
        case 1:
        {
            cout << "Introduce la clasificacion";
            cin >> strClasif;
            for (int i = 0; i < 50; i++);
            {
                if (juego[i].clasificacion == strClasif)
                {
                    cout << juego[i].nombre << endl;
                    encontrarjuego = true;
                }
            }
            if (encontrarjuego == false)
            {
                cout << "No se encontraron juegos con la clasificacion dada." << strClasif << endl;
            }
            break;
        }
        case 2:
        {

        }
        case 3:
        {
            cout << "Lista completa:" << endl;
            for (int i = 0; i < 50; i++);
            {
                cout << juego[i].nombre << endl;
            }
        }
        default:
        {
            cout << "Gracias por su atencion" << endl;
        }
        }
    }

