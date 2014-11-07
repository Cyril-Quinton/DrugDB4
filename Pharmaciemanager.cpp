#include "Pharmaciemanager.h"
#include "Pharmacie.h"
#include <QFileDialog>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <sstream>
PharmacieManager::PharmacieManager()
{
}

std::map<QString, Pharmacie*> PharmacieManager::getmPhar()
{
    return mPhar;
}
void PharmacieManager::parser(Pharmacie* database, QString filename, QString phName, bool verbose)
{
    //open the file
    std::string file_path = filename.toUtf8().constData();
    vector<string> effets;
    ifstream liste(file_path.c_str(),ios::in);
    if (liste){
        if (verbose) {cout<<"fichier ouvert"<<endl;}
        string ligne;
        //for each line...
        while(getline(liste,ligne)){
            string medicament="";
            istringstream iss(ligne);
            do {
                string sub;
                iss >> sub;
                //if the word begin by a uppercase, it's a medicine
                    if(isupper(sub[0])){
                        medicament=sub;
                    }
            }while(iss);
            string delimiter1 = " : ";
            size_t pos = 0;
            string temp;
            //select only the part after the ":"
            while ((pos = ligne.find(delimiter1)) != string::npos) {
                temp= ligne.substr(0, pos);
                ligne.erase(0, pos + delimiter1.length());
            }
            istringstream iss1(ligne);
            string mot="";
            string temp2="";
            do {
                //if the word is "et", we add the previous word
                string sub1;
                iss1 >> sub1;
                if (sub1!="et"){
                    mot+=sub1;
                }
                else{
                    //avoids the problem if there are two spaces side by side
                    if (mot.size()>1){
                    effets.push_back(mot);
                    mot="";
                    }
                }
                //removes the last character and adds the word to the list if it is a "."or a ","
                //avoids troubles with effects in several words.
                char fin=mot[mot.size()-1];
                if(fin==',' || fin=='.'){
                        if(mot.size()>1){
                        mot.erase(mot.begin()+mot.size()-1);
                        effets.push_back(mot);
                        }
                        mot="";
                    }


            }while(iss1);
            //add the medicine to the database
            database->medicinAdder(medicament,effets);
            if (verbose) {
                cout<<"liste des effets de ce médicament : "<<medicament<<endl;
                for (int i=0; i <effets.size(); i++){
                    cout<<effets[i]<<endl;
                }
                cout<<"FIN DE LA LIGNE"<<endl;
            }
            effets.clear();
        }
        liste.close();
    }
    else{
        cout<<"mauvais fichier"<<endl;
        exit(1);
    }
    mPhar[phName]=database;


}

