#include<iostream>
#include "../headers/player.h"
#include "../headers/menu.h"

Player::Player(std::string name,std::string role,std::string teamname,int id){
    Name = name;Role=role;TeamName=teamname;ID=id;
}

void Player::getData(void){
    std::string temp="";
    
    print("",2);
    print("Enter the Follwing Information to Store Player Record",2);

    print("Enter Player Name : ",0,CENTRE,80);
    std::getline(std::cin,temp);
    this->Name=temp;

    print("",2);

    int choice;

    print("Select Player Primary Role : ",1);
    print("1. Batsmen      ",1);
    print("2. Bowler       ",1);
    print("3. Wicket Keeper",1);
    print("4. All Rounder  ",1);

    print("Enter Your Choice          : ",0);
    std::cin>>choice;
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
        print("You Have Provided Invalid Choice !",1);
        return;
    }
    print("",2);

    print("Enter Player Team Name : ",0);
    std::getline(std::cin,temp);
    this->TeamName=temp;
    print("",1);

    print("Enter Player Unique ID : ",0);
    std::cin>>this->ID;
    getchar();
    print("",1);

    // print("Player Name : "+this->Name);
    // print("Team Name : "+this->TeamName);
    // print("Player Role : "+this->Role);
    // print("Player ID : "+std::to_string(this->ID));
}

void Player::viewData(int id){
    
}
void Player::removeData(int id){

}
void Player::updateData(int id){
    
}

const std::string Player::insertData(void){
    std::string query = "INSERT INTO Player VALUES (\""+this->Name+"\",\""+this->Role+"\",\""+this->TeamName+"\",\""+std::to_string(this->ID)+"\")";
    return query;
}