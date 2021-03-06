// Sortowanie bąbelkowe.
#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

class Tablica
{
  int n; // rozmiar
  unique_ptr<int[]> tablica;
  // int* tablica = new int[n];

public:
  void sortowanie(int i); // Metoda do sortowania tablicy
  void wyswietlanie();    // Metoda do wyświetlania tablicy.
  Tablica(); // konstruktor, który generuje losowe wartości do tablicy
  ~Tablica();
};

Tablica::Tablica()
{
  n = 20;
  tablica = make_unique<int[]>(n);
  for (int i = 0; i < n; i++) {
    tablica[i] = (rand() % 100);
  }
}

Tablica::~Tablica() {}

void
Tablica::sortowanie(int i)
{
  if (i < n) {
    for (int j = 0; j < n - 1; j++) {
      if (tablica[j] > tablica[j + 1]) {
        swap(tablica[j], tablica[j + 1]);
      }
    }
    sortowanie(i + 1);
  } else
    return;
}

void
Tablica::wyswietlanie()
{
  for (int k = 0; k < n; k++) {
    cout << tablica[k] << "\t";
  }
}

int
main()
{
  Tablica K;
  K.sortowanie(0);
  K.wyswietlanie();
  return 0;
}
