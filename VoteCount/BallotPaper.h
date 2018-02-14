#pragma once
#include "Candidate.h"

class BallotPaper
{
	Candidate** allCandidates;
	int nbTotalCandidate;

public:

	BallotPaper(int nbCandidate);
	~BallotPaper();

	int getPosCandidate(Candidate* c);
	void setPreference(int nth, Candidate* c);
	Candidate* getPreference(int nth);
	void eliminate(Candidate* c);
};