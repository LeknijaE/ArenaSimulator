#pragma once
#include <vector>
#include <string>
#include "Rounds.h"
using namespace std;


class Player
{
private:
	
	int p_Health, p_Damage, p_Xp, p_Energy;
	std::string p_name;

public:
	
	Player();
	Player(string name, int p_hp, int p_dmg, int p_xp, int p_Enr);
	
	// Status Check
	bool playerAlive();
	bool defeatEnemy();
	bool playerDefeat();

	// Player Choice
	char atkChoice();

	// Getters
	int getHealth();
	int getAtk();
	int getEnergy();
	int gainEnergy();
	int takeDamage();
	int buffDamage();

	

	// Destructor
	~Player();


};

