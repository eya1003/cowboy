

typedef enum STATE STATE;
enum STATE{WAITING,AR,FOLLOWING,ATTACKING};

struct ennemi{
STATE State;
bool directionAller;
SDL_Surface *image;
SDL_Rect position;
SDL_Surface *weapon;
SDL_Rect positionWeapon;
//Num animation fel sprite [0,1,2]
int frameNumber;
// Frames mel sprite sheet
SDL_Rect scorpionAller[ 3 ];
SDL_Rect scorpionRetour[ 3 ];
};

typedef struct ennemi Ennemi;

void animerEnnemi(Ennemi *scorp,SDL_Rect positionperso,SDL_Surface *screen);
Ennemi initScorp();

#endif
