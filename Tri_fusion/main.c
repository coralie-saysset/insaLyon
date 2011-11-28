// =====================================================================================
// 
//       Filename:  main.c
// 
//    Description:  
//        Created:  28/11/2011 00:20:56
//       Compiler:  gcc
// 
//         Author:  Romain GERARD, romain.gerard@insa-lyon.fr
// 
// =====================================================================================



#include	<stdio.h>
#include	<stdlib.h>
#include	"triFusion.h"

int main( ){

    
    liste* l1;
    liste* last;

    l1 = (liste*) malloc( sizeof(liste) );
    l1->valeur = 51;
    last = l1;

    

    //----------------------------------------------------------------------
    //  On remplit la liste
    //----------------------------------------------------------------------
    unsigned int i;
    for( i = 50000; i > 0; i-- ) {

        last->suivant = (liste*) malloc( sizeof(liste) );
        last = last->suivant;
        last->valeur = i;
    }
    last->suivant = 0;



    //----------------------------------------------------------------------
    //  On trie
    //----------------------------------------------------------------------
    l1 = triFusion( l1 );


    //----------------------------------------------------------------------
    //  On affiche la liste triée
    //----------------------------------------------------------------------
    last = l1;
    while( last ) {

        printf("%d ", last->valeur );
        last = last->suivant;
    }
    printf("\n");


    //----------------------------------------------------------------------
    //  On libère la mémoire
    //----------------------------------------------------------------------
    last = l1;
    while( last ) {

        last = l1->suivant;
        free( l1 );
        l1 = last;
    }


    return 0;
}
