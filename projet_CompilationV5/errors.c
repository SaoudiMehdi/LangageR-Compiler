#include "errors.h"

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

void compatibiliteError(){
		printf(" '%s' ERROR COMPATIBILITE at ligne %d",nom_symbol,numLigne);
		exit(0);
}