#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
using namespace std;

class Enemy {
protected:
	std::string name;
	int health;
	int damage;

public:
	Enemy(std::string& name, int health, int damage);

	virtual void attack();
	virtual void displayInfo();
};

class Boss : public Enemy {
private:
	std::string oruzje;
public:
	Boss(std::string& name, int health, int damage, std::string& oruzje);

	void attack() override;

	void displayInfo() override;

};

class Monster :public Enemy {
private:
	std::string sposobnosti;
public:
	Monster(std::string& name, int health, int damage, std::string& sposobnost);

	void attack() override;

	void displayInfo() override;

};
#endif
