#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// definire headere pentru fiecare clasa in parte
#include "Proces.h"
#include "Proces_civil.h"
#include "Proces_penal.h"

// constanta -> 0 (pentru a compara 2 numere reale)
#define eps 0.00001

// variabila statica
int Proces::totalProcese;

int main ()
{
	int i = 0, n;
	float taxa_maxima = 0.0f;
	Proces *p[100];

	// citire procese pana la introducerea tastei 4
	while (true)
	{
		// afisare meniu interactiv
		int tip;
		cout << "Selectati:\n0 -> introducere proces civil\n";
		cout << "1 -> introducere proces penal\n";
		cout << "2 -> modificare stadiu al unui proces existent\n";
		cout << "3 -> afisarea unui proces existent\n";
		cout << "4 -> terminare executie\t\t\t\t\t";
		cin >> tip;
		// aici se opreste bucla de executie a programului
		if (tip == 4)
			break;
		// aici se citeste un obiect de tip Proces_civil si se
		// adauga in vectorul de obiecte de tip Proces
		if (tip == 0) {
  			p[i] = new Proces_civil();
			cin >> *p[i];
			i++;
		}
		// aici se citeste un obiect de tip Proces_penal si se
		// adauga in vectorul de obiecte de tip Proces
		else if (tip == 1){
  			p[i] = new Proces_penal();
			cin >> *p[i];
			i++;
		}
		// aici se poate modifica stadiul unui proces
		// (se citeste id-ul procesului, se identifica procesul cu id respectiv,
		// apoi i se modifica starea)
		else if (tip == 2){
			int j, id;
			cout << "\n\tIntroduceti numarul procesului in cauza: ";
			cin >> id;
			for (j = 0; j < i; j++)
                if (p[j]->get_nr_proces() == id) {
                    int proces_curent = p[j]->get_nr_proces();
                    bool stadiu_vechi = p[j]->afisare_stadiu();
                    p[j]->modificare_stadiu();
                    cout << "\tProcesului " << proces_curent << " i-a fost modificata cu succes starea din ";
                    cout << stadiu_vechi << " in " << (1 - stadiu_vechi) << "\n";
                    break;
                }

            if (j == i){
                cout << "\n\tNU exista acest proces\n\n";
            }
		}
		// aici se poate afisa un proces (este necesar doar id-ul lui)
		else if (tip == 3){
			int j, id;
			cout << "\n\tIntroduceti numarul procesului in cauza: ";
			cin >> id;
			for (j = 0; j < i; j++)
				if (p[j]->get_nr_proces() == id){
					cout << *p[j];
					break;
				}
			if (j == i)
				cout << "\n\tNU exista acest proces\n\n";
		}
		// se trateaza cazul in care se da input diferit de valorile 0-4
		else {
			cout << "\n\tSelectati DOAR 0|1|2|3|4\n\n";
		}
	}

	n = Proces::total_nr_procese();

	for(i = 0; i < n; i++)
	{
		// Downcast: Vrem sa stim daca Procesul este de tip Civil
		// pentru a putea accesa metoda taxa_timbru(),
		// in vederea calculului taxei maxime
		if (dynamic_cast<Proces_civil*>(p[i]) != NULL){
			float taxa_curenta = dynamic_cast<Proces_civil*>(p[i])->taxa_timbru();
			if(taxa_curenta - taxa_maxima > eps)
				taxa_maxima = taxa_curenta;
		}
		// Afisare proces
		cout << *p[i];
	}

	// afisare situatie finala: numar de procese + taxa maxima de timbru
	cout << "\n\nTotal = " << n << " procese\n";
	cout << "Taxa de timbru cea mai mare = " << taxa_maxima << "\n";

	return 0;
}
