*This project has been created as part of the 42 curriculum by jepiscic.*

# LIBFT

## Description 
[Subject](https://cdn.intra.42.fr/pdf/pdf/203993/en.subject.pdf)

get\_next\_line(int fd) is a function that must read a file (pointed by fd) 
-including stdin-, one line at a time, each call returning the allocated next line, 
including the terminating \n. If there is nothing left to read or if an error occurs, 
it should return NULL.
This project aims to introduce you to the use of static variables.
The use of libft is forbidden. The only allowed functions are `malloc`, `free`,  
and `read`.

## Instructions
Compile with `-Wall -Wextra -Werror`.
Compile with `-D BUFFER_SIZE=<size>` to define the buffer size. Default size is 
defined in the header file (with `#ifndef BUFFER_SIZE` guard to avoid redefinition).

## Static variable
A *static variable* is a variable that is initialized once and whose lifetime is the 
entire run of the program, meaning mainly that it remains allocated and keeps its value 
after the function return. In other words, it isn't created and destroyed on each call.
Given it's initialized only once, declaration and initialization are performed on the 
same line (see example below, and the `get_next_line` buffer declaration).
> In general, static memory allocation is the allocation of memory *at compile time*, 
> before the associated program is executed, unlike dynamic memory allocation or automatic 
> memory allocation where memory is allocated as required at run time."
> ([Wikipedia](https://en.wikipedia.org/wiki/Static_variable))
It's a way to keep track of a value in a function along the run, e.g. for counters 
or, in our case, the keep the content of the buffer.

**Example for a counter** (Wikipedia)
```
#include <stdio.h>

void func(void)
{
	static int x = 0;
	// x is initialized only once across five calls of func() and the variable
	// will get incremented five times after these calls. The final value of x
	// will be 5.

	x++;
	printf("%d\n", x); // outputs the value of x
}

int main(void)
{
	func(); // prints 1
	func(); // prints 2
	func(); // prints 3
	func(); // prints 4
	func(); // prints 5
	return 0;
}
```

## Usage
To call the function, first open a file descriptor that you will pass as argument.

### Example

```
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	size_t	i;

	line = NULL;
	fd = open("hitchhikers_guide.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("error: open\n", STDERR_FILENO);
		return (1);
	}
	i = 0;
	while (i < 42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_putstr_fd(line, STDOUT_FILENO);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
```

## Bonus part
Two bonuses are included:
- Using only one static variables.
- Managing multiple file descriptors at the same time, keeping track of the 
reading state of each. This is done by using a static 2D buffer: 
```
static char	buffer\[MAX\_FD\]\[BUFFER_SIZE\];
```

### Example
This will print 1st of fd1, then 1st line of fd2, then 1st line of fd3, 
then 2nd line of fd1, 2nd line of fd2, and so on.

```
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	size_t	i;

	line = NULL;
	fd1 = open("hitchhikers_guide.txt", O_RDONLY);
	fd2 = open("vogon_poetry.txt", O_RDONLY);
	fd3 = open("thank_you_for_the_fish.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		ft_putstr_fd("error: open\n", STDERR_FILENO);
		close(fd1);
		close(fd2);
		close(fd3);
		return (1);
	}
	i = 0;
	while (i < 42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_putstr_fd(line, STDOUT_FILENO);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
```

## Resources
- "Static variable", in [*Wikipedia*](https://en.wikipedia.org/wiki/Static_variable) (last consulted 2026-04-23).
- [42 Gitbook](https://42-cursus.gitbook.io/guide) (last consulted Oct 2025).
- [Claude.ai](https://claude.ai) was used for debugging.
