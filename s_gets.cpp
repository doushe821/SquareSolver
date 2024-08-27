#include <stdio.h>
#include "s_gets.h"

char* s_gets (char* line, int max_line_length)
{
    char* ret_val = fgets(line, max_line_length, stdin);
    int i = 0;
    if(ret_val)
    {
        while(line[i] != '\n' && line[i] != '\0')
            i++;
        if(line[i] == '\n')
            line[i] = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return line;
}
