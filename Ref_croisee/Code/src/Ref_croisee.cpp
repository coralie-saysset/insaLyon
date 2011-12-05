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

    CmdLine::Arguments args;
    {
        CmdLine::Parser parser( "Permet de référencer des mots clefs à travers des fichiers\n\t" + string(argv[0]) + " [options] fichier+" );
        parser.AddOption( "help,h",  "Affiche ce message" );
        parser.AddOption( "exclude,e",  "Inverse le fonctionnement du programme" );
        parser.AddOption( "keyword,k",  "Spécifie la liste des mots clefs à utiliser", true );

        try {
            parser.Parse( argc, argv, args );

        } catch( exception& e ) {
            cout << e.what() << endl;
            cout << parser << endl;
            return 1;
        }

        if( !args.Count( "__args__" ) || args.Count( "help" ) ) {

            cout << parser << endl;
            return 1;
        }
    }

    //----------------------------------------------------------------------
    //  On charge les fichiers à référencer
    //----------------------------------------------------------------------
    vector<string> ficsReferencer;
    ficsReferencer = args.Get<vector<string> >( "__args__" );

    //----------------------------------------------------------------------
    //  On charge les mots clefs si ils sont fournis
    //----------------------------------------------------------------------
    string fichierMotClef;

    if( args.Count( "keyword" ) ) {
        fichierMotClef = args.Get<string>( "keyword" );
    }

    //----------------------------------------------------------------------
    //  L'etat dans lequel mettre le programme
    //----------------------------------------------------------------------
    bool mode( args.Count( "exclude" ) );


    //----------------------------------------------------------------------
    //  On effectue la référence croisée
    //----------------------------------------------------------------------
    References refs;
    try {
        Referenceur referenceur( fichierMotClef, mode );
        referenceur.Referencer( ficsReferencer, refs );

    } catch( exception& e ) {
        cerr << "Une erreur est survenue durant la référance croisée : " << endl;
        cerr << e.what() << endl;
    }


    //----------------------------------------------------------------------
    //  On affiche les résultats
    //----------------------------------------------------------------------
    cout << refs; 

    return 0;
}/*}}}*/
