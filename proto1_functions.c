#include "proto1.h"

long lastCollisionTime = 0;  // variable du temps 
int directionCact=1;
int directionTri=0;


//deplacement aleatoire du tri
int deplacement_tri(tr *trit, int directionT)
{
if(trit->positiontri.x ==0)
directionTri= 1;

if(trit->positiontri.x>=900)
directionTri= 0;

if(directionTri==1)
trit->positiontri.x= trit->positiontri.x+5;
else 
trit->positiontri.x= trit->positiontri.x-5;

}

// deplacement aleatoire du cactus
int delpacement_cactuus(cactu *cac , int direction)
{
if(cac->positioncact.x==0)
directionCact=1; 

if(cac->positioncact.x>=900)
directionCact=0;

if(directionCact==1)
cac->positioncact.x+=10;
else 
cac->positioncact.x-=10;
}

//collision du personnage avec cact
int colli_cac(cactu *cac,  int collision,  person *perso)
{

if(lastCollisionTime>10){
lastCollisionTime--;
return 0;
}

if ((perso->positionperso.x+perso->positionperso.w<(cac->positioncact.x)) || (perso->positionperso.x>(cac->positioncact.x+cac->positioncact.w)) || (perso->positionperso.y+perso->positionperso.h<cac->positioncact.y) || (perso->positionperso.y>(cac->positioncact.y+cac->positioncact.h)))
{
collision=0;
return 0;
}

if(lastCollisionTime<=10){
lastCollisionTime=100;
collision=1;
printf("boom we have collision\n");
}

return 1;
}


//collision personnage avec tri
int colli_tri(person *perso, int collisionT,tr *trit)
{

if(lastCollisionTime>10){
lastCollisionTime--;
return 0;
}

if ((perso->positionperso.x+perso->positionperso.w<(trit->positiontri.x)) || (perso->positionperso.x>(trit->positiontri.x+trit->positiontri.w)) || (perso->positionperso.y+perso->positionperso.h<trit->positiontri.y) || (perso->positionperso.y>(trit->positiontri.y+trit->positiontri.h)))
{
collisionT=0;
return 0;
}

if(lastCollisionTime<=10){
lastCollisionTime=100;
collisionT=1;
printf("booM collision T\n");
}

return 1;
}






