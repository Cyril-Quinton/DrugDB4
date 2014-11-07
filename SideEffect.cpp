#include "SideEffect.h"

SideEffect::SideEffect()
{
    //ctor
}
string SideEffect::getName(){
    return name;
}
vector <Medicin*> SideEffect::getMedicin(){
    return tabMedicin;
}
void SideEffect::setname(string _name){
    name=_name;
}
void SideEffect::setMedicin(Medicin* med){
    tabMedicin.push_back(med);
}
int SideEffect::numberOfMedicin()
{
    return tabMedicin.size();
}
void SideEffect::suppressPointer(Medicin *med)
{
    for (int i=0;i<tabMedicin.size();i++)
    {
        if (tabMedicin.at(i)==med)
        {
            tabMedicin.erase(tabMedicin.begin() + i);
        }
    }
}

SideEffect::~SideEffect()
{
    //dtor
}
