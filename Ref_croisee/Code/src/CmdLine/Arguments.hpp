// NO_FORMAT ============================================================================
//
//       Filename:  cmdLineArgument.hpp
//
//    Description:  Permet de stocker les arguments passé en paramètre du programme
//        Created:  06/11/2011 21:35:00
//       Compiler:  g++
//
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
//
// =====================================================================================


#ifndef CmdLineArgument_HPP
#define CmdLineArgument_HPP

//------------------------------------------------------------------------Include Systeme
#include    <string>
#include    <map>

//------------------------------------------------------------------------Include Personnel
#include    "Exceptions.hpp"
#include    "StringTo.hpp"

namespace CmdLine {

using namespace CmdLine;

/* =====================================================================================
 *        Class:  Argument
 *  Description:  Permet de gérer les options de la ligne de commande
 * =====================================================================================*/
class Arguments {

     public:
         /* ===  FUNCTION  ======================================================================
          *         Name:  Count
          *  Description:  Permet de savoir si une option est présente
          *                Il faut donner le nom long de l'option
          * =====================================================================================*/
          bool Count( std::string arg ) const {
               return _arguments.count( arg );
          }

          /* ===  FUNCTION  ======================================================================
           *         Name:  Get
           *  Description:  Permet de récupérer une option 
           * =====================================================================================*/
          template<typename T>
          T Get( const char* arg ) {

               if ( !_arguments.count( arg ) )
                    {   throw InvalidKey(); }

               return stringTo<T>( _arguments[arg] );
          }

          /* ===  FUNCTION  ======================================================================
           *         Name:  Get
           *  Description:  Permet de récupérer une option 
           * =====================================================================================*/
          template<typename T>
          T Get( std::string& arg ) {

               if ( !_arguments.count( arg ) )
                    {   throw InvalidKey(); }

               return stringTo<T>( _arguments[arg] );
          }


     private:
          /*-----------------------------------------------------------------------------
           *  Structures de données
           *-----------------------------------------------------------------------------*/
          std::map<std::string, std::string> _arguments;

          /*-----------------------------------------------------------------------------
           *  Classe friend
           *-----------------------------------------------------------------------------*/
          friend class Parser;
};

}/*}}}*/

#endif

