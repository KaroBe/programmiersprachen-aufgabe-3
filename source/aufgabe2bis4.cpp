#include <cstdlib> // std::rand()
#include <vector> // std::vector<>
#include <list> // std::list<>
#include <iostream> // std::cout
#include <iterator> // std::ostream_iterator<>
#include <algorithm> // std::reverse, std::generate
#include <string>
#include <set>
#include <map>

int main ()
{

	/*
	
	Aufg. 3.2

	*/

	//list mit unsigned int initialisieren
	std::list<unsigned int> liste(100);

	//mit 100 Zufallszahlen von 0-100 füllen
	for (auto& element : liste) // & -> keine Kopie vom Element wird angelegt,
		//aber weil element verändert werden soll
	{
		element = std::rand() % 101;
	}

	/*
	Alte Variante: Fehleranfällig, viel Schreibarbeit
	for(std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		*it = ...; -> muss dereferenziert werden um auf Element zuzugreifen
	}
	*/

	//Ausgabe liste
	std::cout << " \n liste: \n";
	std::copy(std::begin(liste), std::end(liste),
				std::ostream_iterator<int>(std::cout, " "));

	//vector erzeugen, elemente aus liste kopieren
	std::vector<unsigned int> vektor (std::begin(liste), std::end(liste));

	//Ausgabe vektor
	std::cout << " \n vektor: \n";
	std::copy(std::begin(vektor), std::end(vektor),
				std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

	/*
	
	Aufg. 3.3

	*/
	
	std::set<int> zahlen (liste.begin(), liste.end());
	//Ausgabe Anzahl unterschiedliche Zahlen
	std::cout << "\nAnzahl unterschiedliche Zahlen: "
		<< zahlen.size() <<"\n";

	// VORSICHT UNNOETIG INEFFIZIENT //
	std::cout << "Nicht enthaltene Zahlen: \n";
	for (int i = 0; i<=100; ++i)
	{
		if (zahlen.find(i) == zahlen.end())
		{
			std::cout << i << " ";
		}
	}

	/*
	
	Aufg. 3.4
	Map ist geeignet, da hier Key+Value gespeichert werden
	Zahlen in Set sind keys, und eindeutig, da für jede zahl
	ihre Häufigkeit angegeben werden soll, welche man als
	entsprechenden value speichern kann
	*/	

	//map erstellen
	std::map<unsigned int, int> haufigkeiten;

	//Paare aus Zahl / Haufigkeit zu Map hinzufügen
	for (auto& key : zahlen)
	{	
		int counter = 0;
		for (auto& value : liste)
		{
			if(key == value)
			{
				++counter;
			}
		}
		haufigkeiten[key] = counter;
	}

	std::cout << "\nHaufigkeiten: \n";

	//map ausgeben in form key : value
	for (auto& i : haufigkeiten)
	{
		//i ist pair (first, second) mit (key, value)
		std::cout << i.first << " : " << i.second << "\n";
	}
}