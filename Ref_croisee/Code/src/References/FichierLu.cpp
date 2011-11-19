/*************************************************************************
                           FichierLu  -  description
                             -------------------
    d�but                : 18 nov. 2011
    copyright            : (C) 2011 par csaysset
*************************************************************************/

#include <fstream>
#include "FichierLu.hpp"


namespace Reference_croisee {

using namespace std;
using namespace Reference_croisee;

//----------------------------------------------------------------------
//  CONSTRUCTEURS
//----------------------------------------------------------------------
FichierLu::FichierLu ( const string& nomFichier ):
    _nbLignesLues( 1 )
{/*{{{*/

    if( !nomFichier.empty() ) {
        open( nomFichier.c_str() );
    }
}/*}}}*/


//----------------------------------------------------------------------
//  METHODES MASQUEES
//----------------------------------------------------------------------
void FichierLu::close()
{/*{{{*/

    ifstream::close();
    ifstream::clear();

    _nbLignesLues = 1;
    _nomFichier.clear();
}/*}}}*/

void FichierLu::open( const char* filename,  ios_base::openmode mode )
{/*{{{*/

    exceptions( ifstream::failbit );
    ifstream::open( filename, mode );
    exceptions( ifstream::badbit );
    _nomFichier = filename;
}/*}}}*/

int FichierLu::get()
{/*{{{*/

    int charactere = ifstream::get();

    if ( charactere == '\n' ) {
        _nbLignesLues++;
    }

    return charactere;
}/*}}}*/

//----------------------------------------------------------------------
// METHODES NON HERITÉES 
//----------------------------------------------------------------------
int FichierLu::getNbLignesLues()
{/*{{{*/

    return _nbLignesLues;
}/*}}}*/

string FichierLu::getNomFichier()
{/*{{{*/

    return _nomFichier;
}/*}}}*/

}
