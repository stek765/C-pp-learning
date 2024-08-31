## Steps to make it work

1) Install sfml (for the graphics)
2) compile including the libreries and the version of c++ to use, in my case:

 g++ main.cpp Game.cpp -o tris -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

3) run it -> ./tris   ,  you can press the numbers on your keyboard to play locally.