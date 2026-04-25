# Principum
**This is a game made using Raylib**

## Idea
*When you have an Idea of what to make, paste is here*
*For now, just play around, experiment and learn*

## How The Game Engine Works
The game engine is just my addon ontop of raylib.

The objects/ directory has scripts for different components 
of the game.

game.c is where you use the object functions for the 
initiation of the program, loading of objects, 
updating of logic, rendering of graphics and
cleaning.

### What Each object should consist of...
I recommend that each object contains:

> Render Queueing Function
> Drawing Function
> Cleaning Function

The Render Queueing Function is for adding an object to the rendering queue.
The Drawing Function Contains the Raylib Draw Commands for the object to be drawn.
The Cleaning Function cleans all variables that used allocatied memory.
