// =====================================================================================
// 
//       Filename:  References.cpp
// 
//    Description:  Implementation de la classe References
//                  Permet de visualiser l'aparition de mots clefs dans une collection
//                  de fichiers
//        Created:  15/11/2011 23:37:07
//       Compiler:  g++
// 
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
// 
// =====================================================================================



using namespace std;
#include    <iostream>
#include	<limits>
#include	<fstream>

#include    "References.hpp"

//References & References::operator = ( const References & unReferences )
//{
//}
//
//References::References ( const References & unReferences )
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <References>" << endl;
//#endif
//}
//
//
References::References ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <References>" << endl;
#endif
}
//
//
References::~References ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <References>" << endl;
#endif
}
//






//----------------------------------------------------------------------
//  METHODES PUBLIQUES
//----------------------------------------------------------------------


void References::chargerMotsClefs( const string& nomFichier ) {

	ifstream fichierMotClef;

    //----------------------------------------------------------------------
    //  Si le fichier ne peut être ouvert ou si la lecture échoue
    //  une exception sera lancé
    //----------------------------------------------------------------------
    fichierMotClef.exceptions( ifstream::failbit );
    fichierMotClef.open( nomFichier.c_str(), ios::in );
    fichierMotClef.exceptions( ifstream::badbit );

    //----------------------------------------------------------------------
    //  On extrait la liste de mot clef
    //----------------------------------------------------------------------
    string motRecupere;
    while ( fichierMotClef >> motRecupere )
    {
        _motsClefs.insert ( motRecupere );
        fichierMotClef.ignore(numeric_limits<int>::max(), '\n');
        // ignore le nombre de caractere "valeur max d'un entier" jusqu'à rencontrer \n
    }
    fichierMotClef.close( );

}

void References::chargerMotsClefs(  ) {

    _motsClefs.insert( "A Remplir" );

}


void References::ChargerIdentificateurs( const string& nomFichier ) {

	ifstream fichierIdentificateur;

    //----------------------------------------------------------------------
    //  Si le fichier ne peut être ouvert ou si la lecture échoue
    //  une exception sera lancé
    //----------------------------------------------------------------------
    fichierIdentificateur.exceptions( ifstream::failbit );
    fichierIdentificateur.open( nomFichier.c_str(), ios::in );
    fichierIdentificateur.exceptions( ifstream::badbit );

    //----------------------------------------------------------------------
    //  On extrait la liste de mot clef
    //----------------------------------------------------------------------
    string motRecupere;
    while ( fichierIdentificateur >> motRecupere )
    {
        _identificateurs.insert ( motRecupere );
        fichierIdentificateur.ignore(numeric_limits<int>::max(), '\n');
        // ignore le nombre de caractere "valeur max d'un entier" jusqu'à rencontrer \n
    }
    fichierIdentificateur.close( );

}
