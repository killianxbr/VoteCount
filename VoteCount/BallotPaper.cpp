/**
	BallotPaper.cpp
	Purpose: Object BallotPaper where the candidates are classed by preference
	@author Killian Bradechard C00223822
	@version 01/24/2018
**/
#include "BallotPaper.h"


/**
	Constructor BallotPaper which you can choose its number of candidate
	@param nbCandidate the number of candidate
*/
BallotPaper::BallotPaper(int nbCandidate)
{
	allCandidates = new Candidate* [nbCandidate];
	for (int i = 0; i < nbCandidate; i++)
	{
		allCandidates[i]=nullptr;
	}
	nbTotalCandidate = nbCandidate;
}

/**
	Destructor BallotPaper
*/
BallotPaper::~BallotPaper()
{
	if(allCandidates)
		delete[] allCandidates;
}

/**
	Methods which permits to set a preference to a candidate
	@param nth the preference "int"
	@param c the candidate "Candidate*"
*/
void BallotPaper::setPreference(int nth, Candidate* c)
{
	if (nth <= nbTotalCandidate)
	{
		eliminate(c);
		allCandidates[nth - 1] = c;
	}
}

/**
	Methods which permits to get the position/preference of a candidate
	@param c the candidate "Candidate*"
	@return int the preference
*/
int BallotPaper::getPosCandidate(Candidate* c)
{
	int pos = -1;
	for (int i = 0; i < nbTotalCandidate; i++)
	{
		if (allCandidates[i] == c)
		{
			pos = i;
		}
	}
	return pos;
}

/**
	Methods which permits to get the candidate in term of preference
	@param nth the preference "int"
	@return Candidate* the candidate
*/
Candidate* BallotPaper::getPreference(int nth)
{
	return allCandidates[nth-1];
}

/**
	Methods which permits to eliminate a candidate
	@param c the candidate "Candidate*"
*/
void BallotPaper::eliminate(Candidate* c)
{
	int pos= getPosCandidate(c);
	if (pos != -1)
	{
		//Left Shifted Array
		for (int i = pos; i< nbTotalCandidate - 1; i++)
		{
			allCandidates[i] = allCandidates[i + 1];
			allCandidates[nbTotalCandidate - 1] = nullptr;
		}
	}
}