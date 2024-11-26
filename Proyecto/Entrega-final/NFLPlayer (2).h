#ifndef NFL_PLAYER_H
#define NFL_PLAYER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NFLPlayer {
private:
    string name;
    int overallRating;
    int speed;
    int strength;
    int agility;

public:
    NFLPlayer(string playerName, int playerOverall, int playerSpeed, int playerStrength, int playerAgility)
        : name(playerName), overallRating(playerOverall), speed(playerSpeed), strength(playerStrength), agility(playerAgility) {}

    string getName() const { return name; }
    int getOverallRating() const { return overallRating; }
    int getSpeed() const { return speed; }
    int getStrength() const { return strength; }
    int getAgility() const { return agility; }

    void display() const {
        cout << name << " - Overall: " << overallRating 
             << ", Speed: " << speed 
             << ", Strength: " << strength 
             << ", Agility: " << agility << endl;
    }

    bool operator<(const NFLPlayer& other) const {
        return overallRating < other.overallRating;
    }

    bool operator>(const NFLPlayer& other) const {
        return overallRating > other.overallRating;
    }
};

// Mejor Caso: O(1) Peor Caso: O(1) Caso promedio: O(1), La función de emplace back reduce esta operación a una complejidad de O(1).
void agregarJugador(vector<NFLPlayer>& playerList, const string& name, int overall, int speed, int strength, int agility) {
    playerList.emplace_back(name, overall, speed, strength, agility);
}

// Mejor Caso: O(1) Peor Caso: O(n) Caso promedio: O(n), en el mejor caso el jugador que se quiere eliminar es el primero de la lista, en el peor caso el jugador que se quiere eliminar es el último de la lista y necesita recorrer la lista entera, en el caso promedio el jugador que se quiere eliminar está en el medio de la lista y la complejidad sigue siendo O(n)
void eliminarJugador(vector<NFLPlayer>& playerList, const string& name) {
    for (size_t i = 0; i < playerList.size(); ++i) {
        if (playerList[i].getName() == name) {
            cout << "Eliminando jugador: " << playerList[i].getName() << endl;
            playerList.erase(playerList.begin() + i);
            return;
        }
    }
    cout << "Jugador no encontrado: " << name << endl;
}

// Mejor Caso: O(log n) Caso promedio: O(log n) Peor Caso: O(log n), La complejidad siempre se reduce a la altura máxima del árbol. 

void heapify(vector<NFLPlayer>& playerList, int n, int i, const string& criterio) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    auto compare = [&](const NFLPlayer& a, const NFLPlayer& b) {
        if (criterio == "speed") return a.getSpeed() > b.getSpeed();
        if (criterio == "strength") return a.getStrength() > b.getStrength();
        if (criterio == "agility") return a.getAgility() > b.getAgility();
        return a.getOverallRating() > b.getOverallRating();
    };

    if (left < n && compare(playerList[left], playerList[largest])) {
        largest = left;
    }

    if (right < n && compare(playerList[right], playerList[largest])) {
        largest = right;
    }

    if (largest != i) {
        swap(playerList[i], playerList[largest]);
        heapify(playerList, n, largest, criterio);
    }
}

// Mejor Caso: O(n) Peor Caso: O(n) Caso promedio: O(n)

void buildMaxHeap(vector<NFLPlayer>& playerList, const string& criterio) {
    int n = playerList.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(playerList, n, i, criterio);
    }
}

// Mejor caso: O(n) Peor caso: O(n) Caso promedio: O(n).

int partition(vector<NFLPlayer>& playerList, int low, int high, const string& criterio) {
    auto compare = [&](const NFLPlayer& a, const NFLPlayer& b) {
        if (criterio == "speed") return a.getSpeed() > b.getSpeed();
        if (criterio == "strength") return a.getStrength() > b.getStrength();
        if (criterio == "agility") return a.getAgility() > b.getAgility();
        return a.getOverallRating() > b.getOverallRating();
    };

    NFLPlayer pivot = playerList[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(playerList[j], pivot)) {
            i++;
            swap(playerList[i], playerList[j]);
        }
    }
    swap(playerList[i + 1], playerList[high]);
    return i + 1;
}

// Mejor caso: O(n log n) Peor caso: O(n^2) Caso promedio: O(n log n), el quicksort en su peor caso el pivote siempre es el elemento más pequeño o el más grande, lo que produce una complejidad de O(n^2), en el resto de casos se reduce a O(n log n).

void quicksort(vector<NFLPlayer>& playerList, int low, int high, const string& criterio) {
    if (low < high) {
        int pi = partition(playerList, low, high, criterio);
        quicksort(playerList, low, pi - 1, criterio);
        quicksort(playerList, pi + 1, high, criterio);
    }
}

// O(n), se recorre toda la lista para mostrarla.
void mostrarLista(const vector<NFLPlayer>& playerList, const string& criterio) {
    cout << "\nJugadores ordenados por " << criterio << ":\n";
    for (const auto& player : playerList) {
        player.display();
    }
}

// O(1), el max heap ya tiene al mejor jugador en la posición 0 en todo momento.
void mostrarMejorJugador(const vector<NFLPlayer>& playerList, const string& criterio) {
    if (playerList.empty()) {
        cout << "La lista está vacía.\n";
        return;
    }
    vector<NFLPlayer> heap = playerList;
    buildMaxHeap(heap, criterio);
    cout << "\nMejor jugador según " << criterio << ":\n";
    heap[0].display();
}

// Mejor caso: O(n) Peor caso: O(n) Caso promedio: O(n)

void construirEquipo(const vector<NFLPlayer>& playerList, const string& criterio) {
    if (playerList.empty()) {
        cout << "La lista está vacía.\n";
        return;
    }

    NFLPlayer mejorJugador = playerList[0];

    for (const auto& player : playerList) {
        if ((criterio == "overall" && player.getOverallRating() > mejorJugador.getOverallRating()) ||
            (criterio == "speed" && player.getSpeed() > mejorJugador.getSpeed()) ||
            (criterio == "strength" && player.getStrength() > mejorJugador.getStrength()) ||
            (criterio == "agility" && player.getAgility() > mejorJugador.getAgility())) {
            mejorJugador = player;
        }
    }

    cout << "\nMejor jugador según el criterio '" << criterio << "':\n";
    mejorJugador.display();
}


#endif // NFL_PLAYER_H
