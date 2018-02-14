#pragma once
#include "BallotPaper.h"
#include <map>
#include <vector>
#include <time.h>

class VoteCounter
{
	int nbTotalCandidate;
	std::vector<Candidate*> results;
	std::vector<BallotPaper*> bpList;

public:

	VoteCounter(int nbCandidate);
	~VoteCounter();

	void newVote(BallotPaper* bp);
	Candidate* startElection();
	Candidate* round();
	void resetAllVotesExcept(Candidate* c);
	void countAllVotes();
};