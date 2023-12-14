#include <iostream>
#include <vector>
#include <string>
#include "Enemy.hpp"
using namespace std;

int main()
{
	vector<Enemy*> neprijatelji;

	try
	{
		string ime = "Martin";
		string ime2 = "Ivan";
		string oruzje = "";
		string sposobnost = "Fire ball";
		neprijatelji.push_back(new Boss(ime, 100, 50, oruzje));
		neprijatelji.push_back(new Monster(ime2, 70, 20, sposobnost));

	}
	catch (const std::invalid_argument err)
	{
		cout << "Error"<<err.what();
	}
}
