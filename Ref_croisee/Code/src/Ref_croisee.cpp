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
        CmdLine::Parser parser( "Permet de référencer des mots clefs à travers des fichiers" );
        parser.AddOption( "exclude,e",  "Inverse le fonctionnement du programme" );
        parser.AddOption( "keyword,k",  "Spécifie la liste des mots clefs à utiliser", true );

        try {
            parser.Parse( argc, argv, args );

        } catch( exception& e ) {
            cout << "Une erreur c'est produit durant la récupération de la ligne de commande : " << endl;
            cout << e.what() << endl;
        }
    }
    //----------------------------------------------------------------------
    //  On charge les fichiers à référencer
    //----------------------------------------------------------------------
    vector<string> ficsReferencer;

    if( args.Count( "__args__" ) ) {
        ficsReferencer = args.Get<vector<string> >( "__args__" );

    } else {
        cerr << "Aucun fichier à reférencer !" << endl;
        return 1;
    }

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


    References refs;
    //----------------------------------------------------------------------
    //  On effectue la référence croisée
    //----------------------------------------------------------------------
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
