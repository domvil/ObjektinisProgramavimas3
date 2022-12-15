#include "mylib.h"
class Zmogus
{
protected:
    string vardas_;
    string pavarde_;
public:
    Zmogus() {
        vardas_ = "";
        pavarde_ = "";
    }
    virtual void Test() = 0;
    virtual void setVardas(string vardas) = 0;
    virtual void setPavarde(string pavarde) = 0;
    inline string getVardas() const { return vardas_; }
    inline string getPavarde() const { return pavarde_; }

};

class Studentas : public Zmogus
{
private:
    vector <int>nd_;
    int egz_;
    double rez_;
    double medvid_;

public:
    Studentas() {
        egz_ = 0;
        rez_ = 0;
        medvid_ = 0;
    }
    void Test() {}
    ~Studentas() { nd_.clear(); }
    Studentas(const Studentas& s)
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        copy(s.nd_.begin(), s.nd_.end(), back_inserter(nd_));
        rez_ = s.rez_;
        medvid_ = s.medvid_;
    }
    Studentas& operator=(const Studentas& s)
    {
        if (this == &s)
        {
            return *this;
        }
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        std::copy(s.nd_.begin(), s.nd_.end(), back_inserter(nd_));
        egz_ = s.egz_;
        rez_ = s.rez_;
        medvid_ = s.medvid_;
        return *this;
    }
    void setVardas(string vardas) { vardas_ = vardas; }
    void setPavarde(string pavarde) { pavarde_ = pavarde; }

    double getNd(int i) const { return nd_.at(i); }
    void setNd(int nd, int index) { nd_[index] = nd; }
    void addNd(int nd) {
        nd_.reserve(nd_.size() + 1);
        nd_.push_back(nd);
    }
    void clearNd() { nd_.clear(); }
    inline int getNdSize() { return nd_.size(); }
    void sortNd() { sort(nd_.begin(), nd_.end()); }

    inline int getEgz() const { return egz_; }
    void setEgz(int egz) { egz_ = egz; }

    inline double getRez() const { return rez_; }
    void setRez(double rez) { rez_ = rez; }

    inline double getMedVid() const { return medvid_; }
    void setMedVid(double med_vid) { medvid_ = med_vid; }

    void readfromFile(string filename, vector<Studentas>& sar, int& studentu_skaicius, int& ndSk);
    double median();
    double avg();
    double skaiciuotiGalutini();
    void read(int nr);
    void print();
};

bool compare(Studentas a, Studentas b);

