#include "funkcijos.h"
double Studentas::skaiciuotiGalutini() {
    return 0.4 * medvid_ + 0.6 * (double)egz_;
}

double Studentas::avg() {
    int n = getNdSize();
    if (n > 0) {
        return accumulate(nd_.begin(), nd_.end(), 0.0) / (double)n;
    }
    return 0;
}

double Studentas::median() {
    int n = getNdSize();
    if (n == 0) return 0;
    sortNd();
    if (n % 2 != 0) {
        return (double)nd_[n / 2];
    }
    else {
        return (double)(nd_[(n - 1) / 2] + nd_[n / 2]) / 2.0;
    }
}

void Studentas::print() {
    printf("%-12s %-12s %-16.2lf \n", vardas_.c_str(), vardas_.c_str(), rez_);
}

void Studentas::read(int nr) {
    string t;
    cout << "Iveskite " << nr + 1 << "-tojo studento duomenis:\n";
    cout << "Iveskite studento varda:\n";
    cin >> t;
    vardas_ = t;
    cin.ignore(80, '\n');
    cout << "Iveskite studento pavarde\n";
    cin >> t;
    pavarde_ = t;
    cin.ignore(80, '\n');
    cout << "Ar studento namu darbus sugeneruoti atsitiktinai ar ivesite patys?\n1 - Atsitiktinai 0 - Pats\n";
    random = 0;
    intIvedimas(random, 0, 1);
    int tmp = -1;
    int index = 0;
    if (random == 0) {
        while (tmp != 11) {
            cout << "Ivesti " << ++index << "-ojo namu darbu rezultata (norint baigti ivesti 11)\n";
            intIvedimas(tmp, 0, 10, 11);
            if (tmp != 11 && tmp != -1) {
                addNd(tmp);
            }
        }
        int egz;
        cout << "Iveskite studento egzamino rezultata:\n";
        cin >> egz;
        setEgz(egz);
    }
    else {
        cout << "Namu darbu skaicius:\n";
        int ndSk;
        int t;
        cin >> ndSk;
        for (int i = 0; i < ndSk; i++) {
            t = generuotiSkaiciu();
            cout << i + 1 << "-tojo namu darbu rezultatas:" << t << "\n";
            addNd(t);
        }
        t = generuotiSkaiciu();
        setEgz(t);
        cout << "Studento egzamino rezultatas:" << t << "\n";
    }

    double temp;
    if (pasirinkimas == 1) {
        setMedVid(avg());
    }
    setMedVid(median());
    setRez(skaiciuotiGalutini());
}

void printToFile(string filename, vector<Studentas>& sar, int ndSkaicius) {
    string var[3] = { "Med.", "Vid." };
    stringstream buffer;
    ofstream out(filename);
    buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << "Galutinis(" << var[pasirinkimas] << ")" << "\n";
    for (int i = 0; i < sar.size(); i++) {
        buffer << left << setw(15) << sar[i].getVardas() << setw(15) << sar[i].getPavarde() << fixed
            << setprecision(2) << sar[i].getRez() << "\n";
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}
void readfromFile(string filename, vector<Studentas>& sar, int& studentu_skaicius, int& ndSk) {
    try {
        ifstream fr(filename);
        if (!fr.fail()) {
            int sk;
            double temp2;
            string line;
            string temp, pirmaEil;
            int kiekNd = -3;
            getline(fr >> ws, pirmaEil);
            stringstream iss(pirmaEil);
            while (iss >> temp)
            {
                kiekNd++;
            }
            ndSk = kiekNd;
            while (getline(fr >> ws, line)) {
                Studentas s;
                stringstream iss(line);
                iss >> temp;
                s.setVardas(temp);
                iss >> temp;
                s.setPavarde(temp);
                for (int i = 0; i < kiekNd; i++) {
                    iss >> sk;
                    s.addNd(sk);
                }
                iss >> sk;
                s.setEgz(sk);
                if (pasirinkimas == 1) {
                    s.setMedVid(s.avg());
                }
                else s.setMedVid(s.median());
                s.setRez(s.skaiciuotiGalutini());
                sar.push_back(s);
            }
        }
        else {
            throw runtime_error(filename);
        }
        studentu_skaicius = sar.size();
    }
    catch (exception& e) {
        cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
        system("pause");
        exit(0);
    }
}

bool compare(Studentas a, Studentas b) {
    return a.getRez() < b.getRez();
}
