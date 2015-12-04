#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "display.h"
#include "list.h"

using namespace std;

const int invalidChoice = 0;

int theMenuChoice();
void printTree();
void printError();
void eraseEverything(List& list);

int main()
{
    Display.printTree();
    Display.title();
    int choice;
    do{
        choice = Display.theMenuChoice();

        switch(choice)
        {
        case 1 :
         {
            theList.InsertPersonInfo(fout);
         }      break;
         case 2 :
            theList.searchPerson();
                break;
         case 3 :
             theList.Print();
                break;
         case 4 :
                break;
         case 5 :
                break;
         default:
        {
            cout << "Invalid choice!" << endl;
            sleep(2);
            system("cls");
        }
        }
    }while(choice != 5);

    system("cls");
    cout << "Thank you for your visit, hope to see you again soon." << endl << endl;
    return 0;
}
