#include "Medicin.h"
#include <QStringList>
Medicin::Medicin()
{
    //ctor
}
Medicin::Medicin(string _name)
{

    name=_name;
}
string Medicin::getName(){
    return name;
}
vector <SideEffect*> Medicin::getsideEffect(){
    return sideEffect;
}
void Medicin::setsideEffect(SideEffect* se){
    sideEffect.push_back(se);
}
QStringList Medicin::getSideEffects()
{
    QStringList se;
    for(int i=0;i<sideEffect.size();i++)
        se.append(QString::fromStdString(sideEffect.at(i)->getName()));
    if (se.isEmpty()) { exit(1); }
    return se;
}
void Medicin::setName(string _name)
{
    name=_name;
}

Medicin::~Medicin()
{
    for (int i=0;i<sideEffect.size();i++)
    {
        sideEffect.at(i)->suppressPointer(this);
    }
}
