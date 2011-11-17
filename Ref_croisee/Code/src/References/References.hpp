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


#ifndef References_HPP
#define References_HPP


#include	<string>
#include	<set>
#include	<vector>
#include	<fstream>

//------------------------------------------------------------------------ 
// Rôle de la classe References
// Description : Permet de visualiser la répartition de mots clefs dans une 
//               collection de fichiers
//------------------------------------------------------------------------ 

class References
{
    public:

        References& operator = ( const References &other ); 
        References ();  
        References ( const References &other );
        virtual ~References ();



        //----------------------------------------------------------------------
        //  METHODES PUBLIQUES
        //----------------------------------------------------------------------
        void chargerMotsClefs( const std::string& nomFichier );
        void chargerMotsClefs(  );
        void chargerIdentificateurs( const std::string& nomFichier );
        void referencer( const std::vector<std::string>& fichiers );

    protected:
        enum Mode { Normal, Inverse };
        enum Etat { Separateur, Commentaire, MotClef, Preprocesseur, Literal };

        Mode _mode;
        Etat _etat;

        std::set<std::string> _motsClefs;
        std::set<std::string> _identificateurs;

        //----------------------------------------------------------------------
        //  METHODES PROTEGES
        //----------------------------------------------------------------------
        bool isSeparateur( const char c ) const;
        void changerEtat( std::ifstream& fic );
        void lireFlux( std::ifstream& fic );


        //----------------------------------------------------------------------
        //  METHODES ETATS
        //----------------------------------------------------------------------
        void lirePreprocesseur( std::ifstream& fic );
        void lireSeparateur( std::ifstream& fic );
        void lireMotClef( std::ifstream& fic );
        void lireCommentaire( std::ifstream& fic );
        void lireLiteral( std::ifstream& fic );


}; 

//--------------------------- Autres définitions dépendantes de References

#endif

