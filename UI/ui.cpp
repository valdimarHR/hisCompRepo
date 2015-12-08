#include "UI/ui.h"


ui::ui()
{
    choice = 0;
}

bool ui::start()
{
    cout << "Welcome to Computer Sciense DB." << endl;

    do
    {
        mainMenu();
        menuSwitch();
    }while(choice != 5);

    system("cls");
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
         << "||     4: Erase Database   ||" << endl
         << "||     5: Exit             ||" << endl
         << "||                         ||" << endl
         << "\\\\-------------------------//" << endl
         << "Enter your choice: ";

    cout.flush();
    cin >> choice;
    inputIntCheck(cin.fail(), choice, 1, 5);
    clear();
}

void ui::menuSwitch()
{
    switch(choice)
    {
        case 1 :
        {
            insertMenu();
            break;
        }
        case 2 :
        {
            searchMenu();
            break;
        }
        case 3 :
        {
            printerMenu();
            break;
        }
        case 4 :
        {
            deleteMenu();
            break;
        }
        default:
        {
            break;
        }
    }
}

void ui::insertMenu()
{
    int n;

    cout << "* INSERT *" << endl << endl;
    cout << "Would you like in insert a:" << endl
         << "\t0. Person" << endl
         << "\t1. Computer" << endl
         << "\t2. Info who made which computer" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 0, 2);

    clear();
    if(n == 0) insertMenuPerson();
    else if (n ==1) insertMenuComputer();
    else insertMenuConnection();

}

void ui::insertMenuPerson()
{
    string name, gender;
    int born, death;

    cout << "* INSERTING PERSON *" << endl << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Gender (please write male or female): ";
    cin >> gender;
    while(!((gender == "female")||(gender == "male")))
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
        system("cls");
        return;
    }

    cout << endl << "Person was added to the list.";
    sleep(2);
    system("cls");

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
    int orderBy = 5; //as in file
    int ascending = 1; //1 for true
    cout << "First choose a scientist from this list:";
    sleep(2);
    clear();
    vector<peopleWithComputers> sortedVector = theLogic.printerSortPeople(orderBy, ascending);
    printVector(sortedVector);
    cout << "Scientist number: ";
    int sid;
    cin >> sid;
    inputIntCheck(cin.fail(), sid, 1, sortedVector.size());
    clear();

    cout << "Now choose a computer from this list:";
    sleep(2);
    clear();
    vector<computersWithPeople> sortVector = theLogic.printerSortComputers(orderBy, ascending);
    printVector(sortVector);
    int cid;
    cout << "Computer number: ";
    cin >> cid;
    inputIntCheck(cin.fail(), cid, 1, sortVector.size());

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

    cout << "* SEARCH *" << endl;
    cout << "Would you like to search by" << endl
         << "0. Person" << endl
         << "1. Computer" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 0, 1);
    clear();

    if(n == 0) searchMenuPerson();
    else searchMenuComputer();

}

void ui::searchMenuPerson()
{
    //findBy föllin notar ekki lengur "listOfPeople" -> breyta yfir í SQL fyrirspurn í logic.cpp.
    //findBy föllin notar ekki lengur "listOfPeople" -> breyta yfir í SQL fyrirspurn í logic.cpp.
    //findBy föllin notar ekki lengur "listOfPeople" -> breyta yfir í SQL fyrirspurn í logic.cpp.

    int n;

    cout << "* SEARCH PERSON *" << endl;
    cout << "Would you like to search by" << endl
         << "1. Name" << endl
         << "2. Gender (male or female)" << endl
         << "3. Year of birth" << endl
         << "4. Year of death (write -1 for alive)" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 4);

    vector<people> foundPeople;
    switch(n) {
        case 1: {
            string searchValue = getStringSearchValue("What would you like to search for?");
            foundPeople = theLogic.findByPeopleName(searchValue);
            break;
        }
        case 2: {
            string searchValue = getStringSearchValue("What would you like to search for? (male or female)");
            foundPeople = theLogic.findByPeopleGender(searchValue);
            break;
        }
        case 3: {
            int searchValue = getIntSearchValue();
            foundPeople = theLogic.findByPeopleBirth(searchValue);
            break;
        }
        case 4: {
            int searchValue = getIntSearchValue();
            foundPeople = theLogic.findByPeopleDeath(searchValue);
            break;
        }
        default: {
            break;
        }

        if (foundPeople.size() == 0){
            cout << "No search results found!" << endl;
            system("pause");
            system("cls");

        } else {
//            printVector(foundPeople);
        }
    }
}

void ui::searchMenuComputer()
{
    //IMPLEMENT....
    //IMPLEMENT....
    //IMPLEMENT....

    int n;

    cout << "* SEARCH COMPUTER *" << endl;
    cout << "Would you like to search by" << endl
         << "1. Name" << endl
         << "2. Year created" << endl
         << "3. Type" << endl
         << "4. Ever built or not" << endl
         << "Enter your choice: ";
    cin >> n;
    inputIntCheck(cin.fail(), n, 1, 4);

    cout << " ... implement swith like in search people ... ";
}

void ui::printerMenu()
{
    int printChoice;
    cout << "* PRINTING *" << endl
         << "Do you want to print:" << endl
         << "\t1: People" << endl
         << "\t2: Computers" << endl
         << "Enter your choice: ";
    cout.flush();
    cin >> printChoice;
    inputIntCheck(cin.fail(), printChoice, 1, 2);
    clear();

    if(printChoice == 1)printerMenuPeople();
    else printerMenuComputers();

}

void ui::printerMenuPeople()
{
    int orderBy, ascending;
    cout << "* PRINTING PEOPLE *" << endl
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

    if(orderBy != 2){
        cout << "Do you want this list in descending or ascending order?" << endl
             << "\t0: Descending" << endl
             << "\t1: Ascending" << endl;
    } else {
        cout << "Do you want this list to be ordered by males or females first?" << endl
             << "\t0: Males" << endl
             << "\t1: Females" << endl;
    }

    cout << "Enter your choice: ";
    cout.flush();
    cin >> ascending;
    inputIntCheck(cin.fail(), ascending, 0, 1);
    clear();


    vector<peopleWithComputers> sortedVector = theLogic.printerSortPeople(orderBy, ascending);
    printPeopleVector(sortedVector);
}

void ui::printerMenuComputers()
{
    int orderBy, ascending;
    cout << "* PRINTING COMPUTERS *" << endl
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

    if (orderBy != 4) {
        cout << "Do you this list in descending or ascending order?" << endl
             << "\t0: Descending" << endl
             << "\t1: Ascending" << endl;
    }
    else
    {
        cout << "Do you want this list to be ordered by whether it was built or not built first" << endl
             << "\t0: Built" << endl
             << "\t1: Not built" << endl;
    }

    cout << "Enter your choice: ";
    cout.flush();
    cin >> ascending;
    inputIntCheck(cin.fail(), ascending, 0, 1);
    clear();

    vector<computersWithPeople> sortedVector = theLogic.printerSortComputers(orderBy, ascending);
    printComputersVector(sortedVector);
}

void ui::deleteMenu()
{
    //IMPLEMENT UI....
    //IMPLEMENT UI....
    //IMPLEMENT UI....
}

void ui::printVector(const vector<peopleWithComputers> &list) const
{
    for(const peopleWithComputers person:list)
    {
        cout << person.p.getId() << '\t' << person.p.getName()
             << " " << person.p.getBirth() << "-";
        if (person.p.getDeath() != -1)
            cout << person.p.getDeath() << endl;
        else
            cout << endl;
    }
}

void ui::printVector(const vector<computersWithPeople> &list) const
{
    for(const computersWithPeople computer:list)
    {
        cout << computer.c.getId() << '\t' << computer.c.getName()
             << ", " << computer.c.getYearCreated() << endl;
    }
}

void ui::printPeopleVector(const vector<peopleWithComputers>& list) const
{
    //clear();
    cout << "+------------------------------------------------------------------------------------------+" << endl;
    printf("|%35s|%10s|%8s|%8s|%25s|\n", "PEOPLE NAME", "GENDER", "BIRTH", "DEATH", "COMPUTERS");
    cout << "+------------------------------------------------------------------------------------------+" << endl;
    for(const peopleWithComputers person:list)
    {
        string name = person.p.getName();
        string gender = person.p.getGender();
        int yearOfBirth = person.p.getBirth();
        string death = to_string(person.p.getDeath());
        if(person.p.getDeath() == constants::notDead) death = "Alive";
        printf("|%35s|%10s|%8i|%8s|%25s|\n", name.c_str(), gender.c_str(), yearOfBirth, death.c_str(), "");

        string computerName = person.creations[0].getName().c_str();
        if(computerName != "default")
        {
            for(unsigned int i = 0; i < person.creations.size(); i++)
            {
                printf("|%64s %25s|\n", "", person.creations[i].getName().c_str());
            }
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
    cout << "+------------------------------------------------------------------------------------------+" << endl;
    printf("|%22s|%15s|%8s|%8s|%33s|\n", "COMPUTER NAME", "TYPE", "YEAR", "BUILT", "CREATORS");
    cout << "+------------------------------------------------------------------------------------------+" << endl;
    for(const computersWithPeople comp:list){
        string name = comp.c.getName();
        string type = comp.c.getType();
        int year = comp.c.getYearCreated();
        string built = "No";
        if(comp.c.getWasBuilt()) built = "Yes";
        printf("|%22s|%15s|%8i|%8s|%33s|\n", name.c_str(), type.c_str(), year, built.c_str(), "");

        string personName = comp.creators[0].getName().c_str();
        if(personName != "default")
        {
            for(unsigned int i = 0; i < comp.creators.size(); i++)
            {
                printf("|%56s %33s|\n", "", comp.creators[i].getName().c_str());
            }
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

int ui::getIntSearchValue()
{
    int value;

    cout << "What would you like to search for?" << endl;
    cin >> value;

    inputIntCheck(cin.fail(), value);

    return value;
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
}

void ui::clear() const
{
    #ifdef Q_OS_WIN32 //All Windows versions
        system("cls");
    #else //In any other OS
        system("clear");
    #endif
}

