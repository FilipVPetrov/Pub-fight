/*
 * Duell.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: philip
 */

#include "../include/Duell.h"

Duell::Duell(Fighter * player_1 = nullptr, Fighter * player_2 = nullptr) {
	// TODO Auto-generated constructor stub
	this->setPlayer1(player_1);
	this->setPlayer2(player_2);

}
void Duell::start() {
	if (this->getPlayer1() != nullptr && this->getPlayer2() != nullptr) {
		this->create_First();
		this->create_Second();
		this->getFirst()->join();
		this->getSecond()->join();
	}
}
void Duell::fight(int fighter) {
	Fighter * fighter_1 = this->getPlayer1();
	Fighter * fighter_2 = this->getPlayer2();
	while (fighter_1->getHealth() > 0 && fighter_2->getHealth() > 0) {

		this->lockMutex();
		if (fighter == 1){
			fighter_1->getHitted();
			std::cout << *fighter_1 << std::endl;
		}
		else if (fighter == 2){
			fighter_2->getHitted();
			std::cout << *fighter_2 << std::endl;
		}

		this->unlockMutex();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		if (fighter_1->getHealth() > 0 && fighter_2->getHealth() <= 0) {
			if (this->getFirst()->joinable() && this->getSecond()->joinable())
				std::cout << "\n" << fighter_1->getName() << " Winner!"
						<< std::endl;

			return;
		} else if (fighter_2->getHealth() > 0 && fighter_1->getHealth() <= 0) {
			if (this->getFirst()->joinable() && this->getSecond()->joinable())
				std::cout << fighter_2->getName() << " Winner!" << std::endl;

			return;
		} else if (fighter_1->getHealth() <= 0 && fighter_2->getHealth() <= 0) {
			if (this->getFirst()->joinable() && this->getSecond()->joinable())
				std::cout << "Undecided!" << std::endl;
				std::cout<< "The duell will be rematch!"<<std::endl;
				fighter_1->setHealth(100);
				fighter_2->setHealth(100);
		}
	}
}

Duell::~Duell() {
	// TODO Auto-generated destructor stub
//	delete this->getPlayer1();
//	delete this->getPlayer2();
}

