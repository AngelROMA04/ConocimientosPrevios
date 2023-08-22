#include <iostream>
#include <string.h>

using namespace std;

struct CD
{
    int codigo;
    char artista[30];
    char album[30];
    int no_canciones;
    float precio;
    int existencias;
};

void aggCD(int numCD, int code, CD CDs[50]) {
    CDs[numCD].codigo=code;
    cout << "Ingresa el nombre del artista: ";cin >> CDs[numCD].artista;
    cout << "Ingresa el nombre del album: ";cin >> CDs[numCD].album;
    cout << "Ingresa el numero de canciones: ";cin >> CDs[numCD].no_canciones;
    cout << "Ingresa el precio del CD: ";cin >> CDs[numCD].precio;
    cout << "Ingresa las existencias del CD: ";cin >> CDs[numCD].existencias;
    system("CLS");
}

int buscarCD(int code, CD CDs[50]) {
    int i;for (i = 0;CDs[i].codigo != code;i++);return i;
}

void editCD(int code, CD CDs[50]) {
    int i = buscarCD(code, CDs); aggCD(i, code, CDs);
}

void mostrarCD(int numCD, CD CDs[50]) {
    int i = numCD;
    std::cout << "\nCD NUMERO:" << i+1 << "\nCodigo:" << CDs[i].codigo << endl;
    std::cout << "Artista: " << CDs[i].artista << "\nAlbum: " << CDs[i].album << "\nNo. de canciones: " << CDs[i].no_canciones << "\nPrecio: " << CDs[i].precio << "\nExistencias: " << CDs[i].existencias << endl;
}

void sellCD(int code, CD CDs[50]) {
    int i = buscarCD(code, CDs);CDs[i].existencias--;
    cout << "CD VENDIDO POR $" << CDs[i].precio << endl;system("PAUSE");
}

int main()
{
    int numCDs = 0, codeCHK, i;
    bool cCHK=true;
    struct CD CDs[50];
    for (int j = 0;j < 50;j++) { CDs[j].codigo = 0; }
    char opc;
    do {
        system("CLS");
        cout << "   Control de CDs \n Elige una opcion:\n1. Agregar CD\n2. Mostrar todos los CDs\n3. Buscar por codigo\n4. Modificar\n5. Realizar una venta\n6. Salir" << endl;
        cout << "Tu seleccion (ingresa el numero): "; cin >> opc;

        switch (opc) {
        case '1':
            system("CLS");
            i = 0;
            cout << "   1. AGREGAR CD   \n\nIngresa el codigo del nuevo CD: ";cin >> codeCHK;
            do {
                if (codeCHK == CDs[i].codigo) {
                    cout << "El codigo ya fue registrado" << endl;system("pause");cCHK = false;break;
                }
                i++;
            } while (i < 50);
            if (cCHK == true) {
                aggCD(numCDs, codeCHK, CDs);numCDs++;
                cout << "CD guardado con exito..." << endl;
                system("pause");
            }
            break;
        case '2':
            system("CLS");
            cout << "   2. MOSTRAR TODOS LOS CDs\n" << endl;
            for (i = 0;i < numCDs;i++) { mostrarCD(i, CDs); }
            system("pause");
            break;
        case '3':
            system("CLS");
            cout << "   3. BUSCAR POR CODIGO\n\nIngresa el codigo del CD que deseas ver los datos: ";cin >> codeCHK;
            mostrarCD(buscarCD(codeCHK, CDs), CDs);
            system("PAUSE");
            break;
        case '4':
            system("CLS");
            cout<<"   4. MODIFICAR DATOS\n\nIngresa el codigo del CD que deseas modificar: ";cin >> codeCHK;
            cout << "DATOS DEL CD: ";mostrarCD(buscarCD(codeCHK, CDs), CDs);system("PAUSE");system("CLS");
            editCD(codeCHK, CDs);
            break;
        case '5':
            system("CLS");
            cout<<"   5. REALIZAR UNA VENTA\n\nIngresa el codigo del CD que deseas vender: ";cin >> codeCHK;
            cout << "DATOS DEL CD: ";mostrarCD(buscarCD(codeCHK, CDs), CDs);system("PAUSE");system("CLS");
            sellCD(codeCHK, CDs);
            break;
        case '6':
            exit(0);
            break;
            return 0;
        default:cout << "\n    Ingresa una opcion valida!" << endl; system("pause");
        }
    } while (1);
}
