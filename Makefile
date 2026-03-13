#Make files make compilation of code simplier.
#Make files have variables to easily reuse strings
#The simplest format is target : prerequisite
# ------------------------- >>> 	recipe

#The above simply means that each target has a prerequistie condition that must be met
#in order for the target to be done. The revipe is how these prerequisites are done.

#should also list variables in the order that the prerequisites needs them.

objects = main.o console_control.o game_utility.o game_math.o
CC = gcc
headers = /header_files

main : $(objects)
		gcc -o main $(objects)

main.o : main.c header_files/console_control.h header_files/game_math.h
			gcc -c main.c

console_control.o : source_files/console_control.c header_files/console_control.h 
					gcc -c source_files/console_control.c
	
game_utility.o : source_files/game_utility.c header_files/game_utility.h
					gcc -c source_files/game_utility.c

game_math.o : source_files/game_math.c header_files/game_math.h 
				gcc -c source_files/game_math.c

clean : 
		rm main $(objects)