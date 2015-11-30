#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include "list.h"
#include <string>
#include <vector>

using namespace std;

void InsertPersonInfo(ostream& outs);
int theMenuChoice();
vector<string> dbList(ifstream& file);
void dbPrint(ifstream& fin);
vector<string> dbListSort(vector<string> outList, int orderBy, char sorted);

/* TO DO:
 *  - Setja allt í Klasa
 *  - Villuprófa og checkföll (t.d. setja inn bókstaf í stað tölu)
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ifstream fin("database.csv");
    ofstream fout("database.csv", fstream::app);

    //List theList(fin);

    int choice;
    cout << "Welcome to Computer Sciense DB." << endl;
    do{
        choice = theMenuChoice();

        if (choice == 1)
            InsertPersonInfo(fout);
        else if (choice == 2);
        else if (choice == 3)
            dbPrint(fin);
        else if (choice == 4);
        else if (choice == 5);
        else
            cout << "Invalid choice!" << endl;

    }while(choice != 5);

    cout << "Thank you for your visit, hope to see you again soon." << endl;

    fin.close();
    fout.close();

    return a.exec();
}

void InsertPersonInfo(ostream& outs)
{
    string Name, gender;
    int born, death;
    cout << "Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Gender: ";
    cin >> gender;
    cout << "Year of birth: ";
    cin >> born;
    cout << "Year of death (-1 if still alive): ";
    cin >> death;

    outs << Name << ", " << gender << ", " << born << ", " << death << endl;

}


int theMenuChoice()
{
    int choice;

    cout << "1: Insert" << endl
         << "2: Search" << endl
         << "3: Print" << endl
         << "4: Delete" << endl
         << "5: Exit" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> choice;
    return choice;
}

void dbPrint(ifstream& fin){
    int orderBy;
    char sorted;

    cout << endl << "* PRINT *" << endl
         << "Ordered  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Sex" << endl
         << "\t3: Year of birth" << endl
         << "\t4: Year of death" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;
    cout << "\ta: Asending" << endl
         << "\td: Desending" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> sorted;
    vector<string> outList = dbList(fin);
    //dbListSort(outList, orderBy, sorted);
    for(const string line:outList){
        cout << line << endl;
    }
    cout << endl;
}

//FYI. Creation of List object must be commented out at the top for this to work.
vector<string> dbList(ifstream& file){
    vector<string> dbOutput;
    string line;

    if (file.is_open()){
        file.seekg (0, ios::end);       //file readpointer to end.
        int end = file.tellg();         //keep end placement/index.
        file.seekg(0);                  //file readpointer back to start.
        while (file.tellg() != end){    //while readpointer not at the end.
            getline (file,line);
            dbOutput.push_back(line);
        }
    } else cout << "Unable to open file\n";

    sort(dbOutput.begin(), dbOutput.end());

    return dbOutput;
}

vector<string> dbListSort(vector<string> outList, int orderBy, char sorted){


}

