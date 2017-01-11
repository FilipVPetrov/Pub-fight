/*
 * Pub.h
 *
 *  Created on: Nov 7, 2015
 *      Author: philip
 */

#ifndef PUB_H_
#define PUB_H_
#include <vector>
#include <list>
#include <cstdlib>
#include "Duell.h"

class Pub {
private:
	std::vector<Fighter> m_pub_list;
	std::vector<Duell*> m_duell_list;

public:
	Pub();
	virtual ~Pub();

	std::vector<Fighter>& getPubList() {
		return m_pub_list;
	}

	std::vector<Duell*>& getDuellList() {
		return m_duell_list;
	}

	void add(Fighter temp_fighter) {
		this->getPubList().push_back(temp_fighter);
	}
	void start_arena_fight() {
		int round(1);
		while (this->getPubList().size() > 1) {
			std::cout<<"\nRound "<<round++<<" is started!\n"<<std::endl;
			this->makePairs();
			unsigned size = this->getDuellList().size();
			for (int i = 0; i < size; i++) {
				this->getDuellList()[i]->start();
			}
			this->clear_for_next_round();
			this->refresh_fighters();
		}
	}

	//to heal the winner- preparing them for next round
	void refresh_fighters(){
		std::vector<Fighter>::iterator it = this->getPubList().begin();
		while(it != this->getPubList().end()){
			it->setHealth(100);
			it++;
		}
	}
	void makePairs() {
		bool * arranged = new bool[this->getPubList().size()];
		for (unsigned i = 0; i < this->getPubList().size(); i++) {
			if (arranged[i] == true)
				continue;
			int random;
			do {
				random = rand() % (this->getPubList().size());
			} while (random == i || arranged[random] == true);
			arranged[i] = true;
			arranged[random] = true;
			Fighter * figter_1 = &this->getPubList().at(i);
			Fighter * figter_2 = &this->getPubList().at(random);
			this->getDuellList().push_back(new Duell(figter_1, figter_2));
		}
		//we don`t need this more
		delete arranged;
	}
	void clear_for_next_round() {
		std::vector<Fighter>::iterator it = this->getPubList().begin();
		while (it != this->getPubList().end()) {
			if (it->getHealth() <= 0) {
				this->getPubList().erase(it);
				it--;
			}
			it++;
		}
	}

};

#endif /* PUB_H_ */
