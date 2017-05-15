#include <cstdlib> // std::rand()
#include <vector> // std::vector<>
#include <list> // std::list<>
#include <iostream> // std::cout
#include <iterator> // std::ostream_iterator<>
#include <algorithm> // std::reverse, std::generate
#include <string>

int main ()
{

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
	std::copy(std::begin(liste), std::end(liste),
				std::ostream_iterator<int>(std::cout, " "));

	//vector erzeugen, elemente aus liste kopieren
	std::vector<unsigned int> vektor (std::begin(liste), std::end(liste));

	//Ausgabe vektor
	std::cout << " \n vektor: \n";
	std::copy(std::begin(vektor), std::end(vektor),
				std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";

}