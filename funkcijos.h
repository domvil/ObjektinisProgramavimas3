#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include "mylib.h"
#include "studentas.h"


void generuotiFailus(int& studentu_skaicius, int ndSk);
int pasirinktiMedArVid(int& pasirinkimas);
void vectorOptimizacija(vector<Studentas>& sar, vector <Studentas>& vargsiukai);
void intIvedimas(int& priskirti, int lowerBound, int upperBound, int stoppage = -999);
void readfromFile(string filename, vector<Studentas>& sar, int& studentu_skaicius, int& ndSk);
void printToFile(string filename, vector<Studentas>& sar, int ndSkaicius);
void intIvedimas(int& priskirti, int lowerBound, int upperBound, int stoppage);
int generuotiSkaiciu();

#endif
