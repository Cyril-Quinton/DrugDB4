#ifndef PHARMACIEMANAGER_H
#define PHARMACIEMANAGER_H
#include "Pharmacie.h"
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QTextStream>
#include <vector>
#include <map>
class PharmacieManager
{
public:
    PharmacieManager();
    //construct a pharmacie by reading a .txt file
    void parser(Pharmacie* database,QString filename, QString phNmame, bool verbose);
    std::map<QString, Pharmacie*> getmPhar();
private :
    //hash map in which pharmacies are stored
    std::map<QString, Pharmacie*> mPhar;
};

#endif // PHARMACIEMANAGER_H
