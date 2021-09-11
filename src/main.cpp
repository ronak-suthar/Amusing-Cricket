#include <iostream>
#include <string>
#include "../headers/menu.h"

int main()
{   
    const int LINELENGTH = 100;
    std::string header(LINELENGTH, '=');

    menu();

    std::cout << header << '\n';
    print("Thank You For Using Cricket Managment System Do Visit Again");
    std::cout << header << '\n';
    return 0;
}