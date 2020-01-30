#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "AnalyseurLexicalv1.c"
#define NbrIDF 100
#define TAILLECODE 100

typedef enum{
	IF_ERR,ELSE_ERR,WHILE_ERR,REPEAT_ERR,FOR_ERR,WRITE_ERR,CAT_ERR,IN_ERR,BREAK_ERR,IS_ERR,AS_ERR,
	CLS_ERR,PV_ERR,PT_ERR,PLUS_ERR,
	MOINS_ERR,MULT_ERR,DIV_ERR,VIR_ERR,AFF_ERR,
	INF_ERR,INFG_ERR,SUP_ERR,SUPG_ERR,EGAL_ERR,DIFF_ERR,
	PO_ERR,PF_ERR,ID_ERR,NUM_ERR,ERREUR_ERR,COMM_ERR,AND_ERR,OR_ERR,NOT_ERR,RES_ERR,DIVENT_ERR,POW_ERR,ACCO_ERR,ACCF_ERR,SEQ_ERR,ENTRER_ERR,READ_ERR,EOF_ERR

}CODE_ERR;

typedef enum{
	TCONST,TVAR,TPROG
}TSYM;

typedef enum{
	OAFFEC,OLIRE,OALL
}OPTION;

typedef enum{
	ADD,SUB,MUL,DIV,EQL,
	NEQ,GTR,LSS,GEQ,LEQ, PRN,
	INN,INT,LDI,LDA,LDV,STO,BRN,
	BZE,HLT
}MNEMONIQUES;

//structure Table des Symboles

typedef struct {
	char nom[20];
	TSYM typeSymbole;
	int adresse;
}T_Table_Symbole;

//structure Instruction

typedef struct{
	MNEMONIQUES MNE;
	int SUITE;
}INSTRUCTION;

//declaration 
int progValide = 1;
T_Table_Symbole Table_Symbole[NbrIDF];
TSym_Cour SYM_PREC;
INSTRUCTION PCODE[TAILLECODE];
int pc = 0;
int OFFSET = -1;
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
void PREMIER_SYM();
int CHERCHER_SYM(char* nom,OPTION option);
void AJOUTER_SYM(char* nom,TSYM type);


//traitement 

int main(){
	Ouvrir_Fichier("test1.R");
	PREMIER_SYM();
	
	INSTS();
	
	if(SYM_COUR.CODE==EOF_TOKEN && progValide == 1)
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
			printf("IF_ERR\n"); progValide = 0;
			break;
		case ELSE_ERR:
			printf("ELSE_ERR\n"); progValide = 0;
			break;
		case WHILE_ERR:
			printf("WHILE_ERR\n"); progValide = 0;
			break;
		case REPEAT_ERR:
			printf("REPEAT_ERR\n"); progValide = 0;
			break;
		case FOR_ERR:
			printf("FOR_ERR\n"); progValide = 0;
			break;
		case WRITE_ERR:
			printf("WRITE_ERR\n"); progValide = 0;
			break;
		case CAT_ERR:
			printf("CAT_ERR\n"); progValide = 0;
			break;
		case IN_ERR:
			printf("IN_ERR\n"); progValide = 0;
			break;
		case BREAK_ERR:
			printf("BREAK_ERR\n"); progValide = 0;
			break;
		case IS_ERR:
			printf("IS_ERR\n"); progValide = 0;
			break;
		case AS_ERR:
			printf("AS_ERR\n"); progValide = 0;
			break;
		case CLS_ERR:
			printf("CLS_ERR\n"); progValide = 0;
			break;
		case PV_ERR:
			printf("PV_ERR\n"); progValide = 0;
			break;
		case PT_ERR:
			printf("PT_ERR\n"); progValide = 0;
			break;
		case PLUS_ERR:
			printf("PLUS_ERR\n"); progValide = 0;
			break;
		case MOINS_ERR:
			printf("MOINS_ERR\n"); progValide = 0;
			break;
		case MULT_ERR:
			printf("MULT_ERR\n"); progValide = 0;
			break;
		case DIV_ERR:
			printf("DIV_ERR\n"); progValide = 0;
			break;
		case VIR_ERR:
			printf("VIR_ERR\n"); progValide = 0;
			break;
		case AFF_ERR:
			printf("AFF_ERR\n"); progValide = 0;
			break;
		case INF_ERR:
			printf("INF_ERR\n"); progValide = 0;
			break;
		case INFG_ERR:
			printf("INFG_ERR\n"); progValide = 0;
			break;
		case SUP_ERR:
			printf("SUP_ERR\n"); progValide = 0;
			break;
		case SUPG_ERR:
			printf("SUPG_ERR\n"); progValide = 0;
			break;
		case EGAL_ERR:
			printf("EGAL_ERR\n"); progValide = 0;
			break;
		case DIFF_ERR:
			printf("DIFF_ERR\n"); progValide = 0;
			break;
		case PO_ERR:
			printf("PO_ERR\n"); progValide = 0;
			break;
		case PF_ERR:
			printf("PF_ERR\n"); progValide = 0;
			break;
		case ID_ERR:
			printf("ID_ERR\n"); progValide = 0;
			break;
		case NUM_ERR:
			printf("NUM_ERR\n"); progValide = 0;
			break;
		case ERREUR_ERR:
			printf("ERREUR_ERR\n"); progValide = 0;
			break;
		case COMM_ERR:
			printf("COMM_ERR\n"); progValide = 0;
			break;
		case AND_ERR:
			printf("AND_ERR\n"); progValide = 0;
			break;
		case OR_ERR:
			printf("OR_ERR\n"); progValide = 0;
			break;
		case NOT_ERR:
			printf("NOT_ERR\n"); progValide = 0;
			break;
		case RES_ERR:
			printf("RES_ERR\n"); progValide = 0;
			break;
		case DIVENT_ERR:
			printf("DIVENT_ERR\n"); progValide = 0;
			break;
		case POW_ERR:
			printf("POW_ERR\n"); progValide = 0;
			break;
		case ACCO_ERR:
			printf("ACCO_ERR\n"); progValide = 0;
			break;
		case ACCF_ERR:
			printf("ACCF_ERR\n"); progValide = 0;
			break;
		case SEQ_ERR:
			printf("SEQ_ERR\n"); progValide = 0;
			break;
		case EOF_ERR:
			printf("EOF_ERR\n"); progValide = 0;
			break;
		default:
			printf("ERREUR\n");
		
	}
	SYM_COUR.CODE==ERREUR_TOKEN;
	//exit(0);
}

/*void PROGRAM(){
	Test_Symbole(PROGRAM_TOKEN,PROGRAM_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	AJOUTER_SYM(SYM_PREC.nom,TPROG);
	Test_Symbole(PV_TOKEN,PV_ERR);
	BLOCK();
	Test_Symbole(PT_TOKEN,PT_ERR);
}

void BLOCK(){
	CONSTS();
	VARS();
	INSTS();
}

void CONSTS(){
	switch(SYM_COUR.CODE){
		case CONST_TOKEN:
			Sym_Suiv();
			Test_Symbole(ID_TOKEN,ID_ERR);
			AJOUTER_SYM(SYM_PREC.nom,TCONST);
			Test_Symbole(EGAL_TOKEN,EGAL_ERR);
			Test_Symbole(NUM_TOKEN,NUM_ERR);
			Test_Symbole(PV_TOKEN,PV_ERR);
			while(SYM_COUR.CODE==ID_TOKEN){
				AJOUTER_SYM(SYM_COUR.nom,TCONST);
				Sym_Suiv();
				Test_Symbole(EGAL_TOKEN,EGAL_ERR);
				Test_Symbole(NUM_TOKEN,NUM_ERR);
				Test_Symbole(PV_TOKEN,PV_TOKEN);
			}
			break;
		case VAR_TOKEN:
			break;
		case BEGIN_TOKEN:
			break;
		default:
			printf("default");
	}
}

void VARS(){
	switch(SYM_COUR.CODE){
		case VAR_TOKEN:
			Sym_Suiv();
			Test_Symbole(ID_TOKEN,ID_ERR);
			AJOUTER_SYM(SYM_PREC.nom,TVAR);
			while(SYM_COUR.CODE==VIR_TOKEN){
				Sym_Suiv();
				Test_Symbole(ID_TOKEN,ID_ERR);
				AJOUTER_SYM(SYM_PREC.nom,TVAR);
			}
			Test_Symbole(PV_TOKEN,PV_ERR);
			break;
		case CONST_TOKEN:
			break;
		case BEGIN_TOKEN:
			break;
	}
}
*/
void INSTS(){
	INST();
	while(SYM_COUR.CODE==PV_TOKEN||SYM_COUR.CODE==ENTRER_TOKEN || SYM_COUR.CODE==COMM_TOKEN){
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
		case ENTRER_TOKEN:
			break;
		case COMM_TOKEN:
			break;
		case PV_TOKEN:
			break;
		case ACCF_TOKEN:
			break;
		case BREAK_TOKEN:
			Sym_Suiv();
			break;
		case EOF_TOKEN:
			break;
		default:
			ERREUR(ERREUR_ERR);
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
		if(SYM_COUR.CODE==ID_TOKEN || SYM_COUR.CODE==NUM_TOKEN) Sym_Suiv();
		else Test_Symbole(AFFOP_TOKEN,AFF_ERR);
		
	}else{
		Test_Symbole(AFFOP2_TOKEN,AFF_ERR);
		EXPR();
	}

}

void AFFEC2(){
	EXPR();
	Test_Symbole(AFFOP2_TOKEN,AFF_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
}

void SI(){
	Test_Symbole(IF_TOKEN,IF_ERR);
	COND();
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			Sym_Suiv();
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			break;
		case BREAK_TOKEN: 
			break;
		case ENTRER_TOKEN:
			Sym_Suiv();
			break;
		default:
			printf("%s*/*/*/*/*/*/",SYM_COUR.nom);
			INST();
			break;
	}
	switch(SYM_COUR.CODE){
		case ELSE_TOKEN:
			switch(SYM_COUR.CODE){
				case ACCO_TOKEN:
					INSTS();
					Test_Symbole(ACCF_TOKEN,ACCF_ERR);
					break;
				case ENTRER_TOKEN:
					Sym_Suiv();
					break;
				default:
					INST();
					break;
			}
			break;
		case BREAK_TOKEN:
			break;
		case ENTRER_TOKEN:
			Sym_Suiv();
			break;
		default:
			break;
	}
}

void TANTQUE(){
	Test_Symbole(WHILE_TOKEN,WHILE_ERR);
	COND();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
			break;
		default:
			INST();
			break;
	}
}

void REPETER(){
	int acc_break = 0;
	Test_Symbole(REPEAT_TOKEN,REPEAT_ERR);
	Test_Symbole(ACCO_TOKEN,ACCO_ERR);
	INSTS();
	/*if(SYM_COUR.CODE == ACCO_TOKEN){
		Sym_Suiv();
		acc_break=1;
	}
	Test_Symbole(BREAK_TOKEN,BREAK_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	if(SYM_COUR.CODE == PV_TOKEN) Sym_Suiv();
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	if(acc_break==1){
		Test_Symbole(ACCF_TOKEN,ACCF_ERR);
		acc_break=0;
	}
	if(SYM_COUR.CODE!=ACCF_TOKEN) INSTS();*/
	Test_Symbole(ACCF_TOKEN,ACCF_ERR);
}

void POUR(){
	Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	Test_Symbole(IN_TOKEN,IN_ERR);
	Test_Symbole(NUM_TOKEN,NUM_ERR);
	Test_Symbole(SEQ_TOKEN,SEQ_ERR);
	Test_Symbole(NUM_TOKEN,NUM_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	switch(SYM_COUR.CODE){
		case ACCO_TOKEN:
			Test_Symbole(ACCO_TOKEN,ACCO_ERR);
			INSTS();
			Test_Symbole(ACCF_TOKEN,ACCF_ERR);
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
	Test_Symbole(ID_TOKEN,ID_ERR);
	CHERCHER_SYM(SYM_PREC.nom,OLIRE);
	while(SYM_COUR.CODE==VIR_TOKEN){
		Sym_Suiv();
		Test_Symbole(ID_TOKEN,ID_ERR);
		CHERCHER_SYM(SYM_PREC.nom,OLIRE);
	}
	Test_Symbole(PF_TOKEN,PF_ERR);
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
			switch(SYM_COUR.CODE){
				case EGAL_TOKEN:
					Sym_Suiv();
					break;
				case DIFF_TOKEN:
					Sym_Suiv();
					break;
				case INF_TOKEN:
					Sym_Suiv();
					break;
				case SUP_TOKEN:
					Sym_Suiv();
					break;
				case INFG_TOKEN:
					Sym_Suiv();
					break;
				case SUPG_TOKEN:
					Sym_Suiv();
					break;
				case PF_TOKEN:
					break;
			}
			if(SYM_COUR.CODE != PF_TOKEN){
				EXPR();
				Test_Symbole(PF_TOKEN,PF_ERR);
			}
			break;
	}
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
	while(SYM_COUR.CODE==MULT_TOKEN||SYM_COUR.CODE==DIV_TOKEN){
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
	}
}

void PREMIER_SYM(){
	Lire_Car();
	Sym_Suiv();
}

int CHERCHER_SYM(char* nom,OPTION option){
	for(int i=0;i<indice;i++){
		if(!strcmp(Table_Symbole[i].nom,nom)){
			if(Table_Symbole[i].typeSymbole == TPROG){
				printf("ID PROGRAM ERREUR\n");
				exit(0);
			}
			switch(option){
				case OAFFEC :
					if(Table_Symbole[i].typeSymbole == TCONST){
						printf("ID CONST ERREUR\n");
						exit(0);
					}
					return 1;
				case OLIRE :
					if(Table_Symbole[i].typeSymbole == TCONST){
						printf("ID CONST ERREUR\n");
						exit(0);
					}
					return 1;
				case OALL :
					printf("DOUBLE DECLARATION\n");
					exit(0);
			}
		}
	}
	if(option!=OALL){
		printf("UNDECLARED\n");
		exit(0);
	}
	return 1;
}

void AJOUTER_SYM(char* nom,TSYM type){
	if(CHERCHER_SYM(nom,OALL)){
		strcpy(Table_Symbole[indice].nom, nom);
		Table_Symbole[indice].typeSymbole = type;
		indice++;
	}
}

/*void GENERER1(MNEMONIQUES MNE){
	if(pc == TAILLECODE){
		ERREUR("erreur");
		exit(0);
	}
	pc++;
	PCODE[pc].MNE = MNE;
}

void GENERER2(MNEMONIQUES MNE,int A){
	if(pc == TAILLECODE){
		ERREUR("erreur");
		exit(0);
	}
	pc++;
	PCODE[pc].MNE = MNE;
	PCODE[pc].SUITE = A;
}*/




