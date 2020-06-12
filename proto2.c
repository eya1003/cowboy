
#include "proto2.h"


int main(void){

//Les attributs de la feuille de sprites (229 * 107)

int frameTime=0;
const int SHEET_WIDTH = 229;
const int SHEET_HEIGHT = 107;

const int FPS = 1000;

const int backgroundW=1051;
const int backgroundH=383;
int done=1;
SDL_Event event;//bb

SDL_Surface *screen=NULL;
SDL_Surface *image = NULL;

// Init scorp
Ennemi scorp = initScorp();

printf("STATE %d",scorp.State);

SDL_Surface *personnage =NULL;
SDL_Rect positionecran;
SDL_Rect positionperso;
char pause;


if (SDL_Init(SDL_INIT_VIDEO!=0)){
printf("unable to initalize SDL:%s\n",SDL_GetError());
return (-1) ;}

screen=SDL_SetVideoMode(backgroundW,backgroundH,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

if(screen == NULL){
printf("unable to set video mode :%s\n",SDL_GetError());
return 1;}

image = IMG_Load("bgsghira.jpg");
personnage = IMG_Load("detective.png");//


SDL_SetColorKey(personnage,SDL_SRCCOLORKEY,SDL_MapRGB(personnage->format,255,255,255));
bool isAttacking = false;

if(image==NULL){
printf("unable to load bitmap :%s \n",SDL_GetError());
return 1;}

positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w;

// Position de départ
positionperso.x=0;
positionperso.y=backgroundH-150;
SDL_EnableKeyRepeat(20,20);

/*
distance == (positioncact.x - positionperso.x) ;
s1==100;
s2==450;*/
scorp.positionWeapon = scorp.position;
while(done){
SDL_PollEvent(&event);
switch(event.type){
case SDL_QUIT: 
done =0;
break;
case SDL_KEYDOWN:
switch (event.key.keysym.sym){
case SDLK_UP : 
//positionperso.y--;

//SDL_WaitEvent(&event);
break;
case SDLK_DOWN:
//positionperso.y++;

//SDL_WaitEvent(&event);
break;
case SDLK_RIGHT:
positionperso.x++;

//SDL_WaitEvent(&event);
break;
case SDLK_LEFT: //fleche gauche
positionperso.x--;

//SDL_WaitEvent(&event);
break;
}

break;
}


SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(personnage,NULL,screen,&positionperso);

// Compteur
frameTime++;

// Si compteur / 1000 = 5 

if(FPS/frameTime==15){

frameTime=0;
printf("background width / 2 = %d",(backgroundW/2));
printf("DIFFERENCE POSITION = %d",scorp.position.x-positionperso.x);

// WAITING
if(scorp.position.x-positionperso.x>=backgroundW-300){
scorp.State=WAITING;
animerEnnemi(&scorp,positionperso,screen);

}

else if((scorp.position.x-positionperso.x>=(backgroundW/3))){
//ALLERS/RETOURS
scorp.State=AR;
animerEnnemi(&scorp,positionperso,screen);

}
//FOLLOWING
else if(scorp.position.x-positionperso.x<=(backgroundW/2)&&scorp.position.x-positionperso.x>100){

scorp.State=FOLLOWING;
animerEnnemi(&scorp,positionperso,screen);


}

//ATTACKING
else if(scorp.position.x-positionperso.x<=200){

if(scorp.State!=ATTACKING){
scorp.State=ATTACKING;
scorp.positionWeapon.x = scorp.position.x+40;
scorp.positionWeapon.y = scorp.position.y+10;
}


animerEnnemi(&scorp,positionperso,screen);


}


SDL_Flip(screen);
}

// end while
}	


SDL_FreeSurface(image);
SDL_FreeSurface(personnage);
SDL_FreeSurface(scorp.image);
SDL_Quit();
pause=getchar();
return  0;
}
