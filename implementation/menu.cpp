#include <iostream>
#include "../headers/menu.h"
#include "../headers/database.h"
#include "../headers/player.h"
#include "../headers/Team.h"

void print(std::string s,int newline,Position pos,int linelength)
{
    int spaces = 0;
    switch (pos)
    {
    case CENTRE:
        spaces = (linelength - s.size()) / 2;
        break;
    case RIGHT:
        spaces = linelength - s.size();
        break;
    }

    if (spaces > 0)
        std::cout << std::string(spaces, ' ');
        
    std::cout << s ;
    std::cout << std::string(newline,'\n');
}

void ManagePlayers(database* basePtr){
    const int LINELENGTH = 100;
    std::string header(LINELENGTH, '=');
    system("clear");
    std::cout << header << '\n';

    print("Welcome to Player Managment Section",2);

    print("Below are Operations That You Can Perform",2);

    int choice;

    print("1. Add New Player To Record ",2);
    print("2. View Player Information  ",2);
    print("3. Remove Player From Record",2);
    print("4. Update Player Information",2);

    print("Enter Your Choice : ",0);
    std::cin>>choice;
    getchar();

    switch (choice)
    {
    case 1:
        basePtr->getData();
        basePtr->insertData();
        break;
    case 2:
        basePtr->viewData();
        break;
    case 3:
        basePtr->removeData();
        break;
    case 4:
        basePtr->updateData();
        break;
    default:
        print("You have Entered InValid Choice! ");
        menu();
    }
    getchar();
    menu();
}
void ManageTeams(database* basePtr){
    const int LINELENGTH = 100;
    std::string header(LINELENGTH, '=');
    system("clear");
    std::cout << header << '\n';

    print("Welcome to Team Managment Section",2);

    print("Below are Operations That You Can Perform",2);

    int choice;

    print("1. Add New Team To Record",2);
    print("2. View Team Information",2);
    print("3. Remove Team From Record",2);
    print("4. Update Team Information",2);

    print("Enter Your Choice : ",0);
    std::cin>>choice;
    getchar();

    switch (choice)
    {
    case 1:
        basePtr->getData();
        basePtr->insertData();
        break;
    case 2:
        basePtr->viewData();
        break;
    case 3:
        basePtr->removeData();
        break;
    case 4:
        basePtr->updateData();
        break;
    default:
        print("You have Entered InValid Choice! ");
        menu();
    }
    getchar();
    menu();
}
void ManageMatches(database* basePtr){

}
void menu(void)
{   

    const int LINELENGTH = 100;
    std::string header(LINELENGTH, '=');
    system("clear");

    std::cout << header << '\n';
    print("Welcome to Cricket Match Managment System",2);

    print("Below are Operations That You Can Perform",2);

    int choice;

    print("1. Manage Players",2);
    print("2. Manage Teams  ",2);
    print("3. Manage Matches",2);
    print("Press Any Other Value To Exit",2);
    print("Enter your choice : ",0,CENTRE,80);
    std::cin>>choice;
    getchar();

    database* basePtr;

    switch (choice)
    {
    case 1:
        basePtr = new Player();
        ManagePlayers(basePtr);
        delete basePtr;
        break;
    case 2:
        basePtr = new Team();
        ManageTeams(basePtr);
        delete basePtr;
        break;
    case 3:
        basePtr = new Player();//Change
        ManageMatches(basePtr);
        delete basePtr;
        break;
    default:
        break;
    }

}