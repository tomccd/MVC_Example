#include <SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>

using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char* argv[]){

    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        std::cout<<"SDL could not initialize! SDL Error: "<<SDL_GetError()<<std::endl;
    }

    SDL_Window* screen = NULL;
    screen = SDL_CreateWindow("TTF",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL = screen){
        cout<<"Could not create window: "<<SDL_GetError()<<endl;
        return 1;
    }

    


    return EXIT_SUCCESS;
}