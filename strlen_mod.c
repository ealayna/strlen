size_t ft_lenline (char *s, char *c);

int ft_maxspeed(char *s, char *c, size_t k)
{
    return(s + k == c ? s[k] ? k + ft_maxspeed(s + k, c, k) :
           ft_lenline(s, c) : ft_lenline(s, c));
}

size_t ft_lenline(char *s, char *c)
{
    size_t k;
    size_t i;

    k = 0;
    i = 1;
    while (s[k] != '\0')
    {
        k += i;
        if (s + k != c || !s[k] || k > 4000)
        {

            if (k > 4000 && s + 4000 == c && s[k + 4000])
                return(ft_maxspeed(s, c, 4000));
            else
            {
                k -= i / 2 * 3;
                printf("%i\n", k);
                if (s[k] == '\0')
                    return(k);
                    return(++k + ft_lenline(s + k, c));
            }
        }
        i *= 2;
    }
    return (k);
}

size_t ft_strlen(char *s)
{
    if (*s == '\0')
        return(0);
    return(ft_lenline(s, s));
}