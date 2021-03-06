#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NbrIDF 100
#define NbrFNC 100
#define TAILLECODE 100


typedef enum{
	IF_TOKEN,ELSE_TOKEN,WHILE_TOKEN,REPEAT_TOKEN,FOR_TOKEN,WRITE_TOKEN,CAT_TOKEN,MIN_TOKEN,MAX_TOKEN,MEAN_TOKEN,IN_TOKEN,BREAK_TOKEN,IS_TOKEN,AS_TOKEN,
	CLS_TOKEN,PV_TOKEN,PT_TOKEN,PLUS_TOKEN,
	MOINS_TOKEN,MULT_TOKEN,DIV_TOKEN,VIR_TOKEN,AFFOP_TOKEN,AFFOP1_TOKEN,AFFOP2_TOKEN,
	INF_TOKEN,INFG_TOKEN,SUP_TOKEN,SUPG_TOKEN,EGAL_TOKEN,DIFF_TOKEN,
	PO_TOKEN,PF_TOKEN,ID_TOKEN,INT_TOKEN,FLOAT_TOKEN,ERREUR_TOKEN,COMM_TOKEN,AND_TOKEN,OR_TOKEN,NOT_TOKEN,RES_TOKEN,DIVENT_TOKEN,POW_TOKEN,ACCO_TOKEN,ACCF_TOKEN,SEQ_TOKEN,ENTRER_TOKEN,CHAINE_TOKEN,READ_TOKEN,FONCTION_TOKEN,EOF_TOKEN
}CODE_LEX;

//MNEMONIQUES
typedef enum {ADD, SUB, MUL, DIV, EQL, NEG, GTR, LES, GEQ, LEQ, PRN, INN, INT, LDI, LDA, LDV, STO, BRN, BZE, HLT} MNEMONIQUES;

//La structure INSTRUCTION qui sera utiliser pour le Génerateur de code
typedef struct {
    MNEMONIQUES MNE;
    int SUITE;
}INSTRUCTION;

//P-CODE
INSTRUCTION PCODE[TAILLECODE];

typedef struct {
	CODE_LEX CODE;
	char nom[20];
}TSym_Cour;

//Déclaration Variable Globale
TSym_Cour SYM_COUR;
char Car_Cour;
int numLigne ;
FILE* file;
int FLOAT ;
char nom_symbol[30];

typedef enum{
	TINT,TFLT,TCHR,TLST,TVCT
}TSYM;

typedef enum{
	OAFFEC,OLIRE,OALL
}OPTION;

//structure Table des Fonctions

typedef struct {
	char nom[20];
	int separateur;
	int nombreArgument;
	int INDICE_TOKEN;
}T_Table_Fonction;

//structure Table des Symboles

typedef struct {
	char nom[20];
	TSYM typeSymbole;
	int ADRESSE;
}T_Table_Symbole;

typedef enum{
	false,true
}boolean;


boolean accPresence ;
TSYM TYPE_SYM_PREC_ID;
TSYM TYPE_SYM_PREC;
TSYM type_symbole;

T_Table_Symbole Table_Symbole[NbrIDF];
T_Table_Fonction Table_Fonction[NbrFNC];
TSym_Cour SYM_PREC;
TSym_Cour SYM_PREC_ID;
TSym_Cour SYM;
boolean SAME_TYPE_EXPR ;
boolean oP;

char nom_symbol2[30];
int indice;
int indiceTableFonction;
int PC;
int OFFSET;
#endif