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
	PO_ERR,PF_ERR,ID_ERR,NUM_ERR,ERREUR_ERR,COMM_ERR,AND_ERR,OR_ERR,NOT_ERR,RES_ERR,DIVENT_ERR,POW_ERR,ACCO_ERR,ACCF_ERR,SEQ_ERR,ENTRER_ERR,EOF_ERR

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
void REPEAT();
void FOR();
void PREMIER_SYM();
int CHERCHER_SYM(char* nom,OPTION option);
void AJOUTER_SYM(char* nom,TSYM type);


//traitement 
/*
int main(){
	Ouvrir_Fichier("Pascal.p");
	PREMIER_SYM();
	
	PROGRAM();
	
	if(SYM_COUR.CODE==EOF_TOKEN)
		printf("BRAVO: le programme est correcte!!!");
	else
		printf("PAS BRAVO: fin de programme erronee!!!!");
	
	return 1;
}
*/

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
		case PROGRAM_ERR:
			printf("PROGRAM_ERR\n");
			break;
		case CONST_ERR:
			printf("const_err\n");
			break;
		case VAR_ERR:
			printf("var_err\n");
			break;
		case BEGIN_ERR:
			printf("BEGIN_ERR\n");
			break;
		case END_ERR:
			printf("END_ERR\n");
			break;
		case IF_ERR:
			printf("IF_ERR\n");
			break;
		case ID_ERR:
			printf("ID_ERR\n");
			break;
		case PF_ERR:
			printf("PF_ERR\n");
			break;
		case PV_ERR:
			printf("PV_ERR\n");
			break;
		case PT_ERR:
			printf("PT_ERR\n");
			break;
		case PLUS_ERR:
			printf("PLUS_ERR\n");
			break;
		case PO_ERR:
			printf("PO_ERR\n");
			break;
		case EGAL_ERR:
			printf("EGAL_ERR\n");
			break;
		case AFF_ERR:
			printf("AFF_ERR\n");
			break;
		case SUP_ERR:
			printf("SUP_ERR\n");
			break;
		case SUPG_ERR:
			printf("SUPG_ERR\n");
			break;
		case INF_ERR:
			printf("INF_ERR\n");
			break;
		case INFG_ERR:
			printf("INFG_ERR\n");
			break;
		case DIFF_ERR:
			printf("DIFF_ERR\n");
			break;
		case MOINS_ERR:
			printf("MOINS_ERR\n");
			break;
		case MULT_ERR:
			printf("MULT_ERR\n");
			break;
		case WRITE_ERR:
			printf("WRITE_ERR\n");
			break;
		case WHILE_ERR:
			printf("WHILE_ERR\n");
			break;
		case THEN_ERR:
			printf("THEN_ERR\n");
			break;
		case READ_ERR:
			printf("READ_ERR\n");
			break;
		case DO_ERR:
			printf("DO_ERR\n");
			break;
		case DIV_ERR:
			printf("DIV_ERR\n");
			break;
		case VIR_ERR:
			printf("VIR_ERR\n");
			break;
		default:
			printf("ERREUR\n");
		
	}
	SYM_COUR.CODE==ERREUR_TOKEN;
	exit(0);
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
	while(SYM_COUR.CODE==PV_TOKEN||SYM_COUR.CODE==ENTRER_TOKEN){
		Sym_Suiv();
		INST();
	}
	Test_Symbole(EOF_TOKEN,EOF_ERR);
}

void INST(){
	switch(SYM_COUR.CODE){
		case ID_TOKEN:
			AFFEC();
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
		default:
			ERREUR(ERREUR_ERR);
	}
}

void AFFEC1(){
	//CHERCHER_SYM(SYM_COUR.nom,OAFFEC);
	Sym_Suiv();
	Test_Symbole(AFF_TOKEN,AFF_ERR);
	EXPR();
}

void AFFEC2(){
	EXPR();
	Test_Symbole(AFF_TOKEN,AFF_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
}

void SI(){
	Test_Symbole(IF_TOKEN,IF_ERR);
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
	switch(SYM_COUR.CODE){
		case ELSE_TOKEN:
			switch(SYM_COUR.CODE){
				case ACCO_TOKEN:
					INSTS();
					Test_Symbole(ACCF_TOKEN,ACCF_ERR);
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

void REPEAT(){
	Test_Symbole(ACCO_TOKEN,ACCO_ERR);
	INSTS();
	Test_Symbole(IF_TOKEN,IF_ERR);
	COND();
	Test_Symbole(BREAK_TOKEN,BREAK_ERR);
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

void GENERER1(MNEMONIQUES MNE){
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
}




