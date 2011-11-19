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
Referenceur::Referenceur ( ):
    _mode( Normal ), _etat( Separateur )
{/*{{{*/
    chargerMotsClefsCpp();

#ifdef MAP
    cout << "Appel au constructeur de <Referenceur>" << endl;
#endif
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
    string motRecupere;

    while ( fichierMotClef >> motRecupere ) {
        _identificateurs.insert( motRecupere );
        fichierMotClef.ignore( numeric_limits<int>::max(), '\n' );
        // ignore le nombre de caractere "valeur max d'un entier" jusqu'à rencontrer \n
    }

    fichierMotClef.close( );

}/*}}}*/

void Referenceur::chargerMotsClefsCpp()
{/*{{{*/

    _motsClefsCpp.insert( "asm" );
    _motsClefsCpp.insert( "auto" );
    _motsClefsCpp.insert( "break" );
    _motsClefsCpp.insert( "bool" );
    _motsClefsCpp.insert( "case" );
    _motsClefsCpp.insert( "catch" );
    _motsClefsCpp.insert( "cout" );
    _motsClefsCpp.insert( "char" );
    _motsClefsCpp.insert( "class" );
    _motsClefsCpp.insert( "const" );
    _motsClefsCpp.insert( "const_cast" );
    _motsClefsCpp.insert( "continue" );
    _motsClefsCpp.insert( "default" );
    _motsClefsCpp.insert( "delete" );
    _motsClefsCpp.insert( "do" );
    _motsClefsCpp.insert( "double" );
    _motsClefsCpp.insert( "dynamic_cast" );
    _motsClefsCpp.insert( "else" );
    _motsClefsCpp.insert( "enum" );
    _motsClefsCpp.insert( "extern" );
    _motsClefsCpp.insert( "export" );
    _motsClefsCpp.insert( "explicit" );
    _motsClefsCpp.insert( "false" );
    _motsClefsCpp.insert( "float" );
    _motsClefsCpp.insert( "for" );
    _motsClefsCpp.insert( "friend" );
    _motsClefsCpp.insert( "goto" );
    _motsClefsCpp.insert( "if" );
    _motsClefsCpp.insert( "inline" );
    _motsClefsCpp.insert( "int" );
    _motsClefsCpp.insert( "long" );
    _motsClefsCpp.insert( "mutable" );
    _motsClefsCpp.insert( "namespace" );
    _motsClefsCpp.insert( "new" );
    _motsClefsCpp.insert( "operator" );
    _motsClefsCpp.insert( "private" );
    _motsClefsCpp.insert( "protected" );
    _motsClefsCpp.insert( "public" );
    _motsClefsCpp.insert( "register" );
    _motsClefsCpp.insert( "reinterpret_cast" );
    _motsClefsCpp.insert( "return" );
    _motsClefsCpp.insert( "short" );
    _motsClefsCpp.insert( "signed" );
    _motsClefsCpp.insert( "sizeof" );
    _motsClefsCpp.insert( "static" );
    _motsClefsCpp.insert( "static_cast" );
    _motsClefsCpp.insert( "struct" );
    _motsClefsCpp.insert( "switch" );
    _motsClefsCpp.insert( "template" );
    _motsClefsCpp.insert( "this" );
    _motsClefsCpp.insert( "throw" );
    _motsClefsCpp.insert( "try" );
    _motsClefsCpp.insert( "true" );
    _motsClefsCpp.insert( "typedef" );
    _motsClefsCpp.insert( "typeid" );
    _motsClefsCpp.insert( "typename" );
    _motsClefsCpp.insert( "unsigned" );
    _motsClefsCpp.insert( "union" );
    _motsClefsCpp.insert( "using" );
    _motsClefsCpp.insert( "virtual" );
    _motsClefsCpp.insert( "void" );
    _motsClefsCpp.insert( "volatile" );
    _motsClefsCpp.insert( "while" );
    _motsClefsCpp.insert( "wchar_t" );
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




//----------------------------------------------------------------------
//  METHODES PROTEGES
//----------------------------------------------------------------------
inline bool Referenceur::estInserable( const string& mot ) const
{/*{{{*/

    if( _mode == Normal ) {
        return _identificateurs.empty() ? _motsClefsCpp.count( mot ) :
               _identificateurs.count( mot );

    } else if( _mode == Inverse ) {
        return  _identificateurs.empty() ? false :
                ( !_identificateurs.count( mot ) &&
                  _motsClefsCpp.count( mot ) );
    }

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

}
