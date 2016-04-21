// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);
void Show_Sex(Slav*, int);

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);
	Show_Sex(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	vectorOfSlavs.push_back(slavs);
	for(int i=1 ; i<n ; i++)
	{
		vectorOfSlavs.insert(vectorOfSlavs.begin() + rand()%vectorOfSlavs.size(), &slavs[i]);
	}

	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	vector <Slav *>::iterator itr;
	for( itr = vectorOfSlavs.begin();itr != vectorOfSlavs.end(); itr++)
	{
		cout << (*itr) -> description() << endl;
	}
	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for(int i = n-1; i>=0 ; i--)
	{
		setOfSlavs.insert(vectorOfSlavs[i]);
		vectorOfSlavs.pop_back();
	}

	
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	set< Slav* >::iterator itr_s = setOfSlavs.begin();
	set< Slav* >::iterator itr_removal_s = setOfSlavs.begin();
	while(itr_s != setOfSlavs.end())
	{
		while(itr_s !=setOfSlavs.end())
		{
			mapOfSlavs[*itr_s++] = *itr_s++;
			setOfSlavs.erase(itr_removal_s++);
			setOfSlavs.erase(itr_removal_s++);
		}
	}
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	map <Slav *, Slav*>::iterator itr_m = mapOfSlavs.begin();

	while(itr_m != mapOfSlavs.end())
	{
		cout << (itr_m -> first) -> description() << " -> " <<(itr_m -> second) -> description() << endl;
		itr_m++;
	}

	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	for(int i = 0 ; i < n; i++)
	{
		queueOfSlavs.push(&slavs[i]);
	}
	
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.

	while(queueOfSlavs.empty() == 0)
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	}

	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.

	while(stackOfSlavs.empty() == 0)
	{
		cout << stackOfSlavs.top() -> description() << endl;
		stackOfSlavs.pop();
	}

	REPORT_ADAPTERS;
}
void Show_Sex(Slav *slavs, int n)
{
	map < gender, vector< Slav* > > mapOfGender;
	for(int i = 0; i<n ; i++)
	{
		(slavs[i].Sex()== man ) ? mapOfGender[man].push_back(slavs+i) : mapOfGender[woman].push_back(slavs+i);
	}
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
