#pragma once
#include <cstring>

class Candidate
{
	char * name;
	char * party;
	int nbVotes;

public:

	Candidate(const char n[],const char p[]);
	Candidate();
	~Candidate();

	void setName(char* newName);
	void setParty(char* newParty);
	void setNbVotes(int nb);
	char* getName();
	char* getParty();
	int getNbVotes();

};
