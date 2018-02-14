/**
	Candidate.cpp
	Purpose: Object Candidate with name, party and number of votes
	@author Killian Bradechard C00223822
	@version 01/24/2018
**/
#include "Candidate.h"
#include <iostream>


/**
	Constructor Candidate which you can choose its name and party 
	and set the votes at 0
	@param n the name of the candidate "const char*"
	@param p the party of the candidate "const char*"
*/
Candidate::Candidate(const char n[], const char p[])
{
	int numofCharactersName = strlen(n) + 1;
	name = new char[numofCharactersName];
	strncpy_s(name, numofCharactersName, n, numofCharactersName);

	int numofCharactersParty = strlen(p) + 1;
	party = new char[numofCharactersParty];
	strncpy_s(party, numofCharactersParty, p, numofCharactersParty);

	nbVotes=0;
}

/**
	Constructor Candidate without name and party and set the votes at 0
*/
Candidate::Candidate()
{
	name = new char;
	party = new char;
	nbVotes=0;
}

/**
	Destructor Candidate
*/
Candidate::~Candidate()
{
	if (name)
		delete[] name;
	if (party)
		delete[] party;
}

/**
	Setter which you can choose the name of the candidate
	@param newName the new name of the candidate "char*"
*/
void Candidate::setName(char* newName)
{
	int numofCharactersName = strlen(newName) + 1;
	name = new char[numofCharactersName];
	strncpy_s(name, numofCharactersName, newName, numofCharactersName);
}

/**
	Setter which you can choose the party of the candidate
	@param newParty the new party of the candidate
*/
void Candidate::setParty(char* newParty)
{
	int numofCharactersParty = strlen(newParty) + 1;
	party = new char[numofCharactersParty];
	strncpy_s(party, numofCharactersParty, newParty, numofCharactersParty);
}

/**
	Setter which you can choose the number of votes of the candidate
	@param nb the number of votes
*/
void Candidate::setNbVotes(int nb)
{
	nbVotes=nb;
}

/**
	Getter which you can access at the name of the candidate
	@return char* the name
*/
char* Candidate::getName()
{
	return name;
}

/**
	Getter which you can access at the party of the candidate
	@return char* the party
*/
char* Candidate::getParty()
{
	return party;
}

/**
	Getter which you can access at the the number of votes of the candidate
	@return int the number of the votes
*/
int Candidate::getNbVotes()
{
	return nbVotes;
}