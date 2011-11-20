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


#include    <string>
#include    <set>
#include    <vector>
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
        Referenceur( const std::string fichierMotClef = std::string(),
                     const bool modeInverse = false );

        //----------------------------------------------------------------------
        //  METHODES PUBLIQUES
        //----------------------------------------------------------------------
        void chargerMotsClefs( const std::string& nomFichier );
        inline void setModeInverse( const bool mode );
        void referencer( const std::vector<std::string>& fic, References& refs );

    protected:
        enum Mode { Normal, Inverse };
        enum Etat { Separateur, Commentaire, MotClef, Preprocesseur, Literal };

        //----------------------------------------------------------------------
        //  ATTRIBUTS MEMBRES
        //----------------------------------------------------------------------
        Mode _mode;
        Etat _etat;

        std::set<std::string> _motsClefsCpp;
        std::set<std::string> _identificateurs;

        //----------------------------------------------------------------------
        //  METHODES PROTEGES
        //----------------------------------------------------------------------
        inline bool estInserable( const std::string& mot ) const;
        void chargerMotsClefsCpp();
        bool isSeparateur( const char c ) const;
        void changerEtat( FichierLu& fic );
        void lireFlux( FichierLu& fic, References& refs );


        //----------------------------------------------------------------------
        //  METHODES ETATS
        //----------------------------------------------------------------------
        void lirePreprocesseur( FichierLu& fic, References& refs );
        void lireSeparateur( FichierLu& fic, References& refs );
        void lireMotClef( FichierLu& fic, References& refs );
        void lireCommentaire( FichierLu& fic, References& refs );
        void lireLiteral( FichierLu& fic, References& refs );


};

}/*}}}*/
#endif

