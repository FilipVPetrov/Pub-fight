/*
 * main.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: philip
 */

#include <iostream>
#include "../include/Fighter.h"
#include <thread>
#include <vector>
#include "../include/Duell.h"
#include "../include/Pub.h"

int main() {

	/* initialize random seed: */
	srand(time(NULL));
	Pub my_pub;
	Fighter fighter_1("Wladimir Klitsko");
	Fighter fighter_2("Mike Tyson");
	Fighter fighter_3("Vitali Klitschko");
	Fighter fighter_4("Mohamed Ali");
	Fighter fighter_5("Alexander Povetkin");
	Fighter fighter_6("Tyson Fury");
	Fighter fighter_7("Kubrat Pulev");
	Fighter fighter_8("Shannon Briggs");

	my_pub.add(fighter_1);
	my_pub.add(fighter_2);
	my_pub.add(fighter_3);
	my_pub.add(fighter_4);
	my_pub.add(fighter_5);
	my_pub.add(fighter_6);
	my_pub.add(fighter_7);
	my_pub.add(fighter_8);
	my_pub.start_arena_fight();

	return 0;
}

