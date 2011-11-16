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

    _motsClefs.insert( "asm" );
    _motsClefs.insert( "auto" );
    _motsClefs.insert( "break" );
    _motsClefs.insert( "bool" );
    _motsClefs.insert( "case" );
    _motsClefs.insert( "catch" );
    _motsClefs.insert( "char" );
    _motsClefs.insert( "class" );
    _motsClefs.insert( "const" );
    _motsClefs.insert( "continue" );
    _motsClefs.insert( "default" );
    _motsClefs.insert( "delete" );
    _motsClefs.insert( "do" );
    _motsClefs.insert( "double" );
    _motsClefs.insert( "else" );
    _motsClefs.insert( "enum" );
    _motsClefs.insert( "extern" );
    _motsClefs.insert( "explicit" );
    _motsClefs.insert( "false" );
    _motsClefs.insert( "float" );
    _motsClefs.insert( "for" );
    _motsClefs.insert( "friend" );
    _motsClefs.insert( "goto" );
    _motsClefs.insert( "if" );
    _motsClefs.insert( "inline" );
    _motsClefs.insert( "int" );
    _motsClefs.insert( "long" );
    _motsClefs.insert( "mutable" );
    _motsClefs.insert( "new" );
    _motsClefs.insert( "operator" );
    _motsClefs.insert( "private" );
    _motsClefs.insert( "protected" );
    _motsClefs.insert( "public" );
    _motsClefs.insert( "register" );
    _motsClefs.insert( "return" );
    _motsClefs.insert( "short" );
    _motsClefs.insert( "signed" );
    _motsClefs.insert( "sizeof" );
    _motsClefs.insert( "static" );
    _motsClefs.insert( "struct" );
    _motsClefs.insert( "switch" );
    _motsClefs.insert( "template" );
    _motsClefs.insert( "this" );
    _motsClefs.insert( "throw" );
    _motsClefs.insert( "try" );
    _motsClefs.insert( "true" );
    _motsClefs.insert( "typedef" );
    _motsClefs.insert( "unsigned" );
    _motsClefs.insert( "union" );
    _motsClefs.insert( "virtual" );
    _motsClefs.insert( "void" );
    _motsClefs.insert( "volatile" );
    _motsClefs.insert( "while" );


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
