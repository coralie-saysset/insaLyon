// =====================================================================================
// 
//       Filename:  triFusion.c
// 
//    Description:  Implémente le tri fusion en C
//        Created:  28/11/2011 00:05:19
//       Compiler:  gcc
// 
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
// 
// =====================================================================================


#include	"triFusion.h"

liste* separation( liste* l1 ) {


    if( !l1 || !l1->suivant ) return 0;
    
    liste* l2;

    l2 = l1->suivant;
    l1->suivant = l2->suivant;
    l2->suivant = separation( l2->suivant );

    return l2;

}


liste* fusion( liste* l1,  liste* l2 ) {

    if( !l1 ) return l2;
    if( !l2 ) return l1;

    if( l1->valeur <= l2->valeur ) {
        l1->suivant = fusion( l1->suivant, l2 );
        return l1;

    } else {
        l2->suivant = fusion( l1, l2->suivant );
        return l2;

    }

}


liste* triFusion( liste* l1 ) {
    liste* l2;

    if( !l1 || !l1->suivant ) return l1;

    l2 = separation( l1 );
    l1 = triFusion( l1 );
    l2 = triFusion( l2 );

    return fusion( l1, l2 );

}

int testReussite(liste* l1)
{
while (l1 && l1->suivant)
{
	if (l1 > l1->suivant)
	{
		return 0;
	}
	l1=l1->suivant;
}
return 1;
}
