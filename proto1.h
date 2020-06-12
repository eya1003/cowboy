
#ifndef __COL_H__
#define __COL_H__
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<sys/time.h>


struct cactus{
SDL_Surface *cact;
SDL_Rect positioncact;
};
typedef struct cactus cactu;

struct personnage{
SDL_Surface *personnage;
SDL_Rect positionperso;
};
typedef struct personnage person;

struct tris{
SDL_Surface *tri;
SDL_Rect positiontri;
};
typedef struct tris tr;

int colli_tri(person *perso, int collisionT,tr *trit); //collision tr

int delpacement_cactuus(cactu *cac , int direction); // deplacement aléatoire du cactus 

int deplacement_tri(tr *trit, int directionT); // deplacement aleatoire du tri

int colli_cac(cactu *cac, int collision,person *perso); // collision cactus

#endif /* #ifndef __COL_H__ */
