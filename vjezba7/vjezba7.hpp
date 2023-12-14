#ifndef VJEZBA7_H
#define VJEZBA7_h

class Food {
private:
	static int counter;

public:
	void set_counter(int a);
	void povecaj_porcije(int a);
	void smanji_porcije(int a);
	friend int get_counter(Food);
};
#endif
