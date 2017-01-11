/*
 * Duell.h
 *
 *  Created on: Nov 7, 2015
 *      Author: philip
 */

#ifndef DUELL_H_
#define DUELL_H_

#include "Fighter.h"
#include <mutex>
#include <thread>
class Duell {
private:
	Fighter * m_player_1;
	Fighter * m_player_2;
	std::mutex m_the_mutex;
	std::thread * m_first;
	std::thread * m_second;


public:
	Duell(Fighter * player_1 ,	Fighter * player_2);
	virtual ~Duell();

	void lockMutex(){
		this->getTheMutex().lock();
	}
	void unlockMutex(){
		this->getTheMutex().unlock();
	}

	void fight(int fighter);
	void start();
	void create_First(){
		m_first = new std::thread(&Duell::fight, this, 1);
	}

	void create_Second(){
		m_second = new std::thread(&Duell::fight, this, 2);
	}

	 Fighter*& getPlayer1() {
		return m_player_1;
	}

	void setPlayer1(Fighter* player1) {
		m_player_1 = player1;
	}

	Fighter*& getPlayer2() {
		return m_player_2;
	}

	void setPlayer2(Fighter* player2) {
		m_player_2 = player2;
	}

	std::mutex& getTheMutex(){
		return m_the_mutex;
	}

	std::thread*& getFirst() {
		return m_first;
	}

	std::thread*& getSecond()  {
		return m_second;
	}

};

#endif /* DUELL_H_ */
