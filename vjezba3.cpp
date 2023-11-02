#include "vjezba3.hpp"
#include <algorithm>

void unos1(vector<int>& v, int velicina)
{
	for (int i = 0; i < velicina; i++)
	{
		int a;
		cout << "Unesite elemente: ";
		cin >> a;
		v.push_back(a);
	}
}

void unos2(vector<int>& v, int d, int g)
{
	while (true)
	{
		int a;
		cout << "Unesi broj izmedu intervala " << d << " i " << g << " ";
		cin >> a;
		if (a<d || a>g)
		{
			cout << "Broj nije unutar intervala\n";
			break;
		}
		else
			v.push_back(a);
	}
}

void ispis(vector<int>& v)
{
	cout << "Vektor: ";
	for (int a : v)
	{
		cout << a << " ";
	}
	cout << endl;
}

vector<int> drugizad(vector<int>& prvi, vector<int>& drugi)
{
	vector<int> rezultat;
	for (int a : prvi)
	{
		if (find(drugi.begin(), drugi.end(), a) == drugi.end())
		{
			rezultat.push_back(a);
		}
	}
	return rezultat;
}

void zadatak3(vector<int>& zad3)
{
	sort(zad3.begin(), zad3.end());
	int min = zad3[0];
	zad3.insert(find(zad3.begin(), zad3.end(), min), 0);

	int max = *max_element(zad3.begin(), zad3.end());
	int sum = 0;
	for (int a : zad3)
	{
		sum += a;
	}
	zad3.push_back(sum);
}

void zadatak4(vector<int>& v, int element)
{
	v.erase(remove(v.begin(), v.end(), element), v.end());
}
