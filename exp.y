%{
  #include <stdio.h>
  #include "ts.h"
  extern FILE *yyin;
  extern TS* L;
  extern TS* temp;
%}
%union
{
  char *chaine;
  int entier;
}

%token Begin End Int ';' '='
%token <chaine> IDF
%token <entier> Entier

%%
S:Begin Dec Aff End {printf("programme correct\n");};
Dec :Int IDF ';' {printf("une declaration de %s\n",$2);  };
Aff:IDF '=' Entier ';' {printf("Une affectation avec la valeur %d\n", $3); strcpy(temp->nom,$3); temp->type=0;temp->nature=0; temp->taille=1;update(&L,temp);};
%%
int yyerror(char* msg)
{printf("%s",msg); return 1;}

int main()
{
  yyin=fopen("code.txt","r");
  yyparse();
  int succes =create(&L);

  TS* temp= malloc(sizeof(TS));
  strcpy(temp->nom,"");
  temp->type=-1;
  temp->nature=-1;
  temp->taille=0;
  temp->sv=NULL;
  show(L);
  return 0;
}
