### CPP

#### Compilation

* c++ main.cpp

#### Compilation BTS

Pre-processor  
* c++ -E main.cpp > main.i  
Compiler  
* c++ -S main.i  
Assembler  
* c++ -c main.s  
Linker  
* c++ main.o  

#### Library

Requires header files (.hpp) comprising of function definitions  

Compile modules  
* c++ -std=c++17 -c tools.cpp -o tools.o
 
Organise modules into libraries  
* ar rcs libtools.a tools.o  

Link libraries when building code  
* c++ -std=c++17 main.cpp -L . -ltools -o main 

#### Make Files
* Cmake minimum requirements
* projects

* set standard
* export compile commands (can be used to refer commands)

* add library
* add executeable
* link libraries





My initial plan was to learn cpp from the course "modern c++ for computer vision and image processing". From [this dude](https://www.youtube.com/@moderncpp2315) to be precise. But turns out he is not good at teaching stuff he is much more towards completing the course than anything else. So i had to look for alternatives and found the original author book which turns out to be a [1400 page monstor](https://www.amazon.com/C-Programming-Language-4th/dp/0321563840). I am already reading [this monster](https://szeliski.org/Book/) and i dont think i would be done anytime soon. So i am thinking of alternatives as i dont want to do the without knowing cpp itself. 
