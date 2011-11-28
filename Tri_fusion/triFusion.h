// =====================================================================================
// 
//       Filename:  triFusion.h
// 
//    Description:  Implémente le tri fusion en C
//        Created:  28/11/2011 00:00:51
//       Compiler:  g++
// 
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
// 
// =====================================================================================

#ifndef TRIFUSION_H_
#define TRIFUSION_H_

typedef struct t_liste
{
    int valeur;
    struct t_liste* suivant;

} liste;


liste* fusion( liste* l1, liste* l2 );
liste* triFusion( liste* l1 );
liste* separation( liste* l1 );

#endif
