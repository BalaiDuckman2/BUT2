#include <stdio.h>
#include <stdlib.h>

void creationPrio(tfilePrio *fp);
void ajoutePrio(tfilePrio *fp, tpersonne p, int priorite);
void affichePrio(tfilePrio *fp);
typedef struct { 
    char nom[50]; 
    int age; 
} tpersonne ; 
 
typedef struct elem{ 
    tpersonne pers; 
    struct elem* svt; 
} telement; 
 
typedef struct{ 
    telement* queue; 
    telement* tete; 
} tfile;

void Initialisation(tfile * F){
 F->queue=NULL;
 F->tete=NULL   ;
} 

int Est_Vide(tfile F){
    if ((F.queue==NULL) &&
        (F.tete==NULL)){
        return 1;
    }else{
        return 0;
    }
}

void Ajout(tfile *F,tpersonne valeur){
    telement *p;
    p=(telement *)
        malloc(sizeof(telement));
    p->pers=valeur;
    p->svt=NULL;
    if ((F->queue==NULL) &&
        (F->tete==NULL)){
        F->queue=p;
        F->tete=p;
    }else{
        F->queue->svt=p;
        F->queue=p;
    }
}

void Retrait(tfile *F){
    telement *p;
    if (F->tete==F->queue){
        p=F->tete;
        F->tete=NULL;
        F->queue=NULL;
        free(p);
    }else{
        p=F->tete;
        F->tete=F->tete->svt;
        free(p);
    }
}

tpersonne ObtenirTete(tfile F){
    return F.tete->pers;
}

typedef struct{ 
    tfile urgent; 
    tfile important; 
    tfile standard; 
}tfilePrio ;

void creationPrio(tfilePrio *fp){
    Initialisation(&fp->urgent);
    Initialisation(&fp->important);
    Initialisation(&fp->standard);
}

void ajoutePrio(tfilePrio *fp, tpersonne p, int priorite){
    switch(priorite){
            case 1:
                Ajout(&fp->urgent,p);
                break;
            case 2:
                Ajout(&fp->important,p);
                break;
            case 3:
                Ajout(&fp->standard,p);
                break;
        }
}

void affichePrio(tfilePrio *fp){
    while(!Est_Vide(fp->urgent)){
        printf("%s\n",ObtenirTete(fp->urgent).nom);
        Retrait(&fp->urgent);
    }
    while(!Est_Vide(fp->important)){
        printf("%s\n",ObtenirTete(fp->important).nom);
        Retrait(&fp->important);
    }
    while(!Est_Vide(fp->standard)){
        printf("%s\n",ObtenirTete(fp->standard).nom);
        Retrait(&fp->standard);
    }
}