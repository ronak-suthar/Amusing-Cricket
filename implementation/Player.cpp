#include <iostream>
#include "../headers/player.h"
#include "../headers/menu.h"

Player::Player(std::string name, std::string role, std::string teamname, int id)
{
    Name = name;
    Role = role;
    TeamName = teamname;
    ID = id;
}

void Player::getData(void)
{
    std::string temp = "";

    print("", 2);
    print("Enter the Follwing Information to Store Player Record", 2);

    print("Enter Player Name : ", 0, CENTRE, 80);
    std::getline(std::cin, temp);
    this->Name = temp;

    print("", 2);

    int choice;

    print("Select Player Primary Role : ", 1);
    print("1. Batsmen      ", 1);
    print("2. Bowler       ", 1);
    print("3. Wicket Keeper", 1);
    print("4. All Rounder  ", 1);

    print("Enter Your Choice          : ", 0);
    std::cin >> choice;
    getchar();

    switch (choice)
    {
    case 1:
        this->Role = "Batsmen";
        break;
    case 2:
        this->Role = "Bowler";
        break;
    case 3:
        this->Role = "Wicket Keeper";
        break;
    case 4:
        this->Role = "All Rounder";
        break;

    default:
        print("You Have Provided Invalid Choice !", 1);
        return;
    }
    print("", 2);

    print("Enter Player Team Name : ", 0);
    std::getline(std::cin, temp);
    this->TeamName = temp;
    print("", 1);

    print("Enter Player Unique ID : ", 0);
    std::cin >> this->ID;
    getchar();
    print("", 1);

    // print("Player Name : "+this->Name);
    // print("Team Name : "+this->TeamName);
    // print("Player Role : "+this->Role);
    // print("Player ID : "+std::to_string(this->ID));
}

void Player::viewData(void)
{
    int playerID;
    print("Enter Unique id of Player : ", 0);
    std::cin >> playerID;
    getchar();

    std::string query = "SELECT * FROM Player WHERE ID=" + std::to_string(playerID);

    if (execute_query(query))
    {
        res = mysql_use_result(conn);
        row = mysql_fetch_row(res);

        if (row != NULL)
        {
            print("-----------------------------------");
            print("Player Details are as follows : ", 2);
            print("Name : " + std::string(row[0]), 1);
            print("Role : " + std::string(row[1]), 1);
            print("TeamName : " + std::string(row[2]), 1);
            print("ID : " + std::string(row[3]), 1);
            print("-----------------------------------");
        }
        else
        {
            print("Player Not Found in Records");
        }

        mysql_free_result(res);
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}
void Player::removeData(void)
{
    int playerID;
    print("Enter Unique id of Player : ", 0);
    std::cin >> playerID;
    getchar();

    std::string query = "DELETE FROM Player WHERE ID=" + std::to_string(playerID);

    if (execute_query(query) && mysql_affected_rows(conn) != 0)
    {
        print("Transaction Successfull");
        print("Press Any key to go back to menu");
        getchar();
    }
    else if (mysql_affected_rows(conn) == 0)
    {
        print("Records Already doesn't Exists for given ID");
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}
void Player::updateData(void)
{
    print("Which Field You Would Like to Update ? ");

    int choice;

    print("1. Name of Player", 1);
    print("2. Role of Player", 1);
    print("3. Team of Player", 1);

    print("Enter your choice : ", 0);
    std::cin >> choice;
    getchar();

    int id;
    print("Enter Player ID : ", 0);
    std::cin >> id;
    getchar();

    std::string query = "";

    if (choice == 1)
    {
        std::string newName;
        print("Enter New Name to be Updated : ", 0);
        std::getline(std::cin, newName);

        query = "UPDATE Player SET Name = \"" + newName + "\" WHERE ID=" + std::to_string(id);
    }
    else if (choice == 2)
    {
        int roleChoice;
        print("Select Player Updated Primary Role : ", 1);
        print("1. Batsmen      ", 1);
        print("2. Bowler       ", 1);
        print("3. Wicket Keeper", 1);
        print("4. All Rounder  ", 1);

        print("Enter Your Choice          : ", 0);

        std::cin >> roleChoice;
        getchar();

        std::string newRole;

        if (roleChoice == 1)
        {
            newRole = "Batsmen";
        }
        else if (roleChoice == 1)
        {
            newRole = "Bowler";
        }
        else if (roleChoice == 1)
        {
            newRole = "Wicket Keeper";
        }
        else if (roleChoice == 1)
        {
            newRole = "All ROunder";
        }
        else
        {
            print("Wrong Choice ,Press Any Key to Continue !", 2);
            getchar();
            return;
        }
        query = "UPDATE Player SET Role = \"" + newRole + "\"WHERE ID=" + std::to_string(id);
    }
    else if (choice == 3)
    {
        std::string newTeam;
        print("Enter New Team to be Updated : ", 0);
        std::getline(std::cin, newTeam);

        query = "UPDATE Player SET Team = \"" + newTeam + "\" WHERE ID=" + std::to_string(id);
    }
    else
    {
        print("Wrong Choice ,Press Any Key to Continue !", 2);
        return;
    }

    if (execute_query(query) && mysql_affected_rows(conn) != 0)
    {
        print("Transaction Successfull");
        print("Press Any key to go back to menu");
    }
    else if (mysql_affected_rows(conn) == 0)
    {
        print("Records Already doesn't Exists for given ID");
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}

void Player::insertData()
{
    std::string query = "INSERT INTO Player VALUES (\"" + this->Name + "\",\"" + this->Role + "\",\"" + this->TeamName + "\",\"" + std::to_string(this->ID) + "\")";
    if (execute_query(query))
    {
        print("Transaction Successfull");
        print("Press Any key to go back to menu");
        getchar();
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}