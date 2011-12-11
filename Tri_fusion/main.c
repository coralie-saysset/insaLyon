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
#include	<time.h>
#include	"triFusion.h"


liste* initialiser( double r,  liste* l );
void afficher( liste* l );
void supprimer_liste( liste* l );

int main() {

    
    int nb_maillon;
    
   // printf("Veuillez saisir le n ombre d'élément de la liste : ");
    srand( time(NULL) );
    scanf("%d", &nb_maillon );

    liste* l = initialiser( nb_maillon, NULL );

    
    srand(time(NULL));
    clock_t depart = clock();
    l = triFusion( l );
    double temps = (double) ( clock() - depart ) / CLOCKS_PER_SEC;


    printf("%d %f;\n", nb_maillon, temps);

    supprimer_liste(l);
    l=NULL;


    return 0;
}


liste *initialiser( double r,  liste *l)
{
    static int i = 1;

    if( i++ > r ) return l;

    liste* tmp = malloc(sizeof(liste));
    tmp->valeur = rand();
    tmp->suivant = l;

    return initialiser( r,  tmp );

}

void afficher(liste *l)
{
   if( !l ) return;

   printf("%d ", l->valeur );
   afficher( l->suivant );

}

void supprimer_liste(liste *l)
{
    if( !l ) return;

    supprimer_liste( l->suivant );
    free(l);
}
