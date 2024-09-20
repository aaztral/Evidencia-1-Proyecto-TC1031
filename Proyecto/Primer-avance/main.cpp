#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WideReceiver {
private:
    string name;
    int rating;

public:
    WideReceiver(string playerName, int playerRating) {
        name = playerName;
        rating = playerRating;
    }

    string getName() const {
        return name;
    }

    int getRating() const {
        return rating;
    }

    void setRating(int newRating) {
        rating = newRating;
    }

    // Método para mostrar la información (nombre, overall rating) del Wide Receiver (1)
    void display() const {
        cout << name << " - Rating: " << rating << endl;
    }
};

int main() {
    // Lista de 10 Wide Receivers con sus overall ratings en Madden 24
    vector<WideReceiver> wrList = {
        WideReceiver("Stefon Diggs", 92),
        WideReceiver("Ja'Marr Chase", 93),
        WideReceiver("Tyreek Hill", 99),
        WideReceiver("CeeDee Lamb", 96),
        WideReceiver("Justin Jefferson", 98),
        WideReceiver("Mike Evans", 91),
        WideReceiver("Terry McLaurin", 89),
        WideReceiver("D.K. Metcalf", 87),
        WideReceiver("Davante Adams", 94),
        WideReceiver("A.J. Brown", 95)
    };

    // Mostrar la lista antes de ordenar
    cout << "Lista de Wide Receivers:\n";
    for (const auto &wr : wrList) {
        wr.display();
    }

    // Implementación del QuickSort 
    int partition(vector<WideReceiver> &wrList, int low, int high){
        int pivot = wrList[low].getRating();
        int i = low + 1;
        for(int j = i; j <= high; j++){
            if(wrList[j].getRating() < pivot){
                swap(wrList[i], wrList[j]);
                i++;
            }
        }
        swap(wrList[low], wrList[i - 1]);
        return i - 1;
    }
    
    void quicksort(vector<WideReceiver>& wrList, int low, int high){
        if (low < high) {
            int pivot = partition(wrList, low, high);
            quicksort(wrList, low, pivot - 1);
            quicksort(wrList, pivot + 1, high);
        }
    };
    
    // Mostrar la lista de Wide Receivers después de ordenar
    cout << "\nLista de Wide Receivers ordenados por Overall Rating en Madden 25:\n";
    for (const auto &wr : wrList) {
        wr.display();
    }

    return 0;
}
