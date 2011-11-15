/*************************************************************************
                           lecture  -  description
                             -------------------
    d�but                : 10 nov. 2011
    copyright            : (C) 2011 par csaysset
*************************************************************************/

//---------- R�alisation de la classe <lecture> (fichier lecture.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <limits>


//------------------------------------------------------ Include personnel
#include "lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type lecture::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
//lecture & lecture::operator = ( const lecture & unlecture )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
lecture::lecture ( const lecture & unlecture )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <lecture>" << endl;
#endif
} //----- Fin de lecture (constructeur de copie)


lecture::lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <lecture>" << endl;
#endif
} //----- Fin de lecture


lecture::~lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <lecture>" << endl;
#endif
} //----- Fin de ~lecture


set<string> lecture::litMotClef ( string nomFichier )
{
	ifstream fichierMotClef ( nomFichier.c_str(), ios::in );
	set<string> listeMotClef;

	if ( !fichierMotClef.is_open ( ) )
	{
		cout << "probleme d'ouverture, verifier l'existence du fichier" <<endl;
	}
	else
	{
		string motRecupere;
		while ( !fichierMotClef.eof ( ) )
		{
			fichierMotClef >> motRecupere;
			listeMotClef.insert ( motRecupere );
			fichierMotClef.ignore(numeric_limits<int>::max(), '\n');
			// ignore le nombre de caractere "valeur max d'un entier" jusqu'à rencontrer \n
		}
		fichierMotClef.close( );

	}

	return listeMotClef;
}
set<string> lecture::litIdentificateur ( string nomFichierIdentificateur )
{
	set<string> ListeMotClef = litMotClef ( "/home/csaysset/Documents/Ref_croisee/motClef" );
	set<string> ListeIdentificateur = litMotClef ( nomFichierIdentificateur );

	set<string>::iterator it;
	for ( it = ListeMotClef.begin(); it!= ListeMotClef.end(); it++)
	{
		ListeIdentificateur.erase(*it);
	}
	return ListeIdentificateur;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

