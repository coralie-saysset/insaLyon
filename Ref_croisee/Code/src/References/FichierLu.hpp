/*************************************************************************
                           FichierLu  -  description
                             -------------------
    début                : 18 nov. 2011
    copyright            : (C) 2011 par csaysset
*************************************************************************/

#ifndef FICHIERLU_HPP_
#define FICHIERLU_HPP_

#include    <fstream>
#include    <string>


namespace Reference_croisee {

using namespace Reference_croisee;

/* =====================================================================================
 *        Class:  FichierLu
 *  Description:  Permet de lire un fichier en concervant son nom et le nombre de ligne
 *                déjà parcourue
 * =====================================================================================*/
class FichierLu : public std::ifstream {

    public:
        FichierLu ( const std::string& nomFichier = "" );

        //----------------------------------------------------------------------
        //  METHODES MASQUEES
        //----------------------------------------------------------------------
        void close();
        void open( const char* filename,  ios_base::openmode mode = ios_base::in );
        int get();

        //----------------------------------------------------------------------
        //  METHODES PUBLIQUES
        //----------------------------------------------------------------------
        int getNbLignesLues();
        std::string getNomFichier();


    protected:
        int _nbLignesLues;
        std::string _nomFichier;
};

}

#endif
