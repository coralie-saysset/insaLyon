/*************************************************************************
                           FichierLu  -  description
                             -------------------
    début                : 18 nov. 2011
    copyright            : (C) 2011 par csaysset
*************************************************************************/

#ifndef FICHIERLU_HPP_
#define FICHIERLU_HPP_

#include	<fstream>
#include	<string>

class FichierLu : public std::ifstream
{

    public:
        FichierLu& operator = ( const FichierLu& unFichierLu );


        FichierLu ( const FichierLu& unFichierLu );
        FichierLu ( const std::string nomFichier = "" );

        void close();
        void open( const char * filename,  ios_base::openmode mode = ios_base::in );

        int get ();
        int getNbLignesLues();
        std::string getNomFichier();


    protected:
        int _nbLignesLues;
        std::string _nomFichier;
};


#endif
