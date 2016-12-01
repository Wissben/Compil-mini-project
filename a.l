%{
  #include <stdio.h>
  #include "a.tab.h"
  extern YYSTYPE yylval;
  extern int yylineno;
  #define RED   "\x1B[31m"
  #define GRN   "\x1B[32m"
  #define YEL   "\x1B[33m"
  #define BLU   "\x1B[34m"
  #define MAG   "\x1B[35m"
  #define CYN   "\x1B[36m"
  #define WHT   "\x1B[37m"
  #define RESET "\x1B[0m"

%}
%option yylineno

chiffre [0-9]
Entier [+-]?(0|[1-9]{chiffre}*)
idf [a-zA-Z][a-zA-Z0-9]*
real [+-]?({Entier}\.[0-9]+)
str \"[^\"\r\n]*\"
comment (\/\*([^\*]*|(\**[^\/])*)*\*\/)|\/\/.*\n?

%%
" " {printf("le mot %s est reconnu\n",yytext );}
"Main" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return Main;}
"Import" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return Import;}
"MiniLlang" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext ); return MiniLlang;}
"MiniLio" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return MiniLio;}
"public" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return public;}
"protected" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return protected;}
"class" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return class;}
"INTEGER" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return INTEGER;}
"REAL" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return REAL;}
"STR" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return STR;}
"," {printf("le mot %s est reconnu\n",yytext );return ',';}
"CONST" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return CONST;}
":=" {printf("le mot %s est reconnu\n",yytext );return Affect;}
";" {printf("le mot %s est reconnu\n",yytext );return ';';}
"For" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return For;}
"In" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return In;}
"Out" {printf("le mot " BLU "%s" RESET" est reconnu\n",yytext );return Out;}
"+" {printf("le mot %s est reconnu\n",yytext );return '+';}
"-" {printf("le mot %s est reconnu\n",yytext );return '-';}
"*" {printf("le mot %s est reconnu\n",yytext );return '*';}
"/" {printf("le mot %s est reconnu\n",yytext );return '/';}
">" {printf("le mot %s est reconnu\n",yytext );return '>';}
"<" {printf("le mot %s est reconnu\n",yytext );return '<';}
"=" {printf("le mot %s est reconnu\n",yytext );return '=';}
"!=" {printf("le mot %s est reconnu\n",yytext );return different;}
"<=" {printf("le mot %s est reconnu\n",yytext ); return lessEq;}
">=" {printf("le mot %s est reconnu\n",yytext );return greatEq;}
"&" {printf("le mot %s est reconnu\n",yytext );return '&';}
"|" {printf("le mot %s est reconnu\n",yytext );return '|';}
"!" {printf("le mot %s est reconnu\n",yytext );return '!';}
"//" {printf("le mot %s est reconnu\n",yytext );return doubleSLash;}
")" {printf("le mot %s est reconnu\n",yytext );return ')';}
"(" {printf("le mot %s est reconnu\n",yytext );return '(';}
"[" {printf("le mot %s est reconnu\n",yytext );return '[';}
"]" {printf("le mot %s est reconnu\n",yytext );return ']';}
"{" {printf("le mot %s est reconnu\n",yytext );return '{';}
"}" {printf("le mot %s est reconnu\n",yytext );return '}';}
"\n"
{real} {printf("Le mot " MAG "%s" RESET" est un real \n", yytext);yylval.Real=atof(yytext);return real;}
{Entier} {printf("Le mot " MAG "%s" RESET" est un entier \n", yytext);yylval.entier=atoi(yytext);return Entier;}
{idf} {printf("le mot " BLU "%s" RESET" est un identifiant \n", yytext);yylval.chaine=strdup(yytext);return IDF;}
{str}  {printf("le mot " YEL "%s" RESET" est une chaine de caract\n",yytext );yylval.chaine=strdup(yytext);return str;}
{comment}  {printf("le mot " WHT "%s" RESET" est un commentaire\n",yytext );}
. {printf("le mot %s est faux \n",yytext );}
%%

int yywrap(void)
{
  return 0;
}
