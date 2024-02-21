#include <SDL.h>
#include <iostream>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Window title", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_VULKAN|SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // Set render color to black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // Clear screen
        SDL_RenderClear(renderer);

        // Set render color to red
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Calculate triangle points to center it on the screen
        int screenheight; int screenwidth; SDL_GetWindowSizeInPixels(window, &screenwidth, &screenheight);
        
        int centerX = screenwidth / 2;
        int centerY = screenheight / 2;

        int halfSide = 100; // Half of the side length of the equilateral triangle
        SDL_FPoint points[4] = { {centerX, centerY - halfSide}, {centerX - halfSide, centerY + halfSide}, {centerX + halfSide, centerY + halfSide}, {centerX, centerY - halfSide} };
        
        // Draw triangle
        SDL_RenderLines(renderer, points, 4); // Draw 4 points to connect all the corners

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Destroy window and renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    return 0;
}