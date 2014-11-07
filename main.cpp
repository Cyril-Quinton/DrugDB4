#include "mainwindow.h"
#include <QApplication>
void usage() {
    ifstream file;
    file.open("doc/help.txt",ios::in);
    if (file)
    {
        string line;
        while(getline(file,line)){
            cout<<line<<endl;
        }
     }
    file.close();
}

int main(int argc, char *argv[])
{   for (int i=0; i < argc; i++)
    {
    if(argv[i][0]=='h'){
        usage();
    }
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}

