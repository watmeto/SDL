//Les fichiers d'entete
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"


typedef int bool;
enum {false, true};


//Les attributs de l'ecran (640 * 480)
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 24;

//Les surfaces
SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

//Le Font qu'on va utiliser
TTF_Font *font;

//La structure d'evenement
SDL_Event event;

SDL_Surface *load_image( char *filename ) {
    //L'image qui est chargee
    SDL_Surface* loadedImage = NULL;

    //L'image optimisee que nous utiliserons par la suite
    SDL_Surface* optimizedImage = NULL;

    //Chargement de l'image
    loadedImage = SDL_LoadBMP( filename );

    //Si l'image est chargee correctement
    if( loadedImage != NULL ) {
        //creation de l'image optimisee
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //liberation de l'ancienne image
        SDL_FreeSurface( loadedImage );
    }
    //on retourne l'image optimise
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {

    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //on blit la surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

int main( int argc, char** args ) {

    bool quit = false;

    SDL_Color textColor = { 200, 30, 20 };
    
    //initialisation de tout les sous-systemes de sdl
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
        return 1;
    }

    //on met en place l'ecran
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //Si il y a une erreur lors de la mise en place de l'ecran
    if( screen == NULL ) {
        return 1;
    }

    if( TTF_Init() == -1 ) {
	return 1;
    }
    //Ouverture du Font
    font = TTF_OpenFont( "CaslonBold.ttf", 48 );

    //S'il y a une erreur dans le chargement du Font
    if( font == NULL ) {
	return 1;
    }
    //on met en place la barre caption de la fenetre
    SDL_WM_SetCaption( "Galaxtica", NULL );

    //Chargement des images
    background = load_image( "Background.bmp" );
    
    //Mise en place du texte sur la surface message
    message = TTF_RenderText_Solid( font, "GALAXTICA", textColor );
    //S'il y a une erreur dans la mise en place du texte
    if( message == NULL ) {
	return 1;
    }
    apply_surface( 0, 0, background, screen );
    apply_surface( 50, 150, message, screen );

    //mise a jour de l'ecran
    if( SDL_Flip( screen ) == -1 ) {
        return 2;
    }

    //Tant que l'utilisateur n'a pas quitter
    
     
    //Liberation des surface
    SDL_FreeSurface( message );
    SDL_FreeSurface( background );

    //On quitte sdl
    SDL_Quit();
}
       
     