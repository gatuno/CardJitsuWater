/*
 * water.c
 * This file is part of Card Jitsu Water
 *
 * Copyright (C) 2013 - Félix Arreola Rodríguez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* ----------------
 * LEGAL NOTICE
 * ----------------
 *
 * This game is NOT related to Club Penguin in any way. Also,
 * this game is not intended to infringe copyrights, the graphics and
 * sounds used are Copyright of Disney.
 *
 * The new SDL code is written by Gatuno, and is released under
 * the term of the GNU General Public License.
 */

#include <stdlib.h>
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include "config.h"

#define FPS (1000/24)

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))
#define RANDOM(x) ((int) (x ## .0 * rand () / (RAND_MAX + 1.0)))

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif

#define BACKGROUND_FRAMES 360

/* Enumerar las imágenes */
enum {
	IMG_BACKROCK_CE,
	IMG_BACKROCK_CF,
	IMG_BACKROCK_DE,
	IMG_BACKROCK_DF,
	
	IMG_BACKWATER_1,
	IMG_BACKWATER_2,
	IMG_BACKWATER_3,
	IMG_BACKWATER_4,
	IMG_BACKWATER_5,
	IMG_BACKWATER_6,
	IMG_BACKWATER_7,
	IMG_BACKWATER_8,
	IMG_BACKWATER_9,
	IMG_BACKWATER_10,
	
	IMG_BACKWATER_11,
	IMG_BACKWATER_12,
	IMG_BACKWATER_13,
	IMG_BACKWATER_14,
	IMG_BACKWATER_15,
	IMG_BACKWATER_16,
	IMG_BACKWATER_17,
	IMG_BACKWATER_18,
	IMG_BACKWATER_19,
	IMG_BACKWATER_20,
	
	IMG_BACKWATER_21,
	IMG_BACKWATER_22,
	IMG_BACKWATER_23,
	IMG_BACKWATER_24,
	IMG_BACKWATER_25,
	IMG_BACKWATER_26,
	IMG_BACKWATER_27,
	IMG_BACKWATER_28,
	IMG_BACKWATER_29,
	IMG_BACKWATER_30,
	
	IMG_BACKWATER_31,
	IMG_BACKWATER_32,
	IMG_BACKWATER_33,
	IMG_BACKWATER_34,
	IMG_BACKWATER_35,
	IMG_BACKWATER_36,
	IMG_BACKWATER_37,
	IMG_BACKWATER_38,
	IMG_BACKWATER_39,
	IMG_BACKWATER_40,
	
	IMG_BACKWATER_41,
	IMG_BACKWATER_42,
	IMG_BACKWATER_43,
	IMG_BACKWATER_44,
	IMG_BACKWATER_45,
	IMG_BACKWATER_46,
	IMG_BACKWATER_47,
	IMG_BACKWATER_48,
	IMG_BACKWATER_49,
	IMG_BACKWATER_50,
	
	IMG_BACKWATER_51,
	IMG_BACKWATER_52,
	IMG_BACKWATER_53,
	IMG_BACKWATER_54,
	IMG_BACKWATER_55,
	IMG_BACKWATER_56,
	IMG_BACKWATER_57,
	IMG_BACKWATER_58,
	IMG_BACKWATER_59,
	IMG_BACKWATER_60,
	
	IMG_FRENTE,
	
	NUM_IMAGES
};

const char *images_names[NUM_IMAGES] = {
	GAMEDATA_DIR "images/backrock_CE.png",
	GAMEDATA_DIR "images/backrock_CF.png",
	GAMEDATA_DIR "images/backrock_DE.png",
	GAMEDATA_DIR "images/backrock_DF.png",
	
	GAMEDATA_DIR "images/backwater_0001.png",
	GAMEDATA_DIR "images/backwater_0002.png",
	GAMEDATA_DIR "images/backwater_0003.png",
	GAMEDATA_DIR "images/backwater_0004.png",
	GAMEDATA_DIR "images/backwater_0005.png",
	GAMEDATA_DIR "images/backwater_0006.png",
	GAMEDATA_DIR "images/backwater_0007.png",
	GAMEDATA_DIR "images/backwater_0008.png",
	GAMEDATA_DIR "images/backwater_0009.png",
	GAMEDATA_DIR "images/backwater_0010.png",
	GAMEDATA_DIR "images/backwater_0011.png",
	GAMEDATA_DIR "images/backwater_0012.png",
	GAMEDATA_DIR "images/backwater_0013.png",
	GAMEDATA_DIR "images/backwater_0014.png",
	GAMEDATA_DIR "images/backwater_0015.png",
	GAMEDATA_DIR "images/backwater_0016.png",
	GAMEDATA_DIR "images/backwater_0017.png",
	GAMEDATA_DIR "images/backwater_0018.png",
	GAMEDATA_DIR "images/backwater_0019.png",
	GAMEDATA_DIR "images/backwater_0020.png",
	GAMEDATA_DIR "images/backwater_0021.png",
	GAMEDATA_DIR "images/backwater_0022.png",
	GAMEDATA_DIR "images/backwater_0023.png",
	GAMEDATA_DIR "images/backwater_0024.png",
	GAMEDATA_DIR "images/backwater_0025.png",
	GAMEDATA_DIR "images/backwater_0026.png",
	GAMEDATA_DIR "images/backwater_0027.png",
	GAMEDATA_DIR "images/backwater_0028.png",
	GAMEDATA_DIR "images/backwater_0029.png",
	GAMEDATA_DIR "images/backwater_0030.png",
	GAMEDATA_DIR "images/backwater_0031.png",
	GAMEDATA_DIR "images/backwater_0032.png",
	GAMEDATA_DIR "images/backwater_0033.png",
	GAMEDATA_DIR "images/backwater_0034.png",
	GAMEDATA_DIR "images/backwater_0035.png",
	GAMEDATA_DIR "images/backwater_0036.png",
	GAMEDATA_DIR "images/backwater_0037.png",
	GAMEDATA_DIR "images/backwater_0038.png",
	GAMEDATA_DIR "images/backwater_0039.png",
	GAMEDATA_DIR "images/backwater_0040.png",
	GAMEDATA_DIR "images/backwater_0041.png",
	GAMEDATA_DIR "images/backwater_0042.png",
	GAMEDATA_DIR "images/backwater_0043.png",
	GAMEDATA_DIR "images/backwater_0044.png",
	GAMEDATA_DIR "images/backwater_0045.png",
	GAMEDATA_DIR "images/backwater_0046.png",
	GAMEDATA_DIR "images/backwater_0047.png",
	GAMEDATA_DIR "images/backwater_0048.png",
	GAMEDATA_DIR "images/backwater_0049.png",
	GAMEDATA_DIR "images/backwater_0050.png",
	GAMEDATA_DIR "images/backwater_0051.png",
	GAMEDATA_DIR "images/backwater_0052.png",
	GAMEDATA_DIR "images/backwater_0053.png",
	GAMEDATA_DIR "images/backwater_0054.png",
	GAMEDATA_DIR "images/backwater_0055.png",
	GAMEDATA_DIR "images/backwater_0056.png",
	GAMEDATA_DIR "images/backwater_0057.png",
	GAMEDATA_DIR "images/backwater_0058.png",
	GAMEDATA_DIR "images/backwater_0059.png",
	GAMEDATA_DIR "images/backwater_0060.png",
	
	GAMEDATA_DIR "images/frente.png",
};

/* TODO: Listar aquí los automátas */

/* Codigos de salida */
enum {
	GAME_NONE = 0, /* No usado */
	GAME_CONTINUE,
	GAME_QUIT
};

/* Estructuras */

/* Prototipos de función */
int game_loop (void);
void setup (void);
SDL_Surface * set_video_mode(unsigned);

/* Variables globales */
SDL_Surface * screen;
SDL_Surface * images [NUM_IMAGES];

int background_frame = 0;

int main (int argc, char *argv[]) {
	
	setup ();
	
	do {
		if (game_loop () == GAME_QUIT) break;
	} while (1 == 0);
	
	SDL_Quit ();
	return EXIT_SUCCESS;
}

int game_loop (void) {
	int done = 0;
	SDL_Event event;
	SDLKey key;
	Uint32 last_time, now_time;
	SDL_Rect rect;
	int g;
	
	SDL_EventState (SDL_MOUSEMOTION, SDL_IGNORE);
	
	do {
		last_time = SDL_GetTicks ();
		
		while (SDL_PollEvent(&event) > 0) {
			switch (event.type) {
				case SDL_QUIT:
					/* Vamos a cerrar la aplicación */
					done = GAME_QUIT;
					break;
			}
		}
		
		/* Dibujar el fondo */
		SDL_FillRect (screen, NULL, 0);
		
		/* Calcular el frame de las rocas */
		g = ((background_frame % 8) / 4) * 2 + ((background_frame % 10) / 5);
		
		SDL_BlitSurface (images[IMG_BACKROCK_CE + g], NULL, screen, NULL);
		
		/* Calcular el frame del agua */
		g = background_frame % 60;
		
		SDL_BlitSurface (images[IMG_BACKWATER_1 + g], NULL, screen, NULL);
		
		background_frame++;
		if (background_frame >= BACKGROUND_FRAMES) background_frame = 0;
		
		/* Dibujar el frente */
		SDL_BlitSurface (images[IMG_FRENTE], NULL, screen, NULL);
		
		SDL_Flip (screen);
		
		now_time = SDL_GetTicks ();
		if (now_time < last_time + FPS) SDL_Delay(last_time + FPS - now_time);
		
	} while (!done);
	
	return done;
}

/* Set video mode: */
/* Mattias Engdegard <f91-men@nada.kth.se> */
SDL_Surface * set_video_mode (unsigned flags) {
	/* Prefer 16bpp, but also prefer native modes to emulated 16bpp. */

	int depth;

	depth = SDL_VideoModeOK (760, 480, 16, flags);
	return depth ? SDL_SetVideoMode (760, 480, depth, flags) : NULL;
}

void setup (void) {
	SDL_Surface * image;
	int g;
	char buffer[256];
	
	/* Inicializar el Video SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf (stderr,
			"Error: Can't initialize the video subsystem\n"
			"The error returned by SDL is:\n"
			"%s\n", SDL_GetError());
		exit (1);
	}
	
	/* Crear la pantalla de dibujado */
	screen = set_video_mode (0);
	
	if (screen == NULL) {
		fprintf (stderr,
			"Error: Can't setup 760x480 video mode.\n"
			"The error returned by SDL is:\n"
			"%s\n", SDL_GetError());
		exit (1);
	}
	
	for (g = 0; g < NUM_IMAGES; g++) {
		image = IMG_Load (images_names[g]);
		
		if (image == NULL) {
			fprintf (stderr,
				"Failed to load data file:\n"
				"%s\n"
				"The error returned by SDL is:\n"
				"%s\n", images_names[g], SDL_GetError());
			SDL_Quit ();
			exit (1);
		}
		
		images[g] = image;
		/* TODO: Mostrar la carga de porcentaje */
	}
	
	srand (SDL_GetTicks ());
}

