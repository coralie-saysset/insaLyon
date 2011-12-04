// =====================================================================================
//
//       Filename:  References.hpp
//
//    Description:  Permet de stocker les résultats des références croisées
//        Created:  18/11/2011 22:29:34
//       Compiler:  g++
//
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
//
// =====================================================================================


#ifndef References_HPP
#define References_HPP

//------------------------------------------------------------------------Include Systeme
#include    <map>
#include    <list>
#include    <tr1/unordered_map>

namespace Reference_croisee {

using namespace Reference_croisee;

//------------------------------------------------------------------------
// Rôle de la classe References
// Description : Permet de stocker les occurences des références croisées
//
//------------------------------------------------------------------------
class References {

    public:
//----------------------------------------------------------------------
//  METHODES PUBLIQUES
//----------------------------------------------------------------------

        // ===  FUNCTION  ======================================================================
        //         Name:  Add
        //  Description:  Permet d'ajouter un motClef passé en parametre rencontré dans le fichier
	//		  nomFichier et à la ligne au conteneur
        // =====================================================================================
        void Add( const std::string& motClef, const std::string& nomFichier, int ligne );

        // ===  FUNCTION  ======================================================================
        //         Name:  Display
        //  Description:  Permet d'afficher toutes les références dans le flux fournit en entrée
        // =====================================================================================
        void Display( std::ostream& flux ) const;


    protected:
//----------------------------------------------------------------------
//  ATTRIBUTS MEMBRES
//----------------------------------------------------------------------

        // Structure interne du conteneur
        std::tr1::unordered_map<std::string, std::map<std::string, std::list<int> > > _references;

};

//----------------------------------------------------------------------
//  SURCHARGES OPERATEURS
//----------------------------------------------------------------------

std::ostream& operator<<( std::ostream& flux,  const References& ref );

}/*}}}*/

#endif

