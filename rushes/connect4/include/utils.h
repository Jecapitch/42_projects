/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 23:27:29 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/19 23:05:11 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "colors.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>

# define MIN_HEIGHT	1
# define MAX_HEIGHT	50
# define MIN_WIDTH	1
# define MAX_WIDTH	100
# define DEF_LEVEL	MEDIUM
# define USER_INPUT	64
# define PAWN		(char*[2]){BRED"█"CRESET, BYEL"█"CRESET}

typedef struct s_game		t_game;
typedef struct s_cell		t_cell;
typedef struct s_minimax	t_minimax;
typedef enum e_level		t_level;
typedef enum e_player		t_player;

extern char	**environ;

enum e_player
{
	NONE = 0,
	AI = 1,
	HUMAN = 2
};

struct s_minimax
{
	int	state;
	int	row;
};

struct s_cell
{
	t_player	player;
	int			weight;
	int			max_height;
};

struct s_game
{
	t_cell	**grid;				// grid[height][width]
	int		width;
	int		height;
	bool	first_player;
	int		current_player;
	int		last_move_r;
	int		last_move_c;
	int		col_heights;		// number of pawns in each col, for O(1) insertion
	int		level;				// if we want to allow choice of difficulty, let's 1-3;
	bool	gui;				// for GUI activation
	char	user_input[USER_INPUT];
};

enum e_level
{
	EASY = 2,
	MEDIUM = 3,
	HARD = 4,
	IMPOSSIBLE = 5
};

void			init_cost(t_game *g);
int				ai_turn(t_game game);

int				init(int argc, char **args, t_game *game);
void			cleanup(t_game *game);

void			display_game(t_game game);
void			place_pawn(t_game game);
unsigned long	delay(int ms);

int				ask_player(t_game *game);
int				ask_level(t_game *game);
void			quit(t_game *game);

int				ft_min(int n1, int n2);
int				ft_max(int n1, int n2);

#endif /* UTILS_H */
