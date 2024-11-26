#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "NFLPlayer.h"

using namespace std;

// Función para leer jugadores desde un archivo
void cargarJugadoresDesdeArchivo(const string& nombreArchivo, vector<NFLPlayer>& playerList) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre;
        int overall, speed, strength, agility;

        // Leer los valores separados por comas
        getline(ss, nombre, ',');
        ss >> overall;
        ss.ignore();
        ss >> speed;
        ss.ignore();
        ss >> strength;
        ss.ignore();
        ss >> agility;

        // Agregar jugador a la lista
        agregarJugador(playerList, nombre, overall, speed, strength, agility);
    }

    archivo.close();
    cout << "Jugadores cargados desde " << nombreArchivo << " con éxito.\n";
}

void menuPrincipal() {
    cout << "\n=== Menú Principal ===\n";
    cout << "1. Quarterbacks (QBs)\n";
    cout << "2. Wide Receivers (WRs)\n";
    cout << "3. Running Backs (RBs)\n";
    cout << "4. Construir equipo\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

void gestionarJugadores(vector<NFLPlayer>& playerList) {
    int opcion;
    do {
        cout << "\n=== Opciones ===\n";
        cout << "1. Agregar jugador\n";
        cout << "2. Eliminar jugador\n";
        cout << "3. Mostrar lista ordenada\n";
        cout << "4. Mostrar mejor jugador\n";
        cout << "5. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string name;
            int overall, speed, strength, agility;
            cout << "Ingrese el nombre del jugador: ";
            cin.ignore();
            getline(cin, name);
            cout << "Ingrese el rating general (overall): ";
            cin >> overall;
            cout << "Ingrese la velocidad: ";
            cin >> speed;
            cout << "Ingrese la fuerza: ";
            cin >> strength;
            cout << "Ingrese la agilidad: ";
            cin >> agility;
            agregarJugador(playerList, name, overall, speed, strength, agility);
            cout << "Jugador agregado con éxito.\n";
            break;
        }
        case 2: {
            string name;
            cout << "Ingrese el nombre del jugador a eliminar: ";
            cin.ignore();
            getline(cin, name);
            eliminarJugador(playerList, name);
            break;
        }
        case 3: {
            string criterio;
            cout << "Ingrese el criterio para ordenar la lista (overall, speed, strength, agility): ";
            cin >> criterio;
            quicksort(playerList, 0, playerList.size() - 1, criterio);
            mostrarLista(playerList, criterio);
            break;
        }
        case 4: {
            string criterio;
            cout << "Ingrese el criterio para mostrar el mejor jugador (overall, speed, strength, agility): ";
            cin >> criterio;
            mostrarMejorJugador(playerList, criterio);
                break;
            }
        case 5:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
}

int main() {
    vector<NFLPlayer> qbList, wrList, rbList;

    cargarJugadoresDesdeArchivo("QuarterBa.txt", qbList);
    cargarJugadoresDesdeArchivo("WideRec.txt", wrList);
    cargarJugadoresDesdeArchivo("RunningBa.txt", rbList);

    int opcion;
    do {
        menuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestionarJugadores(qbList);
            break;
        case 2:
            gestionarJugadores(wrList);
            break;
        case 3:
            gestionarJugadores(rbList);
            break;
        case 4: {
            string criterio;
            cout << "Ingrese el criterio para construir el equipo (overall, speed, strength, agility): ";
            cin >> criterio;
            construirEquipo(qbList, criterio);
            construirEquipo(wrList, criterio);
            construirEquipo(rbList, criterio);
            break;
        }
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
