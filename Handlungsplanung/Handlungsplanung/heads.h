/* Handlungsplanung Köpfe 
 * author: Max Regner, Alexandra Mueller
 * date: 23.01.2015
 */

#include <iostream>
#include <string>
#include <list>
#include <set>

using namespace std;

// erstellt den string zur Eigenschaft on(X,Y)
// Zwei Steine
string on(int wert1, int wert2);

// erstellt den string zur Eigenschaft on(X,Y)
// ein Stein und die position auf dem Tisch
string on(int wert1, char wert2);

// erstellt den string zur Eigenschaft table(X)
// ein Stein liegt auf dem Tisch
string table(int wert);

// erstellt den string zur Eigenschaft Clear(X)
// ein Stein ist frei
string clear(int wert);

// erstellt den string zur Eigenschaft table(X)
// die Position auf dem Tisch ist frei
string tablefree(char tableverwenden);

// erstellt den string zur Aktion stack(X,a,Y)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string stack(int wert1, char start, int ziel);

// erstellt den string zur Aktion unstack(X,Y,a)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string unstack(int wert1, int start, char ziel);

// erstellt den string zur Aktion moveOben(X,Y,Z)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string moveOben(int wert1, int von, int nach);

// erstellt den string zur Aktion moveUnten(X,a,b)
// enthält die pre/add/del-Listen der Eigenschaften zu dieser Aktion
string moveUnten(int wert1,char start,char ziel);

void createStart(int array[]);

void createZiel(int array[]);

// Erstellt eine Liste der Eigenschaften
// für Start- / ZielSituation
void createSet(int a[], int b[]);

void ausgabeAktEig();

void ausgabeStartEig();

// ueberprueft, ob eine aktion möglich ist
bool possible(set<string> add, set<string> del, set<string> akt);
