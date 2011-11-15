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
#include "References/References.hpp"

using namespace std;

int main( int argc, char** argv) {


	References fic;
	string monFichier;
	monFichier = "motClef";
	fic.chargerMotsClefs ( monFichier );


	//cout << parser << endl;
	return 0;
}
