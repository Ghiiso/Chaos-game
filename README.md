<h1 align="center">Chaos Game</h1>
Implementation of Chaos Game fractal in C using SDL library. The game starts with a point in the middle of a shape (I chose it to be regular but it works in any case) and iteratively a new point is created by moving a certain fraction of the distance between the last point added and a random vertex. Depending on the number of sides, by choosing the right fraction, a pattern will appear after a certain amount of iteration.

You can play around with the parameters inside the [constant header file](./constants.h). For now, the game is designed for pentagons but it can draw different shapes. 

## Usage
- install SDL library (only base library needed) [Ubuntu tutorial](https://gist.github.com/aaangeletakis/3187339a99f7786c25075d4d9c80fad5)
- build executable using *make* command
- run executable
- terminate program by pressing the *esc* key

## Todo
- refactoring and documentation
- dynamic ratio change based on vertex count
- separate computation and visualisation

## References and inspo
- [Pentagonal chaos game](https://www.youtube.com/watch?v=e5wtveGt_tY&list=LL&index=9)
- ["The Chaos game" Boston University](https://math.bu.edu/DYSYS/chaos-game/node1.html)
- [Wikipedia page](https://en.wikipedia.org/wiki/Chaos_game)
