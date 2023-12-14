#include "vjezba7.h"
#include <iostream>
using namespace std;

int Food::counter;

void Food::set_counter(int a)
{
	counter = a;
}

void Food::povecaj_porcije(int a)
{
	counter += a;
}

void Food::smanji_porcije(int a)
{
	counter -= a;
}

int get_counter(Food f) {
	return f.counter;
}
