#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Room.h"
#include "Item.h"
using namespace std;

/* This plays the adventure game Zuul in the console.
 * Brandon Huynh, last updated 10/10/2024 */

bool playerHasItem(char* newItem, vector<Item*> playerInventory);
Item* getPlayerItem(char* newItem, vector<Item*> &playerInventory);
void printInventory (vector<Item*> playerInventory);

int main() {
  
  // directions
  char north[] = "NORTH";
  char south[] = "SOUTH";
  char east[] = "EAST";
  char west[] = "WEST";

  // room descriptions
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

  // creating rooms with these descriptions
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

  // setting item names
  char bananaName[] = "BANANA";
  char testTubeName[] = "TEST TUBES";
  char printerName[] = "PRINTER";
  char mapName[] = "MAP";
  char projectorName[] = "PROJECTOR";
  
  // creating items with these names
  Item* Banana = new Item(bananaName);
  Item* Printer = new Item(printerName);
  Item* TestTubes = new Item(testTubeName);
  Item* Map = new Item(mapName);
  Item* Projector = new Item(projectorName);
  
  //adding items to the rooms
  Cafeteria->addItem(Banana);
  Storage->addItem(TestTubes);
  AHall1->addItem(Printer);
  History->addItem(Map);
  Auditorium->addItem(Projector);
  
  //setting exits for rooms
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
  Auditorium->setExit(south, AHall6);
  Auditorium->setExit(west, History);

  // setting player inventory, starting rooms
  vector<Item*> playerInventory;
  Room* currentRoom = EClassroom;
  bool quit = false;

  //intro prompt
  cout << "Welcome to Zuul!" << '\n' << endl;
  cout << "You've misplaced your test tubes full of hydrochloric" << '\n' << "acid. Find them, and bring them back to the chemistry lab." << '\n' << endl;
  cout << "You can: MOVE QUIT DROP GRAB" << endl;

  //main repeating sequence
  while (quit != true) {
    //if they've won the game, they've won
    if (currentRoom == Chem && currentRoom->hasItem(testTubeName)) {
      cout << "You won!!!!!" << endl;
      return 0;
  }
    //print room description, exits, items
    cout << '\n';
    currentRoom->printDescription();
    cout << "The exits are: " << endl;
    currentRoom->printExits();
    if (currentRoom->getItemAmount() != 0) {
    cout << '\n' << "There is a ";
    currentRoom->printItems();
    cout << "here" << endl;
    }

    //see what they want to do
    char input[10];
    cin >> input;
    if (strcmp(input, "MOVE") == 0) {
     cout << "Which direction would you like to go?" << endl;
     char directionInput[10];
     cin >> directionInput;
     // they go in an invalid direction
       if (currentRoom == currentRoom->getExit(directionInput)) {
	 cout << "You run into a wall..." << endl;
      }
       // send them on their way
       else {
	 cout << "Walking..." << endl;
	 currentRoom = currentRoom->getExit(directionInput);
       }
    }
    // they want to grab an item!
    else if (strcmp(input, "GRAB") == 0) {
      // check if there's anything to pick up..
      if (currentRoom->getItemAmount() == 0) {
	cout << "There are no items in the room..." << endl;
      }
      else {
	// prompt user on what they want to grab
	cout << "What item would you like to grab?" << endl;
	cout << "There is a: ";
	currentRoom->printItems();
	cout << '\n';
	char itemInput[50];
      	cin.ignore(64, '\n');
	cin.get(itemInput, 50);
	// if it's there, pick it up
	if (currentRoom->hasItem(itemInput) == true) {
	  playerInventory.push_back(currentRoom->getItem(itemInput));
	  cout << "Grabbed item!" << endl;
	}
	else {
	  cout << "That item isn't here..." << endl;
	}
      }
    }
    // they want to drop an item!
    else if (strcmp(input, "DROP") == 0) {
      // check if they have anything to drop.
      if (playerInventory.size() == 0) {
	cout << "You don't have anything to drop..." << endl;
      }
      else {
	// prompt user on what they want to drop
	cout << "What item would you like to drop?" << endl;
	cout << "You have: ";
	printInventory(playerInventory);
	cout << '\n';
	char itemInput[50];
	cin.ignore(64, '\n');
	cin.get(itemInput, 50);
	// if they have it, drop it
	if (playerHasItem(itemInput, playerInventory) == true) {
	  currentRoom->addItem(getPlayerItem(itemInput, playerInventory));
	}
	else {
	  cout << "You don't have that..." << endl;
	}
      }
    }
    // quit
    else if (strcmp(input, "QUIT") == 0) {
       quit = true;
    }
    // show commands
    else if (strcmp(input, "HELP") == 0) {
        cout << "You can: MOVE QUIT DROP GRAB" <<  '\n' << endl;
    }
    // they typed something random... do they need help?
    else {
      cout << "Not quite sure what you meant." << endl;
      cout << "Type \'HELP\' to see valid commands..." << '\n' << endl;
    }
  }
  return 0;
}

bool playerHasItem(char* newItem, vector<Item*> playerInventory) {
  // traverse through inventory, see if any items match
  for (vector<Item*>:: iterator it = playerInventory.begin(); it != playerInventory.end(); ++it) {
       if (strcmp(newItem, (*it)->getName()) == 0) {
	 return true;
       }
   }
  return false;
}

Item* getPlayerItem(char* newItem, vector<Item*> &playerInventory ) {
  // return the wanted item
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
  // traverse through the players inventory, print everything there
    for (vector<Item*>:: iterator it = playerInventory.begin(); it != playerInventory.end(); ++it) {
     cout << (*it)->getName() << " ";
   }
}
