#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <thread>

const int MENU_SIZE = 4; // Define the constant for menu size
extern const char* menuItems[MENU_SIZE]; // Declare the menu items array

void gotoxy(int x, int y);
void printCenteredText(const char* text, int line, int consoleWidth);
void drawMenu(int selected, int consoleWidth, int consoleHeight);
void loadingAnimation(int consoleWidth, int consoleHeight, int time);
void exitAction();
void increaseConsoleWindowSize();
void getConsoleDimensions(int& consoleWidth, int& consoleHeight);
int handleMenu(); // Change the return type to int

#endif // MENU_H