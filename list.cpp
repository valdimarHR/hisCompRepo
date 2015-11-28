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

    while(getline(fin, line))
    {
        indexEnd = line.find(",");
        peoplePush.setName(line.substr(0, indexEnd));
        indexStart = indexEnd + 2;
        indexEnd = line.find("," , indexStart);
        peoplePush.setGender(line.substr(indexStart, indexStart-indexEnd));
        indexStart = indexEnd + 2;
        indexEnd = line.find("," , indexStart);
        peoplePush.setBirth(line.substr(indexStart, indexStart-indexEnd));
        indexStart = indexEnd + 2;
        indexEnd = line.size();
        peoplePush.setBirth(line.substr(indexStart, indexStart-indexEnd));
        listOfPeople.push_back(peoplePush);
    }
}

void List::InsertPerson()
{
    
}
