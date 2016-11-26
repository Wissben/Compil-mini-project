#ifndef TS_H_INCLUDED
#define TS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define null NULL
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
//déclaration
typedef struct TS
{
  char nom[10];
  int nature; //
  int type;
  int taille;
  struct TS* sv;
} TS;
////
TS*L=NULL;
int create (TS** L)
{
  *L =malloc(sizeof(TS));
  (*L)->sv=NULL;
  if(*L!=NULL)
  return 1;
  else
  return 0;
}
int srch(TS* L,char* name)
{
  TS* p;
  for(p=L; p!=NULL; p=p->sv)
  {
    if(strcmp(name,p->nom)==0)
    return 1;
  }
  return 0;
}
////////////////////////////////////////
int getNat(TS* L,char* name)
{
  TS* p;
  for(p=L; p!=NULL; p=p->sv)
  {
    if(strcmp(name,p->nom)==0)
    return p->nature;
  }
  return -1;
}
//////////////////////////////////////
int getType(TS* L,char* name)
{
  TS* p;
  for(p=L; p!=NULL; p=p->sv)
  {
    if(strcmp(name,p->nom)==0)
    return p->type;
  }
  return -1;
}
//////////////////////////////////////
int getSize(TS* L, char* name)
{
  TS* p;
  for(p=L; p!=NULL; p=p->sv)
  {
    if(strcmp(name,p->nom)==0)
    return p->taille;
  }
  return -1;
}
//////////////////////////////////////
int inst(TS**L,char* nom, int type, int nature, int taille)
{

  if(srch(*L,nom)==1)
  return -1;
  else
  {
    if(*L==null)
    {

      if (create(L))
      {
        (*L)->nature=nature;
        (*L)->taille=taille;
        (*L)->type=type;
        strcpy((*L)->nom,nom);
      }
      else
      return 0;
    }
    else
    {
      TS* p;
      for(p=*L; p->sv!=null;p=p->sv);
      //printf("Nom: %s\nType: %d\nNature: %d\nTaille: %d\n\n",s->nom,s->type,s->nature,s->taille);
      p->sv=(TS*)malloc(sizeof(TS));
      p->nature=nature;
      //  printf("%d\n",p->nature );
      p->taille=taille;
      p->type=type;
      strcpy(p->nom,nom);
      //printf("%d\n",p->nature );
      p->sv->sv=null;
      //printf("Nom: %s\nType: %d\nNature: %d\nTaille: %d\n\n",p->nom,p->type,p->nature,p->taille);
      return 1;

    }
  }
}
/////////////////////////////////////
void space(int n,char c)
{
  if(n<0)
  printf("ERROR");
  else
  {
    for (int i=1;i<n;i++)
    {
      printf("%c",c);
    }

  }
}
void show(TS*L)
{
  TS* p;
  /*printf("-------------------------------------------------------------------------\n"
  "|Nom\t\t|Type\t\t|Nature\t\t\tTaille\t\t|\n"
  "-------------------------------------------------------------------------\n");*/
  space(98,'-');
  printf("\n|Nom");
  space(100/4-4,' ');
  printf("|Type");
  space(100/4-5,' ');
  printf("|Nature");
  space(100/4-7,' ');
  printf("|Taille");
  space(100/4-7,' ');
  printf("|\n");
  space(98,'-');
  printf("\n");

  for(p=L;p->sv!=null;p=p->sv)
  {
    int i=p->type;
    printf("|"BLU "%s"RESET,p->nom );
    space(100/4-strlen(p->nom)-1,' ');
    switch (i)
    {
      case 0:{printf("|Entier");space(100/4-7,' ');printf("|");} break;
      case 1:{printf("|Real");space(100/4-5,' ');printf("|");} break;
      case 2:{printf("|String");space(100/4-7,' ');printf("|");}break;
      default :{printf("|Inconnu");space(100-4-8,' ');printf("|");}break;
    }
    i=p->nature;
    switch (i)
    {
      case 0:printf("Variable\t\t|"); break;
      case 1:printf("Tableau\t\t|"); break;
      case 2:printf("Constante\t\t|"); break;
      default : printf("Nature inconnu\n"); break;
    }
    i=p->taille;
    printf(MAG"%d\t\t\t"RESET"|\n",p->taille);
  }
  space(98,'-');
  printf("\n");
}
//////////////////////////////////////////
int update(TS**L,TS*srch)
{
  TS* p;
  for(p=*L;strcmp(p->nom,srch->nom)!=0&&p!=NULL;p=p->sv);
  if(p==NULL)
  return -1;
  else
  {
    p->type=srch->type;
    p->nature=srch->nature;
    p->taille=srch->taille;
    return 1;
  }
}
#endif // TS_H_INCLUDED
