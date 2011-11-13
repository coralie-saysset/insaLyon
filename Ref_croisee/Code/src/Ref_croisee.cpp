//============================================================================
// Name        : Ref_croisee.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>

#include "CmdLine/cmdLine.hpp"
#include "lecture.h"

using namespace std;

int main( int argc, char** argv) {


	lecture fic;
	string monFichier;
	monFichier = "/home/csaysset/Documents/Ref_croisee/identificateur";
	set<string> testMot =  fic.litIdentificateur ( monFichier );
	set<string>::iterator it;
	for (it = testMot.begin(); it != testMot.end(); it++ )
	{
		cout<< *it<< endl;
	}



	//cout << parser << endl;
	return 0;
}
