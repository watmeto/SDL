#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
void pauses()
{
	int continuer = 1;
	SDL_Event event;

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				continuer = 0;
				break;
		}
	}
}

int main(){
	SDL_Surface *ecran = NULL;
	ecran = SDL_SetVideoMode(300, 300,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Rect posMario;
	int i = 0 , j = 255;

	while (i <= 255){
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, i, i, j));
		SDL_Flip(ecran);
		usleep(5000);
		i++;
	}
pauses();	
}
