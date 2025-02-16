# cosmic-conquest-game
2D space shooter game created in c++ using SLD2.

# Project set up
* Make sure you have SDL 2, SDL_image, SDL_ttf, and SDL_mixer installed.
* With brew: 
`brew install sdl2 sdl2_image sdl2_ttf sdl2_mixer`

* Test that sdl is installed properly, compile with:

```
clang++ main.cpp -o sdl_check \
    -I/opt/homebrew/include -L/opt/homebrew/lib \
    -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
```
* `-I/opt/homebrew/include` → Tells the compiler where SDL2 headers are.
* `-L/opt/homebrew/lib` → Tells the linker where SDL2 libraries are.
* `-lSDL2` → Links against the SDL2 library.
* run program `./sdl_check`

# Building program with cmake
* cd into `/build`
* run `cmake ..`
* run `make` then run the executable generated in `/build`


