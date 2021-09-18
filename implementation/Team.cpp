#include <iostream>
#include "../headers/Team.h"
#include "../headers/menu.h"

Team::Team(std::string name, std::string board, std::string mail)
{
    Name = name;
    Board = board;
    Email = mail;
}
void Team::getData()
{
    print("", 2);
    print("Kindly Provide Below Information to Store Team/Country Record", 2);

    print("Enter Team Name : ", 0);
    std::cin >> Name;
    print("", 1);

    print("Enter Country Board : ", 0);
    std::cin >> Board;
    print("", 1);

    print("Enter Boards Email Address : ", 0);
    std::cin >> Email;
    print("", 1);
}
void Team::insertData(void)
{
    std::string query = "INSERT INTO Team VALUES (\"" + this->Name + "\",\"" + this->Board + "\",\"" + this->Email + "\")";
    if (execute_query(query))
    {
        print("Transaction Successfull");
        print("Press Any key to go back to menu");
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}

void Team::viewData(void)
{
    std::string teamName;
    print("Enter Team Name : ", 0);
    std::cin >> teamName;
    getchar();

    std::string query = "SELECT * FROM Team WHERE Name= \"" + teamName + "\"";

    if (execute_query(query))
    {
        res = mysql_use_result(conn);
        row = mysql_fetch_row(res);

        if (row != NULL)
        {
            print("-----------------------------------");
            print("Team Details are as follows : ", 2);
            print("Name : " + std::string(row[0]), 1);
            print("Cricket Board : " + std::string(row[1]), 1);
            print("Contact Email : " + std::string(row[2]), 1);
            print("-----------------------------------");
            getchar();
        }
        else
        {
            print("Team Not Found in Records");
        }

        mysql_free_result(res);
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}

void Team::removeData(void)
{
    std::string teamName;
    print("Enter Team Name : ", 0);
    std::cin >> teamName;
    getchar();

    std::string query = "DELETE FROM Team WHERE Name= \"" + teamName + "\"";

    if (execute_query(query) && mysql_affected_rows(conn) != 0)
    {
        print("Transaction Successfull");
        print("Press Any key to go back to menu");
    }
    else if (mysql_affected_rows(conn) == 0)
    {
        print("Records Already doesn't Exists for given Team Name");
    }
    else
    {
        print("There is Some Issue with your transactions");
    }
}

void Team::updateData(void)
{
    print("Which Field You Would Like to Update ? ");

    int choice;
    std::string teamName;

    print("1. Cricket board of Team ", 1);
    print("2. Email of Cricket Board", 1);

    print("Enter Your Choice : ", 0);

    std::cin >> choice;
    getchar();

    print("Enter Team Name : ", 0);
    std::getline(std::cin, teamName);

    std::string query = "";

    if (choice == 1)
    {
        std::string newBoard;
        print("Enter Board Name to Be Updated : ", 0);
        std::getline(std::cin, newBoard);
        query = "UPDATE Team SET Board=\"" + newBoard + "\" WHERE Name =\"" + teamName + "\"";
    }
    else if (choice == 2)
    {
        std::string newEmail;
        print("Enter Board Email to Be Updated : ", 0);
        std::getline(std::cin, newEmail);
        query = "UPDATE Team SET Email=\"" + newEmail + "\" WHERE Name =\"" + teamName + "\"";
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

