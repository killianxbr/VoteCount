/**
	VoteCounter.cpp
	Purpose: Object VoteCounter where the votes are counted
	@author Killian Bradechard C00223822
	@version 01/24/2018
**/
#include "VoteCounter.h"
#include <iostream>
using namespace std;


/**
	Constructor VoteCounter which you can choose its number of candidate
	@param nbCandidate the number of candidate
*/
VoteCounter::VoteCounter(int nbCandidate)
{
	nbTotalCandidate= nbCandidate;
}

/**
	Destructor VoteCounter
*/
VoteCounter::~VoteCounter(){}

/**
	Methods which permits to add a new vote to the vote counter
	@param bp the BallotPaper that you want to add "BallotPaper*"
*/
void VoteCounter::newVote(BallotPaper* bp)
{
	bpList.push_back(bp);
	for (int i = 0; i< nbTotalCandidate; i++)
	{
		Candidate* cTemp = bp->getPreference(i+1);
		if (cTemp != nullptr)
		{
			//if results doesn't contain Candidate
			if (!(std::find(results.begin(), results.end(), cTemp) != results.end()))
			{
				results.push_back(cTemp);
			}
		}
	}
}

/**
	Methods which permits to start one election and determine the winner
	@return Candidate* the winner of the election
*/
Candidate* VoteCounter::startElection()
{
	int left= nbTotalCandidate;
	Candidate* winner= new Candidate();
	while (left != 1)
	{
		cout << "========= ROUND NUMBER " << left << " =========\n";
		winner = round();
		left--;
	}
	return winner;
}

/**
	Methods which permits to start one round into the election 
	Determine the round winner and eliminate the round loser
	@return Candidate* the round winner
*/
Candidate* VoteCounter::round()
{
	countAllVotes();

	int max= 0;
	Candidate* winnerRound= nullptr;
	int min= nbTotalCandidate;
	Candidate* loserRound = nullptr;
	vector<Candidate*> listLoserRound;

	// Find the winner and loser(s)
	for (int i = 0; i< results.size(); i++)
	{
		int nbVotesTemp = results[i]->getNbVotes();
		if (nbVotesTemp != -1)
		{
			cout << "Candidate " << results[i]->getName() << " has " << nbVotesTemp << " vote(s)\n";
			if (nbVotesTemp > max)
			{
				max = nbVotesTemp;
				winnerRound = results[i];
			}

			if (nbVotesTemp < min)
			{
				listLoserRound.clear();
				min = nbVotesTemp;
			}

			if (nbVotesTemp == min)
			{
				loserRound = results[i];
				listLoserRound.push_back(loserRound);
			}
		}
	}
	//Random loser
	if (listLoserRound.size() > 1)
	{
		srand(time(NULL));
		int random = rand();
		int ind = random % listLoserRound.size();
		loserRound = listLoserRound[ind];
		//Random winner if the last candidates have the same number of votes
		if (std::find(listLoserRound.begin(), listLoserRound.end(), winnerRound) != listLoserRound.end() 
			&& listLoserRound.size() == 2)
		{
			random = rand();
			ind = random % listLoserRound.size();
			loserRound = listLoserRound[ind];
			listLoserRound.erase(std::find(listLoserRound.begin(), listLoserRound.end(), loserRound));
			winnerRound = listLoserRound[0];
		}
	}

	cout << "========= RESULTS ROUND  =========\n" ;
	cout << "Winner Round ==> " << winnerRound->getName() << "\n";
	cout << "Loser Round  ==> " << loserRound->getName() << "\n\n";
	resetAllVotesExcept(loserRound);

	//Eliminate the worst candidate
	for (int i = 0; i< bpList.size(); i++)
	{
		bpList[i]->eliminate(loserRound);
	}

	return winnerRound;
}

/**
	Methods which permits to count all the votes with preference 1 per candidate
*/
void VoteCounter::countAllVotes()
{
	for (int i = 0; i< bpList.size(); i++)
	{
		BallotPaper* bpTemp = bpList[i];
		int pref = 1;
		while (pref <= nbTotalCandidate)
		{
			Candidate* cTemp = bpTemp->getPreference(pref);
			if (cTemp != nullptr)
			{
				cTemp->setNbVotes((cTemp->getNbVotes()) + 1);
				break;
			}
			pref++;
		}
	}
}

/**
	Methods which permits to reset all the votes
*/
void VoteCounter::resetAllVotesExcept(Candidate* c)
{
	c->setNbVotes(-1);
	for (int i = 0; i< results.size(); i++)
	{
		if (results[i]->getNbVotes() != -1)
		{
			results[i]->setNbVotes(0);
		}
	}
}