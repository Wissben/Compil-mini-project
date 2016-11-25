%{
  #include <stdio.h>
  #include "exp.tab.h"
  #include "ts.h"
  extern YYSTYPE yylval;
  extern TS* L;
  extern TS* temp;
%}

chiffre [0-9]
Entier [+-]?(0|[1-9]{chiffre}*)
IDF[a-zA-Z][a-zA-Z0-9]*
%%
"Begin" {printf("le mot %s est reconnu\n",yytext );strcpy(temp->nom,"Begin");inst(&L,*temp);return Begin;}
"End" {printf("le mot %s est reconnu\n",yytext );strcpy(temp->nom,"End");inst(&L,*temp);return End;}
"Int" {printf("le mot %s est reconnu\n",yytext );strcpy(temp->nom,"Int");inst(&L,*temp);return Int;}
"=" {printf("le mot %s est reconnu\n",yytext );strcpy(temp->nom,"=");inst(&L,*temp);return '=';}
";" {printf("le mot %s est reconnu\n",yytext );strcpy(temp->nom,";");inst(&L,*temp);return ';';}
"\n" {printf("le mot %s est reconnu\n",yytext );}
" " {printf("le mot %s est reconnu\n",yytext );}
{Entier} {printf("Le mot %s est entier \n", yytext);yylval.entier=atoi(yytext);strcpy(temp->nom,yytext);inst(&L,*temp);return Entier;}
{IDF} {printf("le mot %s est un idf \n", yytext);yylval.chaine=strdup(yytext);strcpy(temp->nom,yytext);inst(&L,*temp);return IDF;}
. {printf("le mot %s n'est pas reconnu \n",yytext );}
%%

int yywrap(void)
{
   return 0;
}
