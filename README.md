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
