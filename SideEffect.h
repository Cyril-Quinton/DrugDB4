
#ifndef SIDEEFFECT_H
#define SIDEEFFECT_H
#include <vector>
#include <string>
using namespace std;
struct Medicin;




class SideEffect
{

    public:
        SideEffect();
        virtual ~SideEffect();
        string getName();
        void setname(string _name);
        vector <Medicin*> getMedicin();
        void setMedicin(Medicin* med);
        int numberOfMedicin();
        void suppressPointer(Medicin* med);
    protected:
    private:
        string name;
        vector <Medicin*> tabMedicin;


};

#endif // SIDEEFFECT_H
