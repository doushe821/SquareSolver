#ifndef CONSOLE_COMMANDS_H_INCLUDED
#define CONSOLE_COMMANDS_H_INCLUDED

enum cl_flags_list
{
    UN_COMMAND_CL = -1,
    HELP_CL,
    VERSION_CL,
    COEFFICIENTS_CL,
    TEST,
    FTEST
};

const int NUMBER_OF_COMMANDS = 5;
const int MAX_COMMAND_SIZE = 64;
const int MAX_TESTDATA_SIZE = 1024;
const int NUMBER_OF_TESTS = 25;

struct command_line_option
{
    const char* name;
    int val;
};

int get_console_commands(int n, char* cl_name[], const struct command_line_option* option);
bool execute_console_command(int c, int* j, char* v[]);

const char VERSION[] =        "# 0.426b\n";
const char HELP[] =           "# This application can solve quadratic equations.\n"
                              "# all you need is to input 3 coefficients with floating point: ax^2 + bx + c = 0\n"
                              "# To start solving press 's', to quit program press  'q'. make sure your numbers are a bit less than 1.74E314 and bigger than 2.06E-170.\n"
                              "# If you want to enter coefficients through console, type \"coefficients\" and then type your coefficients.\n";
const char UNKNOWN_COMMAND[]= "Unknown command. Enter --help if you need help.\n";

#endif // CONSOLE_COMMANDS_H_INCLUDED
//C:\Users\dou\Documents\GitHub\SquareSolver\bin\Debug\SquareSolver.exe
