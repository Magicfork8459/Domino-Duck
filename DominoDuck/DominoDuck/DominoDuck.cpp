// DominoDuck.cpp : Defines the entry point for the application.
//
#include <map>
#include "DominoDuck.h"

using namespace std;

int main(int argc, char** argv)
{
	SDL_Window* window = SDL_CreateWindow("Testing 1 2 3...", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 720, 640, SDL_WINDOW_SHOWN);
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	return 0;
}
