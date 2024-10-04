#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

int main() {
  char north[] = "NORTH";
  char south[] = "SOUTH";
  char east[] = "EAST";
  char west[] = "WEST";

  char EClassroomD[60] = "You are in an English class...";
  char CourtyardD[60] = "You are in a courtyard. The flowers smell nice!";
  char CafeteriaD[60] = "You are in the cafeteria... it's not lunch time.";
  char AHall1D[60] = "You realize you've hit a dead end...";
  char AHall2D[60] = "It keeps going. There seems to be something further down...";
  char AHall3D[60] = "You enter a long hall...";
  char AHall4D[60] = "You enter a long hall... there's some classes further down!";
  char AHall5D[60] = "You travel further down the hall...";
  char AHall6D[60]= "You reach the end of the hall!";

  Room* EClassroom = new Room (EClassroomD);
  Room* Courtyard = new Room (CourtyardD);
  Room* Cafeteria = new Room (CafeteriaD);
  Room* AHall1 = new Room (AHall1D);
  Room* AHall2 = new Room (AHall2D);
  Room* AHall3 = new Room (AHall3D);
  Room* AHall4 = new Room (AHall4D);
  Room* AHall5 = new Room (AHall5D);
  Room* AHall6 = new Room (AHall6D);
  EClassroom->setExit(east, Courtyard);
  Courtyard->setExit(north, AHall4);
  Courtyard->setExit(east, Cafeteria);
  Courtyard->setExit(south, AHall3);
  Courtyard->setExit(west, EClassroom);
  Cafeteria->setExit(west, Courtyard);
  AHall3->setExit(north, Courtyard);
  AHall3->setExit(south, AHall2);
  AHall2->setExit(south, AHall1);
  AHall2->setExit(north, AHall3);
  AHall1->setExit(north, AHall2);
  AHall4->setExit(south, Courtyard);
  AHall4->setExit(north, AHall5);
  AHall5->setExit(south, AHall4);
  AHall5->setExit(north, AHall6);
  AHall6->setExit(south, AHall5);
  
  Room* currentRoom = EClassroom;
  bool quit = false;
  cout << "Welcome to Zuul!" << endl;
  while (quit != true) {
    currentRoom->printDescription();
    cout << "You can: MOVE QUIT" << endl;
    cout << "The exits are: " << endl;
    currentRoom->printExits();
    char input[10];
    cin >> input;
    if (strcmp(input, "MOVE") == 0) {
     cout << "Which direction would you like to go?" << endl;
     char directionInput[10];
     cin >> directionInput;
       if (currentRoom == currentRoom->getExit(directionInput)) {
	 cout << "You run into a wall..." << endl;
      }
       else {
	 cout << "Walking..." << endl;
	 currentRoom = currentRoom->getExit(directionInput);
       }
    }
    else if (strcmp(input, "QUIT") == 0) {
       quit = true;
    }
  }
  return 0;
}
