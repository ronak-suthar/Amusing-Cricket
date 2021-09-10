#ifndef MENU_H
#define MENU_H
#include<string>

enum Position{ LEFT, CENTRE, RIGHT }; 
void print( std::string,int=1,Position=CENTRE,int=100);
void menu(void);

#endif