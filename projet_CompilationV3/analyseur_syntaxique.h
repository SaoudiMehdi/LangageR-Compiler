#ifndef ANALYSEUR_SYNTHAXIQUE_H
#define ANALYSEUR_SYNTHAXIQUE_H


#include "analyseur_lexical.h"
#include "table_symboles.h"

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
void GENERER1(MNEMONIQUES M);
void GENERER2(MNEMONIQUES M, int val);
void SaveInstToFile(INSTRUCTION INST);
void SavePCodeToFile();

#endif