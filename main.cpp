#include <ncurses.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
class Card
{
	public:
		int* value;
		char* colour;
		string* name;
		Card(int* v, char* c, string* n){
			value = v;
			colour = c;
			name = n;
		}
		Card(){value = 0; colour = "x";}
		int* getValue(){return value;}
		char* getColour(){return colour;}
		string* getName() {return name;}
};
//Card::Card(int v, char* c, string n){
//	value = v;
//	colour = c;
//	name = n;
//}
class Deck
{
	public:
		Card cards[52];
		Deck();
		Card getRandomCard(){
			srand( time(NULL) );
			return cards[rand() % 52];
		}
};
Deck::Deck(){ //keine passende Funktion zum Aufruf von Card::Card()?
	int v;
	string n;
	char colours[] = "cdhs";
	string names[12] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "Ace"};
	for (int i = 0; i < 12; i++){
		
		if ((i + 2) <= 10){v = i + 2;}
		else if ((i + 2) == 12){v = 11;}
		else {v = 10;}
		n = names[i];
		cards[i] = Card(&v, &colours[0], &n);
	}
	for (int i = 0; i < 12; i++){
		
		if ((i + 2) <= 10){v = i + 2;}
		else if ((i + 2) == 12){v = 11;}
		else {v = 10;}
		n = names[i];
		cards[i] = Card(&v, &colours[1], &n);
	}
	for (int i = 0; i < 12; i++){
		
		if ((i + 2) <= 10){v = i + 2;}
		else if ((i + 2) == 12){v = 11;}
		else {v = 10;}
		n = names[i];
		cards[i] = Card(&v, &colours[2], &n);
	}
	for (int i = 0; i < 12; i++){
		
		if ((i + 2) <= 10){v = i + 2;}
		else if ((i + 2) == 12){v = 11;}
		else {v = 10;}
		n = names[i];
		cards[i] = Card(&v, &colours[3], &n);
	}
}
int main()
{
	Deck deck;
	Card c = deck.getRandomCard();
	cout << c.getValue() << endl << c.getColour() << endl << c.getName() << endl;
	//Card wird nicht mit Parametern initialisiert!
	return 0;
}
