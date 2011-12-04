// =====================================================================================
//
//       Filename:  References.cpp
//
//    Description:
//        Created:  18/11/2011 22:50:44
//       Compiler:  g++
//
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
//
// =====================================================================================


//---------------------------------------------------------------------- include systeme
#include <iostream>

//---------------------------------------------------------------------- include personnel
#include "References.hpp"

namespace Reference_croisee {

using namespace std;
using namespace Reference_croisee;


//----------------------------------------------------------------------
//  METHODES PUBLIQUES
//----------------------------------------------------------------------
void References::Add( const string& motClef, const string& nomFichier, const int ligne )
{/*{{{*/


    if ( !_references.count( motClef ) )
    {	_references.insert( make_pair( motClef, map<string, list<int> >() ) );
        _references[motClef].insert( make_pair( nomFichier, list<int>( 1, ligne ) ) );
    }
    else if ( !_references[motClef].count( nomFichier ) )
    {	_references[motClef].insert( make_pair( nomFichier, list<int>( 1, ligne ) ) );
    }
    else
    {	_references[motClef][nomFichier].push_back( ligne );
    }


}/*}}}*/

void References::Display( ostream& flux ) const
{/*{{{*/

    tr1::unordered_map<string, map<string, list<int> > >::const_iterator itClef;
    map<string, list<int> >::const_iterator itFic;
    list<int>::const_iterator itLigne;


    for ( itClef = _references.begin(); itClef != _references.end(); itClef++ )
    {	//flux.width(15);
        //flux << left;
        flux << itClef->first << "\t";

        for ( itFic = itClef->second.begin(); itFic != itClef->second.end(); itFic++ )
	{	flux << itFic->first;

            for ( itLigne = itFic->second.begin(); itLigne != itFic->second.end(); itLigne++ )
	    {	flux << ' ' << *itLigne;
            }

            flux << '\t';
        }

        flux << endl;
    }

}/*}}}*/



//----------------------------------------------------------------------
//  SURCHARGES OPERATEURS
//----------------------------------------------------------------------
ostream& operator<<( ostream& flux,  const References& ref ) {

    ref.Display( flux );

    return flux;

}

}
