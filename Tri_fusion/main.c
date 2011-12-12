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




void afficher( liste* l );
void supprimer_liste( liste* l );
liste* initialiserDecroissant( double r,  liste* l);
liste* initialiserAleatoire( double r,  liste* l);
liste* initialiserCroissant( double r,  liste* l);

int main() {

    
    int nb_maillon;
    printf("Veuillez saisir le nombre d'élément de la liste : ");
    scanf("%d", &nb_maillon );


    liste* l = initialiserDecroissant( nb_maillon, NULL );
    printf("Allocation terminé\n");

    
    srand(time(NULL));
    clock_t depart = clock();
    l = triFusion( l );
    double temps = (double) ( clock() - depart ) / CLOCKS_PER_SEC;
    printf("%f\n", temps);


    if (testReussite(l))
    {
        printf("tri reussi\n");
    }
    else
    {
        printf("tri echoue\n");
    }
    supprimer_liste(l);
    l=NULL;


    return 0;
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
liste* initialiserCroissant( double r,  liste* l)
{

    if( r < 0 ) return l;

    liste* tmp = malloc(sizeof(liste));
    tmp->valeur = r--;
    tmp->suivant = l;

    return initialiserCroissant( r,  tmp );

}

liste* initialiserDecroissant( double r,  liste* l) 
{
    static int i = 1;

    if( i > r ) return l;

    liste* tmp = malloc(sizeof(liste));
    tmp->valeur = i++;
    tmp->suivant = l;

    return initialiserDecroissant( r,  tmp );

}


liste* initialiserAleatoire( double r,  liste* l)
{
    static int i = 1;

    if( i > r ) return l;
	i++;
    liste* tmp = malloc(sizeof(liste));
    tmp->valeur = rand();
    tmp->suivant = l;

    return initialiserAleatoire( r,  tmp );

}
