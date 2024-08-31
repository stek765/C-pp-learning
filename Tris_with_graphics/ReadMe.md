## Steps to make it work

1) Install sfml (for the graphics)
2) compile including the libreries and the version of c++ to use, in my case:

 g++ main.cpp Game.cpp -o tris -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

3) run it -> ./tris   ,  you can press the numbers on your keyboard to play locally.



![Screenshot 2024-08-31 alle 19 39 21](https://github.com/user-attachments/assets/a7252b6d-4ee0-4416-b235-0106152bbe39)
