
#include "proto1.h"
int main(void){

person hero;
cactu cactusObjet;
tr trisObjet;

int done=1;
SDL_Event event;//bb
SDL_Surface *screen=NULL;
SDL_Surface *image = NULL;

SDL_Rect positionecran;
//SDL_Rect positioncact;
//SDL_Rect positiontri;
SDL_Rect positionperso;//
char pause;
int collision,direction,directionT,collisionT;
image = IMG_Load("level1.png");
hero.personnage = IMG_Load("detective.png");//
cactusObjet.cact = IMG_Load("cact.png");
trisObjet.tri = IMG_Load("tri.png");

if (SDL_Init(SDL_INIT_VIDEO!=0)){
printf("unable to initalize SDL:%s\n",SDL_GetError());
return (-1) ;}

screen=SDL_SetVideoMode(964,536,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

if(screen == NULL){
printf("unable to set video mode :%s\n",SDL_GetError());
return 1;}


if(image==NULL){
printf("unable to load bitmap :%s \n",SDL_GetError());
return 1;}


SDL_SetColorKey(hero.personnage,SDL_SRCCOLORKEY,SDL_MapRGB(hero.personnage->format,255,255,255));
SDL_SetColorKey(cactusObjet.cact,SDL_SRCCOLORKEY,SDL_MapRGB(cactusObjet.cact->format,255,255,255));
SDL_SetColorKey(trisObjet.tri,SDL_SRCCOLORKEY,SDL_MapRGB(trisObjet.tri->format,255,255,255));

positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w;

hero.positionperso.x=0;
hero.positionperso.y=200;
SDL_EnableKeyRepeat(20,20);

cactusObjet.positioncact.x=700;
cactusObjet.positioncact.y=400;

trisObjet.positiontri.x=350;
trisObjet.positiontri.y=200;


//deplacement du perso
while(done){

SDL_PollEvent(&event);
switch(event.type){
case SDL_QUIT: 
done =0;
break;
case SDL_KEYDOWN:
switch (event.key.keysym.sym){
case SDLK_UP : 
hero.positionperso.y-=5;
break;
case SDLK_DOWN:
hero.positionperso.y+=5;
break;
case SDLK_RIGHT:
hero.positionperso.x+=5;
break;
case SDLK_LEFT: //fleche gauche
hero.positionperso.x-=5;
break;
}

break;
}

// les fonctions rappel
delpacement_cactuus(&cactusObjet , direction);
deplacement_tri(&trisObjet,directionT);
colli_cac(&cactusObjet, collision,&hero);
colli_tri(&hero, collisionT,&trisObjet);


SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_BlitSurface(hero.personnage,NULL,screen,&hero.positionperso);
SDL_BlitSurface(cactusObjet.cact,NULL,screen,&cactusObjet.positioncact);
SDL_BlitSurface(trisObjet.tri,NULL,screen,&trisObjet.positiontri);



SDL_Flip(screen);

}

SDL_FreeSurface(trisObjet.tri);
SDL_FreeSurface(image);
SDL_FreeSurface(hero.personnage);
SDL_FreeSurface(cactusObjet.cact);
SDL_Quit();
pause=getchar();
return  0;
}
