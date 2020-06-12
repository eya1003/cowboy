
#include "proto2.h"

//#include "collis.h"
const int SHEET_WIDTH = 229;
const int SHEET_HEIGHT = 107;

const int backgroundW=1051;
const int backgroundH=383;

Ennemi initScorp(){

// Initialization ennemi scorpion
Ennemi scorp = {WAITING,true,IMG_Load("scorpion.png"),{backgroundW-(SHEET_WIDTH/3),backgroundH-(SHEET_HEIGHT/2)},IMG_Load("web2020.png"),{backgroundW-(SHEET_WIDTH/3),backgroundH-(SHEET_HEIGHT/2)},0};


    //On coupe la partie en haut
    scorp.scorpionAller[ 2 ].x = 0;
    scorp.scorpionAller[ 2 ].y = 0;
    scorp.scorpionAller[ 2 ].w = SHEET_WIDTH/3;
    scorp.scorpionAller[ 2 ].h = SHEET_HEIGHT/2;

    scorp.scorpionAller[ 1 ].x = SHEET_WIDTH/3;
    scorp.scorpionAller[ 1 ].y = 0;
    scorp.scorpionAller[ 1 ].w = SHEET_WIDTH/3;
    scorp.scorpionAller[ 1 ].h = SHEET_HEIGHT/2;

    scorp.scorpionAller[ 0 ].x = SHEET_WIDTH/1.5;
    scorp.scorpionAller[ 0 ].y = 0;
    scorp.scorpionAller[ 0 ].w = SHEET_WIDTH/3;
    scorp.scorpionAller[ 0 ].h = SHEET_HEIGHT/2;


    //On coupe la deuxieme ligne
    scorp.scorpionRetour[ 2 ].x = SHEET_WIDTH/1.5;
    scorp.scorpionRetour[ 2 ].y = SHEET_HEIGHT/2;
    scorp.scorpionRetour[ 2 ].w = SHEET_WIDTH/3;
    scorp.scorpionRetour[ 2 ].h = SHEET_HEIGHT/2;

    scorp.scorpionRetour[ 1 ].x = SHEET_WIDTH/3;
    scorp.scorpionRetour[ 1 ].y = SHEET_HEIGHT/2;
    scorp.scorpionRetour[ 1 ].w = SHEET_WIDTH/3;
    scorp.scorpionRetour[ 1 ].h = SHEET_HEIGHT/2;


    scorp.scorpionRetour[ 0 ].x = 0;
    scorp.scorpionRetour[ 0 ].y = SHEET_HEIGHT/2;
    scorp.scorpionRetour[ 0 ].w = SHEET_WIDTH/3;
    scorp.scorpionRetour[ 0 ].h = SHEET_HEIGHT/2;

return scorp;
}

void animerEnnemi(Ennemi *scorp,SDL_Rect positionperso,SDL_Surface *screen){

switch(scorp->State){


case WAITING:
scorp->position.x=backgroundW-(SHEET_WIDTH/3);
SDL_BlitSurface(scorp->image,&scorp->scorpionAller[ scorp->frameNumber ],screen,&scorp->position);
break;



case AR:
// ALLER RETOUR


if(scorp->directionAller==1){
scorp->position.x = backgroundW-(SHEET_WIDTH/3)-(scorp->frameNumber+1)*50;
SDL_BlitSurface(scorp->image,&scorp->scorpionAller[ scorp->frameNumber ],screen,&scorp->position);

if(scorp->frameNumber==2){
printf("CHANGEMENT DIRECTION");
scorp->directionAller=false;
scorp->frameNumber=0;
}else{
scorp->frameNumber++;
}
}

else{

scorp->position.x = scorp->position.x+(scorp->frameNumber+1)*5;
SDL_BlitSurface(scorp->image,&scorp->scorpionRetour[ scorp->frameNumber ],screen,&scorp->position);

if(scorp->frameNumber==2){
printf("CHANGEMENT DIRECTION \n");
scorp->directionAller=true;
scorp->frameNumber=0;
}else{
scorp->frameNumber++;
}
}
break;


case FOLLOWING:
scorp->directionAller=true;
scorp->position.x = scorp->position.x-10;
SDL_BlitSurface(scorp->image,&scorp->scorpionAller[ scorp->frameNumber ],screen,&scorp->position);

if(scorp->frameNumber==2){
scorp->frameNumber=0;
}else{
scorp->frameNumber++;
}
break;



case ATTACKING:
if(scorp->positionWeapon.x-positionperso.x>=40){
scorp->positionWeapon.x-=30;
}

else
scorp->State=AR;

/*else{
scorp->position.x=positionperso.x+300;
scorp->positionWeapon.x=scorp->position.x;
}*/

SDL_BlitSurface(scorp->weapon,NULL,screen,&scorp->positionWeapon);
SDL_BlitSurface(scorp->image,&scorp->scorpionAller[ scorp->frameNumber ],screen,&scorp->position);
break;
}

}
