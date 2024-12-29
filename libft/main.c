#include "libft.h"
#include "get_next_line.h"

int main()
{
	int fd = open("bible.txt", O_RDONLY);
	char	*line;
	int i = 0;
	while (i < 777)
	{
	(line = get_next_line(fd));
	free(line);
	i++;
	}
	(line = get_next_line(fd));
	ft_printf("%s", line);
	free(line);
	close(fd);
	return (0);
}
