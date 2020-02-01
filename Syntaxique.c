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


//declaration 
int accPresence = 0;
TSym_Cour SYM_PREC;


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



//traitement 

int main(){
	Ouvrir_Fichier("test1.R");
	PREMIER_SYM();
	INSTS();
	
	if(SYM_COUR.CODE==EOF_TOKEN)
		printf("BRAVO: le programme est correcte!!! test");
	else
		printf("PAS BRAVO: fin de programme erronee!!!! test");
	return 1;
}

//Définition des fonctions

void Test_Symbole(CODE_LEX code,CODE_ERR error){
	if(SYM_COUR.CODE==code){
		SYM_PREC.CODE = SYM_COUR.CODE;
		strcpy(SYM_PREC.nom,SYM_COUR.nom);
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
		case NUM_TOKEN:
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
	Sym_Suiv();
	if(SYM_COUR.CODE==AFFOP1_TOKEN){
		Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
		Test_Symbole(ID_TOKEN,ID_ERR);
	}else if(SYM_COUR.CODE==AFFOP_TOKEN){
		Test_Symbole(AFFOP_TOKEN,AFF_ERR);
		if(SYM_COUR.CODE!=READ_TOKEN){
			if(SYM_COUR.CODE!=CHAINE_TOKEN) EXPR();
			else{
				Sym_Suiv();
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
			accPresence++;
			Sym_Suiv();
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence--;
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
					accPresence++;
					Sym_Suiv();
					INSTS();
					Test_Symbole(ACCF_TOKEN,ACCF_ERR);
					accPresence--;
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
			accPresence++;
			Sym_Suiv();
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence--;
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
	accPresence++;
	INSTS();
	Test_Symbole(ACCF_TOKEN,ACCF_ERR);
	accPresence--;
	if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);

}

void POUR(){
	Test_Symbole(FOR_TOKEN,FOR_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	Test_Symbole(IN_TOKEN,IN_ERR);
	if(SYM_COUR.CODE == NUM_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(FOR_ERR);
	Test_Symbole(SEQ_TOKEN,SEQ_ERR);
	if(SYM_COUR.CODE == NUM_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(FOR_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			accPresence++;
			Test_Symbole(ACCO_TOKEN,ACCO_ERR);
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			accPresence--;
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
	while(SYM_COUR.CODE==PLUS_TOKEN||SYM_COUR.CODE==MOINS_TOKEN){
		Sym_Suiv();
		TERM();
	}
}

void TERM(){
	FACT();
	while(SYM_COUR.CODE==MULT_TOKEN||SYM_COUR.CODE==DIV_TOKEN || SYM_COUR.CODE==DIVENT_TOKEN || SYM_COUR.CODE==RES_TOKEN){
		Sym_Suiv();
		FACT();
	}
}

void FACT(){
	switch(SYM_COUR.CODE){
		case ID_TOKEN:
			Test_Symbole(ID_TOKEN,ID_ERR);
			break;
		case NUM_TOKEN:
			Test_Symbole(NUM_TOKEN,NUM_ERR);
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
	if((SYM_PREC.CODE == PV_TOKEN || SYM_PREC.CODE == ENTRER_TOKEN || SYM_PREC.CODE == 0 ) && accPresence==0)
		ERREUR(PV_ERR);
}

void MIN(){
	Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	if(SYM_COUR.CODE == NUM_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(MIN_ERR);
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	if(SYM_COUR.CODE == NUM_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(MIN_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
}


void MAX(){
	Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	if(SYM_COUR.CODE == NUM_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
	else ERREUR(MIN_ERR);
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	if(SYM_COUR.CODE == NUM_TOKEN || SYM_COUR.CODE == ID_TOKEN) Sym_Suiv();
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
		case NUM_TOKEN:
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

