#include "Enemy.hpp"
#include <iostream>
#include <string>
using namespace std;


Enemy::Enemy(string& name, int health, int damage)
{
	this->name = name;
	this->damage = damage;
	this->health = health;

	if (health < 0 || damage < 0)
	{
		throw std::invalid_argument("Error");
	}
}

Boss::Boss(string& name, int health, int damage, string& oruzje) :Enemy(name, health, damage)
{
	if (oruzje.empty())
	{
		throw std::invalid_argument("Mora postojati oruzje");
	}
	this->oruzje = oruzje;
}

void attack() {
	cout << "Boss napada sa oruzjem " << endl;
}

void displayInfo() {
	cout << "Boss ime: " << name << ", " << "health: " << health << ", " << "damage: " << damage << ", " << "oruzje: " << oruzje << endl;
}


Monster(string& name, int health, int damage, string& sposobnost) :Enemy(name, health, damage)
{
	if (sposobnosti.empty())
	{
		throw std::invalid_argument("Mora postojati sposobnost");
	}
	this->sposobnosti = sposobnost;
}

void attack() {
	cout << "Monster napada" << endl;
}

void displayInfo() {
	cout << "Monster ime: " << name << ", " << "health: " << health << ", " << "damage: " << damage << ", " << "sposobnost: " << sposobnosti << endl;
}
