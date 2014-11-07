#ifndef MEDICIN_H
#define MEDICIN_H
#include <vector>
#include "SideEffect.h"
#include <QString>
#include <QStringList>

using namespace std;

class Medicin
{
    public:
        Medicin();
        Medicin(string _name);
        Medicin(string _name, vector <SideEffect*> _sideEffect);
        virtual ~Medicin();
        string getName();
        void setName(std::string name);
        vector <SideEffect*> getsideEffect();
        void setsideEffect(SideEffect* se);
        QStringList getSideEffects();
    protected:

    private:
        string name;
        vector <SideEffect*> sideEffect;

};

#endif // MEDICIN_H
