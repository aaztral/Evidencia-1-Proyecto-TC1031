#include "WideReceivers.h"

int main() {
    vector<WideReceiver> wrList;  // Lista vacía al inicio

    cout << "=== Caso de Prueba 1 ===\n";
    // Caso de Prueba 1: Agregar jugadores uno a uno
    agregarJugador(wrList, "Stefon Diggs", 92);
    agregarJugador(wrList, "Ja'Marr Chase", 93);
    agregarJugador(wrList, "Tyreek Hill", 99);
    agregarJugador(wrList, "CeeDee Lamb", 96);
    agregarJugador(wrList, "Justin Jefferson", 98);
    agregarJugador(wrList, "Mike Evans", 91);
    agregarJugador(wrList, "Terry McLaurin", 89);
    agregarJugador(wrList, "D.K. Metcalf", 87);
    agregarJugador(wrList, "Davante Adams", 94);
    agregarJugador(wrList, "A.J. Brown", 95);

    quicksort(wrList, 0, wrList.size() - 1);
    mostrarLista(wrList);
    mostrarMejorJugador(wrList);

    cout << "\n=== Caso de Prueba 2 ===\n";
    // Caso de Prueba 2: Agregar y eliminar jugadores
    agregarJugador(wrList, "DeAndre Hopkins", 90);  // Agregar un nuevo jugador
    eliminarJugador(wrList, "Tyreek Hill");          // Eliminar a Tyreek Hill

    quicksort(wrList, 0, wrList.size() - 1);
    mostrarLista(wrList);
    mostrarMejorJugador(wrList);

    return 0;
}
