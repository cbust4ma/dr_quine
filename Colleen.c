# include <stdio.h>

/*

    Comentario fuera del main

*/

char *s()
{
    //mas comentarios
    char *code = "# include <stdio.h>%1$c%1$c/*%1$c%1$c    Comentario fuera del main%1$c%1$c*/%1$c%1$cchar *s()%1$c{%1$c    //mas comentarios%1$c    char *code = %2$c%3$s%2$c;%1$c    return code;%1$c}%1$c%1$cint main ()%1$c{%1$c    //comentario dentro del main%1$c    printf(s(), 10, 34, s());%1$c    return (0);%1$c}%1$c";
    return code;
}

int main ()
{
    //comentario dentro del main
    printf(s(), 10, 34, s());
    return (0);
}
