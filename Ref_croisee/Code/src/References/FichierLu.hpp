/*************************************************************************
                           FichierLu  -  description
                             -------------------
    début                : 18 nov. 2011
    copyright            : (C) 2011 par csaysset
*************************************************************************/

#ifndef FICHIERLU_HPP_
#define FICHIERLU_HPP_

//------------------------------------------------------------------------Include Systeme
#include    <fstream>
#include    <string>


namespace Reference_croisee {

using namespace Reference_croisee;

/* =====================================================================================
 *        Class:  FichierLu
 *  Description:  Permet de lire un fichier en concervant son nom et le nombre de ligne
 *                déjà parcourue
 * =====================================================================================*/
class FichierLu : private std::ifstream {

    public:
        // ===  FUNCTION  ======================================================================
        //         Name:  FichierLu
        //  Description:  Constructeur de la classe, prend en argument un chemin vers un fichier
        // =====================================================================================
        FichierLu ( const std::string& nomFichier = "" );





//----------------------------------------------------------------------
//  METHODES MASQUEES
//----------------------------------------------------------------------

        // ===  FUNCTION  ======================================================================
        //         Name:  Close
        //  Description:  Ferme le fichier
        // =====================================================================================
        void close();

        // ===  FUNCTION  ======================================================================
        //         Name:  open
        //  Description:  Ouvre un fichier
        // =====================================================================================
        void open( const char* filename,  ios_base::openmode mode = ios_base::in );


        // ===  FUNCTION  ======================================================================
        //         Name:  get
        //  Description:  Permet de récupérer un caractère 
        // =====================================================================================
        int get();

        int peek() { return std::ifstream::peek(); }
        bool eof() { return std::ifstream::eof(); }




//----------------------------------------------------------------------
//  METHODES PUBLIQUES
//----------------------------------------------------------------------

        // ===  FUNCTION  ======================================================================
        //         Name:  GetNbLignesLues
        //  Description:  Retourne le nombre de lignes déjà lues dans le fichier
        // =====================================================================================
        int GetNbLignesLues() const;

        // ===  FUNCTION  ======================================================================
        //         Name:  GetNomFichier
        //  Description:  Retourne le nom du fichier passé lors de la construction de l'objet 
        // =====================================================================================
        std::string GetNomFichier() const;


    protected:
        int _nbLignesLues;                      // contient le nombre de lignes lues
        std::string _nomFichier;                // contient le nom du fichier
};

}/*}}}*/

#endif
