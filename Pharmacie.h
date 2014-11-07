#ifndef Pharmacie_H
#define Pharmacie_H
#include <string>
#include <vector>
#include "Medicin.h"
#include "SideEffect.h"
#include <QTextStream>
#include <QTextEdit>
using namespace std;

class Pharmacie
{
    public:
        Pharmacie(QString _name);
        void medicinAdder(string name,vector <string> vectorSideEffect);
        virtual ~Pharmacie();
        SideEffect *getPointer(string name_effect);
        void displaySideEffect(string medicin_name);
        void displaySideEffect(string medicin_name, QTextEdit *te);
        void displayMedicin(string sideEffect_name);
        void displayMedicin(string sideEffect_name, QTextEdit *te);
        //display all drugs name into a QTextEdit
        void displayMedicin(QTextEdit *te);
        //display drugs that share a maximum of side effect with the drug given
        void displayMostSideShared(string medicin_name, QTextEdit *te);
        //display drugs that share at least "sideSared"  side effects with the drug given
        void displayMostSideShared(string medicin_name,QTextEdit *te,int sideShared);
        //display first 2 drugs which share at least 1 side effect whith the drug given
        void displayMostSideSharedQuick(string medicin_name, QTextEdit *te);
        //display a random drug which share at least 1 side effect whith the drug given
        void displayMedicinRandom(string medicin_name,QTextEdit *te);
        void suppressMedicin(string medicin_name);
        void modifyNameMedicin(string medicin_name,string new_name);
        void modifyNameSide(string side_name,string new_name);
        bool medicinExist(string medicin_name);
        bool sideExist(string side_name);
        void save(QString fileName);
        //suppress blank and set lowercase
        //if isMedicin : first letter is set uppercase
        string normalize(string name, bool isMedicin);
        //return all side effects object from the pharmacy
        vector <SideEffect*> getSideEffect();
        //return all drugs object from the pharmacy
        vector <Medicin*> getMedicin();
        //return pharmacy name
        QString getName();
    protected:
    private:
        //return the number of common elements between 2 sideEffect vectors
        int vectorCompare(vector <SideEffect*> vs1, vector <SideEffect*> vs2);
        vector <Medicin*> vectorMedicin;
        vector <SideEffect*> vectorSideEffect;
        int d;
        QString name;


};

#endif // MEDICINDATABASE_H
