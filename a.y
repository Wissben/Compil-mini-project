%{
  #include <stdio.h>
  #include "ts.h"
  #include "stack.h"
  //Useful functions
  char* getSignByType(int type);
  int getTypeBySign(char* sign);
  //End
  extern FILE* yyin;
  extern int yylineno;
  extern TS* L;
  extern Q*teteQ;
  //Useful variables
  int i=-1;
  int natIDF;
  int typeIDF;
  int typeSTR;
  int sizeIDF;
  int AffleftType;
  int AffRightType;
  int IDFcst;
  int ExpLeftType;
  int ExpRightType;
  char ch[100],chInt[100],cheFloat[100],chStr[100],chTab[100];
  char temp[100];
  char idfVal[100];
  //End
  #define RED   "\x1B[31m"
  #define GRN   "\x1B[32m"
  #define YEL   "\x1B[33m"
  #define BLU   "\x1B[34m"
  #define MAG   "\x1B[35m"
  #define CYN   "\x1B[36m"
  #define WHT   "\x1B[37m"
  #define RESET "\x1B[0m"
%}
%union
{
  char* chaine;
  char* IDFa;
  char car;
  int entier;
  float Real;

}

%token Main Import MiniLlang MiniLio public protected class INTEGER REAL STR  CONST  For In Out
%token Affect '+' '-' '*' '/' '>' '<' '=' different lessEq greatEq '&' '|' '!'
%token doubleSLash ',' ';' ')' '(' '[' ']' '{' '}'
%token <chaine> IDF
%token <chaine> str
//%token <chaine> comment
%token <entier> Entier
//%token <entier> EntierSigne
%token <Real> real
%start S
%left '|'
%left '&'
%left '!'
%left '>' greatEq lessEq '=' different '<'
%left '+' '-'
%left '/' '*'
%left '(' ')'
%%

S
 : imp modif class IDF '{' DEC Main '{' INST '}' '}'
 {
   printf(GRN "\n****programme correcte syntaxiquement****\n\n" RESET);
   return EXIT_SUCCESS;
 }
 ;

imp
 : H imp
 | H
 ;

H
 : Import MiniLlang ';'
 | Import MiniLio ';'

 ;

modif
 : public
 | protected

 ;

DEC
 : nat DEC
 | nat
 ;

nat
 : simple
 | tab
 | cst
 ;

simple
 : type IDF ',' loopSimple ';'  {
                                  if (strlen($2)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$2); return 0;}
                                  if (srch(L,$2)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$2); return 0;} inst(&L,$2,i,0,1);
                                }
 | type IDF ';'                 {
                                  if (strlen($2)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$2); return 0;}
                                  if (srch(L,$2)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$2); return 0;} inst(&L,$2,i,0,1);
                                }
 ;

loopSimple
 : IDF ',' loopSimple {
                        if (strlen($1)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$1); return 0;}
                        if (srch(L,$1)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$1); return 0 ;} inst(&L,$1,i,0,1);
                      }
 | IDF                {
                        if (strlen($1)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$1); return 0;}
                        if (srch(L,$1)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$1); return 0 ;} inst(&L,$1,i,0,1);
                      }
 ;

tab
 : type IDF '[' Entier ']' ';' {
                                     if (strlen($2)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$2); return 0;}
                                     if (srch(L,$2)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$2); return 0;} inst(&L,$2,i,1,$4);
                                   }
 ;

cst
 : CONST type IDF Affect Val ',' loopCst ';' {
                                               if (strlen($3)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$3); return 0;}
                                               if (srch(L,$3)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$3); return 0;} inst(&L,$3,i,2,1);
                                               if (getType(L,$3)!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                             }

 | CONST type IDF Affect Val ';'             {
                                               if (strlen($3)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$3); return 0;}
                                               if (srch(L,$3)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$3); return 0;} inst(&L,$3,i,2,1);
                                               if (getType(L,$3)!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}

                                             }
 ;

loopCst
 : IDF Affect Val ',' loopCst {
                                if (strlen($1)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$1); return 0;}
                                if (srch(L,$1)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$1); return 0;} inst(&L,$1,i,2,1);
                                if (getType(L,$1)!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}

                              }

 | IDF Affect Val             {
                                if (strlen($1)>10) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) trop long \n\n" RESET,yylineno,$1); return 0;}
                                if (srch(L,$1)==1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) déjà déclaré\n\n" RESET,yylineno,$1); return 0;} inst(&L,$1,i,2,1);
                                if (getType(L,$1)!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                              }
 ;

Val
 : Entier {AffRightType=0;}
 | str    {AffRightType=2;}
 | real   {AffRightType=1;}
 ;

type
 : INTEGER {i=0;}
 | REAL {i=1;}
 | STR {i=2;}
 ;

INST
 : ty  INST
 | ty
 ;

ty
 : Aff
 | Loop
 | Lect
 | Ecrit
 | %empty
 ;

Aff
 : IDFa Affect Expression ';' {
                                 if(AffleftType!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                 if(IDFcst==1) {printf(RED"\n-----> ligne %d .ERREUR constante non modifiable \n\n" RESET,yylineno); return 0;}
                                 quad(&teteQ,&q,":=",temp,"",idfVal);
                              }
 ;

Loop
 : For '(' Init ';' Condf ';' Incf ')' '{' INST '}'
 ;

Lect
 : In '(' str ',' IDF ')' ';'                {
                                               natIDF=getNat(L,$5);
                                               typeIDF=getType(L,$5);
                                               typeSTR=getTypeBySign($3);
                                               if (srch(L,$5)==0)   {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$5); return 0;}
                                               //if (natIDF==1)       {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,$5); return 0;}
                                               if (natIDF==2)       {printf(RED"\n-----> ligne %d .ERREUR : la constante (%s) ne peut pas être modifiée\n\n" RESET,yylineno,$5); return 0;}
                                               if(typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),$3); return 0;}
                                             }

 | In '(' str ',' IDF '[' Expression ']' ')' ';' {
                                               natIDF=getNat(L,$5);
                                               typeIDF=getType(L,$5);
                                               typeSTR=getTypeBySign($3);
                                               sizeIDF=getSize(L,$5);
                                               if (srch(L,$5)==0)   {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$5); return 0;}
                                               if (natIDF!=1)       {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,$5); return 0;}
                                               //if ($7>=sizeIDF)     {printf(RED"\n-----> ligne %d .ERREUR : Dérnier indice du tableau (%s) dépassé de %d \n\n" RESET,yylineno,$5,$7-sizeIDF+1); return 0;}
                                               if(typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR : types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),$3); return 0;}
                                             }
 ;

Ecrit
 : Out '(' str ',' IDF ')' ';'               {
                                               natIDF=getNat(L,$5);
                                               typeIDF=getType(L,$5);
                                               //typeSTR=getTypeBySign( strcat(  strstr($3,"%")  ,  *(strstr($3,"%")+1) ) );
                                               if (natIDF==1)        {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,$5); return 0;}
                                               if (srch(L,$5)==0)    {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$5); return 0;}
                                               if (natIDF==2)        {printf(RED"\n-----> ligne %d .ERREUR : la constante (%s) ne peut pas être modifiée\n\n" RESET,yylineno,$5); return 0;}
                                               if (typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),$3); return 0;}
                                             }

 | Out '(' str ',' IDF '[' Expression ']' ')' ';'{
                                               natIDF=getNat(L,$5);
                                               typeIDF=getType(L,$5);
                                               typeSTR=getTypeBySign($3);
                                               sizeIDF=getSize(L,$5);
                                               if (srch(L,$5)==0)    {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$5); return 0;}
                                               if (natIDF!=1)        {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,$5); return 0;}
                                               //if ($7>=sizeIDF)      {printf(RED"\n-----> ligne %d .ERREUR : Dérnier indice du tableau (%s) dépassé de %d \n\n" RESET,yylineno,$5,$7-sizeIDF+1); return 0;}
                                               if (typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR : types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),$3); return 0;}
                                             }
 | Out '(' str ')' ';'
 ;

Init
 : IDFa Affect Expression ',' Init {if(AffleftType!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}quad(&teteQ,&q,":=",temp,"",idfVal);}
 | IDFa Affect Expression          {if(AffleftType!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}quad(&teteQ,&q,":=",temp,"",idfVal);}
 ;

IDFa
 : IDF                 {

                         if(getNat(L,$1)==2) IDFcst=1;
                         else
                         IDFcst=0;
                         AffleftType=getType(L,$1);
                         natIDF=getNat(L,$1);
                         strcpy(idfVal,$1);
                         if (natIDF==1)     {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,$1); return 0;}
                         if (srch(L,$1)==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$1); return 0;}
                       }

 | IDF '[' Expression ']'  {
                         AffleftType=getType(L,$1);
                         sizeIDF=getSize(L,$1);
                         natIDF=getNat(L,$1);
                         strcpy(idfVal,$1);
                         if (natIDF!=1)     {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,$1); return 0;}
                         if (srch(L,$1)==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$1); return 0;}
                         //if ($3>=sizeIDF)   {printf(RED"\n-----> ligne %d .ERREUR : Dérnier indice du tableau %s dépassé de %d \n\n" RESET,yylineno,$1,$3-sizeIDF+1); return 0;}
                       }
 ;

Condf
 : Cond ',' Condf
 | Cond
 ;

Cond
 : '(' Cond ')'
 | Expression comparator Expression
// | Cond binary Cond
 | A
 ;

comparator
 : '>'
 | greatEq
 | '<'
 | lessEq
 | '='
 ;

A
 :Cond binary Cond
 |Expression
 ;

binary
 : '&'
 | '|'
 ;

Incf
 : Inc ',' Incf
 | Inc
 ;

Inc
 : IDFa Affect Expression {if(AffleftType!=AffRightType) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}quad(&teteQ,&q,":=",temp,"",idfVal);}
 ;

Expression
 : Expression '+' Expression{
   //showStack(S);

                               Element* op2=pop(&S);
                               Element* op1=pop(&S);
                               if(strcmp(op1->type,op2->type)==0)
                                {
                                  strcpy(temp,op1->name);
                                  strcat(temp,"+");
                                  //printf(RED"%s\n"RESET,op1->name );
                                  strcat(temp,op2->name);
                                  quad(&teteQ,&q,"+",op1->name,op2->name,temp);
                                  push(&S,"Expression",temp,op1->type);
                                  //strcpy(temp,"");
                                }
                                else
                                {
                                  printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                                }
                            }
 | Expression '-' Term       {
                               Element* op2=pop(&S);
                               Element* op1=pop(&S);
                               if(strcmp(op1->type,op2->type)==0)
                                {
                                  strcpy(temp,op1->name);
                                  strcat(temp,"-");
                                  strcat(temp,op2->name);
                                  quad(&teteQ,&q,"-",op1->name,op2->name,temp);
                                  push(&S,"Expression",temp,op1->type);
                                 }
                                 else
                                 {
                                   printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                                 }

                             }

 | Term                      {
                               Element* op=pop(&S);
                               push(&S,"Expression",op->name,op->type);
                               strcpy(temp,op->name);
                               //quad(&teteQ,&q,"",op->name,"",temp);
                             }
 ;

Term
 : Term '*' Factor {
                      Element* op2=pop(&S);
                      Element* op1=pop(&S);
                      if(strcmp(op1->type,op2->type)==0)
                      {

                        strcpy(temp,op1->name);
                        strcat(temp,"*");
                        strcat(temp,op2->name);
                        quad(&teteQ,&q,"*",op1->name,op2->name,temp);
                        push(&S,"Term",temp,op1->type);
                      }
                      else
                      {
                        printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                      }
                    }

 | Term '/' Factor  {
                      Element* op2=pop(&S);
                      Element* op1=pop(&S);
                      if(strcmp(op1->type,op2->type)==0)
                      {

                        strcpy(temp,op1->name);
                        strcat(temp,"/");
                        strcat(temp,op2->name);
                        quad(&teteQ,&q,"/",op1->name,op2->name,temp);
                        push(&S,"Term",temp,op1->type);
                      }
                      else
                      {
                        printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                      }
                    }

 | Factor           {
                      Element* op=pop(&S);
                      push(&S,"Term",op->name,op->type);
                      strcpy(temp,op->name);
                      //quad(&teteQ,&q,"",op->name,"",temp);
                    }
 ;

Factor
 : IDF                {
                        AffRightType=getType(L,$1);
                        natIDF=getNat(L,$1);
                        //strcpy(idfVal,$1);
                        if (natIDF==1)     {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,$1); return 0;}
                        if (srch(L,$1)==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$1); return 0;}
                        int t=getType(L,$1);
                        sprintf(ch,"%d",t);
                        push(&S,"Factor",$1,ch);
                      }
 | IDF '[' Expression ']' {
                           AffRightType=getType(L,$1);
                           sizeIDF=getSize(L,$1);
                           natIDF=getNat(L,$1);
                           //strcpy(idfVal,$1);
                           if (natIDF!=1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,$1); return 0;}
                           if (srch(L,$1)==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$1); return 0;}
                           int t=getType(L,$1);
                           sprintf(ch,"%d",t);
                          //  char tm[100];
                          //  strcpy(tm,"[");
                          //  strcat(tm,temp);
                          //  strcat(tm,"]");
                          //  strcat($1,tm);
                           push(&S,"Factor",$1,ch);
                           //if ($3>=sizeIDF) {printf(RED"\n-----> ligne %d .ERREUR : Dérnier indice du tableau (%s) dépassé de %d \n\n" RESET,yylineno,$1,$3-sizeIDF+1); return 0;}
                          }

 | Entier              {
                         AffRightType=0;
                         //sprintf(idfVal,"%d",$1);
                         //sprintf(ch,"%d",t);
                         //char chInt[10];
                         sprintf(chInt,"%d",$1);
                         sprintf(ch,"%d",0);
                         push(&S,"Factor",chInt,ch);
                       }

 | real                {
                         AffRightType=1;
                         //sprintf(idfVal,"%f",$1);
                         //sprintf(ch,"%d",t);
                         //char cheFloat[10];
                         sprintf(chInt,"%f",$1);
                         sprintf(ch,"%d",1);
                         push(&S,"Factor",chInt,ch);
                       }

 | str                 {
                         AffRightType=2;
                         //strcpy(idfVal,$1);
                         //sprintf(ch,"%d",t);
                         sprintf(ch,"%d",2);
                         push(&S,"Factor",$1,ch);
                       }

 | '(' Expression ')'  {
                        Element* p=pop(&S);
                        char tmp[100];
                        strcpy(tmp,"(");
                        strcat(tmp,p->name);
                        strcat(tmp,")\0");
                        push(&S,"Factor",tmp,p->type);
                       }
 | '-' Factor          {
                         Element* op=pop(&S);
                         push(&S,"Factor",op->name,op->type);
                       }
 ;

%%
int yyerror(char* msg)
{
  printf(RED "\n%s at the line %d\n\n" RESET, msg, yylineno);
  return 1;
}

int getTypeBySign(char* sign)
{
  if(strcmp(sign,"\"%d\"")==0)
   return 0;
   else
    if (strcmp(sign,"\"%f\"")==0)
      return 1;
      else
       if(strcmp(sign,"\"%s\"")==0)
        return 2;
        else
         return -1;
}
char* getSignByType(int type)
{
  char* sign=malloc(5*sizeof(char));
  sign[4]='\0';
  switch (type)
  {
    case 0: { strcpy(sign,"\"%d\""); } break;
    case 1: { strcpy(sign,"\"%f\"");} break;
    case 2: { strcpy(sign,"\"%s\"");} break;
    default: { printf("Error\n");} break;
  }
  return sign;
}
int main()
{
  create(&L);
  initStack(&S);
  yyin=fopen("code.txt","r");
  yyparse();
  show(L);
  afficherQ(teteQ);
  printf("\n\n-------------------------\n"
         "|        Legende        |\n"
         "-------------------------\n"
         "|"BLU"Mot clé"RESET"                |\n"
         "|"BLU"Identifiant"RESET"            |\n"
         "|"YEL"String"RESET"                 |\n"
         "|"MAG"Valeur"RESET"                 |\n"
         "|"WHT"Commentaire"RESET"            |\n"
         "|"RED"Error"RESET"                  |\n"
         "|"GRN"Programm accepted"RESET"      |\n"
         "-------------------------\n"
    );
    //showStack(S);

  return 0;
  /*printf(RED "red\n" RESET);
  printf(GRN "green\n" RESET);
  printf(YEL "yellow\n" RESET);
  printf(BLU "blue\n" RESET);
  printf(MAG "magenta\n" RESET);
  printf(CYN "cyan\n" RESET);
  printf(WHT "white\n" RESET);*/
}
