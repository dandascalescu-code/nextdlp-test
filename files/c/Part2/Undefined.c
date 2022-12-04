/*
    This code contains instances of undefined behaviour, for demonstration purposes
*/

#include <stdio.h>
#include <string.h>

char *f(int m) {
    char buf[6];
    int x;

    if (m == 1 && x--)
    {
        strcpy(buf, "AAAAAA"); /* This string is 7 bytes (including final 0 bytes), 
                                    but buf is 6 bytes. This will cause an overflow. */
        return buf; /* buf is a local variable, and thus will be destroyed upon 
                        function exit. This will therefore return an address that is not 
                        owned by the program, and whose value is undefined. */
    }
    else if (m == 2)
    {
        char *msg = (char *)malloc(100); /* malloc is implicitly declared, as stdlib.h 
                                            was not included. */
        strcpy(msg, "BBBBBB");
        return msg;
    }
} /* If m > 2, this function has no return statement, therefore the return address is
        undefined. */

int main(int argc, char **argv)
{
    char *m;
    m = f(argc);
    printf("%p\n", m);
    putchar(m[0]); /* This will seg fault if argc = 1, due to the reason on line 16. */
                    /* It will also seg fault if argc > 2 due to the reason on line 27. */
    return 0;
}
