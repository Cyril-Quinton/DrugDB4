#include "Pharmacie.h"
#include <string>
#include <iostream>
#include "mainwindow.h"
#include <QTextEdit>
#include <QString>
#include <QTextStream>
#include <Medicin.h>
using namespace std;

Pharmacie::Pharmacie(QString _name)
{
    name=_name;
    vectorSideEffect={};
    vectorMedicin={};
}
void Pharmacie::save(QString fileName)
{
    std::string file_path = fileName.toUtf8().constData();
    ofstream file;
    file.open(file_path.c_str());
    for (int i=0;i<vectorMedicin.size();i++){
        file << vectorMedicin.at(i)->getName();
        file << " : effets indésirables notoires : ";
        for(int j=0;j<vectorMedicin.at(i)->getsideEffect().size();j++) {

            file << vectorMedicin.at(i)->getsideEffect().at(j)->getName();
            file <<", ";

        }
        file <<".\n";
    }
    file.close();
}
/*create a new medicin associated with side effects
add a pointer to the medicin object to the vector of medicins in each side effect object concerned
add a pointers to side effects objets in the medicin object */
void Pharmacie::medicinAdder(string _name, vector <string> parserSideEffect)
{
    Medicin *nMedicin=new Medicin(_name);
    for (int i=0; i<parserSideEffect.size();i++) {
            SideEffect *pt=getPointer(parserSideEffect[i]);
            pt->setMedicin(nMedicin);
            nMedicin->setsideEffect(pt);

    }
    vectorMedicin.push_back(nMedicin);
}
/*return a pointer to a side effect object
if the side effect doesn't exist yet,
it is created and it return its pointer*/
SideEffect* Pharmacie::getPointer(string name_effect){
    for(int i=0;i<vectorSideEffect.size();i++){
        if (vectorSideEffect[i]->getName().compare(name_effect)==0){
            return vectorSideEffect[i];
        }
    }

    SideEffect *sideeffect=new SideEffect;
    sideeffect->setname(name_effect);
    vectorSideEffect.push_back(sideeffect);
    return sideeffect;

}
/*get vector of side effect from the medicin concerned
counts number of side effect shared with others medicin
if the number is equal to maximum, medicin name is appended to result
if the number is above maximum, result is cleared and medicin name is appended
to result*/
void Pharmacie::displayMostSideShared(string medicin_name, QTextEdit *te)
{
    vector <string> result;
    vector <SideEffect*> vse;
    for(int i=0;i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()==medicin_name)
        {
            vse=vectorMedicin.at(i)->getsideEffect();
        }
    }
    int max=0;
    for (int i=0;i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()!=medicin_name)
        {
            int score=vectorCompare(vse,vectorMedicin.at(i)->getsideEffect());
            if (score==max)
            {
                result.push_back(vectorMedicin.at(i)->getName());
            }
            if (score>max)
            {
                max=score;
                result.clear();
                result.push_back(vectorMedicin.at(i)->getName());


            }
        }
    }
    te->append(QString::number(max));
    te->append("\n");
    for (int i=0;i<result.size();i++)
    {
        te->append(QString::fromStdString(result.at(i)));
    }

}
/*get vector of side effect from the medicin concerned
counts number of side effect shared with others medicin
if the number is equal or above the "sideShared" number,
medicin name is appended to result*/
void Pharmacie::displayMostSideShared(string medicin_name, QTextEdit *te, int sideShared)
{
    vector <string> result;
    vector <SideEffect*> vse;
    for(int i=0;i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()==medicin_name)
        {
            vse=vectorMedicin.at(i)->getsideEffect();
        }

    }
    for (int i=0;i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()!=medicin_name)
        {
            int score=vectorCompare(vse,vectorMedicin.at(i)->getsideEffect());
            if (score>=sideShared)
            {
                result.push_back(vectorMedicin.at(i)->getName());
            }
        }
    }
    for (int i=0;i<result.size();i++)
    {
        te->append(QString::fromStdString(result.at(i)));
    }
}
//display first 2 drugs which share at least 1 side effect whith the drug given
void Pharmacie::displayMostSideSharedQuick(string medicin_name, QTextEdit *te)
{
    int cpt=0;
    vector <string> result;
    vector <SideEffect*> vse;
    for(int i=0;i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()==medicin_name)
        {
            vse=vectorMedicin.at(i)->getsideEffect();
        }

    }
    int i=0;
    while (i<vectorMedicin.size() && cpt<2)
    {
        if (vectorMedicin.at(i)->getName()!=medicin_name)
        {
            int score=vectorCompare(vse,vectorMedicin.at(i)->getsideEffect());
            if (score>=1)
            {
                result.push_back(vectorMedicin.at(i)->getName());
                ++cpt;
            }
        }
        ++i;
    }

    for (int i=0;i<result.size();i++)
    {
        te->append(QString::fromStdString(result.at(i)));

    }
}
//display a random drug which share at least 1 side effect whith the drug given
void Pharmacie::displayMedicinRandom(string medicin_name, QTextEdit *te)
{
    vector <SideEffect*> vse;
    for(int i=0;i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()==medicin_name)
        {
            vse=vectorMedicin.at(i)->getsideEffect();
        }

    }
    int score=0;
    int index;
    while (score<1)
    {
        index=rand() % vectorMedicin.size();
        score=vectorCompare(vse,vectorMedicin.at(index)->getsideEffect());
    }
    te->append(QString::fromStdString(vectorMedicin.at(index)->getName()));
}
bool Pharmacie::medicinExist(string medicin_name)
{
    bool rep=false;
    for (int i=0; i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()==medicin_name)
        {
            rep=true;
            break;
        }
    }
    return rep;
}
bool Pharmacie::sideExist(string side_name)
{
    bool rep=false;
    for (int i=0; i<vectorSideEffect.size();i++)
    {
        if (vectorSideEffect.at(i)->getName()==side_name)
        {
            rep=true;
            break;
        }
    }
    return rep;
}

void Pharmacie::suppressMedicin(string medicin_name)
{

    for (std::vector<Medicin*>::iterator it=vectorMedicin.begin();it!=vectorMedicin.end();++it)
    {
        if ((*it)->getName()==medicin_name)
        {
            delete *it;
            it=vectorMedicin.erase(it);

        }
    }
}
void Pharmacie::modifyNameMedicin(string medicin_name, std::string new_name)
{
    for (int i=0;i<vectorMedicin.size();i++)
    {
        if (vectorMedicin.at(i)->getName()==medicin_name)
        {
            vectorMedicin.at(i)->setName(new_name);
        }
    }
}
void Pharmacie::modifyNameSide(string side_name, string new_name)
{
    for (int i=0;i<vectorSideEffect.size();i++)
    {
        if (vectorSideEffect.at(i)->getName()==side_name)
        {
            vectorSideEffect.at(i)->setname(new_name);
        }
    }
}



int Pharmacie::vectorCompare(vector<SideEffect *> vs1, vector<SideEffect *> vs2)
{
    int cpt=0;
    for (int i=0; i<vs1.size();i++)
    {
        for(int j=0;j<vs2.size();j++)
        {
            if (vs1[i]==vs2[j]) {
                ++cpt;

            }
        }
    }
    return cpt;
}

void Pharmacie::displaySideEffect(string medicin_name, QTextEdit *te)
{
    for (int i=0;i<vectorMedicin.size();i++) {
        if (vectorMedicin[i]->getName()==medicin_name) {
            for (int j=0;j<vectorMedicin[i]->getsideEffect().size();j++) {
                te->append(QString::fromStdString(vectorMedicin[i]->getsideEffect()[j]->getName()));
            }
        }
    }
}


void Pharmacie::displaySideEffect(string medicin_name) {
    for (int i=0;i<vectorMedicin.size();i++) {
        if (vectorMedicin[i]->getName()==medicin_name) {
            for (int j=0;j<vectorMedicin[i]->getsideEffect().size();j++) {
                cout<<vectorMedicin[i]->getsideEffect()[j]->getName()<<endl;
            }
        }
    }
}
void Pharmacie::displayMedicin(string side_name) {
    for (int i=0;i<vectorSideEffect.size();i++) {
        if (vectorSideEffect[i]->getName()==side_name) {
            for (int j=0; j<vectorSideEffect[i]->getMedicin().size();j++) {
                cout << vectorSideEffect[i]->getMedicin()[j]->getName()<<endl;
            }
        }
    }
}
void Pharmacie::displayMedicin(string sideEffect_name, QTextEdit *te)
{
    for (int i=0;i<vectorSideEffect.size();i++) {
        if (vectorSideEffect[i]->getName()==sideEffect_name) {
            for (int j=0; j<vectorSideEffect[i]->getMedicin().size();j++) {
                te->append(QString::fromStdString(vectorSideEffect[i]->getMedicin()[j]->getName()));
            }
        }
    }
}

void Pharmacie::displayMedicin(QTextEdit *te)
{
    for (int i=0;i<vectorMedicin.size();i++) {
        QString name=QString::fromStdString(vectorMedicin.at(i)->getName());
        te->append(name);
        //te->append("\n");
    }
}


string Pharmacie::normalize(string name, bool isMedicin)
{
    int i=0;
        while(i<name.size()) {
            if (name[i]==' ') {
                name.erase(i,1);
            }
            name[i]=tolower(name[i]);
            ++i;
        }
        if (isMedicin) {
        name[0]=toupper(name[0]);
        }

        return name;
}


vector<SideEffect*> Pharmacie::getSideEffect(){
    return vectorSideEffect;
}
vector <Medicin*> Pharmacie::getMedicin(){
    return vectorMedicin;
}
QString Pharmacie::getName()
{
    return name;
}

Pharmacie::~Pharmacie()
{
    //dtor
}
