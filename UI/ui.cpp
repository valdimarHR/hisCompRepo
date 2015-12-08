#include "UI/ui.h"


ui::ui()
{
    choice = 0;
}

bool ui::start()
{
    cout << "Welcome to Computer Sciense DB." << endl;
    printTree();
    do
    {
        mainMenu();
        menuSwitch();
    }while(choice != 5);

    clear();
    cout << "Thank you for your visit, hope to see you again soon." << endl << endl;
    return 0;
}

void ui::mainMenu()
{
    cout << "//-------------------------\\\\" << endl
         << "||        MAIN MENU        ||" << endl
         << "||                         ||" << endl
         << "||     1: Insert           ||" << endl
         << "||     2: Search           ||" << endl
         << "||     3: Print            ||" << endl
         << "||     4: Delete from DB   ||" << endl
         << "||     5: Exit             ||" << endl
         << "||                         ||" << endl
         << "\\\\-------------------------//" << endl
         << "Enter your choice: ";

    cout.flush();
    cin.clear();
    cin >> choice;
    inputIntCheck(cin.fail(), choice, 1, 5);
    clear();
}

void ui::menuSwitch()
{
    switch(choice)
    {
    case 1 :
        insertMenu();
        break;
    case 2 :
        searchMenu();
        break;
    case 3 :
        printerMenu();
        break;
    case 4 :
        deleteMenu();
        break;
    default:
        break;
    }
}

void ui::insertMenu()
{
    int n;

    cout << "* INSERT *" << endl << endl
         << "Would you like in insert a:" << endl
         << "\t1. Person" << endl
         << "\t2. Computer" << endl
         << "\t3. Info who made which computer" << endl
         << "\t4. Back" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 4);

    clear();

    switch(n)
    {
    case 1 :
        insertMenuPerson();
        break;
    case 2 :
        insertMenuComputer();
        break;
    case 3 :
        insertMenuConnection();
        break;
    default:
        break;
    }

}

void ui::insertMenuPerson()
{
    string name, gender;
    int born, death;

    cout << "* INSERTING PERSON *" << endl << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Gender (please write Male or Female): ";
    cin >> gender;

    while(!((gender == "Male")||(gender == "Female")))
    {
        cout << "Invalid choice!" << endl << "Try again: ";
        cin >> gender;
    }

    cout << "Year of birth: ";
    cin >> born;
    inputIntCheck(cin.fail(), born);

    cout << "Year of death (-1 if still alive): ";
    cin >> death;
    inputIntCheck(cin.fail(), death);

    while (death > born)
    {
        cout << "Person can't die before it is born, try again." << endl;
        cout << "Year of death: ";
        cin >> death;
        inputIntCheck(cin.fail(), death);
    }

    bool exists = theLogic.insertPerson(name, gender, born, death);

    if(exists)
    {
        cout << endl << "This person was already on the list and was therefore not added again."
             << endl << endl;
        sleep(3);
        clear();
        return;
    }

    cout << endl << "Person was added to the list.";
    sleep(2);
    clear();

}

void ui::insertMenuComputer()
{
    string name, type, builtCheck;
    int created;
    bool built;

    cout << "* INSERTING COMPUTER *" << endl << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Year Created (invented): ";
    cin >> created;
    inputIntCheck(cin.fail(), created);
    cout << "What type of computer: ";
    cin.ignore();
    getline(cin, type);
    cout << "Was it built (Y/N): ";
    cin >> builtCheck;
    built = inputStrToBool(builtCheck);

    bool exists = theLogic.insertComputer(name, created, type, built);

    if(exists)
    {
        cout << endl << "This computer was already on the list and was therefore not added again."
             << endl << endl;
        sleep(3);
        clear();
        return;
    }

    cout << endl << "Computer was added to the list.";
    sleep(2);
    clear();

}

void ui::insertMenuConnection()
{
    cout << "* WHO INVENTED WHAT *" << endl << endl;

    cout << "First choose a scientist from this list:" << endl;
    vector<people> peep = theLogic.printerPeople();
    int sizeP = printOnlyPeople(peep);
    cout << "Scientist number: ";
    int sid;
    cin >> sid;
    inputIntCheck(cin.fail(), sid, 0, sizeP);
    if(sid == 0)
    {
        clear();
        return;
    }
    clear();
    cout << "* WHO INVENTED WHAT *" << endl << endl;
    cout << "Now choose a computer from this list:" << endl;
    vector<computers> comp = theLogic.printerComputers();
    int sizeC = printOnlyComputers(comp);
    int cid;
    cout << "Computer number: ";
    cin >> cid;
    inputIntCheck(cin.fail(), cid, 0, sizeC);
    if(cid == 0)
    {
        clear();
        return;
    }
    cid = comp[cid-1].getId();
    sid = peep[sid-1].getId();
    bool connected = theLogic.insertConnection(sid, cid);
    if (connected)
    {
        cout << "This connection was already in the database";
        sleep(2);
        clear();
        return;
    }

    cout << "The connection was added to the database.";
    sleep (2);
    clear();
}

void ui::searchMenu()
{
    int n;

    cout << "* SEARCH *" << endl << endl
         << "Would you like to search by" << endl
         << "\t1: Person" << endl
         << "\t2: Computer" << endl
         << "\t3: Back" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 3);
    clear();

    if(n == 1)
        searchMenuPerson();
    else if(n == 2)
        searchMenuComputer();

}

void ui::searchMenuPerson()
{
    int n;

    cout << "* SEARCH PERSON *" << endl << endl
         << "Would you like to search by" << endl
         << "\t1: Name" << endl
         << "\t2: Gender (male or female)" << endl
         << "\t3: Year of birth" << endl
         << "\t4: Year of death (write -1 for alive)" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 4);

    vector<peopleWithComputers> foundPeople;
    string question;
    string column;
    switch(n)
    {
    case 1:
        {
            question = "What would you like to search for?";
            column = "name";
            break;
        }
    case 2:
        {
            question = "What would you like to search for (male or female)?";
            column = "gender";
            break;
        }
    case 3:
        {
            question = "Enter a year: ";
            column = "birth";
            break;
        }
    case 4:
        {
            question = "Enter a year: ";
            column = "death";
            break;
        }
    default:
        break;
    }

    string searchValue = getStringSearchValue(question);
    foundPeople = theLogic.findPeople(column, searchValue);

    if (foundPeople.size() == 0)
    {
        cout << "No search results found!" << endl;
        system("pause");
        clear();
    }
    else
    {
        printPeopleVector(foundPeople);
    }
}

void ui::searchMenuComputer()
{
    int n;

    cout << "* SEARCH COMPUTER *" << endl
         << "Would you like to search by" << endl
         << "\t1: Name" << endl
         << "\t2: Year created" << endl
         << "\t3: Type" << endl
         << "\t4: Ever built or not" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 4);

    vector<computersWithPeople> foundComputer;

    string question;
    string column;
    switch(n)
    {
    case 1:
        {
            question = "What would you like to search for?";
            column = "name";
            break;
        }
    case 2:
        {
            question = "Enter a year: ";
            column = "yearCreated";
            break;
        }
    case 3:
        {
            question = "Enter a type of computer: ";
            column = "type";
            break;
        }
    case 4:
        {
            question = "Was it built? (Y/N): ";
            column = "wasBuilt";
            break;
        }
    default:
            break;

    }

    string searchValue = getStringSearchValue(question);
    foundComputer = theLogic.findComputer(column, searchValue);

    if (foundComputer.size() == 0)
    {
        cout << "No search results found!" << endl;
        system("pause");
        clear();
    }
    else
    {
        printComputersVector(foundComputer);
    }
}

void ui::printerMenu()
{
    int printChoice;
    cout << "* PRINTING *" << endl << endl
         << "Please make the window bigger so the list will fit" << endl
         << "Do you want to print:" << endl
         << "\t1: People" << endl
         << "\t2: Computers" << endl
         << "\t3: Back" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> printChoice;
    inputIntCheck(cin.fail(), printChoice, 1, 3);
    clear();

    if(printChoice == 1)
        printerMenuPeople();
    else if(printChoice == 2)
        printerMenuComputers();

}

void ui::printerMenuPeople()
{
    int orderBy, ascending;
    cout << "* PRINTING PEOPLE *" << endl << endl
         << "Order  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Gender" << endl
         << "\t3: Year of birth" << endl
         << "\t4: Year of death" << endl
         << "\t5: As in file" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;

    inputIntCheck(cin.fail(), orderBy, 1, 5);
    clear();

    if(orderBy != 2 && orderBy != 5)
    {
        cout << "Do you want this list in descending or ascending order?" << endl
             << "\t0: Descending" << endl
             << "\t1: Ascending" << endl;
    }
    else if ( orderBy == 2)
    {
        cout << "Do you want this list to be ordered by males or females first?" << endl
             << "\t0: Males" << endl
             << "\t1: Females" << endl;
    }

    if (orderBy != 5)
    {
        cout << "Enter your choice: ";
        cout.flush();
        cin >> ascending;
        inputIntCheck(cin.fail(), ascending, 0, 1);
    }
    else
        orderBy = 1;
    clear();

    vector<peopleWithComputers> sortedVector = theLogic.printerSortPeople(orderBy, ascending);
    printPeopleVector(sortedVector);
}

void ui::printerMenuComputers()
{
    int orderBy, ascending;
    cout << "* PRINTING COMPUTERS *" << endl << endl
         << "Order  by:" << endl
         << "\t1: Name" << endl
         << "\t2: Type" << endl
         << "\t3: Year of Creation" << endl
         << "\t4: Whether it was Built" << endl
         << "\t5: As in file" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> orderBy;
    
    inputIntCheck(cin.fail(), orderBy, 1, 5);
    clear();

    if (orderBy != 4 && orderBy != 5)
    {
        cout << "Do you want this list in descending or ascending order?" << endl
             << "\t0: Descending" << endl
             << "\t1: Ascending" << endl;
    }
    else if (orderBy == 4)
    {
        cout << "Do you want this list to be ordered by whether it was built or not built first" << endl
             << "\t0: Built" << endl
             << "\t1: Not built" << endl;
    }

    if (orderBy != 5)
    {
        cout << "Enter your choice: ";
        cout.flush();
        cin >> ascending;
        inputIntCheck(cin.fail(), ascending, 0, 1);
    }
    else
        ascending = 1;
    clear();

    vector<computersWithPeople> sortedVector = theLogic.printerSortComputers(orderBy, ascending);
    printComputersVector(sortedVector);
}

void ui::printPeopleVector(const vector<peopleWithComputers>& list) const
{
    //clear();
    cout << "+==========================================================================================+" << endl;
    printf("|%-35s|%-10s|%-8s|%-8s|%-25s|\n", "PEOPLE NAME", "GENDER", "BIRTH", "DEATH", "COMPUTERS");
    cout << "+==========================================================================================+" << endl;
    for(const peopleWithComputers person:list)
    {
        string name = person.p.getName();
        string gender = person.p.getGender();
        int yearOfBirth = person.p.getBirth();
        string death = to_string(person.p.getDeath());
        if(person.p.getDeath() == constants::notDead) death = "Alive";

        string computerName = person.creations[0].getName();
        if(computerName == "default") computerName = "";
        printf("|%-35.35s|%-10.10s|%-8.8s|%-8.8s|%-25.25s|\n", name.c_str(), gender.c_str(), to_string(yearOfBirth).c_str(), death.c_str(), computerName.c_str());

        for(unsigned int i = 1; i < person.creations.size(); i++)
        {
            printf("|%-64.64s %-25.25s|\n", "", person.creations[i].getName().c_str());
        }
        cout << "+------------------------------------------------------------------------------------------+" << endl;
    }
    //cout << "+------------------------------------------------------------------------------------------+" << endl;
    system("pause");
    clear();
}

void ui::printComputersVector(const vector<computersWithPeople>& list) const
{
    //clear();
    cout << "+==========================================================================================+" << endl;
    printf("|%-22s|%-15s|%-8s|%-8s|%-33s|\n", "COMPUTER NAME", "TYPE", "YEAR", "BUILT", "CREATORS");
    cout << "+==========================================================================================+" << endl;
    for(const computersWithPeople comp:list)
    {
        string name = comp.c.getName();
        string type = comp.c.getType();
        int year = comp.c.getYearCreated();
        string built = "No";
        if(comp.c.getWasBuilt()) built = "Yes";

        string personName = comp.creators[0].getName().c_str();
        if(personName == "default") personName = "";
        printf("|%-22.22s|%-15.15s|%-8.8s|%-8.8s|%-33.33s|\n", name.c_str(), type.c_str(), to_string(year).c_str(), built.c_str(), personName.c_str());

        for(unsigned int i = 1; i < comp.creators.size(); i++)
        {
            printf("|%-56.56s %-33.33s|\n", "", comp.creators[i].getName().c_str());
        }
        cout << "+------------------------------------------------------------------------------------------+" << endl;
    }
    //cout << "+------------------------------------------------------------------------------------------+" << endl;
    system("pause");
    clear();
}

string ui::getStringSearchValue(string question)
{
    string value;

    cout << question << endl;
    cin >> value;

    return value;
}

void ui::deleteMenu()
{
    clear();
    int choice;
    cout << "* DELETE MENU *" << endl << endl
         << "\t1: Remove Scientist." << endl
         << "\t2: Remove Computer." << endl
         << "\t3: Remove Whole Database." << endl
         << "\t4: Back." << endl
         << "Enter your choice ";
    cout.flush();
    cin >> choice;
    inputIntCheck(cin.fail(), choice, 1, 4);

    if(choice == 1)
    {
        deletePeople();
        clear();
    }
    else if(choice == 2)
    {
        deleteComputer();
        clear();
    }
    else if(choice == 3)
    {
        deleteDB();
        clear();
    }
    else
        clear();

}

void ui::deletePeople()
{
    clear();
    cout << "* DELETE MENU *" << endl << endl;
    vector<people> peep = theLogic.printerPeople();
    int size = printOnlyPeople(peep);
    cout << endl << "Choose which scientist to delete: ";
    int index;
    cin >> index;
    inputIntCheck(cin.fail(), index, 0, size);
    if(index == 0)
        return;
    theLogic.eraseChosenPeople(peep, index);

    cout << endl << "~~DELETING~~";
    sleep(1);
    peep.clear();
}

void ui::deleteComputer()
{
    clear();
    cout << "* DELETE MENU *" << endl << endl;
    vector<computers> comp = theLogic.printerComputers();
    int size = printOnlyComputers(comp);
    cout << endl << "Choose which computer to delete: ";
    int index;
    cin >> index;
    inputIntCheck(cin.fail(), index, 0, size);
    if(index == 0)
        return;
    theLogic.eraseChosenComputer(comp, index);
    cout << endl << "~~DELETING~~";
    sleep(1);
    comp.clear();
}

void ui::deleteDB()
{
    string warning;
    clear();
    cout << "* DELETE MENU *" << endl << endl;
    cout << "This will erase everything in the database permanently!!" << endl;
    cout    << "Type the following to confirm \"continue\" (anything else to cancel)" << endl;
    cin >> warning;

    if(warning != "continue")
    {
        cout << "Good!";
        sleep(1);
        clear();
        return;
    }
    else
    {
        theLogic.eraseDB();
        clear();
        cout << "Deleting";
        sleep(1);
        clear();
        cout << "Deleting.";
        sleep(1);
        clear();
        cout << "Deleting..";
        sleep(1);
        clear();
    }
}


int ui::printOnlyPeople(const vector<people>& peep)
{
    int size = peep.size();

    for(int i = 0; i<size; i++)
    {
        cout << "\t" << i+1 << ". " << peep[i].getName() << ", " << peep[i].getBirth() << "-";
        if (peep[i].getDeath() == constants::notDead)
            cout << endl;
        else
            cout << peep[i].getDeath()  << endl;
    }
    cout << "\t0. Exit" << endl;
    return size;
}

int ui::printOnlyComputers(const vector<computers>& comp)
{
    int size = comp.size();
    for(int i = 0; i<size; i++)
    {
        cout << "\t" << i+1 << ". " << comp[i].getName() << ", " << comp[i].getYearCreated() << endl;
    }
    cout << "\t0. Exit" << endl;
    return size;
}

void ui::inputIntCheck(bool inputFail, int& var)
{
    while(inputFail)
    {
        cout << "Input needs to be an integer." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Try again: ";
        cin >> var;
        inputFail = cin.fail();
    }
}

void ui::inputIntCheck(bool inputFail, int& var, int low, int high)
{
    while(inputFail || var < low || var > high)
    {
        cout << "Input needs to be an integer and within range." << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Try again: ";
        cin >> var;
        inputFail = cin.fail();
    }
}

bool ui::inputStrToBool(string& built)
{
    do
    {
        if (built == "Y" || built == "y" || built == "Yes" || built == "yes" )
            return true;
        else if (built == "N" || built == "n" || built == "No" || built == "no")
            return false;
        else
            cout << "Invalid input!" << endl
                 << "Try again: ";
        cin.clear();
        cin >> built;
    }while(true);
}

void ui::printTree()const
{
    cout << "----Merry Christmas!!----" << endl;
    cout << endl;

    int star = 1, size = 10;
    int Height = size / 3, Width = size / 2;

    for(int total = size; total > 0; --total)
    {
        for(int i = (total - 1); i > 0; --i)
            cout << " ";

        for(int j = 0; j < star ; ++j)
            cout << "*";

        star += 2;
        cout << '\n';
    }

    for(int i = 0; i < Height; ++i)
    {
        for(int j = 0; j < (size - (Width - (Width / 2))); ++j)
             cout << " ";

        for(int k = 0; k < Width; ++k)
             cout << "|";

        cout << '\n';
    }

    cout << endl;
    sleep(3);
    clear();

}

void ui::clear() const
{
    #ifdef Q_OS_WIN32 //All Windows versions
        system("cls");
    #else //In any other OS
        system("clear");
    #endif
}

