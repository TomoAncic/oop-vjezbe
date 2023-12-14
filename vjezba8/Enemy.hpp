#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
using namespace std;

class Enemy {
protected:
	string name;
	int health;
	int damage;

public:
	Enemy(string& name, int health, int damage);

	void attack();
	void displayInfo();
};

class Boss : public Enemy {
private:
	string oruzje;
public:
	Boss(string& name, int health, int damage, string& oruzje);
	
	void attack();

	void displayInfo();

};

class Monster :public Enemy {
private:
	string sposobnosti;
public:
	Monster(string& name, int health, int damage, string& sposobnost);

	void attack();

	void displayInfo();

};
#endif

