#include <iostream>
#include "vjezba7.hpp"
using namespace std;

int main()
{
	Food food;
	food.set_counter(10);
	cout << "Trenutno stanje porcija: " << get_counter(food) << endl;

	food.povecaj_porcije(2);
	cout << "Nakon povecana porcija stanje je: " << get_counter(food) << endl;

	food.smanji_porcije(4);
	cout << "Nakon smanjenja porcija stanje je: " << get_counter(food) << endl;
}
