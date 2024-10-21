#ifndef WIDERECEIVERS_H
#define WIDERECEIVERS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // find_if

using namespace std;

class WideReceiver {
private:
    string name;
    int rating;

public:
    WideReceiver(string playerName, int playerRating)
        : name(playerName), rating(playerRating) {}

    string getName() const { return name; }
    int getRating() const { return rating; }

    void display() const {
        cout << name << " - Rating: " << rating << endl;
    }

    bool operator<(const WideReceiver& other) const {
        return rating < other.rating;
    }

    bool operator>(const WideReceiver& other) const {
        return rating > other.rating;
    }
};

// Función para agregar un Wide Receiver a la lista
void agregarJugador(vector<WideReceiver>& wrList, const string& name, int rating) {
    wrList.emplace_back(name, rating);
}

// Función para eliminar un Wide Receiver por nombre
void eliminarJugador(vector<WideReceiver>& wrList, const string& name) {
    auto it = find_if(wrList.begin(), wrList.end(), [&name](const WideReceiver& wr) {
        return wr.getName() == name;
    });

    if (it != wrList.end()) {
        cout << "Eliminando jugador: " << it->getName() << endl;
        wrList.erase(it);
    } else {
        cout << "Jugador no encontrado: " << name << endl;
    }
}

// Función para mantener la propiedad del Max-Heap
void heapify(vector<WideReceiver>& wrList, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && wrList[left] > wrList[largest]) {
        largest = left;
    }

    if (right < n && wrList[right] > wrList[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(wrList[i], wrList[largest]);
        heapify(wrList, n, largest);
    }
}

// Función para construir el Max-Heap
void buildMaxHeap(vector<WideReceiver>& wrList) {
    int n = wrList.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(wrList, n, i);
    }
}

// Función para aplicar Quicksort
int partition(vector<WideReceiver>& wrList, int low, int high) {
    int pivot = wrList[high].getRating();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (wrList[j].getRating() > pivot) {  
            i++;
            swap(wrList[i], wrList[j]);
        }
    }
    swap(wrList[i + 1], wrList[high]);
    return i + 1;
}

void quicksort(vector<WideReceiver>& wrList, int low, int high) {
    if (low < high) {
        int pi = partition(wrList, low, high);
        quicksort(wrList, low, pi - 1);
        quicksort(wrList, pi + 1, high);
    }
}

// Función para mostrar la lista ordenada
void mostrarLista(const vector<WideReceiver>& wrList) {
    cout << "\nWide Receivers ordenados por Overall Rating:\n";
    for (const auto& wr : wrList) {
        wr.display();
    }
}

// Función para mostrar al mejor Wide Receiver usando Max-Heap
void mostrarMejorJugador(const vector<WideReceiver>& wrList) {
    vector<WideReceiver> heap = wrList;
    buildMaxHeap(heap);
    cout << "\nMejor Wide Receiver según el rating en Madden 24:\n";
    heap[0].display();
}

#endif // WIDERECEIVERS_H
