// =====================================================================================
//
//       Filename:  Referenceur.cpp
//
//    Description:  Implementation de la classe Referenceur
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
#include    <limits>
#include    <fstream>

#include    "Referenceur.hpp"

namespace Reference_croisee {

using namespace Reference_croisee;



//----------------------------------------------------------------------
//  CONSTRUCTEURS
//----------------------------------------------------------------------
Referenceur::Referenceur ( const string fichierMotClef, const bool modeInverse ):
    _mode( modeInverse ? Inverse : Normal ), _etat( Separateur )
{/*{{{*/

#ifdef MAP
    cout << "Appel au constructeur de <Referenceur>" << endl;
#endif

    chargerMotsClefsCpp();

    if( !fichierMotClef.empty() ) {
        chargerMotsClefs( fichierMotClef );
    }

}/*}}}*/

//----------------------------------------------------------------------
//  METHODES PUBLIQUES
//----------------------------------------------------------------------
void Referenceur::chargerMotsClefs( const string& nomFichier )
{/*{{{*/


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
    _motsClefs.clear();
    string motRecupere;

    while ( fichierMotClef >> motRecupere ) {
        _motsClefs.insert( motRecupere );
        fichierMotClef.ignore( numeric_limits<int>::max(), '\n' );
        // ignore le nombre de caractere "valeur max d'un entier" jusqu'à rencontrer \n
    }

    fichierMotClef.close( );

}/*}}}*/

void Referenceur::chargerMotsClefsCpp()
{/*{{{*/

    _motsClefs.clear();
    _motsClefs.insert( "asm" );
    _motsClefs.insert( "auto" );
    _motsClefs.insert( "break" );
    _motsClefs.insert( "bool" );
    _motsClefs.insert( "case" );
    _motsClefs.insert( "catch" );
    _motsClefs.insert( "cout" );
    _motsClefs.insert( "char" );
    _motsClefs.insert( "class" );
    _motsClefs.insert( "const" );
    _motsClefs.insert( "const_cast" );
    _motsClefs.insert( "continue" );
    _motsClefs.insert( "default" );
    _motsClefs.insert( "delete" );
    _motsClefs.insert( "do" );
    _motsClefs.insert( "double" );
    _motsClefs.insert( "dynamic_cast" );
    _motsClefs.insert( "else" );
    _motsClefs.insert( "enum" );
    _motsClefs.insert( "extern" );
    _motsClefs.insert( "export" );
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
    _motsClefs.insert( "namespace" );
    _motsClefs.insert( "new" );
    _motsClefs.insert( "operator" );
    _motsClefs.insert( "private" );
    _motsClefs.insert( "protected" );
    _motsClefs.insert( "public" );
    _motsClefs.insert( "register" );
    _motsClefs.insert( "reinterpret_cast" );
    _motsClefs.insert( "return" );
    _motsClefs.insert( "short" );
    _motsClefs.insert( "signed" );
    _motsClefs.insert( "sizeof" );
    _motsClefs.insert( "static" );
    _motsClefs.insert( "static_cast" );
    _motsClefs.insert( "struct" );
    _motsClefs.insert( "switch" );
    _motsClefs.insert( "template" );
    _motsClefs.insert( "this" );
    _motsClefs.insert( "throw" );
    _motsClefs.insert( "try" );
    _motsClefs.insert( "true" );
    _motsClefs.insert( "typedef" );
    _motsClefs.insert( "typeid" );
    _motsClefs.insert( "typename" );
    _motsClefs.insert( "unsigned" );
    _motsClefs.insert( "union" );
    _motsClefs.insert( "using" );
    _motsClefs.insert( "virtual" );
    _motsClefs.insert( "void" );
    _motsClefs.insert( "volatile" );
    _motsClefs.insert( "while" );
    _motsClefs.insert( "wchar_t" );
}/*}}}*/

void Referenceur::referencer( const vector<string>& fichiers, References& refs )
{/*{{{*/

    vector<string>::const_iterator it;
    FichierLu fichier;

    for( it = fichiers.begin(); it != fichiers.end(); it++ ) {

        fichier.open( it->c_str() );

        while( !fichier.eof() ) {

            changerEtat( fichier );
            lireFlux( fichier, refs );

        }

        fichier.close();
    }

}/*}}}*/

inline void Referenceur::setModeInverse( const bool mode )
{/*{{{*/
    _mode = ( mode ) ? Inverse : Normal;
}/*}}}*/



//----------------------------------------------------------------------
//  METHODES PROTEGES
//----------------------------------------------------------------------
inline bool Referenceur::estInserable( const string& mot ) const
{/*{{{*/

    const char c = mot.at( 0 );

    if( c >= '0' && c <= '9' ) {
        return false;
    }

    return  ( _mode == Normal ) ? _motsClefs.count( mot ) :
            !_motsClefs.count( mot );


}/*}}}*/

inline bool Referenceur::isSeparateur( const char c ) const
{/*{{{*/

    // Je me suis basé sur la table ASCII
    return ( c >= -1 && c <= '/' ) ||
           ( c >= ':' && c <= '@' ) ||
           ( c >= '[' && c <= '^' ) ||
           ( c >= '{' && c <= '~' ) ||
           ( c == '`' );

}/*}}}*/

void Referenceur::changerEtat( FichierLu& fic )
{/*{{{*/

    const char c = fic.peek();

    if( c == '#' ) {
        _etat = Preprocesseur;

    } else if(  c == '/' ) {
        _etat = Commentaire;

    } else if(  c == '"' || c == '\'' ) {
        _etat = Literal;

    } else if( isSeparateur( c ) ) {
        _etat = Separateur;

    } else {
        _etat = MotClef;
    }
}/*}}}*/

void Referenceur::lireFlux( FichierLu& fic, References& refs )
{/*{{{*/

    switch( _etat ) {

        case Preprocesseur:
            lirePreprocesseur( fic, refs );
            break;

        case Separateur:
            lireSeparateur( fic, refs );
            break;

        case Commentaire:
            lireCommentaire( fic, refs );
            break;

        case MotClef:
            lireMotClef( fic, refs );
            break;

        case Literal:
            lireLiteral( fic, refs );
            break;
    }

}/*}}}*/




//----------------------------------------------------------------------
//  METHODES ETATS
//----------------------------------------------------------------------
void Referenceur::lirePreprocesseur( FichierLu& fic, References& refs )
{/*{{{*/

    char last = fic.get();

    while( fic.peek() != '\n' || last == '\\' ) {
        last = fic.get();
    }

    fic.get();


}/*}}}*/

void Referenceur::lireCommentaire( FichierLu& fic, References& refs )
{/*{{{*/

    fic.get();

    if( fic.peek() == '/' ) {
        while ( !fic.eof() && fic.get() != '\n' );

    } else if( fic.peek() == '*' ) {
        while ( !fic.eof() && ( fic.get() != '*' || fic.peek() != '/' ) );

        fic.get();
    }

}/*}}}*/

void Referenceur::lireMotClef( FichierLu& fic, References& refs )
{/*{{{*/

    string mot;
    mot.append( 1, fic.get() );

    while( !fic.eof() && !isSeparateur( fic.peek() ) ) {
        mot.append( 1, fic.get() );
    }

    if( estInserable( mot ) ) {
        refs.add( mot, fic.getNomFichier(), fic.getNbLignesLues() );
    }

}/*}}}*/

void Referenceur::lireSeparateur( FichierLu& fic, References& refs )
{/*{{{*/

    fic.get();
}/*}}}*/

void Referenceur::lireLiteral( FichierLu& fic, References& refs )
{/*{{{*/

    char last = fic.get();

    if( last == '"' ) {
        while( fic.peek() != '"' || last == '\\' ) {
            last = fic.get();
        }

        fic.get();

    } else if( last == '\'' ) {
        while( fic.peek() != '\'' || last == '\\' ) {
            last = fic.get();
        }

        fic.get();

    }

}/*}}}*/

}/*}}}*/
