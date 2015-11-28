#include "list.h"

using namespace std;

List::List()
{

}

List::List(istream& fin)
{
    string line;
    int indexStart, indexEnd;
    people peoplePush;
    char newline;

    while(getline(fin, line))
    {
        indexEnd = line.find(",");
        peoplePush.setName(line.substr(0, indexEnd));
        indexStart = indexEnd + 2;
        indexEnd = line.find("," , indexStart);
        peoplePush.setGender(line.substr(indexStart, (indexEnd-indexStart)));
        indexStart = indexEnd + 2;
        indexEnd = line.find("," , indexStart);
        peoplePush.setBirth(line.substr(indexStart, (indexEnd-indexStart)));
        indexStart = indexEnd + 2;
        indexEnd = line.size();
        peoplePush.setDeath(line.substr(indexStart, (indexEnd-indexStart)));
        listOfPeople.push_back(peoplePush);
        fin >> newline;
    }
}

void List::InsertPerson()
{
    
}
