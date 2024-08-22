#ifndef CONSOLE_COMMANDS_H_INCLUDED
#define CONSOLE_COMMANDS_H_INCLUDED

enum cl_flags_list{
    UN_COMMAND_CL = -1,
    HELP_CL,
    VERSION_CL,
    COEFFICIENTS_CL,
    TEST
};
const int NUMBER_OF_COMMANDS = 4;

struct command_line_option{
    const char* name;
    int val;
};

int get_console_commands(int n, char* cl_name[], const struct command_line_option* option);

#endif // CONSOLE_COMMANDS_H_INCLUDED
//C:\Users\dou\Documents\GitHub\SquareSolver\bin\Debug\SquareSolver.exe
