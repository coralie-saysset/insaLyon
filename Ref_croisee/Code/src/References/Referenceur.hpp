// =====================================================================================
//
//       Filename:  References.hpp
//
//    Description:  Interface de la classe References
//                  Permet de visualiser la répartition de mots clefs dans une
//                  collection de fichiers
//        Created:  15/11/2011 23:30:30
//       Compiler:  g++
//
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
//
// =====================================================================================


#ifndef Referenceur_HPP
#define Referenceur_HPP

//------------------------------------------------------------------------Include Systeme
#include    <string>
#include    <vector>
#include    <tr1/unordered_set>

//------------------------------------------------------------------------Include Personnels
#include    "FichierLu.hpp"
#include    "References.hpp"

namespace Reference_croisee {

using namespace Reference_croisee;

//------------------------------------------------------------------------
// Rôle de la classe References
// Description : Permet de visualiser la répartition de mots clefs dans une
//               collection de fichiers
//------------------------------------------------------------------------
class Referenceur {

    public:
//----------------------------------------------------------------------
//  CONSTRUCTEURS
//----------------------------------------------------------------------
        Referenceur( const std::string fichierMotClef = std::string(),
                     const bool modeInverse = false );

//----------------------------------------------------------------------
//  METHODES PUBLIQUES
//----------------------------------------------------------------------

        // ===  FUNCTION  ======================================================================
        //         Name:  ChargerMotsClefs
        //  Description:  Permet de charger des mots clefs à partir d'un fichier "nomFichier" 
        // =====================================================================================
        void ChargerMotsClefs( const std::string& nomFichier );
        
        // ===  FUNCTION  ======================================================================
        //         Name:  ChargerMotsClefsCpp
        //  Description:  Permet de définir les mots clefs C++ standard comme des mots clefs
        // =====================================================================================
        void ChargerMotsClefsCpp();
        
        // ===  FUNCTION  ======================================================================
        //         Name:  SetModeInverse
        //  Description:  Permet de passer le parseur en mode inverse
        // =====================================================================================
        inline void SetModeInverse( const bool mode );

        // ===  FUNCTION  ======================================================================
        //         Name:  Referencer
        //  Description:  Permet de chercher les mots clefs une collection de fichier
        //                Les résultats sont stockés dans refs
        // =====================================================================================
        void Referencer( const std::vector<std::string>& fic, References& refs );

    protected:
        enum Mode { Normal, Inverse };          // Les différents mode du parseur
        enum Etat { Separateur, Commentaire, MotClef, Preprocesseur, Literal }; // Les états interne de l'automate



//----------------------------------------------------------------------
//  ATTRIBUTS MEMBRES
//----------------------------------------------------------------------
        Mode _mode;
        Etat _etat;

        std::tr1::unordered_set<std::string> _motsClefs; // le conteneur des mots clefs



//----------------------------------------------------------------------
//  METHODES PROTEGES
//----------------------------------------------------------------------

        // ===  FUNCTION  ======================================================================
        //         Name:  estInserable
        //  Description:  retourne vrai si l'identificateur passé en parametre est un mot clef
        // =====================================================================================
        inline bool estInserable( const std::string& mot ) const;

        // ===  FUNCTION  ======================================================================
        //         Name:  isSeparateur
        //  Description:  Retourne vrai si le caractère c est un séparateur
        // =====================================================================================
        bool isSeparateur( const char c ) const;

        // ===  FUNCTION  ======================================================================
        //         Name:  changerEtat
        //  Description:  Définit le nouvel état de l'automate
        // =====================================================================================
        void changerEtat( FichierLu& fic );

        // ===  FUNCTION  ======================================================================
        //         Name:  lireFlux
        //  Description:  Avance dans le flux de données en fonction de l'état de l'automate
        // =====================================================================================
        void lireFlux( FichierLu& fic, References& refs );



//----------------------------------------------------------------------
//  METHODES ETATS
//----------------------------------------------------------------------

        // ===  FUNCTION  ======================================================================
        //         Name:  lirePreprocesseur
        //  Description:  Traite les instructions préprocesseurs
        // =====================================================================================
        void lirePreprocesseur( FichierLu& fic, References& refs );

        // ===  FUNCTION  ======================================================================
        //         Name:  lireSeparateur
        //  Description:  Traite les séparateurs
        // =====================================================================================
        void lireSeparateur( FichierLu& fic, References& refs );

        // ===  FUNCTION  ======================================================================
        //         Name:  lireIdentificateur
        //  Description:  Traite les identificateurs
        // =====================================================================================
        void lireIdentificateur( FichierLu& fic, References& refs );

        // ===  FUNCTION  ======================================================================
        //         Name:  lireCommentaire
        //  Description:  Traite les commentaires
        // =====================================================================================
        void lireCommentaire( FichierLu& fic, References& refs );

        // ===  FUNCTION  ======================================================================
        //         Name:  lireLiteral
        //  Description:  Traire les chaines de caractères
        // =====================================================================================
        void lireLiteral( FichierLu& fic, References& refs );


};

}/*}}}*/
#endif

