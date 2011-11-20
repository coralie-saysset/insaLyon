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
    CmdLine::Parser parser( "Permet de référencer des mots clefs à travers des fichiers" );
    parser.addOption( "exclude,e",  "Inverse le fonctionnement du programme" );
    parser.addOption( "keyword,k",  "Spécifie la liste des mots clefs à utiliser", true );

    try {
        parser.parse( argc, argv, args );

    } catch( exception& e ) {
        cout << "Une erreur c'est produit durant la récupération de la ligne de commande : " << endl;
        cout << e.what() << endl;
    }

    //----------------------------------------------------------------------
    //  On charge les fichiers à référencer
    //----------------------------------------------------------------------
    vector<string> ficsReferencer;

    if( args.count( "__args__" ) ) {
        ficsReferencer = args.get<vector<string> >( "__args__" );

    } else {
        cerr << "Aucun fichier à reférencer !" << endl;
        return 1;
    }

    //----------------------------------------------------------------------
    //  On charge les mots clefs si ils sont fournis
    //----------------------------------------------------------------------
    string fichierMotClef;

    if( args.count( "keyword" ) ) {
        fichierMotClef = args.get<string>( "keyword" );
    }

    //----------------------------------------------------------------------
    //  L'etat dans lequel mettre le programme
    //----------------------------------------------------------------------
    bool mode( args.count( "exclude" ) );


    References refs;

    //----------------------------------------------------------------------
    //  On effectue la référence croisée
    //----------------------------------------------------------------------
    try {
        Referenceur referenceur( fichierMotClef, mode );
        referenceur.referencer( ficsReferencer, refs );

    } catch( exception& e ) {
        cerr << "Une erreur est survenue durant la référance croisée : " << endl;
        cerr << e.what() << endl;
    }


    //----------------------------------------------------------------------
    //  On affiche les résultats
    //----------------------------------------------------------------------
    refs.display( cout );

    return 0;
}/*}}}*/
