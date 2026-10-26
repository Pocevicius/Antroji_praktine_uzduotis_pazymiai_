#include <iostream>
#include <string>
using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

int main() {
string vardai [MAX_MOKINIU];
    int pazymiai [MAX_MOKINIU][MAX_PAZYMIU];
    int mokiniuKiekis = 0;
    int pazymiuKiekis[MAX_MOKINIU] = {};
    int pasirinkimas;

    do {
        cout << "\n1. Ivesti mokini" << endl;
        cout << "2. Perziureti visus mokinius" << endl;
        cout << "3. Perziureti viena mokini" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Apskaiciuoti vidurki" << endl;
        cout << "6. Pasalinti mokini" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Pasirinkite: ";
        cin >> pasirinkimas;
        if (pasirinkimas == 1) {
            if (mokiniuKiekis < MAX_MOKINIU) {
                cout << "Iveskite mokinio varda" << endl;
                cin >> vardai[mokiniuKiekis];
                pazymiuKiekis[mokiniuKiekis] = 0;
                do {
                    cout << "Kiek pazymiu turi mokinys? (0-" << MAX_PAZYMIU << "): ";
                    cin >> pazymiuKiekis[mokiniuKiekis];

                    if (pazymiuKiekis[mokiniuKiekis] < 0 ||
                        pazymiuKiekis[mokiniuKiekis] > MAX_PAZYMIU) {
                        cout << "Iveskite skaiciu nuo 0 iki " << MAX_PAZYMIU << "." << endl;
                        }
                } while (pazymiuKiekis[mokiniuKiekis] < 0 ||
                         pazymiuKiekis[mokiniuKiekis] > MAX_PAZYMIU);
                for (int j = 0; j < pazymiuKiekis[mokiniuKiekis]; j++) {
                    do {
                        cout << "Iveskite " << j + 1 << ". pazymi (1-10): ";
                        cin >> pazymiai[mokiniuKiekis][j];

                        if (pazymiai[mokiniuKiekis][j] < 1 ||
                            pazymiai[mokiniuKiekis][j] > 10) {
                            cout << "Pazymys turi buti nuo 1 iki 10." << endl;
                            }
                    } while (pazymiai[mokiniuKiekis][j] < 1 ||
                             pazymiai[mokiniuKiekis][j] > 10);
                }
                mokiniuKiekis++;
                cout << "Mokinys pridetas"<< endl;
            } else {
                cout <<"Mokiniu sarasas pilnas"<< endl;
            }
        } else if (pasirinkimas == 2) {
            if (mokiniuKiekis == 0) {
                cout <<"Mokiniu sarasas tuscias"<< endl;

            } else { for (int i = 0; i < mokiniuKiekis; i++) {
                cout << i+1 <<"."<< vardai[i] << endl;
                if (pazymiuKiekis[i]==0) {
                    cout <<"Pazmiu nera"<< endl;
                }else {
                    cout << "Pazymiai: ";
                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                    cout<<pazymiai[i][j]<<" ";
                }
                    cout << endl;
                }
            }}
        } else if (pasirinkimas == 3) {
            if (mokiniuKiekis == 0) {
                cout <<"Mokiniu nera"<< endl;
            }else {
                int mokinioNumeris;

                do {
                    cout << "Iveskite mokinio numeri: ";
                    cin >> mokinioNumeris;

                    if (mokinioNumeris < 1 || mokinioNumeris > mokiniuKiekis) {
                        cout << "Neteisingas mokinio numeris. Iveskite skaiciu nuo 1 iki "
                             << mokiniuKiekis << "." << endl;
                    }
                } while (mokinioNumeris < 1 || mokinioNumeris > mokiniuKiekis);
                int indeksas = mokinioNumeris - 1;

                cout << "Mokinys: " << vardai[indeksas] << endl;

                if (pazymiuKiekis[indeksas] == 0) {
                    cout << "Pazymiu nera." << endl;
                } else {
                    cout << "Pazymiai: ";
                    for (int j = 0; j < pazymiuKiekis[indeksas]; j++) {
                        cout << pazymiai[indeksas][j] << " ";
                    }
                    cout << endl;
                }
                }
            }
        else if (pasirinkimas == 7) {
            cout << "Programa baigiama." << endl;
        } else {
            cout << "Si funkcija dar kuriama." << endl;
        }
    } while(pasirinkimas != 7);
    return 0;
}
