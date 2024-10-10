#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"
#include "Item.h"
using namespace std;

bool playerHasItem(char* newItem, vector<Item*> playerInventory);
Item* getPlayerItem(char* newItem, vector<Item*> &playerInventory);
void printInventory (vector<Item*> playerInventory);
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
  char GymD[60] = "You enter the gym... the lights are off.";
  char ChemD[60] = "You're in the chemistry lab. Have you found the test tubes?";
  char BathroomD[60]= "You enter the bathroom... why...";
  char MathD[60] = "You enter a math class...";
  char HistoryD[60] = "You enter a history class... is that Napoleon?";
  char AuditoriumD[60] = "You enter the auditorium... the lights are off.";
  char StorageD[60] = "You enter the storage room... I wonder what's in here!";
  
  Room* EClassroom = new Room (EClassroomD);
  Room* Courtyard = new Room (CourtyardD);
  Room* Cafeteria = new Room (CafeteriaD);
  Room* AHall1 = new Room (AHall1D);
  Room* AHall2 = new Room (AHall2D);
  Room* AHall3 = new Room (AHall3D);
  Room* AHall4 = new Room (AHall4D);
  Room* AHall5 = new Room (AHall5D);
  Room* AHall6 = new Room (AHall6D);
  Room* Gym = new Room(GymD);
  Room* Chem = new Room(ChemD);
  Room* Bathroom = new Room(BathroomD);
  Room* Math = new Room(MathD);
  Room* History = new Room(HistoryD);
  Room* Auditorium = new Room(AuditoriumD);
  Room* Storage = new Room(StorageD);
  char bananaDescription[60] = "Banana";
  Item* Banana = new Item(bananaDescription);
  EClassroom->addItem(Banana);
  EClassroom->setExit(east, Courtyard);
  EClassroom->setExit(north, Gym);
  History->setExit(south, Math);
  History->setExit(east, Auditorium);
  Bathroom->setExit(east, Math);
  Bathroom->setExit(south, Chem);
  Chem->setExit(north, Bathroom);
  Chem->setExit(south, Gym);
  Gym->setExit(south, EClassroom);
  Gym->setExit(north, Bathroom);
  Storage->setExit(west, AHall5);
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
  AHall5->setExit(east, Storage);
  AHall6->setExit(south, AHall5);
  AHall6->setExit(north, Auditorium);
  AHall6->setExit(west, Math);
  Math->setExit(west, Bathroom);
  Math->setExit(north, History);
  Math->setExit(east, AHall6);

  vector<Item*> playerInventory;
  
  Room* currentRoom = EClassroom;
  bool quit = false;
  cout << "Welcome to Zuul!" << endl;
  cout << "You can: MOVE QUIT DROP GRAB" << endl;
  while (quit != true) { 
    currentRoom->printDescription();
    cout << "The exits are: " << endl;
    currentRoom->printExits();
    if (currentRoom->getItemAmount() != 0) {
    cout << "There is a ";
    currentRoom->printItems();
    cout << "here" << endl;
    }
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
    else if (strcmp(input, "GRAB") == 0) {
      if (currentRoom->getItemAmount() == 0) {
	cout << "There are no items in the room..." << endl;
      }
      else {
	cout << "What item would you like to grab?" << endl;
	cout << "There is a: ";
	currentRoom->printItems();
	cout << '\n';
	char itemInput[50];
	cin.ignore(64, '\n');
	cin.get(itemInput, 50);
	if (currentRoom->hasItem(itemInput) == true) {
	  playerInventory.push_back(currentRoom->getItem(itemInput));
	}
	else {
	  cout << "That item isn't here..." << endl;
	}
      }
    }
    else if (strcmp(input, "DROP") == 0) {
      if (playerInventory.size() == 0) {
	cout << "You don't have anything to drop..." << endl;
      }
      else {
	cout << "What item would you like to drop?" << endl;
	cout << "You have: ";
	printInventory(playerInventory);
	cout << '\n';
	char itemInput[50];
	cin.ignore(64, '\n');
	cin.get(itemInput, 50);
	if (playerHasItem(itemInput, playerInventory) == true) {
	  currentRoom->addItem(getPlayerItem(itemInput, playerInventory));
	}
      }
    }
    else if (strcmp(input, "QUIT") == 0) {
       quit = true;
    }
    else if (strcmp(input, "HELP") == 0) {
      cout << "You can: MOVE QUIT" << endl;
    }
    else {
      cout << "Not quite sure what you meant..." << endl;
      cout << "Type \'HELP\' to see valid commands..." << endl;
    }
  }
  return 0;
}

bool playerHasItem(char* newItem, vector<Item*> playerInventory) {
  for (vector<Item*>:: iterator it = playerInventory.begin(); it != playerInventory.end(); ++it) {
       if (strcmp(newItem, (*it)->getName()) == 0) {
	 return true;
       }
   }
  return false;
}

Item* getPlayerItem(char* newItem, vector<Item*> &playerInventory ) {
  for (vector<Item*>:: iterator it = playerInventory.begin(); it != playerInventory.end(); ++it) {
       if (strcmp(newItem, (*it)->getName()) == 0) {
          Item* returnItem = *it;
	  playerInventory.erase(it);
	  return returnItem;
       }
   }
  return nullptr;
}

void printInventory(vector<Item*> playerInventory) {
    for (vector<Item*>:: iterator it = playerInventory.begin(); it != playerInventory.end(); ++it) {
     cout << (*it)->getName() << " ";
   }
}
