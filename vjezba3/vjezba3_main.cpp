#include "vjezba3.hpp"
#include <vector>
#include<iostream>
using namespace std;


int main()
{
	vector<int> nesto;
	vector<int> prvi;
	vector<int> drugi;
	vector<int> rezultat;
	vector<int> zad3;
	vector<int> zad4;

	//unos1(nesto, 5);
	//ispis(nesto);
	//nesto.clear();
	//unos2(nesto, 2, 14);
	//ispis(nesto);

	//unos1(prvi, 7);
	//ispis(prvi);
	//unos1(drugi, 5);
	//ispis(drugi);
	//rezultat = drugizad(prvi, drugi);
	//cout << "Novi vektor:" << endl;
	//ispis(rezultat);

	//unos1(zad3, 5);
	//zadatak3(zad3);
	//cout << "Novi vektor: " << endl;
	//ispis(zad3);

	unos1(zad4, 7);
	cout << "Orginalni vektor:" << endl;
	ispis(zad4);
	zadatak4(zad4, 4);
	cout << "Novi vektor" << endl;
	ispis(zad4);

}
