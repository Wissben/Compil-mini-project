#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
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
typedef struct Element
{
  char left[100];
  char name[100];
  char type[100];
  struct Element* sv;
} Element;
Element* S=null;
int initStack(Element** S)
{
  *S=malloc(sizeof(Element));
  (*S)->sv=NULL;
  if(*S!=NULL)
   return 1;
   return 0;
}

int empty(Element* S)
{
  if(S==NULL)
  return 1;
  return 0;
}

Element* pop(Element** S)
{
  Element* p=NULL;
  if(!empty(*S))
  {
    p=malloc(sizeof(Element));
    strcpy(p->left,(*S)->left);
    strcpy(p->name,(*S)->name);
    strcpy(p->type,(*S)->type);
    p->sv=NULL;
    *S=(*S)->sv;
  }
  return p;
}

void push(Element**S,char* left,char* name,char* type)
{
  Element* p = malloc(sizeof(Element));
  strcpy(p->left,left);
  strcpy(p->name,name);
  strcpy(p->type,type);
  p->sv=*S;
  *S=p;
}
void showStack(Element* S)
{
  Element* p=S;
  for(p=S;p->sv!=null;p=p->sv)
  {
    printf("%s / %s / %s \n",p->left,p->name,p->type );
  }
}
#endif // STACK_H_INCLUDED
