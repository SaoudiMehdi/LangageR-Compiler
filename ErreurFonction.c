void ERREUR(CODE_ERR error){
	switch(error){
		case IF_ERR:
			printf("IF_ERR\n");
			break;
		case ELSE_ERR:
			printf("ELSE_ERR\n");
			break;
		case WHILE_ERR:
			printf("WHILE_ERR\n");
			break;
		case REPEAT_ERR:
			printf("REPEAT_ERR\n");
			break;
		case FOR_ERR:
			printf("FOR_ERR\n");
			break;
		case WRITE_ERR:
			printf("WRITE_ERR\n");
			break;
		case CAT_ERR:
			printf("CAT_ERR\n");
			break;
		case IN_ERR:
			printf("IN_ERR\n");
			break;
		case BREAK_ERR:
			printf("BREAK_ERR\n");
			break;
		case IS_ERR:
			printf("IS_ERR\n");
			break;
		case AS_ERR:
			printf("AS_ERR\n");
			break;
		case CLS_ERR:
			printf("CLS_ERR\n");
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
		case MOINS_ERR:
			printf("MOINS_ERR\n");
			break;
		case MULT_ERR:
			printf("MULT_ERR\n");
			break;
		case DIV_ERR:
			printf("DIV_ERR\n");
			break;
		case VIR_ERR:
			printf("VIR_ERR\n");
			break;
		case AFF_ERR:
			printf("AFF_ERR\n");
			break;
		case INF_ERR:
			printf("INF_ERR\n");
			break;
		case INFG_ERR:
			printf("INFG_ERR\n");
			break;
		case SUP_ERR:
			printf("SUP_ERR\n");
			break;
		case SUPG_ERR:
			printf("SUPG_ERR\n");
			break;
		case EGAL_ERR:
			printf("EGAL_ERR\n");
			break;
		case DIFF_ERR:
			printf("DIFF_ERR\n");
			break;
		case PO_ERR:
			printf("PO_ERR\n");
			break;
		case PF_ERR:
			printf("PF_ERR\n");
			break;
		case ID_ERR:
			printf("ID_ERR\n");
			break;
		case NUM_ERR:
			printf("NUM_ERR\n");
			break;
		case ERREUR_ERR:
			printf("ERREUR_ERR\n");
			break;
		case COMM_ERR:
			printf("COMM_ERR\n");
			break;
		case AND_ERR:
			printf("AND_ERR\n");
			break;
		case OR_ERR:
			printf("OR_ERR\n");
			break;
		case NOT_ERR:
			printf("NOT_ERR\n");
			break;
		case RES_ERR:
			printf("RES_ERR\n");
			break;
		case DIVENT_ERR:
			printf("DIVENT_ERR\n");
			break;
		case POW_ERR:
			printf("POW_ERR\n");
			break;
		case ACCO_ERR:
			printf("ACCO_ERR\n");
			break;
		case ACCF_ERR:
			printf("ACCF_ERR\n");
			break;
		case SEQ_ERR:
			printf("SEQ_ERR\n");
			break;
		case EOF_ERR:
			printf("EOF_ERR\n");
			break;
		default:
			printf("ERREUR\n");
		
	}
	SYM_COUR.CODE==ERREUR_TOKEN;
	exit(0);
}