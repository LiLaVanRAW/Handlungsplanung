#include <iostream>
#include <string>
#include <list>
#include <set>

using namespace std;

list<string> listeAktionen;
set<string> aktuell;
// ueberprueft, ob aktion möglich ist
bool possible(set<string> add, set<string> del){
	bool moeglich = false;
	set<string>::iterator iterator;
	for(iterator = add.begin(); iterator != add.end(); iterator++){
		if(aktuell.find(*iterator) != aktuell.end()){
			moeglich = true;
		}
	}

	for(iterator = del.begin(); iterator != del.end(); iterator++){
		if(aktuell.find(*iterator) != aktuell.end()){
			moeglich = false;
		}
	}

	return moeglich;


}

void fuehreAktionAus(string aktion, set<string> add, set<string> pre){
	set<string>::iterator iterator;
	for(iterator = add.begin(); iterator != add.end(); iterator++){
		aktuell.erase(*iterator);
	}

	for(iterator = pre.begin(); iterator != pre.end(); iterator++){
		aktuell.insert(*iterator);
	}

	// Aktion in Liste mit Aktionen einfuegen
}

void befehlAusfuehren(string befehl){
	string ausfuehren;
	int wert1; 
	int wert2;
	int wert3;
	char tisch1;
	char tisch2;
	if(befehl.substr(0,9) == "moveUnten"){
	}
}

int main(){
	aktuell.insert("1");
	aktuell.insert("2");
	aktuell.insert("3");

	set<string> add;
	add.insert("5");
	add.insert("7");
	add.insert("8");

	set<string> del;
	del.insert("5");
	cout << possible(add,del);
	befehlAusfuehren("MoveUnten()");
	getchar();
	
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
	return wort;
}