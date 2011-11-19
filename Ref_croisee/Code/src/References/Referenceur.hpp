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


#include	<string>
#include	<set>
#include	<vector>
#include	"FichierLu.hpp"
#include	"References.hpp"

//------------------------------------------------------------------------ 
// Rôle de la classe References
// Description : Permet de visualiser la répartition de mots clefs dans une 
//               collection de fichiers
//------------------------------------------------------------------------ 
class Referenceur
{
    public:

        Referenceur& operator = ( const Referenceur& other ); 
        Referenceur ();  
        Referenceur ( const Referenceur& other );


        //----------------------------------------------------------------------
        //  METHODES PUBLIQUES
        //----------------------------------------------------------------------
        void chargerMotsClefs( const std::string& nomFichier );
        void referencer( const std::vector<std::string>& fic, References& refhiers );

    protected:
        enum Mode { Normal, Inverse };
        enum Etat { Separateur, Commentaire, MotClef, Preprocesseur, Literal };

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
        void lireFlux( FichierLu& fic, References& ref );


        //----------------------------------------------------------------------
        //  METHODES ETATS
        //----------------------------------------------------------------------
        void lirePreprocesseur( FichierLu& fic, References& ref );
        void lireSeparateur( FichierLu& fic, References& ref );
        void lireMotClef( FichierLu& fic, References& ref );
        void lireCommentaire( FichierLu& fic, References& ref );
        void lireLiteral( FichierLu& fic, References& ref );


}; 

#endif

