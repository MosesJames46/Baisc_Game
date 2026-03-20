
#ifndef CONSOLE_CONTROL_HEADER
#define CONSOLE_CONTROL_HEADER

/*
[CONTROL SEQUENCES]
-----------------------------
A control sequence is how programs interact with the terminal.

The only way a program can interact with the terminal is by sending the correct byte encoding.

Go to: ghostty.org/docs/vt/concepts/sequences for more information on all control sequences.

[C0 CONTROL CHARACTERS]
-----------------------------
-Simple characters between 0x00 - 0x20. Spanning the first 32 characters in ASCII encoding.
- Basic encodings are the:
    - Bell:                 Alert users. BEL 0x07    
    - Backspace:            Move cursor back one position. 0x08 BS
    - Tab: Move             cursor right to the next tab stop. 0x09 TAB
    - Linefeed:             Move the cursor down one line. 0x0A LF
    - Carriage Return:      Move the cursor to the leftmost column. 0x0B CR
[CSI ENCODINGS]
-------------------------------
All CSI encodings start with either \e[, \x1b[, or \033[ followed by a pair of integer parameters.
Various sequences can be found on Wikipedia.

The character needed for erasing the screen is the escape sequence:
CSI n J -> \e[nJ
Moving the cursor to the top lefthand corner and then clear the screen gives the illusion of 
clearing entire screen. 
\e[1:1H + \e[nJ

*/

/*
    Instead of using the console to control text directly, just use an 2D array that stores 
    information. This can be sent to the terminal making it even more modular.
*/

typedef struct console_struct Console;
struct console_struct{
    int width;
    int height;  
    int* test_array;
    int** screen;
};



//const char* clear_display = "\e[1:1H\e[2J";
void init_screen(int width, int height, int*** screen);
void print_to_screen(int width, int height, int*** screen);
void print_2Darray(int row, int col, float*** screen);
void print_newline();
static int get_largest_stringf(float* float_array, int array_sze);
#endif