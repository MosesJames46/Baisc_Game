#Make files make compilation of code simplier.
#Make files have variables to easily reuse strings
#The simplest format is target : prerequisite
# ------------------------- >>> 	recipe

#The above simply means that each target has a prerequistie condition that must be met
#in order for the target to be done. The revipe is how these prerequisites are done.

objects = console_control.o game_math.o game_utility.o
CC = gcc
headers = /header_files

main : $(objects)
		gcc -o main $(objects)


console_control.o : stdio.h
					CC source_files/game_utility.c

clean : 
		rm main $(objects)