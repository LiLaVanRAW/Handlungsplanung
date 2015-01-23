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

// Variable der aktuellen Eigenschaften
// verändert sich innerhalb des laufenden Programms mehrmals
set<string> aktuelleEigenschaften;

// Aktionsplan
list<string> listeAktionen;


/*-------------------------------------------------------------*/
/*--------------------Anfang Eigenschaften---------------------*/
/*-------------------------------------------------------------*/

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

/*-------------------------------------------------------------*/
/*--------------------Ende---Eigenschaften---------------------*/
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/*--------------------Anfang----Aktionen-----------------------*/
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/*--------------------Ende------Aktionen-----------------------*/
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/*--------------------Anfang----Methoden-----------------------*/
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/*--------------------Ende------Methoden-----------------------*/
/*-------------------------------------------------------------*/

// Erstellt die erste Liste der Eigenschaften
void createSet(int array[])
{
	int stein = 1;
	char platz = 'A';
	if(array[0] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;
		if(array[1] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			//aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
	else
	{
		aktuelleEigenschaften.insert(tablefree(platz));
	}
	platz++;
	if(array[2] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;

		if(array[3] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			//aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
	else
	{
		aktuelleEigenschaften.insert(tablefree(platz));
	}
	platz++;
	if(array[4] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;

		if(array[5] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			//aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
	else
	{
		aktuelleEigenschaften.insert(tablefree(platz));
	}
	platz++;
	if(array[6] != 0)
	{
		aktuelleEigenschaften.insert(table(stein));
		aktuelleEigenschaften.insert(clear(stein));
		aktuelleEigenschaften.insert(on(stein,platz));
		stein++;

		if(array[7] != 0)
		{
			aktuelleEigenschaften.erase(clear(stein-1));
			aktuelleEigenschaften.insert(on(stein, stein-1));
			//aktuelleEigenschaften.insert(clear(stein));
			stein++;
		}
	}
	else
	{
		aktuelleEigenschaften.insert(tablefree(platz));
	}
}

void ausgabeSet()
{
	// Ausgabe der aktuellen Liste der Eigenschaften
	set<string>::iterator element;
	for(element = aktuelleEigenschaften.begin(); element != aktuelleEigenschaften.end(); element++)
	{
		cout << *element;
		cout << "\n";
	}
}

/*---------------------MAIN-METHODE----------------------------*/
int main(int argc, char* argv)
{
	int eingabeStart[8] = {1,1,0,0,1,0,0,0};
	int eingabeZiel[8] = {1,0,0,0,1,0,1,0};

	createSet(eingabeZiel);

	ausgabeSet();
	


	system("pause");
	return 1;
}