#include "funkcijos.h"

mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
uniform_int_distribution<int> dist(0, 10);

int generuotiSkaiciu() {
    return dist(mt);
}

void intIvedimas(int& priskirti, int lowerBound, int upperBound, int stoppage) {
    if (random == 0) {
        cin >> priskirti;
        while ((cin.fail() || (priskirti > upperBound && upperBound != -1) || priskirti < lowerBound) && priskirti != stoppage) {
            cout << "Bloga ivestis, ivesti sveika skaiciu is [" << lowerBound << " , ";
            if (upperBound == -1) {
                cout << "int32lim]\n";
            }
            else {
                cout << upperBound << "]\n";
            }
            cin.clear();
            cin.ignore(80, '\n');
            cin >> priskirti;
        }
    }
    else {
        priskirti = generuotiSkaiciu();
        cout << "Atsitiktinai priskirta " << priskirti << "\n";
    }
}



int pasirinktiMedArVid(int& pasirinkimas) {
    cout << "Ar norite, jog galutiniam bale butu naudojamas namu darbu vidurkis ar mediana?\nIvesti 0 arba 1\n0 - Mediana, 1 - Vidurkis\n";
    intIvedimas(pasirinkimas, 0, 1);
    return pasirinkimas;
}

void vectorOptimizacija(vector<Studentas>& sar, vector <Studentas>& vargsiukai) {
    partition(sar.begin(), sar.end(), [](const Studentas& s) { return s.getRez() < 5.00; });
    auto it = find_if(sar.begin(), sar.end(), [](const Studentas& s) { return s.getRez() >= 5.00; });
    copy(sar.begin(), it, back_inserter(vargsiukai));
    sar.erase(sar.begin(), it);
}



void generuotiFailus(int& studentu_skaicius, int ndSk) {
    string filename = "studentai" + to_string(studentu_skaicius) + ".txt";
    stringstream buffer;
    ofstream out(filename);
    buffer << "Vardas" << setw(15) << "Pavarde";
    for (int i = 0; i < ndSk; i++) {
        buffer << setw(15) << "ND" << i + 1;
    }
    buffer << setw(15) << "Egz.\n";
    for (int i = 0; i < studentu_skaicius; i++) {
        buffer << "Vardas" << i + 1 << setw(15) << "Pavarde" << i + 1;
        for (int j = 0; j < ndSk; j++) {
            buffer << setw(15) << generuotiSkaiciu();
        }
        buffer << setw(15) << generuotiSkaiciu() << "\n";
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}



