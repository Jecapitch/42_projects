*This project has been created as part of the 42 curriculum by jepiscic.*

# LIBFT

## Description 
[Subject](https://cdn.intra.42.fr/pdf/pdf/199104/en.subject.pdf).
Reimplement a set of functions from the libc in a libft.a library. Functions will have
the same prototypes and behaviors as the originals, adhering strictly to their definitions
in the man page. The only difference will be their names, which must start with the ’tester_ft_’
prefix.

## Instructions
Compile with `make` or `make all`.
`make clean` will remove .o files.
`make fclean` will execute `make clean` and remove the library binary.
`make re` is equivalent to `make fclean && make`.

To use in a program, compile with `-L <dirpath_of_libft> -lft -I <dirpath_of_tester_libft.h>`.

To test bsd functions (e.g. strlcpy, strlcat, bzero), include *bsd/string.h* and compile with
`-lbsd`.

## Grouping
Instead of having one file per function, I grouped them in categories.

## Helper functions
I already added some useful functions in my library, used throughout the required ones.
Helpers unique to a given function are declared static in that function file.

## Guards
Error checking not being allowed at compile time with \__attributes\__ (for portability),
I made the choice that all functions taking a pointer as parameter are guarded and display
an error message on stderr.

## Resources
- man
- [42 Gitbook](https://42-cursus.gitbook.io/guide) (last consulted Oct 2025).
- [GeeksforGeeks](https://www.geeksforgeeks.org/) for descriptions, use cases and examples
of implementations of some functions.
- [Claude.ai](https://claude.ai) was used for debugging.
