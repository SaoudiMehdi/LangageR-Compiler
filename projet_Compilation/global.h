#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NbrIDF 100
#define TAILLECODE 100


typedef enum{
	IF_TOKEN,ELSE_TOKEN,WHILE_TOKEN,REPEAT_TOKEN,FOR_TOKEN,WRITE_TOKEN,CAT_TOKEN,MIN_TOKEN,MAX_TOKEN,IN_TOKEN,BREAK_TOKEN,IS_TOKEN,AS_TOKEN,
	CLS_TOKEN,PV_TOKEN,PT_TOKEN,PLUS_TOKEN,
	MOINS_TOKEN,MULT_TOKEN,DIV_TOKEN,VIR_TOKEN,AFFOP_TOKEN,AFFOP1_TOKEN,AFFOP2_TOKEN,
	INF_TOKEN,INFG_TOKEN,SUP_TOKEN,SUPG_TOKEN,EGAL_TOKEN,DIFF_TOKEN,
	PO_TOKEN,PF_TOKEN,ID_TOKEN,INT_TOKEN,FLOAT_TOKEN,ERREUR_TOKEN,COMM_TOKEN,AND_TOKEN,OR_TOKEN,NOT_TOKEN,RES_TOKEN,DIVENT_TOKEN,POW_TOKEN,ACCO_TOKEN,ACCF_TOKEN,SEQ_TOKEN,ENTRER_TOKEN,CHAINE_TOKEN,READ_TOKEN,EOF_TOKEN
}CODE_LEX;



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


boolean accPresence ;
TSYM TYPE_SYM_PREC_ID;
TSYM TYPE_SYM_PREC;
TSYM type_symbole;

T_Table_Symbole Table_Symbole[NbrIDF];
TSym_Cour SYM_PREC;
TSym_Cour SYM_PREC_ID;
TSym_Cour SYM;
boolean SAME_TYPE_EXPR ;

char nom_symbol2[30];
int indice ;
#endif