#ifndef USER_MENU_H_INCLUDED
#define USER_MENU_H_INCLUDED

const char MENU_INPUT[]= "# Type \"s\" to start solving equations, type \"q\" to exit program.\n"
"# Type \"f\" to get input from file.\n";
const char INVALID_IN[]= "# Invalid input\n";
const int MAX_FILENAME_LENGTH = 100;

struct equation_input{
    double a;
    double b;
    double c;
    bool eof_flag;
    bool quit_flag;
};

void answers_output(const struct solve_output answers);
struct equation_input user_menu();

#endif // USER_MENU_H_INCLUDED
