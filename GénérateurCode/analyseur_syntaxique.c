#include "analyseur_syntaxique.h"
#include "errors.h"

//FILE *FICH_SORTIE;
//FICH_SORTIE = fopen("C:\\fichierSortie.op", "w+" );

void SavePCodeToFile() {
	int i;
	for (i=0; i<=PC; i++) {
		SaveInstToFile(PCODE[i]);
	}
}
//Fclose(FICH_SORTIE);

void Test_Symbole(CODE_LEX code,CODE_ERR error){
	if(SYM_COUR.CODE==code){
		SYM_PREC.CODE = SYM_COUR.CODE;
		strcpy(SYM_PREC.nom,SYM_COUR.nom);
		SYM_PREC.VAL_INT_FLOAT = SYM_COUR.VAL_INT_FLOAT; 
		//strcpy(SYM_PREC.VAL_CHAR,SYM_COUR.VAL_CHAR);
		Sym_Suiv();
	}else{
		ERREUR(error);
	}
}

void PROG(){
	Num_Var = 0;
	GENERER2(INT, Num_Var);
	INSTS();
	GENERER3(Num_Var, 0);
	GENERER1(HLT);
	SavePCodeToFile();
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
		case CHAINE_TOKEN:
			AFFEC3();
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
	Test_Symbole(ID_TOKEN,ID_ERR);
	strcpy(nom_symbol2,nom_symbol);
	if(SYM_COUR.CODE==AFFOP1_TOKEN){
		int t = CHERCHER_SYM(nom_symbol2,OAFFEC);
		Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
		Test_Symbole(ID_TOKEN,ID_ERR);
		AJOUTER_SYM(nom_symbol,t);
	}else if(SYM_COUR.CODE==AFFOP_TOKEN){
		AJOUTER_SYM(nom_symbol2, -1);
		if(Table_Symbole[INDEX_SYM(nom_symbol2)].ADRESSE == -1){
			Table_Symbole[INDEX_SYM(nom_symbol2)].ADRESSE = ++OFFSET;
			Num_Var++;
		}
		GENERER2(LDA, Table_Symbole[INDEX_SYM(nom_symbol2)].ADRESSE);
		Test_Symbole(AFFOP_TOKEN,AFF_ERR);
		switch(SYM_COUR.CODE){
			case READ_TOKEN:
				LIRE();
				GENERER1(INN);
				break;
			case MIN_TOKEN:
				MIN();
				GENERER1(STO);
				break;
			case MAX_TOKEN:
				MAX();
				GENERER1(STO);
				break;
			default:
				if(SYM_COUR.CODE!=CHAINE_TOKEN) {
					EXPR();
					GENERER1(STO);
				} 
				else{
					Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);
					//GENERER2(LDI, SYM_PREC.VAL_CHAR);
					GENERER1(STO);
					AJOUTER_SYM(nom_symbol2,TCHR);
				}
				break;
		}
	}else if(SYM_COUR.CODE==AFFOP2_TOKEN){
		AJOUTER_SYM(nom_symbol2, -1);
		if(Table_Symbole[INDEX_SYM(nom_symbol2)].ADRESSE == -1){
			Table_Symbole[INDEX_SYM(nom_symbol2)].ADRESSE = ++OFFSET;
			Num_Var++;
		}
		GENERER2(LDA, Table_Symbole[INDEX_SYM(nom_symbol2)].ADRESSE);
		Test_Symbole(AFFOP2_TOKEN,AFF_ERR);
		switch(SYM_COUR.CODE){
			case READ_TOKEN:
				LIRE();
				GENERER1(INN);
				break;
			case MIN_TOKEN:
				MIN();
				GENERER1(STO);
				break;
			case MAX_TOKEN:
				MAX();
				GENERER1(STO);
				break;
			default:
				if(SYM_COUR.CODE!=CHAINE_TOKEN) {
					EXPR();
					GENERER1(STO);
				}
				else{
					Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);
					GENERER1(STO);
					AJOUTER_SYM(nom_symbol2,TCHR);
				}
				break;
		}
	}else{
		int t1 = CHERCHER_SYM(nom_symbol2,OAFFEC);
		GENERER2(LDA, Table_Symbole[INDEX_SYM(SYM_PREC.nom)].ADRESSE);
		GENERER1(LDV);
		ECRIRE2();
		int t2 = CHERCHER_SYM(nom_symbol2,OAFFEC);
		switch(SYM_COUR.CODE){
			case AFFOP1_TOKEN: 
				Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
				Test_Symbole(ID_TOKEN,ID_ERR);
				AJOUTER_SYM(nom_symbol,t2);
				AJOUTER_SYM(nom_symbol2,t1);
				break;
			case ENTRER_TOKEN:
			case PV_TOKEN:
				GENERER1(PRN);
				break;	
			default: 
				ERREUR(WRITE_ERR);
		}

	}
	
}

void AFFEC2(){
	int t1 = CHERCHER_SYM(nom_symbol2,OAFFEC);
	EXPR();
	Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	AJOUTER_SYM(nom_symbol,type_symbole);
	AJOUTER_SYM(nom_symbol2,t1);
}

void AFFEC3(){
	Test_Symbole(CHAINE_TOKEN,CHAINE_ERR);
	Test_Symbole(AFFOP1_TOKEN,AFF_ERR);
	Test_Symbole(ID_TOKEN,ID_ERR);
	AJOUTER_SYM(nom_symbol,TCHR);
}

void SI(){
	Test_Symbole(IF_TOKEN,IF_ERR);
	COND();
	GENERER1(BZE);
	int _PC = PC;
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
	int BRANCHEMENT = PC - _PC;
	GENERER3(BRANCHEMENT, _PC);
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
					if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=ACCF_TOKEN  && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
					break;
				default:
					INST();
					break;
			}
			break;
		default:
			INST();
			break;
	}
}

void COND(){
	Test_Symbole(PO_TOKEN,PO_ERR);
	MNEMONIQUES RELOP1;
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
			SYM_COUR.CODE == INFG_TOKEN ||SYM_COUR.CODE == SUPG_TOKEN ) {
				RELOP1 = MNE_OP(SYM_COUR);
				Sym_Suiv();
			} 
			else if (SYM_COUR.CODE == PF_TOKEN){
				Sym_Suiv();
				break;
			}else{
				ERREUR(PF_ERR);
			}
			if(SYM_COUR.CODE != PF_TOKEN){
				EXPR();
				GENERER1(RELOP1);
				Test_Symbole(PF_TOKEN,PF_ERR);
			}
			else {
				ERREUR(PF_ERR);
			}
			break;
	}
}

void TANTQUE(){
	Test_Symbole(WHILE_TOKEN,WHILE_ERR);
	int LABEL_BRN = PC + 1;
	COND();
	GENERER1(BZE);
	int INDICE_BZE = PC;
	while(SYM_COUR.CODE==ENTRER_TOKEN) Sym_Suiv();
		switch(SYM_COUR.CODE){
			case ACCO_TOKEN:
				accPresence= true;
				Sym_Suiv();
				INSTS();
				Test_Symbole(ACCF_TOKEN,ACCF_ERR);
				accPresence= false;
				if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=ACCF_TOKEN && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
				break;
			default:
				INST();
				break;
	}
	GENERER3(PC - INDICE_BZE + 1, INDICE_BZE);
	GENERER2(BRN, LABEL_BRN);
}


void REPETER(){
	Test_Symbole(REPEAT_TOKEN,REPEAT_ERR);
	while(SYM_COUR.CODE == ENTRER_TOKEN) Sym_Suiv();
	Test_Symbole(ACCO_TOKEN,ACCO_ERR);
	accPresence= true;
	INSTS();
	Test_Symbole(ACCF_TOKEN,ACCF_ERR);
	accPresence= false;
	if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=ACCF_TOKEN  && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);

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
			if(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=ACCF_TOKEN  && SYM_COUR.CODE!=EOF_TOKEN) ERREUR(ENTRER_ERR);
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
	GENERER1(PRN);
	Test_Symbole(PF_TOKEN,PF_ERR);
}

void LIRE(){
	Test_Symbole(READ_TOKEN,READ_ERR);
	Test_Symbole(PO_TOKEN,PO_ERR);
	Test_Symbole(PF_TOKEN,PF_ERR);
}



void EXPR(){
	TSym_Cour OPER;
	type_symbole = -1;
	TERM();
	TYPE_SYM_PREC = TYPE_SYM_PREC_ID;
	while(SYM_COUR.CODE==PLUS_TOKEN||SYM_COUR.CODE==MOINS_TOKEN){
		OPER = SYM_COUR;
		if(oP == false) oP = true;
		Sym_Suiv();
		TERM();
		GENERER1(MNE_OP(OPER));
	}
	TYPE_SYM_PREC = -1;
	oP = false;
}

void TERM(){
	TSym_Cour OPER;
	FACT();
	TYPE_SYM_PREC = TYPE_SYM_PREC_ID;
	while(SYM_COUR.CODE==MULT_TOKEN||SYM_COUR.CODE==DIV_TOKEN || SYM_COUR.CODE==DIVENT_TOKEN || SYM_COUR.CODE==RES_TOKEN){
		OPER = SYM_COUR;
		if(oP == false) oP = true;
		Sym_Suiv();
		FACT();
		GENERER1(MNE_OP(OPER));
	}
}

void FACT(){
	if(TYPE_SYM_PREC == TCHR && TYPE_SYM_PREC != TYPE_SYM_PREC_ID){
		compatibiliteError();
	}
	switch(SYM_COUR.CODE){
		case ID_TOKEN:
			Test_Symbole(ID_TOKEN,ID_ERR);
			printf("%s\n",nom_symbol);
			printf("%s\n",nom_symbol2);
			int r = CHERCHER_SYM(nom_symbol,OAFFEC);
			GENERER2(LDA, Table_Symbole[INDEX_SYM(SYM_PREC.nom)].ADRESSE);
			GENERER1(LDV);
			if (r != -1)
			{
				if (r == TFLT) {
					AJOUTER_SYM(nom_symbol2,TFLT);
					TYPE_SYM_PREC = TFLT;
				}
				else if(oP == true){
					if(r < 2)
						AJOUTER_SYM(nom_symbol2, r); 
					else{
						compatibiliteError();
					}
				} 
			}
			else {
				printf(" '%s' UNDECLARED at ligne %d\n", nom_symbol, numLigne);
				exit(0);
			}
			break;
		
		case INT_TOKEN:
			if(oP == true && CHERCHER_SYM(nom_symbol2,OALL) > 1) compatibiliteError();
			if(type_symbole != TFLT) type_symbole = TINT;
			Test_Symbole(INT_TOKEN,NUM_ERR);
			GENERER2(LDI, SYM_PREC.VAL_INT_FLOAT);
			AJOUTER_SYM(nom_symbol2,(CHERCHER_SYM(nom_symbol2,OALL)==TFLT)? TFLT : TINT);
			break;
		case FLOAT_TOKEN:
			if(oP == true && CHERCHER_SYM(nom_symbol2,OALL) > 1) compatibiliteError();
			type_symbole = TFLT;
			Test_Symbole(FLOAT_TOKEN,NUM_ERR);
			GENERER2(LDI, SYM_PREC.VAL_INT_FLOAT);
			AJOUTER_SYM(nom_symbol2,type_symbole);
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
		case CHAINE_TOKEN:
			Sym_Suiv();
			break;
		default:
			ERREUR(ERREUR_ERR);
			break;
	}
}

void PREMIER_SYM(){
	PC = -1;
	OFFSET = -1;
    numLigne = 1;
    FLOAT = 0;
    accPresence = false;
    SAME_TYPE_EXPR = true;
    indice = 0;
	oP = false;
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
	switch(SYM_COUR.CODE){
		case INT_TOKEN:
			AJOUTER_SYM(nom_symbol2,TINT);
			Sym_Suiv();
			break;
		case FLOAT_TOKEN:
			AJOUTER_SYM(nom_symbol2,TFLT);
			Sym_Suiv();
			break;
		case ID_TOKEN:
			AJOUTER_SYM(nom_symbol2,CHERCHER_SYM(nom_symbol,OAFFEC));
			Sym_Suiv();
			break;
		case CHAINE_TOKEN:
			AJOUTER_SYM(nom_symbol2,TCHR);
			Sym_Suiv();
			break;
		default:
			ERREUR(MIN_ERR);
			break;
	}
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	int typePrec = CHERCHER_SYM(nom_symbol2,OAFFEC);
	switch(SYM_COUR.CODE){
		case INT_TOKEN:
			if(typePrec != 2) AJOUTER_SYM(nom_symbol2,TINT);
			Sym_Suiv();
			break;
		case FLOAT_TOKEN:
			if(typePrec == 1)AJOUTER_SYM(nom_symbol2,TFLT);
			Sym_Suiv();
			break;
		case ID_TOKEN:
			if(typePrec != 2 && (CHERCHER_SYM(nom_symbol,OAFFEC) == 2 || CHERCHER_SYM(nom_symbol,OAFFEC) ==1) ) AJOUTER_SYM(nom_symbol2,CHERCHER_SYM(nom_symbol,OAFFEC));
			Sym_Suiv();
			break;
		case CHAINE_TOKEN:
			AJOUTER_SYM(nom_symbol2,TCHR);
			Sym_Suiv();
			break;
		default:
			ERREUR(MIN_ERR);
			break;
	}
	Test_Symbole(PF_TOKEN,PF_ERR);
}


void MAX(){
	Sym_Suiv();
	Test_Symbole(PO_TOKEN,PO_ERR);
	switch(SYM_COUR.CODE){
		case INT_TOKEN:
			AJOUTER_SYM(nom_symbol2,TINT);
			Sym_Suiv();
			break;
		case FLOAT_TOKEN:
			AJOUTER_SYM(nom_symbol2,TFLT);
			Sym_Suiv();
			break;
		case ID_TOKEN:
			AJOUTER_SYM(nom_symbol2,CHERCHER_SYM(nom_symbol,OAFFEC));
			Sym_Suiv();
			break;
		case CHAINE_TOKEN:
			AJOUTER_SYM(nom_symbol2,TCHR);
			Sym_Suiv();
			break;
		default:
			ERREUR(MAX_ERR);
			break;
	}
	Test_Symbole(VIR_TOKEN,VIR_ERR);
	int typePrec = CHERCHER_SYM(nom_symbol2,OAFFEC);
	switch(SYM_COUR.CODE){
		case INT_TOKEN:
			if(typePrec != 2) AJOUTER_SYM(nom_symbol2,TINT);
			Sym_Suiv();
			break;
		case FLOAT_TOKEN:
			if(typePrec == 1)AJOUTER_SYM(nom_symbol2,TFLT);
			Sym_Suiv();
			break;
		case ID_TOKEN:
			if(typePrec != 2 && (CHERCHER_SYM(nom_symbol,OAFFEC) == 2 || CHERCHER_SYM(nom_symbol,OAFFEC) ==1) ) AJOUTER_SYM(nom_symbol2,CHERCHER_SYM(nom_symbol,OAFFEC));
			Sym_Suiv();
			break;
		case CHAINE_TOKEN:
			AJOUTER_SYM(nom_symbol2,TCHR);
			Sym_Suiv();
			break;
		default:
			ERREUR(MAX_ERR);
			break;
	}
	Test_Symbole(PF_TOKEN,PF_ERR);
}

void ECRIRE2(){
	while(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=PV_TOKEN && SYM_COUR.CODE != AFFOP1_TOKEN){
		MNEMONIQUES RELOP1;
		if(SYM_COUR.CODE == PLUS_TOKEN || SYM_COUR.CODE == MOINS_TOKEN || SYM_COUR.CODE == MULT_TOKEN ||
		SYM_COUR.CODE == DIV_TOKEN || SYM_COUR.CODE == DIVENT_TOKEN) {
			RELOP1 = MNE_OP(SYM_COUR);
			if(SYM_COUR.CODE == PLUS_TOKEN || SYM_COUR.CODE == MOINS_TOKEN){
				Sym_Suiv();
				TERM();
			}
			else {
				Sym_Suiv();
				FACT();
			}
			GENERER1(RELOP1);
		}
	}
}

/*void ECRIRE2(){
	int operationSYM = 0;
	while(SYM_COUR.CODE!=ENTRER_TOKEN && SYM_COUR.CODE!=PV_TOKEN && SYM_COUR.CODE != AFFOP1_TOKEN){
		MNEMONIQUES RELOP;
		switch(SYM_COUR.CODE){
			case PLUS_TOKEN:
			case MOINS_TOKEN:
			case MULT_TOKEN:
			case DIV_TOKEN:
			case DIVENT_TOKEN:
				operationSYM++;
				Sym_Suiv();
				break;
			case RES_TOKEN:
				operationSYM++;
				Sym_Suiv();
				break;
			case ID_TOKEN:
				CHERCHER_SYM(nom_symbol);
				GENERER2(LDA, Table_Symbole[INDEX_SYM(SYM_COUR.nom)].ADRESSE);
				GENERER1(LDV);
				operationSYM--;
				Sym_Suiv();
				break;
			case INT_TOKEN:
				operationSYM--;
				GENERER2(LDI, SYM_COUR.VAL_INT_FLOAT);
				Sym_Suiv();
				break;
			case FLOAT_TOKEN:
				//AJOUTER_SYM(nom_symbol2,TFLT);
				GENERER2(LDI, SYM_COUR.VAL_INT_FLOAT);
				operationSYM--;
				Sym_Suiv();
				break;
			case PO_TOKEN:
				RELOP = MNE_OP(SYM_PREC);
				EXPR();
				GENERER1(RELOP);
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
	if(operationSYM>=1 || operationSYM<0) ERREUR(WRITE_ERR);
}*/

void GENERER1(MNEMONIQUES M) {
	PC++;
	if(PC == TAILLECODE) {
		printf("Max de taille du code\n");
		exit(0);
	}
	PCODE[PC].MNE = M;
}

void GENERER2(MNEMONIQUES M, int val) {
	PC++;
	if(PC == TAILLECODE) {
		printf("Max de taille du code\n");
		exit(0);
	}
	PCODE[PC].MNE = M;
	PCODE[PC].SUITE = val;
}

void GENERER3(int val, int _PC){
	PCODE[_PC].SUITE = val;
}

MNEMONIQUES MNE_OP(TSym_Cour OP){
    int classe = OP.CODE;
    switch(classe){
        case PLUS_TOKEN :
            return ADD;
        case MOINS_TOKEN :
            return SUB;  
        case MULT_TOKEN :
            return MUL;
        case DIV_TOKEN :
            return DIV; 
		case DIVENT_TOKEN :
            return DIV; 	
		case EGAL_TOKEN :
			return EQL;
		case DIFF_TOKEN :
			return NEQ;	
		case INF_TOKEN :
			return LES;
		case SUP_TOKEN :
			return GTR;
		case INFG_TOKEN :
			return LEQ;
		case SUPG_TOKEN : 
			return GEQ;				
    }
}

void SaveInstToFile(INSTRUCTION INST)
	{
	switch( INST.MNE){
		case LDA: printf("%s \t %d \n", "LDA", INST.SUITE); break;
		case LDI: printf("%s \t %d \n", "LDI", INST.SUITE); break;
		case INT: printf("%s \t %d \n", "INT", INST.SUITE); break;
		case BZE: printf("%s \t %d \n", "BZE", INST.SUITE); break;
		case BRN: printf("%s \t %d \n", "BRN", INST.SUITE); break;
		case LDV: printf("%s \n", "LDV"); break;
		case ADD: printf("%s \n", "ADD"); break;
		case SUB: printf("%s \n", "SUB"); break;
		case MUL: printf("%s \n", "MUL"); break;
		case DIV: printf("%s \n", "DIV"); break;
		case LEQ: printf("%s \n", "LEQ"); break;
		case GEQ: printf("%s \n", "GEQ"); break;
		case GTR: printf("%s \n", "GTR"); break;
		case HLT: printf("%s \n", "HLT"); break;
		case STO: printf("%s \n", "STO"); break;
		case INN: printf("%s \n", "INN"); break;
		case PRN: printf("%s \n", "PRN"); break;
		case LES: printf("%s \n", "LES"); break;
		case EQL: printf("%s \n", "EQL"); break;
		case NEQ: printf("%s \n", "NEQ"); break;

	}
}