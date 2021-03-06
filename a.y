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
  Q* Q1 =NULL;
  Q* Q2 =NULL;
  int s1,s2,s3;

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
  char ch[100],chInt[100],cheFloat[100],chStr[100],chTab[100],CondSave[255];
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

  char car;
  int entier;
  float Real;
  struct perso
  {
    char typeVar[2550];
    char str[2550];
  } perso;
}

%token Main Import MiniLlang MiniLio public protected class INTEGER REAL STR  CONST  For In Out
%token Affect '+' '-' '*' '/' '>' '<' '=' different lessEq greatEq '&' '|' '!'
%token doubleSLash ',' ';' ')' '(' '[' ']' '{' '}'
%token <chaine> IDF
%token <chaine> str

%token <entier> Entier

%token <Real> real
%type<perso> Condf Cond comparator A binary Expression IDFa Factor Term
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
                                     sprintf(chTab,"%d",$4);
                                     quad(&teteQ,&q,"BOUNDS","0",chTab,"");
                                     quad(&teteQ,&q,"ADEC",$2,"","");
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

Lect
 : In '(' str ',' IDF ')' ';'                {
                                               natIDF=getNat(L,$5);
                                               typeIDF=getType(L,$5);
                                               typeSTR=getTypeBySign($3);
                                               if (srch(L,$5)==0)   {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$5); return 0;}
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
                                               if(typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR : types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),$3); return 0;}
                                             }
 ;

Ecrit
 : Out '(' str ',' IDF ')' ';'               {
                                               natIDF=getNat(L,$5);
                                               typeIDF=getType(L,$5);
                                               typeSTR=getTypeBySign($3);
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

                                               if (typeIDF!=typeSTR) {printf(RED"\n-----> ligne %d .ERREUR : types incompatibles entre (%s) et (%s) \n\n" RESET,yylineno,getSignByType(typeIDF),$3); return 0;}
                                             }
 | Out '(' str ')' ';'
 ;

 Loop
  : For '(' Init           {
                              s1 = getNumQuad();
                           }

  ';' Condf                {
                              Q1 = quad(&teteQ,&q,"BZ","",CondSave,"");
                              Q2 = quad(&teteQ,&q,"BR","",CondSave,"");
                              s2 = getNumQuad();
                           }

  ';' Incf                 {
                             char Save[100];
                             sprintf(Save,"%d",s1);
                             quad(&teteQ,&q,"BR",Save,"","");
                             sprintf(Save,"%d",getNumQuad());
                             strcpy(Q2->op1,Save);
    }

   ')' '{' INST            {
                            char Save[100];
                            sprintf(Save,"%d",s2);
                            quad(&teteQ,&q,"BR",Save,"","");
                            sprintf(Save,"%d",getNumQuad());
                            strcpy(Q1->op2,Save);
                           }

   '}'
  ;

Init
 : IDFa Affect Expression ',' Init {if(strcmp($1.typeVar,$3.typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                      quad(&teteQ,&q,":=",$3.str,"",$1.str);}
 | IDFa Affect Expression           {
                                      if(strcmp($1.typeVar,$3.typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                      quad(&teteQ,&q,":=",$3.str,"",$1.str);}
 ;

Aff
 : IDFa Affect Expression ';' {
                                if(strcmp($1.typeVar,$3.typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
                                if(IDFcst==1) {printf(RED"\n-----> ligne %d .ERREUR constante non modifiable \n\n" RESET,yylineno); return 0;}
                                quad(&teteQ,&q,":=",$3.str,"",$1.str);
 }
 ;

IDFa
 : IDF                 {

                         if(getNat(L,$1)==2) IDFcst=1;
                         else
                         IDFcst=0;

                         AffleftType=getType(L,$1);
                         natIDF=getNat(L,$1);

                         strcpy($$.str,$1);
                         char c[255];
                         char* sign=getSignByType(AffleftType);
                         sprintf(c,"%d",AffleftType);
                         strcpy($$.typeVar,c);
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
                         strcpy(chTab,$1);
                         strcat(chTab,"[");
                         strcat(chTab,$3.str);
                         strcat(chTab,"]");
                         strcpy($$.str,chTab);
                         char c[255];
                         char* sign=getSignByType(AffleftType);

                         if(strcmp(sign,"%s")!=0)
                         {
                           sprintf(c,sign,AffleftType);
                           strcpy($$.typeVar,c);
                         }
                         else
                         strcpy($$.typeVar,"2");
                         quad(&teteQ,&q,chTab,"","",$3.str);

                       }
 ;

Condf
 : Cond ',' Condf {strcpy(CondSave,$1.str);}
 | Cond {strcpy(CondSave,$1.str);}
 ;

Cond
 : A binary Cond {
                   strcpy($$.str,$1.str);
                   strcat($$.str,$2.str);
                   strcat($$.str,$3.str);
                   quad(&teteQ,&q,$2.str,$1.str,$3.str,$$.str);
                 }
 | A { strcpy($$.str,$1.str);}
 ;

A
 : '!' '(' Cond ')'{
                     strcpy($$.str,"!(");
                     strcat($$.str,$3.str);
                     strcat($$.str,")");
                     quad(&teteQ,&q,"!",$3.str,"",$$.str);
                   }
 | '(' Cond ')' {
                  strcpy($$.str,"(");
                  strcat($$.str,$2.str);
                  strcat($$.str,")");
                }
 |Expression comparator Expression {

                                      if(strcmp($1.typeVar,$3.typeVar)!=0)
                                       {printf(RED"\n-----> ligne %d .ERREUR : Types incompatibles \n\n" RESET,yylineno); return 0;}
                                       strcpy($$.str,$1.str);
                                       strcat($$.str,$2.str);
                                       strcat($$.str,$3.str);

                                       quad(&teteQ,&q,$2.str,$1.str,$3.str,$$.str);
                                   }
 |IDFa
 ;

comparator
 : '>' {strcpy($$.str,">");}
 | greatEq {strcpy($$.str,">=");}
 | '<' {strcpy($$.str,"<");}
 | lessEq {strcpy($$.str,"<=");}
 | '=' {strcpy($$.str,"=");}
 ;

binary
 : '&' {strcpy($$.str,"&");}
 | '|' {strcpy($$.str,"|");}
 ;

Incf
 : Inc ',' Incf
 | Inc
 ;

Inc
 : IDFa Affect Expression {if(strcmp($1.typeVar,$3.typeVar)!=0) {printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;}
 quad(&teteQ,&q,":=",$3.str,"",$1.str);}
 ;

Expression
 : Expression '+' Term{

                               if(strcmp($1.typeVar,$3.typeVar)==0)
                                {
                                  strcpy(temp,$1.str);
                                  strcat(temp,"+");
                                  strcat(temp,$3.str);
                                  strcpy($$.str,temp);
                                  strcpy($$.typeVar,$1.typeVar);
                                  quad(&teteQ,&q,"+",$1.str,$3.str,$$.str);

                                 }
                                else
                                {
                                  printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                                }
                            }
 | Expression '-' Term       {

                               if(strcmp($1.typeVar,$3.typeVar)==0)
                                {
                                  strcpy(temp,$1.str);
                                  strcat(temp,"-");
                                  strcat(temp,$3.str);
                                  strcpy($$.str,temp);
                                  strcpy($$.typeVar,$1.typeVar);
                                  quad(&teteQ,&q,"-",$1.str,$3.str,temp);

                                 }
                                 else
                                 {
                                   printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                                 }

                             }

 | Term                      {

                               strcpy($$.str,$1.str);
                               strcpy($$.typeVar,$1.typeVar);
                               //quad(&teteQ,&q,"",$1.str,"",$$.str);
                             }
 ;

Term
 : Term '*' Factor {

                      if(strcmp($1.typeVar,$3.typeVar)==0)
                      {
                        strcpy(temp,$1.str);
                        strcat(temp,"*");
                        strcat(temp,$3.str);
                        strcpy($$.str,temp);
                        strcpy($$.typeVar,$1.typeVar);
                        quad(&teteQ,&q,"*",$1.str,$3.str,temp);

                      }
                      else
                      {
                        printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                      }
                    }

 | Term '/' Factor  {

                      if(strcmp($1.typeVar,$3.typeVar)==0)
                      {

                        strcpy(temp,$1.str);
                        strcat(temp,"/");
                        strcat(temp,$3.str);
                        strcpy($$.str,temp);
                        strcpy($$.typeVar,$1.typeVar);
                        quad(&teteQ,&q,"/",$1.str,$3.str,temp);

                      }
                      else
                      {
                        printf(RED"\n-----> ligne %d .ERREUR :  types incompatibles \n\n" RESET,yylineno); return 0;
                      }
                    }

 | Factor           {

                      strcpy($$.str,$1.str);
                      strcpy($$.typeVar,$1.typeVar);

                    }
 ;

Factor
 : IDF                {

                        natIDF=getNat(L,$1);

                        if (natIDF==1)     {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) est un tableau \n\n" RESET,yylineno,$1); return 0;}
                        if (srch(L,$1)==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$1); return 0;}
                        int t=getType(L,$1);
                        sprintf(ch,"%d",t);
                        strcpy($$.str,$1);
                        strcpy($$.typeVar,ch);

                      }
 | IDF '[' Expression ']' {
                           AffleftType=getType(L,$1);

                           natIDF=getNat(L,$1);

                           if (natIDF!=1) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) n'est pas un tableau\n\n" RESET,yylineno,$1); return 0;}
                           if (srch(L,$1)==0) {printf(RED"\n-----> ligne %d .ERREUR : l'IDF (%s) non déclaré\n\n" RESET,yylineno,$1); return 0;}
                           int t=getType(L,$1);
                           sprintf(ch,"%d",t);

                           strcpy(chTab,$1);
                           strcat(chTab,"[");
                           strcat(chTab,temp);
                           strcat(chTab,"]");
                           strcpy($$.str,chTab);
                           char c[255];
                           char* sign=getSignByType(AffleftType);

                           if(strcmp(sign,"%s")!=0)
                           {
                             sprintf(c,sign,AffleftType);
                             strcpy($$.typeVar,c);
                           }
                           else
                           strcpy($$.typeVar,"2");
                           quad(&teteQ,&q,chTab,"","",$3.str);

                          }

 | Entier              {

                         sprintf(chInt,"%d",$1);
                         sprintf(ch,"%d",0);
                         strcpy($$.str,chInt);
                         strcpy($$.typeVar,ch);

                       }

 | real                {

                         sprintf(chInt,"%f",$1);
                         sprintf(ch,"%d",1);
                         strcpy($$.str,chInt);
                         strcpy($$.typeVar,ch);

                       }

 | str                 {

                         sprintf(ch,"%d",2);

                         strcpy($$.str,$1);
                         strcpy($$.typeVar,ch);
                       }

 | '(' Expression ')'  {

                        char tmp[100];
                        strcpy(tmp,"(");
                        strcat(tmp,$2.str);
                        strcat(tmp,")\0");

                        strcpy($$.str,tmp);
                        strcpy($$.typeVar,$2.typeVar);
                       }
 | '-' Factor          {

                         strcpy($$.str,"-");
                         strcat($$.str,$2.str);
                         strcpy($$.typeVar,$2.typeVar);
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
  char* sign=malloc(3*sizeof(char));
  sign[2]='\0';
  switch (type)
  {
    case 0: { strcpy(sign,"%d"); } break;
    case 1: { strcpy(sign,"%f");} break;
    case 2: { strcpy(sign,"%s");} break;
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

  return 0;
  /*printf(RED "red\n" RESET);
  printf(GRN "green\n" RESET);
  printf(YEL "yellow\n" RESET);
  printf(BLU "blue\n" RESET);
  printf(MAG "magenta\n" RESET);
  printf(CYN "cyan\n" RESET);
  printf(WHT "white\n" RESET);*/
}
