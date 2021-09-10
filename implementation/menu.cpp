#include <iostream>
#include "../headers/menu.h"
#include "../headers/player.h"
#include "../headers/database.h"
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

void ManagePlayers(database& db){
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

    Player Data;

    switch (choice)
    {
    case 1:
        Data.getData();
        db.execute_query(Data.insertData());
        break;
        int id;
        print("Kindly Enter ID of Player : ",0);
        std::cin>>id;
    case 2:
        Data.viewData(id);
        break;
    case 3:
        Data.removeData(id);
        break;
    case 4:
        Data.updateData(id);
        break;
    default:
        print("You have Entered InValid Choice! ");
        return;
    }
    getchar();
}
void ManageTeams(database& db){
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
}
void ManageMatches(database& db){

}
void menu(void)
{   

    const int LINELENGTH = 100;
    std::string header(LINELENGTH, '=');
    system("clear");

    database db;
    std::cout << header << '\n';
    print("Welcome to Cricket Match Managment System",2);

    print("Below are Operations That You Can Perform",2);

    int choice;

    print("1. Manage Players",2);
    print("2. Manage Teams  ",2);
    print("3. Manage Matches",2);

    print("Enter your choice : ",0,CENTRE,80);
    std::cin>>choice;
    getchar();

    switch (choice)
    {
    case 1:
        ManagePlayers(db);
        break;
    case 2:
        ManageTeams(db);
        break;
    case 3:
        ManageMatches(db);
        break;
    default:
        break;
    }

    std::cout << header << '\n';
}