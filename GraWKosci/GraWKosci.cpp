// Lukasz Jarzab - AEI, Informatyka sem. 3 - Projekt na PK3

#include <iostream>

#include "Interface.h"

void programInit() {
    boldFont();
    system("chcp 1250");
    system("cls");
}

int main()
{
    programInit();

    Interface::mainMenu();

    return 0;
}
