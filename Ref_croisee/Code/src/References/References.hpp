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

    protected:
        enum Mode { Normal, Inverse };
        enum Etat { Libre, Commentaire, MotClef, Separateur };

        std::set<std::string> _motsClefs;
        std::set<std::string> _identificateurs;

        //----------------------------------------------------------------------
        //  METHODES PROTEGE
        //----------------------------------------------------------------------
        bool isSeparateur( const char c ) const;

}; 

//--------------------------- Autres définitions dépendantes de References

#endif

