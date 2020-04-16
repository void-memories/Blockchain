Details about the program :-
Every single class of the program is in a different cpp file.
Inorder to merge several cpp files I had to use headers to declare the classes.

The program has 3 main folders :-
SOURCE - Contains the source files.
HEADERS - Contains the header files for every source file.
IMPORTS - Contains external libraries that was used in the program.
DATA - Contains the sample details of the students.
OUTPUT - Contains the hashed keys.You can add your fake hash keys here when the program prompts.

Instructions :-
A UNIX terminal is required for the execution of the program.
Keep the terminal maximized.
Redirect yourself to the root of this folder in a terminal.

Execute the following command :-

g++ imports/sha256.cpp source/database.cpp source/dehash.cpp source/hash.cpp source/read.cpp source/verification.cpp source/write.cpp source/exceptions.cpp main.cpp -o voidchain && ./voidchain -v

I've attached a video in the folder for the better understanding of project execution.
