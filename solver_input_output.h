#ifndef USER_MENU_H_INCLUDED
#define USER_MENU_H_INCLUDED

struct solve_output{
    double x1;
    double x2;
    int roots_num;
    bool is_linear;
};

struct equation_input{
    double a;
    double b;
    double c;
    bool eof_flag;
    bool quit_flag;
};

void answers_output(const struct solve_output answers);
struct equation_input user_menu ();
struct solve_output solve_quad (double a_s, double b_s, double c_s);

#endif // USER_MENU_H_INCLUDED
