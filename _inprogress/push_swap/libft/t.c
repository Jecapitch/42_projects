#include <stdio.h>
#include "libft.h"
#include "mymath.h"

int main()
{
    printf("%s\n", ft_ltostr((long)INT_MAX - (long)INT_MIN, 3));
    printf("%u\n", ft_strlen(ft_ltostr(500, 3)));
    return 0;
}
