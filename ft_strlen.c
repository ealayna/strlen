#include<stdio.h>

char *lenline(char *s, size_t i)
{
    if (i == 16 && (s + i) && *(s + i))
       return(lenline(s + i, i));
    if (!(s + i) || !*(s + i))
       return(lenline(s, i >> 1));
    if (i == 0)
       return(s + 1);
    if ((s + i) && *(s + i))
        return(lenline(s + i, i << 1));
    return(s + 1);
}

size_t ft_strlen(char *s)
{
    char *str = s;
 
    if (!s || !*s)
        return(0);
    return (lenline(s, 1) - s);
}