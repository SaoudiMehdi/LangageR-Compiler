#include "analyseur_lexical.h"

void Sym_Suiv(){
	while(CaractereVide(Car_Cour)){
		Lire_Car();
	}
	if((Car_Cour>='a' && Car_Cour<='z')||(Car_Cour>='A' && Car_Cour<='Z')){
		Lire_Mot();
	}else if(Car_Cour>='0' && Car_Cour<='9'){
		Lire_Nombre();
	}else if(Car_Cour=='#'){
		Lire_Commentaire();
	}else if(Car_Cour=='"'){
		Lire_Chaine();
	}else{
		switch(Car_Cour){
			case '+': 
				SYM_COUR.CODE=PLUS_TOKEN;
				strcpy(SYM_COUR.nom,"PLUS_TOKEN");
				Lire_Car();
				break;
			case '-': 
				SYM_COUR.CODE=MOINS_TOKEN;
				strcpy(SYM_COUR.nom,"MOINS_TOKEN");
				Lire_Car();
				if(Car_Cour=='>') {
					SYM_COUR.CODE=AFFOP1_TOKEN;
					strcpy(SYM_COUR.nom,"AFFOP1_TOKEN");
					Lire_Car();
					if(Car_Cour=='>') {
						Lire_Car();
					}
				}
				break;
			case '*': 
				SYM_COUR.CODE=MULT_TOKEN;
				strcpy(SYM_COUR.nom,"MULT_TOKEN");
				Lire_Car();
				break;
			case '/': 
				SYM_COUR.CODE=DIV_TOKEN;
				strcpy(SYM_COUR.nom,"DIV_TOKEN");
				Lire_Car();
				break;
			case '.': 
				SYM_COUR.CODE=PT_TOKEN;
				strcpy(SYM_COUR.nom,"PT_TOKEN");
				Lire_Car();
				if(Car_Cour>='0' && Car_Cour<='9'){
					FLOAT++;
					Lire_Nombre();
				}
				break;
			case ',': 
				SYM_COUR.CODE=VIR_TOKEN;
				strcpy(SYM_COUR.nom,"VIR_TOKEN");
				Lire_Car();
				break;
			case ';': 
				SYM_COUR.CODE=PV_TOKEN;
				strcpy(SYM_COUR.nom,"PV_TOKEN");
				Lire_Car();
				break;
			case '(': 
				SYM_COUR.CODE=PO_TOKEN;
				strcpy(SYM_COUR.nom,"PO_TOKEN");
				Lire_Car();
				break;
			case ')': 
				SYM_COUR.CODE=PF_TOKEN;
				strcpy(SYM_COUR.nom,"PF_TOKEN");
				Lire_Car();
				break;
			case '=': 
				SYM_COUR.CODE=AFFOP_TOKEN;
				strcpy(SYM_COUR.nom,"AFFOP_TOKEN");
				Lire_Car();
				if(Car_Cour=='=') {
					SYM_COUR.CODE=EGAL_TOKEN;
					strcpy(SYM_COUR.nom,"EGAL_TOKEN");
					Lire_Car();
				}
				break;
			case '%': 
				Lire_Car();
				if(Car_Cour=='%') {
					SYM_COUR.CODE=RES_TOKEN;
					strcpy(SYM_COUR.nom,"RES_TOKEN");
					Lire_Car();
				}else if(Car_Cour=='/') {
					Lire_Car();
					if(Car_Cour=='%') {
						SYM_COUR.CODE=DIVENT_TOKEN;
						strcpy(SYM_COUR.nom,"DIVENT_TOKEN");
						Lire_Car();
					}else{
						SYM_COUR.CODE=ERREUR_TOKEN;
						strcpy(SYM_COUR.nom,"ERREUR_TOKEN");
						Lire_Car();
					}
				}else{
					SYM_COUR.CODE=ERREUR_TOKEN;
					strcpy(SYM_COUR.nom,"ERREUR_TOKEN");
					Lire_Car();
				}
				break;
			case '>': 
				SYM_COUR.CODE=SUP_TOKEN;
				strcpy(SYM_COUR.nom,"SUP_TOKEN");
				Lire_Car();
				if(Car_Cour=='=') {
					SYM_COUR.CODE=SUPG_TOKEN;
					strcpy(SYM_COUR.nom,"SUPG_TOKEN");
					Lire_Car();
				}
				break;
			case '<': 
				SYM_COUR.CODE=INF_TOKEN;
				strcpy(SYM_COUR.nom,"INF_TOKEN");
				Lire_Car();
				if(Car_Cour=='='){
					SYM_COUR.CODE=INFG_TOKEN;
					strcpy(SYM_COUR.nom,"INFG_TOKEN");
					Lire_Car();
				}else if(Car_Cour=='>'){
					SYM_COUR.CODE=DIFF_TOKEN;
					strcpy(SYM_COUR.nom,"DIFF_TOKEN");
					Lire_Car();
				}else if(Car_Cour=='-'){
					SYM_COUR.CODE=AFFOP2_TOKEN;
					strcpy(SYM_COUR.nom,"AFFOP2_TOKEN");
					Lire_Car();
				}else if(Car_Cour=='<'){
					Lire_Car();
					if(Car_Cour=='-'){
						SYM_COUR.CODE=AFFOP2_TOKEN;
						strcpy(SYM_COUR.nom,"AFFOP2_TOKEN");
						Lire_Car();
					}else{
						SYM_COUR.CODE=ERREUR_TOKEN;
						strcpy(SYM_COUR.nom,"ERREUR_TOKEN");
						Lire_Car();
					}
				}
				break;
			case '|':
				SYM_COUR.CODE=OR_TOKEN;
				strcpy(SYM_COUR.nom,"OR_TOKEN");
				Lire_Car();
				if(Car_Cour=='|') {
					Lire_Car();
				}
				break;
			case '&':
				SYM_COUR.CODE=AND_TOKEN;
				strcpy(SYM_COUR.nom,"AND_TOKEN");
				Lire_Car();
				if(Car_Cour=='&') {
					Lire_Car();
				}
				break;
			case '{':
				SYM_COUR.CODE=ACCO_TOKEN;
				strcpy(SYM_COUR.nom,"ACCO_TOKEN");
				Lire_Car();
				break;
			case '}':
				SYM_COUR.CODE=ACCF_TOKEN;
				strcpy(SYM_COUR.nom,"ACCF_TOKEN");
				Lire_Car();
				break;
			case ':':
				SYM_COUR.CODE=SEQ_TOKEN;
				strcpy(SYM_COUR.nom,"SEQ_TOKEN");
				Lire_Car();
				break;
			case '!':
				SYM_COUR.CODE=NOT_TOKEN;
				strcpy(SYM_COUR.nom,"NOT_TOKEN");
				Lire_Car();
				if(Car_Cour=='=') {
					SYM_COUR.CODE=DIFF_TOKEN;
					strcpy(SYM_COUR.nom,"DIFF_TOKEN");
					Lire_Car();
				}
				break;
			case '\n':
				numLigne+=1;
				SYM_COUR.CODE=ENTRER_TOKEN;
				strcpy(SYM_COUR.nom,"ENTRER_TOKEN");
				Lire_Car();
				break;
			case EOF: 
				SYM_COUR.CODE=EOF_TOKEN;
				strcpy(SYM_COUR.nom,"EOF_TOKEN");
				break;
			default :
				SYM_COUR.CODE=ERREUR_TOKEN;
				strcpy(SYM_COUR.nom,"ERREUR_TOKEN");
				Lire_Car();
		}
	}
	
}

void Lire_Car(){
	Car_Cour=fgetc(file);
}

void Lire_Mot(){
	int _compt=0;
	char* mot = calloc(1028,sizeof(char));
	while(AlphaNum(Car_Cour)){
		*(mot+_compt)=Car_Cour;
		_compt++;
		Lire_Car();
	}
	*(mot+_compt)='\0';
	
	if(!strcmp(mot,"if")){
		SYM_COUR.CODE=IF_TOKEN;
		strcpy(SYM_COUR.nom,"IF_TOKEN");
	}else if(!strcmp(mot,"in")){
		SYM_COUR.CODE=IN_TOKEN;
		strcpy(SYM_COUR.nom,"IN_TOKEN");
	}else if(!strcmp(mot,"repeat")){
		SYM_COUR.CODE=REPEAT_TOKEN;
		strcpy(SYM_COUR.nom,"REPEAT_TOKEN");
	}else if(!strcmp(mot,"while")){
		SYM_COUR.CODE=WHILE_TOKEN;
		strcpy(SYM_COUR.nom,"WHILE_TOKEN");
	}else if(!strcmp(mot,"else")){
		SYM_COUR.CODE=ELSE_TOKEN;
		strcpy(SYM_COUR.nom,"ELSE_TOKEN");
	}else if(!strcmp(mot,"break")){
		SYM_COUR.CODE=BREAK_TOKEN;
		strcpy(SYM_COUR.nom,"BREAK_TOKEN");
	}else if(!strcmp(mot,"scan")){
		SYM_COUR.CODE=READ_TOKEN;
		strcpy(SYM_COUR.nom,"READ_TOKEN");
	}else if(!strcmp(mot,"cat")){
		SYM_COUR.CODE=WRITE_TOKEN;
		strcpy(SYM_COUR.nom,"WRITE_TOKEN");
	}else if(!strcmp(mot,"print")){
		SYM_COUR.CODE=WRITE_TOKEN;
		strcpy(SYM_COUR.nom,"WRITE_TOKEN");
	}else if(!strcmp(mot,"for")){
		SYM_COUR.CODE=FOR_TOKEN;
		strcpy(SYM_COUR.nom,"FOR_TOKEN");
	}else if(!strcmp(mot,"min")){
		SYM_COUR.CODE=MIN_TOKEN;
		strcpy(SYM_COUR.nom,"MIN_TOKEN");
	}else if(!strcmp(mot,"max")){
		SYM_COUR.CODE=MAX_TOKEN;
		strcpy(SYM_COUR.nom,"MAX_TOKEN");
	}else{
		SYM_COUR.CODE=ID_TOKEN;
		strcpy(SYM_COUR.nom,"ID_TOKEN");
		strcpy(nom_symbol,mot);
	}
	memset(mot,'\0',1024);
} 

void Lire_Nombre(){
	while((Car_Cour>='0' && Car_Cour<='9') || Car_Cour=='.'){
		if(Car_Cour=='.') FLOAT++;
		if(FLOAT>1) break;
		Lire_Car();
	}
	if(CaractereVide(Car_Cour) || CaractereSigne(Car_Cour) || Car_Cour == ',' ||Car_Cour=='\n' || Car_Cour==')' || Car_Cour==':'){
		if(FLOAT){
			SYM_COUR.CODE = FLOAT_TOKEN;
			strcpy(SYM_COUR.nom,"FLOAT_TOKEN");
		}else{
			SYM_COUR.CODE = INT_TOKEN;
			strcpy(SYM_COUR.nom,"INT_TOKEN");
		}
	}else{
		while(!CaractereVide(Car_Cour))
			Lire_Car();
		SYM_COUR.CODE = ERREUR_TOKEN;
		strcpy(SYM_COUR.nom,"ERREUR_TOKEN");
	}
	FLOAT = 0;
}

void Lire_Commentaire(){
	SYM_COUR.CODE = COMM_TOKEN;
	strcpy(SYM_COUR.nom,"COMM_TOKEN");
	do{
		Lire_Car();
	}while(Car_Cour!='\n');
}

void Lire_Chaine(){
	SYM_COUR.CODE = CHAINE_TOKEN;
	strcpy(SYM_COUR.nom,"CHAINE_TOKEN");
	do{
		Lire_Car();
	}while(Car_Cour!='"' && Car_Cour!=EOF);
	Lire_Car();
}

void AfficherToken(TSym_Cour sym){
	printf("%s\n",SYM_COUR.nom);
}

void Ouvrir_Fichier(char* fileName){
	file = fopen(fileName, "r");
}

int CaractereVide(char Car_Cour){
	if(Car_Cour==' '||Car_Cour=='\t')
		return 1;
	return 0;
}

int AlphaNum(char Car_Cour){
	if((Car_Cour>='a' && Car_Cour<='z')||(Car_Cour>='A' && Car_Cour<='Z')||(Car_Cour>='0' && Car_Cour<='9') )
		return 1;
	return 0;
}

int CaractereSigne(char Car_Cour){
	if(Car_Cour=='+'||Car_Cour=='*'||Car_Cour=='-'||Car_Cour=='<'||Car_Cour=='>'||Car_Cour=='/'||Car_Cour==';')
		return 1;
	return 0;
}