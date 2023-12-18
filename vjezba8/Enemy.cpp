#include "Enemy.hpp"
#include <iostream>
#include <string>
using namespace std;


Enemy::Enemy(std::string& name, int health, int damage)
{
	this->name = name;
	this->damage = damage;
	this->health = health;

	if (health < 0 || damage < 0)
	{
		throw std::invalid_argument("Error");
	}
}

void Enemy::attack() {
	cout << "Enemy napada" << endl;
}

void Enemy::displayInfo() {
	cout << "Enemy ime: " << name << ", " << "health: " << health << ", " << "damage: " << damage << endl;
}

Boss::Boss(std::string& name, int health, int damage, std::string& oruzje) :Enemy(name, health, damage)
{
	if (oruzje.empty())
	{
		throw std::invalid_argument("Mora postojati oruzje");
	}
	this->oruzje = oruzje;
}

void Boss::attack() {
	cout << "Boss napada" << endl;
}

void Boss::displayInfo() {
	cout << "Boss ime: " << name << ", " << "health: " << health << ", " << "damage: " << damage << ", " << "oruzje: " << oruzje << endl;
}


Monster::Monster(std::string& name, int health, int damage, std::string& sposobnost) :Enemy(name, health, damage) {
	if (sposobnost.empty())
	{
		throw std::invalid_argument("Mora postojati sposobnost");
	}
	this->sposobnosti = sposobnost;
}

void Monster::attack() {
	cout << "Monster napada" << endl;
}

void Monster::displayInfo() {
	cout << "Monster ime: " << name << ", " << "health: " << health << ", " << "damage: " << damage << ", " << "sposobnost: " << sposobnosti << endl;
}
