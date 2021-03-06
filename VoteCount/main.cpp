/**
	main.cpp
	Purpose: Vote count controller in election simulation 
	@author Killian Bradechard C00223822
	@version 01/24/2018
**/
#include "VoteCounter.h"
#include <stdlib.h> 
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	int nbCandidate=5;
	Candidate** arrCand= new Candidate* [nbCandidate];
	arrCand[0] = new Candidate("A", "p1"); //Cand 1
	arrCand[1] = new Candidate("B", "p2"); // Cand 2
	arrCand[2] = new Candidate("C", "p2"); // Cand 3
	arrCand[3] = new Candidate("D", "p1"); // Cand 4
	arrCand[4] = new Candidate("E", "p2"); //Cand 5

	vector<BallotPaper*> listBallot;

	// Text file where the candidate number is placed on the ascending preference
	// candidate preference1;cand pref2; cand pref3; cand pref4; cand pref5
	ifstream file("votes.txt", ios::in);
	char ballot[50];

	if (file)  // open file if it is correct
	{
		while (file >> ballot)
		{
			int i=0;
			int nbRef = 1;
			char c= ballot[i];
			char convert[10]="";
			BallotPaper* bp = new BallotPaper(nbCandidate);

			// Read the line char by char
			while (c != '\0' && nbRef < nbCandidate+1)
			{
				if (c != ';')
				{
					snprintf(convert, sizeof convert, "%s%c", convert, c);
				}
				else
				{
					// Insert the candidate "num-1" into the reference "nbRef"
					int num = atoi(convert);
					if (num - 1 < nbCandidate)
					{
						bp->setPreference(nbRef, arrCand[num - 1]);
					}
					nbRef++;
					strcpy_s(convert,sizeof(convert),"");
				}
				c = ballot[++i];
			}

			if (nbRef != nbCandidate+1)
			{
				// Insert the candidate "num-1" into the reference "nbRef"
				int num = atoi(convert);
				if (num - 1 < nbCandidate)
				{
					bp->setPreference(nbRef, arrCand[num - 1]);
				}
				nbRef++;
				listBallot.push_back(bp);
			}
		}
		file.close();
	}
	else
		cerr << "Error" << endl;

	// Insert every BallotPaper into the VoteCounter
	VoteCounter* vc = new VoteCounter(nbCandidate);
	for (int i = 0; i < listBallot.size(); i++)
	{
		vc->newVote(listBallot[i]);
	}

	// Winner is define by the election
	Candidate* winner = vc->startElection();
	cout << "The winner is " << winner->getName() << " and it's in the party " << winner->getParty() << " !!!!\n";
	system("pause");
    return 0;
}