#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#include "global.h"
#include "analyseur_syntaxique.h"

int main(int argc, char const *argv[])
{
	const char * fichierR = argv[1];
	char fichier[20] ;
	strcpy(fichier,fichierR);
	
    if(argc == 3){
	Ouvrir_Fichier(fichier);
	if (file == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
	Lire_Car();
	while(Car_Cour != EOF ){
		Sym_Suiv();
		AfficherToken(SYM_COUR);
	}
	//pour afficher la fin du fichier
	Sym_Suiv();
	AfficherToken(SYM_COUR);
	}else{
    Ouvrir_Fichier(fichier);
	TYPE_SYM_PREC = -1;
    
	PREMIER_SYM();
	INSTS();
	
	if(SYM_COUR.CODE==EOF_TOKEN)
		printf("BRAVO: le programme est correcte!!!\n");
	else{
	printf("PAS BRAVO: fin de programme erronee!!!!\n");}
    }
	return 0;
	
}
