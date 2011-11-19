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


#include	<map>
#include	<list>
#include	<tr1/unordered_map>

//------------------------------------------------------------------------ 
// Rôle de la classe References
// Description : Permet de stocker les occurences des références croisées
//
//------------------------------------------------------------------------ 
class References
{

    public:
        References ();  

        void add( const std::string& motClef, const std::string& nomFichier, int ligne );
        void display( std::ostream& flux ) const;

    protected:
        std::tr1::unordered_map<std::string, std::map<std::string, std::list<int> > > _references; 




}; 



#endif

