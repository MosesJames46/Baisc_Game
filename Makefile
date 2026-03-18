#Make files make compilation of code simplier.
#Make files have variables to easily reuse strings
#The simplest format is target : prerequisite
# ------------------------- >>> 	recipe

#The above simply means that each target has a prerequistie condition that must be met
#in order for the target to be done. The revipe is how these prerequisites are done.

#should also list variables in the order that the prerequisites needs them.

objects = main.o console_control.o game_utility.o game_math_utility.o game_math.o string_functionality.o
CC = gcc
headers = /header_files

main : $(objects)
		gcc -o main $(objects) -lm

main.o : main.c header_files/console_control.h header_files/game_math.h header_files/game_math_utility.h 
			gcc -c main.c

console_control.o : source_files/console_control.c header_files/console_control.h \
					header_files/game_utility.h header_files/string_functionality.h
					gcc -c source_files/console_control.c
	
game_utility.o : source_files/game_utility.c header_files/game_utility.h
					gcc -c source_files/game_utility.c

game_math_utility.o : source_files/game_math_utility.c header_files/game_math_utility.h header_files/string_functionality.h
					gcc -c source_files/game_math_utility.c

game_math.o : source_files/game_math.c header_files/game_math.h 
				gcc -c source_files/game_math.c

string_functionality.o: source_files/string_functionality.c header_files/string_functionality.h
						gcc -c source_files/string_functionality.c

valgrind : 
			valgrind ./main

clean : 
		rm main $(objects)