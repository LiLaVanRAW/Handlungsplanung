///* Handlungsplanung 
// * author: Max Regner, Alexandra Mueller
// * date: 23.01.2015
// */
//
//#include <iostream>
//#include <string>
//#include <list>
//#include <set>
//
//#include "heads.h"
//
//using namespace std;
//
//// Variablen der Start- und Ziel-Welt
//set<string> startSituation;
//
//// Variable der aktuellen Eigenschaften
//// verändert sich innerhalb des laufenden Programms mehrmals
//set<string> aktuelleEigenschaften;
//
//// Aktionsplan
//list<string> listeAktionen;
//
//
///*-------------------------------------------------------------*/
///*--------------------Anfang Eigenschaften---------------------*/
///*-------------------------------------------------------------*/
//
//// erstellt den string zur Eigenschaft on(X,Y)
//// Zwei Steine
//string on(int wert1, int wert2)
//{
//	string wort = "";
//	wort += "on(";
//	wort += to_string(wert1);
//	wort += ",";
//	wort += to_string(wert2);
//	wort += ")";
//	return wort;
//}
//
//// erstellt den string zur Eigenschaft on(X,Y)
//// ein Stein und die position auf dem Tisch
//string on(int wert1, char wert2)
//{
//	string wort = "";
//	wort += "on(";
//	wort += to_string(wert1);
//	wort += ",";
//	wort += wert2;
//	wort += ")";
//	return wort;
//}
//
//// erstellt den string zur Eigenschaft table(X)
//// ein Stein liegt auf dem Tisch
//string table(int wert)
//{
//	string wort = "";
//	wort += "table(";
//	wort += to_string(wert);
//	wort += ")";
//	return wort;
//}
//
//// erstellt den string zur Eigenschaft Clear(X)
//// ein Stein ist frei
//string clear(int wert)
//{
//	string wort = "";
//	wort += "clear(";
//	wort += to_string(wert);
//	wort += ")";
//	return wort;
//}
//
//// erstellt den string zur Eigenschaft table(X)
//// die Position auf dem Tisch ist frei
//string tablefree(char tableverwenden)
//{
//	string wort = "";
//	wort += "tablefree(";
//	wort += tableverwenden;
//	wort += ")";
//	return wort;
//}
//
///*-------------------------------------------------------------*/
///*--------------------Ende---Eigenschaften---------------------*/
///*-------------------------------------------------------------*/
//
///*-------------------------------------------------------------*/
///*--------------------Anfang----Aktionen-----------------------*/
///*-------------------------------------------------------------*/
//
//// erstellt den string zur Aktion stack(X,a,Y)
//// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
//string stack(int wert1, char start, int ziel)
//{
//	set<string> pre;
//	pre.insert(table(wert1));
//	pre.insert(table(ziel));
//	pre.insert(clear(wert1));
//	pre.insert(clear(ziel));
//	pre.insert(on(wert1,start));
//
//	set<string> add;
//	add.insert(on(wert1,ziel));
//	add.insert(tablefree(start));
//
//	set<string> del;
//	del.insert(clear(wert1));
//	del.insert(clear(ziel));
//	del.insert(table(wert1));
//	del.insert(on(wert1,start));
//
//	//INSERT Possible Abfrage hier
//	{
//		bool poss = possible(add, del, aktuelleEigenschaften);
//		cout << poss;
//	}
//
//	string wort = "";
//	wort += "stack(";
//	wort += to_string(wert1);
//	wort += ",";
//	wort += start;
//	wort += ",";
//	wort += to_string(ziel);
//	wort += ")";
//	return wort;
//}
//
//// erstellt den string zur Aktion unstack(X,Y,a)
//// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
//string unstack(int wert1, int start, char ziel)
//{
//	set<string> pre;
//	//pre.insert(clear(wert1));
//	pre.insert(on(wert1,start));
//	pre.insert(tablefree(ziel));
//	pre.insert(table(start));
//
//	set<string> add;
//	add.insert(table(wert1));
//	add.insert(clear(start));
//	add.insert(clear(wert1));
//	add.insert(on(wert1,ziel));
//
//	set<string> del;
//	del.insert(on(wert1,start));
//	del.insert(tablefree(ziel));
//
//	//INSERT Possible Abfrage hier
//	{
//		bool poss = possible(add, del, aktuelleEigenschaften);
//		cout << poss;
//	}
//
//	string wort = "";
//	wort += "unstack(";
//	wort += to_string(wert1);
//	wort += ",";
//	wort += to_string(start);
//	wort += ",";
//	wort += ziel;
//	wort += ")";
//	return wort;
//}
//
//// erstellt den string zur Aktion moveOben(X,Y,Z)
//// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
//string moveOben(int wert1, int von, int nach)
//{
//	set<string> pre;
//	//pre.insert(clear(wert1));
//	pre.insert(clear(nach));
//	pre.insert(on(wert1,von));
//	pre.insert(table(von));
//	pre.insert(table(nach));
//
//	set<string> del;
//	del.insert(on(wert1,von));
//	del.insert(clear(nach));
//
//	set<string> add;
//	add.insert(clear(von));
//	add.insert(on(wert1,nach));
//	
//	//INSERT Possible Abfrage hier
//
//	string wort = "";
//	wort += "moveOben(";
//	wort += to_string(wert1);
//	wort += ",";
//	wort += to_string(von);
//	wort += ",";
//	wort += to_string(nach);
//	wort += ")";
//	return wort; 
//}
//
//// erstellt den string zur Aktion moveUnten(X,a,b)
//// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
//string moveUnten(int wert1,char start,char ziel)
//{
//	set<string> pre;
//	pre.insert(clear(wert1));
//	pre.insert(table(wert1));
//	pre.insert(tablefree(ziel));
//	pre.insert(on(wert1,start));
//
//	set<string> add;
//	add.insert(tablefree(start));
//	add.insert(on(wert1,ziel));
//
//	set<string> del;
//	del.insert(tablefree(ziel));
//	del.insert(on(wert1,start));
//
//	//INSERT Possible Abfrage hier
//
//	string wort = "";
//	wort += "moveUnten(";
//	wort += to_string(wert1);
//	wort += ",";
//	wort += start;
//	wort += ",";
//	wort += ziel;
//	wort += ")";
//	return wort;
//}
//
///*-------------------------------------------------------------*/
///*--------------------Ende------Aktionen-----------------------*/
///*-------------------------------------------------------------*/
//
///*-------------------------------------------------------------*/
///*--------------------Anfang----Methoden-----------------------*/
///*-------------------------------------------------------------*/
//
//void createStart(int array[])
//{
//	int stein = 1;
//	char platz = 'A';
//	if(array[0] != 0)
//	{
//		startSituation.insert(table(stein));
//		startSituation.insert(clear(stein));
//		startSituation.insert(on(stein,platz));
//		stein++;
//		if(array[1] != 0)
//		{
//			startSituation.erase(clear(stein-1));
//			startSituation.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		startSituation.insert(tablefree(platz));
//	}
//	platz++;
//	if(array[2] != 0)
//	{
//		startSituation.insert(table(stein));
//		startSituation.insert(clear(stein));
//		startSituation.insert(on(stein,platz));
//		stein++;
//
//		if(array[3] != 0)
//		{
//			startSituation.erase(clear(stein-1));
//			startSituation.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		startSituation.insert(tablefree(platz));
//	}
//	platz++;
//	if(array[4] != 0)
//	{
//		startSituation.insert(table(stein));
//		startSituation.insert(clear(stein));
//		startSituation.insert(on(stein,platz));
//		stein++;
//
//		if(array[5] != 0)
//		{
//			startSituation.erase(clear(stein-1));
//			startSituation.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		startSituation.insert(tablefree(platz));
//	}
//	platz++;
//	if(array[6] != 0)
//	{
//		startSituation.insert(table(stein));
//		startSituation.insert(clear(stein));
//		startSituation.insert(on(stein,platz));
//		stein++;
//
//		if(array[7] != 0)
//		{
//			startSituation.erase(clear(stein-1));
//			startSituation.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		startSituation.insert(tablefree(platz));
//	}
//}
//
//void createZiel(int array[])
//{
//	int stein = 1;
//	char platz = 'A';
//	if(array[0] != 0)
//	{
//		aktuelleEigenschaften.insert(table(stein));
//		aktuelleEigenschaften.insert(clear(stein));
//		aktuelleEigenschaften.insert(on(stein,platz));
//		stein++;
//		if(array[1] != 0)
//		{
//			aktuelleEigenschaften.erase(clear(stein-1));
//			aktuelleEigenschaften.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		aktuelleEigenschaften.insert(tablefree(platz));
//	}
//	platz++;
//	if(array[2] != 0)
//	{
//		aktuelleEigenschaften.insert(table(stein));
//		aktuelleEigenschaften.insert(clear(stein));
//		aktuelleEigenschaften.insert(on(stein,platz));
//		stein++;
//
//		if(array[3] != 0)
//		{
//			aktuelleEigenschaften.erase(clear(stein-1));
//			aktuelleEigenschaften.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		aktuelleEigenschaften.insert(tablefree(platz));
//	}
//	platz++;
//	if(array[4] != 0)
//	{
//		aktuelleEigenschaften.insert(table(stein));
//		aktuelleEigenschaften.insert(clear(stein));
//		aktuelleEigenschaften.insert(on(stein,platz));
//		stein++;
//
//		if(array[5] != 0)
//		{
//			aktuelleEigenschaften.erase(clear(stein-1));
//			aktuelleEigenschaften.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		aktuelleEigenschaften.insert(tablefree(platz));
//	}
//	platz++;
//	if(array[6] != 0)
//	{
//		aktuelleEigenschaften.insert(table(stein));
//		aktuelleEigenschaften.insert(clear(stein));
//		aktuelleEigenschaften.insert(on(stein,platz));
//		stein++;
//
//		if(array[7] != 0)
//		{
//			aktuelleEigenschaften.erase(clear(stein-1));
//			aktuelleEigenschaften.insert(on(stein, stein-1));
//			stein++;
//		}
//	}
//	else
//	{
//		aktuelleEigenschaften.insert(tablefree(platz));
//	}
//}
//
//// Erstellt eine Liste der Eigenschaften
//// für Start- / ZielSituation
//void createSet(int a[], int b[])
//{
//	createStart(a);
//	createZiel(b);
//}
//
//void ausgabeAktEig()
//{
//	// Ausgabe der aktuellen Liste der Eigenschaften
//	set<string>::iterator element;
//	for(element = aktuelleEigenschaften.begin(); element != aktuelleEigenschaften.end(); element++)
//	{
//		cout << *element;
//		cout << "\n";
//	}
//}
//
//void ausgabeStartEig()
//{
//	// Ausgabe der aktuellen Liste der Eigenschaften
//	set<string>::iterator element;
//	for(element = startSituation.begin(); element != startSituation.end(); element++)
//	{
//		cout << *element;
//		cout << "\n";
//	}
//}
//
//// ueberprueft, ob eine aktion möglich ist
//bool possible(set<string> add, set<string> del, set<string> akt)
//{
//	bool moeglich = false;
//	set<string>::iterator iterator;
//	for(iterator = add.begin(); iterator != add.end(); iterator++)
//	{
//		// falls das Element vorhanden ist
//		// bekommt der iterator den Wert der Stelle
//		// falls nicht den Wert vom Ende
//		if(akt.find(*iterator) != akt.end())
//		{
//			moeglich = true;
//		}
//		else
//			return false;
//	}
//	for(iterator = del.begin(); iterator != del.end(); iterator++)
//	{
//		if(akt.find(*iterator) != akt.end())
//		{
//			return false;
//		}
//	}
//	return moeglich;
//}
//
//
///*-------------------------------------------------------------*/
///*--------------------Ende------Methoden-----------------------*/
///*-------------------------------------------------------------*/
//
///*-------------------------------------------------------------*/
///*---------------------MAIN-METHODE----------------------------*/
///*-------------------------------------------------------------*/
//int main(int argc, char* argv)
//{
//	int eingabeStart[8] = {1,1,0,0,1,0,0,0};
//	int eingabeZiel[8] = {1,0,0,0,1,0,1,0};
//
//	createSet(eingabeStart, eingabeZiel);
//
//	// Ausgabe
//	ausgabeAktEig();
//	printf("\n------------------\n");
//	ausgabeStartEig();
//	printf("\n------------------\n");
//
//	{
//		string name = unstack(1,2,'A');
//		printf("\n------------------\n");
//		cout << name;
//		printf("\n------------------\n");
//	}
//
//	system("pause");
//	return 1;
//}