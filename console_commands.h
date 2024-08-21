#ifndef CONSOLE_COMMANDS_H_INCLUDED
#define CONSOLE_COMMANDS_H_INCLUDED

const char VERSION[] = "# 0.426b\n";
const char HELP[] = "# This application can solve quadratic equations.\n"
"all you need is to input 3 coefficients with floating point: ax^2 + bx + c = 0\n"
"To start solving press 's', to quit program press  'q'. make sure your numbers are a bit less than 1.74E314 and bigger than 2.06E-170.\n"
"If you want to enter coefficients through console, type \"coefficients\" and then type your coefficients.\n";
const char UNKNOWN_COMMAND[]= "Unknown command. Enter help if you need help.\n";

struct console_coef_input{
    int a;
    int b;
    int c;
};

struct console_coef_input console_commands(int c, char* v[]);

#endif // CONSOLE_COMMANDS_H_INCLUDED
//C:\Users\dou\Documents\GitHub\SquareSolver\bin\Debug\SquareSolver.exe
