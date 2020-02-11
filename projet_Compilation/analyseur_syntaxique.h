#ifndef ANALYSEUR_SYNTHAXIQUE_H
#define ANALYSEUR_SYNTHAXIQUE_H


#include "analyseur_lexical.h"

//declaration 





void Test_Symbole(CODE_LEX code,CODE_ERR error);

void INSTS();
void INST();
void AFFEC1();
void AFFEC2();
void AFFEC3();
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
int INDEX_SYM(char* nom);
void AJOUTER_SYM(char* nom,TSYM type);

#endif