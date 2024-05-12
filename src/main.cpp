#include <SDL.h>
#include <iostream>

#include "WADLoader.h"

int main()
{
    char* basePath = SDL_GetBasePath();
    
    if (basePath) {
        std::string wadPath = std::string(basePath) + "../assets/DOOM1.wad";
        WADLoader wadloader(wadPath);
        wadloader.LoadWAD();
        SDL_free(basePath);
    } else {
        std::cout << "Error getting base path: " << SDL_GetError() << std::endl;
    }

    return 0;
}