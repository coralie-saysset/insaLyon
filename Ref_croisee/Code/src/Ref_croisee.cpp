//============================================================================
// Name        : Ref_croisee.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "CmdLine/cmdLine.hpp"
#include "References/Referenceur.hpp"
#include "References/References.hpp"

using namespace std;
using namespace Reference_croisee;

int main( int argc, char** argv )
{/*{{{*/

    CmdLine::Argument args;
    CmdLine::Parser parser( "Permet de référencer des mots clefs à travers des fichiers" );
    parser.addOption( "exclude,e",  "Inverse le fonctionnement du programme" );
    parser.addOption( "keyword,k",  "Spécifie la liste des mots clefs à utiliser", true );

    parser.parse( argc, argv, args );

    vector<string> fics = args.get<vector<string> >( "__args__" );

    References refs;
    Referenceur referenceur;

    referenceur.referencer( fics, refs );

    refs.display( cout );


    return 0;
}/*}}}*/
