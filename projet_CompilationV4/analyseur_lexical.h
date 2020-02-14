#ifndef ANALYSEUR_LEXICAL_H
#define ANALYSEUR_LEXICAL_H


#include "global.h"
#include "errors.h"



void Lire_Car();
void Lire_Mot();
void Lire_Nombre();
void Lire_Commentaire();
void Lire_Chaine();
void Init_Fonctions();
void add_fonction(char* nomFonction, int sep, int nombreArgument);
T_Table_Fonction Chercher_Fonction(char* nomFonction);
void Sym_Suiv();
void Ouvrir_Fichier(char* fileName);
void AfficherToken(TSym_Cour sym);
int AlphaNum(char Car_Cour);
int CaractereVide(char Car_Cour);
int CaractereSigne(char Car_Cour);

#endif