#include "mylib.h"
#include "funkcijos.h"


int pasirinkimas;
int random;


int main()
{
    std::chrono::duration<double> diff;
    int studentu_skaicius = 0;
    vector<Studentas> sar, moksliukai, vargsiukai;

    int veiksmas;
    int ndSk = 0;
    cout << "Pasirinkite programos funkcija\n1 - Ivesti studentu duomenis ranka\n";
    cout << "2 - Nuskaityti pasirinkta duomenu faila\n";
    cout << "3 - Atsitiktinai generuoti studentu duomenu failus\n";
    cout << "4 - Studentu grupavimo testavimas\n";
    cout << "Ivesti pasirinkimo nr. 1 , 2 , 3 arba 4\n";
    intIvedimas(veiksmas, 1, 4);
    if (veiksmas == 1) {
        int nr = 0;
        pasirinktiMedArVid(pasirinkimas);
        studentu_skaicius = 1;
        char ivedimas = 'X';
        cout << "Iveskite studentu duomenis:\n";
        while (ivedimas != 'N' && ivedimas != 'n') {
            Studentas s;
            s.read(nr);
            nr++;
            if (s.getNdSize() > ndSk) {
                ndSk = s.getNdSize();
            }
            sar.push_back(s);
            cout << "Testi/Baigti ivedima? Ivesti T/N\n";
            cin >> ivedimas;
            cin.ignore(80, '\n');
            float bendras = 0;
            while (ivedimas != 'T' && ivedimas != 't' && ivedimas != 'N' && ivedimas != 'n') {
                cout << "Bloga ivestis, bandykite dar karta!\n";
                cin >> ivedimas;
            }
            studentu_skaicius++;
        }
    }
    else if (veiksmas == 2) {
        cout << "Iveskite duomenu failo pavadinima: (pvz 123.txt)\n";
        string filename;
        cin >> filename;
        pasirinktiMedArVid(pasirinkimas);
        auto prad = hrClock::now();
        readfromFile(filename, sar, studentu_skaicius, ndSk);
        auto pab = hrClock::now();
        diff = pab - prad;
        cout << studentu_skaicius << " irasu failo nuskaitymas uztruko: " << diff.count() << "s\n";
        float bendras = diff.count();

    }
    else if (veiksmas == 3) {
        cout << "Iveskite norima sugeneruotu studentu skaiciu\n";
        intIvedimas(studentu_skaicius, 0, -1);
        cout << "Iveskite norima studentu namu darbu skaiciu\n";
        intIvedimas(ndSk, 0, -1);
        auto prad = hrClock::now();
        generuotiFailus(studentu_skaicius, ndSk);
        auto pab = hrClock::now();
        diff = pab - prad;
        cout << studentu_skaicius << " irasu failo sugeneravimas uztruko: " << diff.count() << "s\n";
    }
    if (veiksmas == 1 || veiksmas == 2) {
        random = 0;
        cout << sar.size() << "\n";
        auto bendras = diff.count();
        auto prad = hrClock::now();
        vectorOptimizacija(sar, vargsiukai);
        auto pab = hrClock::now();
        diff = pab - prad;
        bendras += diff.count();
        cout << studentu_skaicius << " irasu dalijimas i 2 grupes uztruko: " << diff.count() << "s\n";
        prad = hrClock::now();
        printToFile("vargsiukai.txt", vargsiukai, ndSk);
        pab = hrClock::now();
        diff = pab - prad;
        bendras += diff.count();
        cout << studentu_skaicius << " irasu vargsiuku irasymo i faila laikas uztruko: " << diff.count() << "s\n";
        prad = hrClock::now();
        printToFile("moksliukai.txt", sar, ndSk);
        pab = hrClock::now();
        diff = pab - prad;
        bendras += diff.count();
        cout << studentu_skaicius << " irasu moksliuku irasymo i faila laikas uztruko: " << diff.count() << "s\n";
        cout << studentu_skaicius << " irasu failo bendras testavimo laikas: " << bendras << "s\n";
    }
    else if (veiksmas == 4) {
        cout << "Iveskite norimo testuoti studentu skaiciu:\n";
        intIvedimas(studentu_skaicius, 0, -1);
        string filename;
        string s;
        printf("%-52s %-20s %-0s \n", "Veiksmas", "Vector laikas (s.)", "List laikas (s.)");

        cout << string(80, '-') << "\n";
        s = to_string(studentu_skaicius);
        filename = "studentai" + s + ".txt";
        readfromFile(filename, sar, studentu_skaicius, ndSk);

        auto prad = hrClock::now();
        vectorOptimizacija(sar, vargsiukai);
        auto pab = hrClock::now();
        diff = pab - prad;
        auto pirmas = diff.count();
        printf("%-52s %-20.10lf\n", (s + " irasu failo dalijimas i grupes (3 strategija)").c_str(), pirmas);

        cout << string(95, '-') << "\n";
    }
    system("pause");
    return 0;
}