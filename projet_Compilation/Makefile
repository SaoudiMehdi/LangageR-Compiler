all: compiler

compiler: compiler.o analyseur_lexical.o global.o analyseur_syntaxique.o 
	gcc -o compiler compiler.o analyseur_lexical.o analyseur_syntaxique.o errors.o -g

compiler.o: compiler.c analyseur_syntaxique.h global.h analyseur_syntaxique.h 
	gcc -o compiler.o -c compiler.c -g

analyseur_synthaxique.o: analyseur_syntaxique.c analyseur_syntaxique.h analyseur_lexical.h global.h errors.h 
	gcc -o analyseur_syntaxique.o -c analyseur_syntaxique.c -g


analyseur_lexical.o: analyseur_lexical.c global.h errors.h 
	gcc -o analyseur_lexical.o -c analyseur_lexical.c -g

global.o: errors.c errors.h
	gcc -o errors.o -c errors.c -g

