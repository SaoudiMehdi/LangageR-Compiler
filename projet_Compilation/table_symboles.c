#include "table_symboles.h"

int CHERCHER_SYM(char* nom,OPTION option){
	for(int i=0;i<indice;i++){
		if(!strcmp(Table_Symbole[i].nom,nom)){
			TYPE_SYM_PREC_ID = Table_Symbole[i].typeSymbole;
			return Table_Symbole[i].typeSymbole;
		}
	}
	if(option!=OALL){
		printf(" '%s' UNDECLARED at ligne %d\n",nom,numLigne);
		exit(0);
	}
	return -1;
}

int INDEX_SYM(char* nom){
	for(int i=0;i<indice;i++){
		if(!strcmp(Table_Symbole[i].nom,nom)){
			TYPE_SYM_PREC_ID = Table_Symbole[i].typeSymbole;
			return i;
		}
	}
	return -1;
}

void AJOUTER_SYM(char* nom,TSYM type){

	int index = INDEX_SYM(nom);
	if(index != -1){
		printf("%d\n",type);
		Table_Symbole[index].typeSymbole = type;
	}else{
		strcpy(Table_Symbole[indice].nom, nom);
		Table_Symbole[indice].typeSymbole = type;
		indice++;
	}
	for (int i = 0; i < indice; i++)
	{
		printf("symbol: %s type: %d\n",Table_Symbole[i].nom,Table_Symbole[i].typeSymbole);
	}
	
}