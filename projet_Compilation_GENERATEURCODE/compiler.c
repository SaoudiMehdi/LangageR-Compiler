#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//#include "global.h"
#include "analyseur_syntaxique.h"

int main(int argc, char const *argv[])
{
    Ouvrir_Fichier("test.R");
	TYPE_SYM_PREC = -1;
    
	PREMIER_SYM();
	PROG();
	if(SYM_COUR.CODE==EOF_TOKEN)
		printf("BRAVO: le programme est correcte!!! test\n");
	else
		printf("PAS BRAVO: fin de programme erronee!!!! test\n");
    return 0;
}
