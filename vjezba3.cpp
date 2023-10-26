#include "vjezba3.hpp"


void unos1(vector<int> &v, int velicina)
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