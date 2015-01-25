#include <iostream>
#include <string>
#include <list>
#include <set>
#include "heads.h"

using namespace std;

// Variablen der Start- und Ziel-Welt
set<string> startSituation;
set<string> zielSituation;

// Variable der aktuellen Eigenschaften
// verändert sich innerhalb des laufenden Programms mehrmals
set<string> aktuelleEigenschaften;

	int eingabeStart[8] = {3,2,0,0,1,0,0,0};
	int eingabeZiel[8] = {3,1,0,0,2,0,0,0};

typedef struct Aktion{
	string aktion;
	Aktion* vorgaenger;
} Aktion;

list<Aktion> aktionen;
list<Aktion> ablauf;
bool suche = true;
bool herstellungAktuellerSituation = false;
Aktion *betrachtendeAktion = NULL;

void erstelleAktuelleEigenschaften(){
	aktuelleEigenschaften.clear();
	ablauf.clear();
	// aktuelleEigenschaften mit Eigenschaften von Ziel befuellen
	set<string>::iterator iterator;
	for(iterator = startSituation.begin(); iterator != startSituation.end(); iterator++){
		aktuelleEigenschaften.insert(*iterator);
	}
	list<Aktion> listezwischenaktionen;
	Aktion *zwischenaktion = betrachtendeAktion;
	// Weg finden vom Zwischenziel bis zum Start
	while(zwischenaktion){
		listezwischenaktionen.push_front(*zwischenaktion);
		zwischenaktion = zwischenaktion->vorgaenger;
	}
	herstellungAktuellerSituation = true;
	suche = true;
	list<Aktion>::iterator ite;
	for(ite = listezwischenaktionen.begin(); ite != listezwischenaktionen.end(); ite++) 
		macheAktionAusStringAusfuehrbar(ite->aktion);
	ablauf = listezwischenaktionen;

	
}

void plane(){
	aktuelleEigenschaften.clear();
	// aktuelleEigenschaften mit Eigenschaften von Ziel befuellen
	set<string>::iterator iterator;
	for(iterator = startSituation.begin(); iterator != startSituation.end(); iterator++){
		aktuelleEigenschaften.insert(*iterator);
	}
	suche = true;
	herstellungAktuellerSituation = false;
	betrachtendeAktion = NULL;






	list<Aktion>::iterator ite;
	int wertSetzen = 1;

	while(!gleicheSets(aktuelleEigenschaften,zielSituation)){
		// alle Aktionen durchtesten

	suche = true;
	herstellungAktuellerSituation = false;
	
		for(int zaehler1 = 0; zaehler1 < 8; zaehler1++){
			for(int zaehler2 = 0; zaehler2 < 8; zaehler2++){
				for(int zaehler3 = 0; zaehler3 < 8; zaehler3++){
					if(eingabeZiel[zaehler1] != 0 && eingabeZiel[zaehler2] != 0 && eingabeZiel[zaehler3] != 0 && (zaehler1 != zaehler2 != zaehler3)){
						moveOben(eingabeZiel[zaehler1],eingabeZiel[zaehler2],eingabeZiel[zaehler3]);
					}
				}
			}
		}
		for(char buchstabe = 'A'; buchstabe < 'E'; buchstabe++){
				for(char buchstabe2 = 'A'; buchstabe2 < 'E'; buchstabe2++){
					for(int i = 0; i < 8; i++){
						if(eingabeZiel[i] != 0 && buchstabe != buchstabe2){
							moveUnten(eingabeZiel[i],buchstabe,buchstabe2);
						}
					}
				}
		}

		for(int zaehler1 = 0; zaehler1 < 8; zaehler1++){
			for(int zaehler2 = 0; zaehler2 < 8; zaehler2++){
				for(char buchstabe = 'A'; buchstabe < 'E'; buchstabe++){
					if(zaehler1 != zaehler2 && eingabeZiel[zaehler1] != 0 && eingabeZiel[zaehler2] != 0){
						stack(eingabeZiel[zaehler1],buchstabe,eingabeZiel[zaehler2]);
						unstack(eingabeZiel[zaehler1], eingabeZiel[zaehler2], buchstabe);
					}
				
				}
			}
		}

		if(wertSetzen){
			ite = aktionen.begin();
			wertSetzen = 0;
		}

		betrachtendeAktion = &(*(ite));
		ite++;

		erstelleAktuelleEigenschaften();
	}


}

bool gleicheSets(set<string> zustand, set<string> vergleichenderZustand){
	if(zustand.size() != vergleichenderZustand.size()) return false;
	set<string>::iterator iterator;
	for(iterator = vergleichenderZustand.begin(); iterator != vergleichenderZustand.end(); iterator++){
		zustand.insert(*iterator);
	}
	if(zustand.size() != vergleichenderZustand.size()) return false;
	else return true;
}

int findeUnterschiedeSets(set<string> zustand, set<string> vergleichenderZustand){
	set<string>::iterator iterator;
	int unterschied;
	if(zustand.size() >= vergleichenderZustand.size()){
		for(iterator = vergleichenderZustand.begin(); iterator != vergleichenderZustand.end(); iterator++){
			zustand.erase(*iterator);
		}
		unterschied = zustand.size();
	}else{
		for(iterator = zustand.begin(); iterator != zustand.end(); iterator++){
			vergleichenderZustand.erase(*iterator);
		}
		unterschied = vergleichenderZustand.size();
	}
	return unterschied;
}

// ueberprueft, ob aktion moeglich ist
bool possible(set<string> add, set<string> del){
	bool moeglich = false;
	set<string>::iterator iterator;
	for(iterator = add.begin(); iterator != add.end(); iterator++){
		if(aktuelleEigenschaften.find(*iterator) != aktuelleEigenschaften.end()){
			moeglich = true;
		}
	}

	for(iterator = del.begin(); iterator != del.end(); iterator++){
		if(aktuelleEigenschaften.find(*iterator) != aktuelleEigenschaften.end()){
			moeglich = false;
		}
	}

	return moeglich;


}

bool possible(set<string> pre){
	bool moeglich = false;
	set<string>::iterator iterator;
	for(iterator = aktuelleEigenschaften.begin(); iterator != aktuelleEigenschaften.end(); iterator++){
		pre.erase(*iterator);
	}
	if(pre.size() == 0){
		moeglich = true;
	}
	return moeglich;


}

void fuehreAktionAus(set<string> add, set<string> del){
	set<string>::iterator iterator;
	for(iterator = add.begin(); iterator != add.end(); iterator++){
		aktuelleEigenschaften.insert(*iterator);
	}

	for(iterator = del.begin(); iterator != del.end(); iterator++){
		aktuelleEigenschaften.erase(*iterator);
	}
}
string on(int wert1, int wert2){
	string wort = "";
	wort += "on(";
	wort += to_string(wert1);
	wort += ",";
	wort += to_string(wert2);
	wort += ")";
	return wort;
}

string on(int wert1, char wert2){
	string wort = "";
	wort += "on(";
	wort += to_string(wert1);
	wort += ",";
	wort += wert2;
	wort += ")";
	return wort;
}


string table(int wert){
	string wort = "";
	wort += "table(";
	wort += to_string(wert);
	wort += ")";
	return wort;
}

string clear(int wert){
	string wort = "";
	wort += "clear(";
	wort += to_string(wert);
	wort += ")";
	return wort;
}

string tablefree(char tableverwenden){
	string wort = "";
	wort += "tablefree(";
	wort += tableverwenden;
	wort += ")";
	return wort;
}

string moveOben(int wert1, int von, int nach){
	set<string> pre;
	pre.insert(clear(wert1));
	pre.insert(clear(nach));
	pre.insert(on(wert1,von));
	pre.insert(table(von));
	pre.insert(table(nach));

	set<string> del;
	del.insert(on(wert1,von));
	del.insert(clear(nach));

	set<string> add;
	add.insert(clear(von));
	add.insert(on(wert1,nach));

	string wort = "";
	wort += "moveOben(";
	wort += to_string(wert1);
	wort += ",";
	wort += to_string(von);
	wort += ",";
	wort += to_string(nach);
	wort += ")";
	if(suche){
		if(possible(pre)){
			if(herstellungAktuellerSituation){
				fuehreAktionAus(add, del);
			}else{
				Aktion neu = {wort,betrachtendeAktion};
				aktionen.push_back(neu);
			}
		}
	}
	return wort; 
}

string stack(int wert1, char start, int ziel){
	set<string> pre;
	pre.insert(table(wert1));
	pre.insert(table(ziel));
	pre.insert(clear(wert1));
	pre.insert(clear(ziel));
	pre.insert(on(wert1,start));

	set<string> add;
	add.insert(on(wert1,ziel));
	add.insert(tablefree(start));

	set<string> del;
	del.insert(clear(ziel));
	del.insert(table(wert1));
	del.insert(on(wert1,start));

	string wort = "";
	wort += "stack(";
	wort += to_string(wert1);
	wort += ",";
	wort += start;
	wort += ",";
	wort += to_string(ziel);
	wort += ")";

	if(suche){
		if(possible(pre)){
			if(herstellungAktuellerSituation){
				fuehreAktionAus(add, del);
			}else{
				Aktion neu = {wort,betrachtendeAktion};
				aktionen.push_back(neu);
			}
		}
	}

	return wort;
}

string unstack(int wert1, int start, char ziel){
	set<string> pre;
	pre.insert(clear(wert1));
	pre.insert(on(wert1,start));
	pre.insert(tablefree(ziel));
	pre.insert(table(start));

	set<string> add;
	add.insert(table(wert1));
	add.insert(clear(start));
	add.insert(on(wert1,ziel));

	set<string> del;
	del.insert(on(wert1,start));
	del.insert(tablefree(ziel));

	string wort = "";
	wort += "unstack(";
	wort += to_string(wert1);
	wort += ",";
	wort += to_string(start);
	wort += ",";
	wort += ziel;
	wort += ")";

	if(suche){
		if(possible(pre)){
			if(herstellungAktuellerSituation){
				fuehreAktionAus(add, del);
			}else{
				Aktion neu = {wort,betrachtendeAktion};
				aktionen.push_back(neu);
			}
		}
	}

	return wort;
}

string moveUnten(int wert1,char start,char ziel){
	set<string> pre;
	pre.insert(clear(wert1));
	pre.insert(table(wert1));
	pre.insert(tablefree(ziel));
	pre.insert(on(wert1,start));

	set<string> add;
	add.insert(tablefree(start));
	add.insert(on(wert1,ziel));

	set<string> del;
	del.insert(tablefree(ziel));
	del.insert(on(wert1,start));

	string wort = "";
	wort += "moveUnten(";
	wort += to_string(wert1);
	wort += ",";
	wort += start;
	wort += ",";
	wort += ziel;
	wort += ")";

	if(suche){
		if(possible(pre)){
			if(herstellungAktuellerSituation){
				fuehreAktionAus(add, del);
			}else{
				Aktion neu = {wort,betrachtendeAktion};
				aktionen.push_back(neu);
			}
		}
	}
	return wort;
}

// string fuer die Aktionen ausfuerbar machen
void macheAktionAusStringAusfuehrbar(string befehl){
	string ausfuehren;
	int wert1; 
	int wert2;
	int wert3;
	char tisch1;
	char tisch2;
	int i;
	int aktuellerChar;
	for(i = 0; befehl[i] != '('; i++);
	i++;
	aktuellerChar = i;
	if(befehl.substr(0,i-1) == "moveOben"){
		for(i = aktuellerChar; befehl[i] != ','; i++);
		wert1 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ','; i++);
		wert2 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ')'; i++);
		wert3 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		cout << moveOben(wert1,wert2,wert3);
	}else if(befehl.substr(0,i-1) == "moveUnten"){
		for(i = aktuellerChar; befehl[i] != ','; i++);
		wert1 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ','; i++);
		tisch1 = befehl[i - 1];
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ')'; i++);
		tisch2 = befehl[i - 1];
		cout << moveUnten(wert1,tisch1,tisch2);
	}else if(befehl.substr(0,i-1) == "stack"){
		for(i = aktuellerChar; befehl[i] != ','; i++);
		wert1 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ','; i++);
		tisch1 = befehl[i - 1];
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ')'; i++);
		wert2 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		cout << stack(wert1,tisch1,wert2);
	}else if(befehl.substr(0,i-1) == "unstack"){
		for(i = aktuellerChar; befehl[i] != ','; i++);
		wert1 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ','; i++);
		wert2 = stoi(befehl.substr(aktuellerChar,i - aktuellerChar));
		i++;
		aktuellerChar = i;
		for(i = aktuellerChar; befehl[i] != ')'; i++);
		tisch1 = befehl[i - 1];
		cout << unstack(wert1,wert2,tisch1);
	}
}
void createEigenschaften(int array[],set<string> &eigenschaften)
{
	char platz = 'A';
	if(array[0] != 0)
	{
		eigenschaften.insert(table(array[0]));
		eigenschaften.insert(clear(array[0]));
		eigenschaften.insert(on(array[0],platz));
		if(array[1] != 0)
		{
			eigenschaften.erase(clear(array[0]));
			eigenschaften.insert(on(array[1], array[0]));
			eigenschaften.insert(clear(array[1]));
		}
	}
	else
	{
		eigenschaften.insert(tablefree(platz));
	}
	platz++;
	if(array[2] != 0)
	{
		eigenschaften.insert(table(array[2]));
		eigenschaften.insert(clear(array[2]));
		eigenschaften.insert(on(array[2],platz));

		if(array[3] != 0)
		{
			eigenschaften.erase(clear(array[2]));
			eigenschaften.insert(on(array[3], array[2]));
			eigenschaften.insert(clear(array[3]));
		}
	}
	else
	{
		eigenschaften.insert(tablefree(platz));
	}
	platz++;
	if(array[4] != 0)
	{
		eigenschaften.insert(table(array[4]));
		eigenschaften.insert(clear(array[4]));
		eigenschaften.insert(on(array[4],platz));

		if(array[5] != 0)
		{
			eigenschaften.erase(clear(array[4]));
			eigenschaften.insert(on(array[5], array[4]));
			eigenschaften.insert(clear(array[5]));
		}
	}
	else
	{
		eigenschaften.insert(tablefree(platz));
	}
	platz++;
	if(array[6] != 0)
	{
		eigenschaften.insert(table(array[6]));
		eigenschaften.insert(clear(array[6]));
		eigenschaften.insert(on(array[6],platz));

		if(array[7] != 0)
		{
			eigenschaften.erase(clear(array[6]));
			eigenschaften.insert(clear(array[0]));
			eigenschaften.insert(on(array[7], array[6]));
		}
	}
	else
	{
		eigenschaften.insert(tablefree(platz));
	}
}

int main(){
	createEigenschaften(eingabeStart,startSituation);
	createEigenschaften(eingabeZiel,zielSituation);
	plane();
	erstelleAktuelleEigenschaften();
	getchar();


}