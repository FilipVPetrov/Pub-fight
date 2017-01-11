/*
 * Fighter.h
 *
 *  Created on: Nov 5, 2015
 *      Author: philip
 */

#ifndef FIGHTER_H_
#define FIGHTER_H_

#include <iostream>
#include <cstdlib>
#include <ctime>

class Fighter {
private:
	int m_health;
	std::string m_name;
public:
	Fighter() {
		this->setHealth(0);
	}
	Fighter(std::string name,int health = 100) {
		this->setHealth(health);
		this->setName(name);
	}

	virtual ~Fighter() {
		this->setHealth(0);
		this->setName("");
	}

	int getHealth() const {
		return m_health;
	}

	void setHealth(int health) {
		this->m_health = health;
	}

	const std::string& getName() const {
		return m_name;
	}

	void setName(const std::string& name) {
		this->m_name = name;
	}
	void getHitted() {
		/* generate secret number between 1 and 20: */
		int damage = rand() % 20 + 1;
		int health = this->getHealth();
		int live = health - damage;
		if (live > 0) {
			this->setHealth(live);
		} else {
			this->setHealth(0);
		}
	}

	friend std::ostream& operator<< (std::ostream& out, Fighter& temp_fighter){
		out<<"Fighter ("<<temp_fighter.getName()<<", "<<temp_fighter.getHealth()<<")";
		return out;
	}
};

#endif /* FIGHTER_H_ */
