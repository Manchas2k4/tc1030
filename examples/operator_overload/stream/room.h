/*************************************************************
* File: room.h
* Author: Pedro Perez
* Description: This file contains the definition of
*              Room class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef ROOM_H
#define ROOM_H

#include "enemy.h"
#include "hero.h"

class Room {
private:
	Enemy* enemy;

public:
	Room();
	Room(int);
	Room(const Room&);

	bool passEncounter(Hero*);
};

#endif
