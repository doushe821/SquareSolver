#ifndef CONSOLE_COMMANDS_H_INCLUDED
#define CONSOLE_COMMANDS_H_INCLUDED

const int NUMBER_OF_COMMANDS = 3;
const int HELP_CL = 0;
const int VERSION_CL = 1;
const int COEFFICIENTS_CL = 2;
const int UN_COMMAND_CL = -1;

struct command_line_option{
    const char* name;
    int val;
};

int get_console_commands(int n, char* cl_name[], const struct command_line_option* option);

#endif // CONSOLE_COMMANDS_H_INCLUDED
//C:\Users\dou\Documents\GitHub\SquareSolver\bin\Debug\SquareSolver.exe
