/* Handlungsplanung 
 * author: Max Regner, Alexandra Mueller
 * date: 23.01.2015
 */

#include <iostream>
#include <string>
#include <list>
#include <set>

using namespace std;

// Variablen der Start- und Ziel-Welt
set<string> startSituation;
set<string> zielSituartion;

// Variable der aktuellen Eigenschaften
// verändert sich innerhalb des laufenden Programms mehrmals
set<string> aktuelleEigenschaften;
// set<string> listeAktionen;
list<string> listeAktionen;

/*-----------------------------------------------------------*/
/*-------------------------Eigenschaften---------------------*/
/*-----------------------------------------------------------*/

// erstellt den string zur Eigenschaft on(X,Y)
// Zwei Steine
string on(int wert1, int wert2)
{
	string wort = "";
	wort += "on(";
	wort += to_string(wert1);
	wort += ",";
	wort += to_string(wert2);
	wort += ")";
	return wort;
}

// erstellt den string zur Eigenschaft on(X,Y)
// ein Stein und die position auf dem Tisch
string on(int wert1, char wert2)
{
	string wort = "";
	wort += "on(";
	wort += to_string(wert1);
	wort += ",";
	wort += wert2;
	wort += ")";
	return wort;
}

// erstellt den string zur Eigenschaft table(X)
// ein Stein liegt auf dem Tisch
string table(int wert)
{
	string wort = "";
	wort += "table(";
	wort += to_string(wert);
	wort += ")";
	return wort;
}

// erstellt den string zur Eigenschaft Clear(X)
// ein Stein ist frei
string clear(int wert)
{
	string wort = "";
	wort += "clear(";
	wort += to_string(wert);
	wort += ")";
	return wort;
}

// erstellt den string zur Eigenschaft table(X)
// die Position auf dem Tisch ist frei
string tablefree(char tableverwenden)
{
	string wort = "";
	wort += "tablefree(";
	wort += tableverwenden;
	wort += ")";
	return wort;
}

/*-----------------------------------------------------------*/
/*----------------------------Aktionen-----------------------*/
/*-----------------------------------------------------------*/

// erstellt den string zur Aktion moveOben(X,Y,Z)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string moveOben(int wert1, int von, int nach)
{
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

// erstellt den string zur Aktion moveUnten(X,a,b)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string moveUnten(int wert1,char start,char ziel)
{
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

// erstellt den string zur Aktion stack(X,a,Y)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string stack(int wert1, char start, int ziel)
{
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

// erstellt den string zur Aktion unstack(X,a,Y)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string unstack(int wert1, int start, char ziel)
{
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

/*-----------------------------------------------------------*/
/*----------------------------Methoden-----------------------*/
/*-----------------------------------------------------------*/

// Erstellt die erste Liste der Eigenschaften
void createSet(int array[])
{
	int stein = 1;
	char platz = 'A';
	if(array[1] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;
		if(array[2] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
	platz++;
	if(array[3] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;

		if(array[4] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
	platz++;
	if(array[5] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;

		if(array[6] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
	platz++;
	if(array[7] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;

		if(array[8] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
}

// gibt falsch zurück fals <a> nicht Teilmenge von <b>
bool vergleich(set<string> a, set<string> b)
{
	//jedes Element von <ZielSituation> muss in <aktuelleEigenschaften> stehen
	bool possible = false;
	set<string>::iterator iterator;
	for(iterator = a.begin(); iterator != a.end(); iterator++)
	{
		if(!(b.find(*iterator) != b.end()))
			return false;
	}
}

void aMoveO(int x,int y,int z)
{
	// insert string in front
	// gegenstück dazu: pop_front()
	listeAktionen.push_front(moveOben(x, y, z));
}
void aMoveU();
void aStack();
void aUnstack();

