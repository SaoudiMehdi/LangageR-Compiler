#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "AnalyseurLexicalv1.c"
#define NbrIDF 100
#define TAILLECODE 100

typedef enum{
	IF_ERR,ELSE_ERR,WHILE_ERR,REPEAT_ERR,FOR_ERR,WRITE_ERR,CAT_ERR,MIN_ERR,MAX_ERR,IN_ERR,BREAK_ERR,IS_ERR,AS_ERR,
	CLS_ERR,PV_ERR,PT_ERR,PLUS_ERR,
	MOINS_ERR,MULT_ERR,DIV_ERR,VIR_ERR,AFF_ERR,
	INF_ERR,INFG_ERR,SUP_ERR,SUPG_ERR,EGAL_ERR,DIFF_ERR,
	PO_ERR,PF_ERR,ID_ERR,NUM_ERR,ERREUR_ERR,COMM_ERR,AND_ERR,OR_ERR,NOT_ERR,RES_ERR,DIVENT_ERR,POW_ERR,ACCO_ERR,ACCF_ERR,SEQ_ERR,ENTRER_ERR,READ_ERR,CHAINE_ERR,EOF_ERR

}CODE_ERR;


typedef enum{
	TINT,TFLT,TCHR
}TSYM;

typedef enum{
	OAFFEC,OLIRE,OALL
}OPTION;

//structure Table des Symboles

typedef struct {
	char nom[20];
	TSYM typeSymbole;
}T_Table_Symbole;

typedef enum{
	false,true
}boolean;

//declaration 
boolean accPresence = false;
TSYM TYPE_SYM_PREC_ID;
TSYM TYPE_SYM_PREC;
TSYM type_symbole;

T_Table_Symbole Table_Symbole[NbrIDF];
TSym_Cour SYM_PREC;
TSym_Cour SYM_PREC_ID;
TSym_Cour SYM;
boolean SAME_TYPE_EXPR = true;

int indice = 0;


//prototypes des fonctions utilisées
void Test_Symbole(CODE_LEX code,CODE_ERR error);
void ERREUR(CODE_ERR error);

//void VARS();
void INSTS();
void INST();
void AFFEC1();
void AFFEC2();
void SI();
void TANTQUE();
void ECRIRE();
void LIRE();
void COND();
void EXPR();
void TERM();
void FACT();
void POUR();
void REPETER();
void FOR();
void MIN();
void MAX();
void PREMIER_SYM();
void pvTest();
void ECRIRE2();
int CHERCHER_SYM(char* nom,OPTION option);
void AJOUTER_SYM(char* nom,TSYM type);



//traitement 

int main(){
	Ouvrir_Fichier("test1.R");
	TYPE_SYM_PREC = -1;
	PREMIER_SYM();
	INSTS();
	
	if(SYM_COUR.CODE==EOF_TOKEN)
		printf("BRAVO: le programme est correcte!!! test\n");
	else
		printf("PAS BRAVO: fin de programme erronee!!!! test\n");
	return true;
}

//Définition des fonctions

void Test_Symbole(CODE_LEX code,CODE_ERR error){
	if(SYM_COUR.CODE==code){
		SYM_PREC_ID.CODE = SYM_COUR.CODE;
		strcpy(SYM_PREC_ID.nom,SYM_COUR.nom);
		Sym_Suiv();
	}else{
		ERREUR(error);
	}
}

void ERREUR(CODE_ERR error){
	switch(error){
		case IF_ERR:
			printf("IF_ERR at ligne %d\n",numLigne); 
			break;
		case ELSE_ERR:
			printf("ELSE_ERR at ligne %d\n",numLigne); 
			break;
		case WHILE_ERR:
			printf("WHILE_ERR at ligne %d\n",numLigne); 
			break;
		case REPEAT_ERR:
			printf("REPEAT_ERR at ligne %d\n",numLigne); 
			break;
		case FOR_ERR:
			printf("FOR_ERR at ligne %d\n",numLigne); 
			break;
		case WRITE_ERR:
			printf("WRITE_ERR at ligne %d\n",numLigne); 
			break;
		case CAT_ERR:
			printf("CAT_ERR at ligne %d\n",numLigne); 
			break;
		case IN_ERR:
			printf("IN_ERR at ligne %d\n",numLigne); 
			break;
		case BREAK_ERR:
			printf("BREAK_ERR at ligne %d\n",numLigne); 
			break;
		case IS_ERR:
			printf("IS_ERR at ligne %d\n",numLigne); 
			break;
		case AS_ERR:
			printf("AS_ERR at ligne %d\n",numLigne); 
			break;
		case CLS_ERR:
			printf("CLS_ERR at ligne %d\n",numLigne); 
			break;
		case PV_ERR:
			printf("PV_ERR at ligne %d\n",numLigne); 
			break;
		case PT_ERR:
			printf("PT_ERR at ligne %d\n",numLigne); 
			break;
		case PLUS_ERR:
			printf("PLUS_ERR at ligne %d\n",numLigne); 
			break;
		case MOINS_ERR:
			printf("MOINS_ERR at ligne %d\n",numLigne); 
			break;
		case MULT_ERR:
			printf("MULT_ERR at ligne %d\n",numLigne); 
			break;
		case DIV_ERR:
			printf("DIV_ERR at ligne %d\n",numLigne); 
			break;
		case VIR_ERR:
			printf("VIR_ERR at ligne %d\n",numLigne); 
			break;
		case AFF_ERR:
			printf("AFF_ERR at ligne %d\n",numLigne); 
			break;
		case INF_ERR:
			printf("INF_ERR at ligne %d\n",numLigne); 
			break;
		case INFG_ERR:
			printf("INFG_ERR at ligne %d\n",numLigne); 
			break;
		case SUP_ERR:
			printf("SUP_ERR at ligne %d\n",numLigne); 
			break;
		case SUPG_ERR:
			printf("SUPG_ERR at ligne %d\n",numLigne); 
			break;
		case EGAL_ERR:
			printf("EGAL_ERR at ligne %d\n",numLigne); 
			break;
		case DIFF_ERR:
			printf("DIFF_ERR at ligne %d\n",numLigne); 
			break;
		case PO_ERR:
			printf("PO_ERR at ligne %d\n",numLigne); 
			break;
		case PF_ERR:
			printf("PF_ERR at ligne %d\n",numLigne); 
			break;
		case ID_ERR:
			printf("ID_ERR at ligne %d\n",numLigne); 
			break;
		case NUM_ERR:
			printf("NUM_ERR at ligne %d\n",numLigne); 
			break;
		case ERREUR_ERR:
			printf("ERREUR_ERR at ligne %d\n",numLigne); 
			break;
		case COMM_ERR:
			printf("COMM_ERR at ligne %d\n",numLigne); 
			break;
		case AND_ERR:
			printf("AND_ERR at ligne %d\n",numLigne); 
			break;
		case OR_ERR:
			printf("OR_ERR at ligne %d\n",numLigne); 
			break;
		case NOT_ERR:
			printf("NOT_ERR at ligne %d\n",numLigne); 
			break;
		case RES_ERR:
			printf("RES_ERR at ligne %d\n",numLigne); 
			break;
		case DIVENT_ERR:
			printf("DIVENT_ERR at ligne %d\n",numLigne); 
			break;
		case POW_ERR:
			printf("POW_ERR at ligne %d\n",numLigne); 
			break;
		case ACCO_ERR:
			printf("ACCO_ERR at ligne %d\n",numLigne); 
			break;
		case ACCF_ERR:
			printf("ACCF_ERR at ligne %d\n",numLigne); 
			break;
		case SEQ_ERR:
			printf("SEQ_ERR at ligne %d\n",numLigne); 
			break;
		case ENTRER_ERR:
			printf("ENTRER_ERR at ligne %d\n",numLigne); 
			break;
		case MIN_ERR:
			printf("MIN_ERR at ligne %d\n",numLigne); 
			break;
		case MAX_ERR:
			printf("MAX_ERR at ligne %d\n",numLigne); 
			break;
		case CHAINE_ERR:
			printf("CHAINE_ERR at ligne %d\n",numLigne); 
			break;
		case EOF_ERR:
			printf("EOF_ERR at ligne %d\n",numLigne); 
			break;
		default:
			printf("ERREUR\n");
		
	}
	SYM_COUR.CODE==ERREUR_TOKEN;
	exit(0);
}

void INSTS(){
	INST();
	while(SYM_COUR.CODE==PV_TOKEN || SYM_COUR.CODE==ENTRER_TOKEN || SYM_COUR.CODE==COMM_TOKEN){
		SYM_PREC.CODE = SYM_COUR.CODE;
		Sym_Suiv();
		INST();
	}
}


void INST(){
	switch(SYM_COUR.CODE){
		case ID_TOKEN:
			AFFEC1();
			break;
		case INT_TOKEN:
		case FLOAT_TOKEN:
			AFFEC2();
			break;
		case PO_TOKEN:
			AFFEC2();
			break;
		case IF_TOKEN:
			SI();
			break;
		case WHILE_TOKEN:
			TANTQUE();
			break;
		case REPEAT_TOKEN:
			REPETER();
			break;	
		case FOR_TOKEN:
			POUR();
			break;	
		case WRITE_TOKEN:
			ECRIRE();
			break;
		case READ_TOKEN:
			LIRE();
			break;
		case MIN_TOKEN:
			MIN();
			break;
		case MAX_TOKEN:
			MAX();
			break;
		case ENTRER_TOKEN:
			break;
		case COMM_TOKEN:
			break;
		case PV_TOKEN:
			pvTest();
			break;
		case BREAK_TOKEN:
			Sym_Suiv();
			break;
		case EOF_TOKEN:
			break;
		default:
			break;
	}
}
	
void AFFEC1(){
	//CHERCHER_SYM(SYM_COUR.nom,OAFFEC);
	Test_Symbole(ID_TOKEN,ID_ERR);
	printf("%s\n",nom_symbol);
	if(SYM_COUR.CODE==AFFOP1_TOKEN){
		CHERCHER_SYM(SYM_PREC_ID.nom,OAFFEC);
		Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
		Test_Symbole(ID_TOKEN,ID_ERR);
		AJOUTER_SYM(SYM_PREC_ID.nom,TYPE_SYM_PREC_ID);
	}else if(SYM_COUR.CODE==AFFOP_TOKEN){
		Test_Symbole(AFFOP_TOKEN,AFF_ERR);
		if(SYM_COUR.CODE!=READ_TOKEN){
			if(SYM_COUR.CODE!=CHAINE_TOKEN) EXPR();
			else{
				Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);
				AJOUTER_SYM(nom_symbol,TCHR);
			}
		}
		else LIRE();
	}else if(SYM_COUR.CODE==AFFOP2_TOKEN){
		Test_Symbole(AFFOP2_TOKEN,AFF_ERR);
		if(SYM_COUR.CODE!=READ_TOKEN){
			if(SYM_COUR.CODE!=CHAINE_TOKEN) EXPR();
			else{
				Sym_Suiv();
			}
		}
		else LIRE();
	}else{
		ECRIRE2();
	}
	
}

void AFFEC2(){
	EXPR();
	Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
}

void SI(){
	Test_Symbole(IF_TOKEN,IF_ERR);
	COND();
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			accPresence= true;
			Sym_Suiv();
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence= false;
			if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=ELSE_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
	if(SYM_COUR.CODE==PV_TOKEN){
		Sym_Suiv();
		if(SYM_COUR.CODE==ELSE_TOKEN) ERREUR(ELSE_ERR);
	}
	if(SYM_COUR.CODE==ENTRER_TOKEN){
		Sym_Suiv();
		while(SYM_COUR.CODE==ENTRER_TOKEN){
			Sym_Suiv();
		}
		if(SYM_COUR.CODE==ELSE_TOKEN) ERREUR(ELSE_ERR);
	}
	
	switch(SYM_COUR.CODE){
		case ELSE_TOKEN:
			Sym_Suiv();
			while(SYM_COUR.CODE==ENTRER_TOKEN) Sym_Suiv();
			switch(SYM_COUR.CODE){
				case ACCO_TOKEN:
					accPresence= true;
					Sym_Suiv();
					INSTS();
					Test_Symbole(ACCF_TOKEN,ACCF_ERR);
					accPresence= false;
					if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
					break;
				default:
					INST();
					break;
			}
			break;
		default:
			break;
	}
}

void COND(){
	Test_Symbole(PO_TOKEN,PO_ERR);
	switch(SYM_COUR.CODE){
		case NOT_TOKEN:
			Test_Symbole(NOT_TOKEN,NOT_ERR);
			EXPR();
			Test_Symbole(PF_TOKEN,PF_ERR);
			break;
		default: 
			EXPR();
			if(SYM_COUR.CODE == EGAL_TOKEN || SYM_COUR.CODE == DIFF_TOKEN 
			|| SYM_COUR.CODE == INF_TOKEN ||SYM_COUR.CODE == SUP_TOKEN ||
			SYM_COUR.CODE == INFG_TOKEN ||SYM_COUR.CODE == SUPG_TOKEN ) Sym_Suiv();
			else if (SYM_COUR.CODE == PF_TOKEN){
				Sym_Suiv();
				break;
			}else{
				ERREUR(PF_ERR);
			}
			if(SYM_COUR.CODE != PF_TOKEN){
				EXPR();
				Test_Symbole(PF_TOKEN,PF_ERR);
			}
			break;
	}
}

void TANTQUE(){
	Test_Symbole(WHILE_TOKEN,WHILE_ERR);
	COND();
	while(SYM_COUR.CODE==ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			accPresence= true;
			Sym_Suiv();
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence= false;
			if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
}


void REPETER(){
	Test_Symbole(REPEAT_TOKEN,REPEAT_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	Test_Symbole(ACCO_TOKEN,ACCO_ERR);
	accPresence= true;
	INSTS();
	Test_Symbole(ACCF_TOKEN,ACCF_ERR);
	accPresence= false;
	if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);

}

void POUR(){
	Test_Symbole(FOR_TOKEN,FOR_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	Test_Symbole(IN_TOKEN,IN_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(FOR_ERR);
	Test_Symbole(SEQ_TOKEN,SEQ_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(FOR_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			accPresence= true;
			Test_Symbole(ACCO_TOKEN,ACCO_ERR);
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence= false;
			if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
			break;
		default:
			INST();
			break;
	}
}

void ECRIRE(){
	Test_Symbole(WRITE_TOKEN,WRITE_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	EXPR();
	Test_Symbole(PF_TOKEN,PF_ERR);
}

void LIRE(){
	Test_Symbole(READ_TOKEN,READ_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(PF_TOKEN,ID_ERR);
	/*CHERCHER_SYM(SYM_PREC.nom,OLIRE);
	while(SYM_COUR.CODE==VIR_TOKEN){
		Sym_Suiv();
		Test_Symbole(ID_TOKEN,ID_ERR);
		CHERCHER_SYM(SYM_PREC.nom,OLIRE);
	}
	Test_Symbole(PF_TOKEN,PF_ERR);*/
}


void EXPR(){
	TERM();
	TYPE_SYM_PREC = TYPE_SYM_PREC_ID;
	while(SYM_COUR.CODE==PLUS_TOKEN||SYM_COUR.CODE==MOINS_TOKEN){
		Sym_Suiv();
		TERM();
	}
	TYPE_SYM_PREC = -1;
}

void TERM(){
	FACT();
	TYPE_SYM_PREC = TYPE_SYM_PREC_ID;
	while(SYM_COUR.CODE==MULT_TOKEN||SYM_COUR.CODE==DIV_TOKEN || SYM_COUR.CODE==DIVENT_TOKEN || SYM_COUR.CODE==RES_TOKEN){
		Sym_Suiv();
		FACT();
	}
}

void FACT(){
	if(TYPE_SYM_PREC == TCHR && TYPE_SYM_PREC!= TYPE_SYM_PREC_ID){
		printf(" '%s' ERROR COMPATIBILITE at ligne %d",SYM_COUR.nom,numLigne);
		exit(0);
	}
	switch(SYM_COUR.CODE){
		case ID_TOKEN:
			printf("testddddd\n");
			Test_Symbole(ID_TOKEN,ID_ERR);
			printf("%s",nom_symbol);
			CHERCHER_SYM(nom_symbol,OAFFEC);
			break;
		case INT_TOKEN:
			type_symbole = TINT;
			Test_Symbole(INT_TOKEN,NUM_ERR);
			AJOUTER_SYM(nom_symbol,type_symbole);
			//TYPE_SYM_PREC_ID = TINT;
			break;
		case FLOAT_TOKEN:
			type_symbole = TFLT;
			Test_Symbole(FLOAT_TOKEN,NUM_ERR);
			AJOUTER_SYM(nom_symbol,type_symbole);
			//TYPE_SYM_PREC_ID = TFLT;
			break;
		case PO_TOKEN:
			Test_Symbole(PO_TOKEN,PO_ERR);
			EXPR();
			Test_Symbole(PF_TOKEN,PF_ERR);
			break;
		case MIN_TOKEN:
			MIN();
			break;
		case MAX_TOKEN:
			MAX();
			break;
		default:
			ERREUR(ERREUR_ERR);
			break;
	}
}

void PREMIER_SYM(){
	Lire_Car();
	Sym_Suiv();
}

void pvTest(){
	if((SYM_PREC.CODE == PV_TOKEN || SYM_PREC.CODE == ENTRER_TOKEN || SYM_PREC.CODE == 0 ) && accPresence==false)
		ERREUR(PV_ERR);
}

void MIN(){
	Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(MIN_ERR);
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(MIN_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
}


void MAX(){
	Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(MIN_ERR);
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	if(SYM_COUR.CODE == INT_TOKEN || SYM_COUR.CODE == FLOAT_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(MIN_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
}

void ECRIRE2(){
	int operationSYM = 0;
	while(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=PV_TOKEN){
	switch(SYM_COUR.CODE){
		case PLUS_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case MOINS_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case MULT_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case DIV_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case DIVENT_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case RES_TOKEN:
			operationSYM++;
			Sym_Suiv();
			break;
		case ID_TOKEN:
			operationSYM--;
			Sym_Suiv();
			break;
		case INT_TOKEN: 
		case FLOAT_TOKEN:
			operationSYM--;
			Sym_Suiv();
			break;
		case ENTRER_TOKEN:
			break;
		case PV_TOKEN:
			break;
		default:
			ERREUR(WRITE_ERR);
			break;
	}
	}
	if(operationSYM>=1) ERREUR(WRITE_ERR);
}

int CHERCHER_SYM(char* nom,OPTION option){
	for(int i=0;i<indice;i++){
		if(!strcmp(Table_Symbole[i].nom,nom)){
			TYPE_SYM_PREC_ID = Table_Symbole[i].typeSymbole;
			return i+1;
		}
	}
	if(option!=OALL){
		printf(" '%s' UNDECLARED at ligne %d\n",nom,numLigne);
		exit(0);
	}
	return 0;
}

void AJOUTER_SYM(char* nom,TSYM type){

	int index = CHERCHER_SYM(nom,OALL);
	if(index){
		Table_Symbole[index-1].typeSymbole = type;
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

