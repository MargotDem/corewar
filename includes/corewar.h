/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:26:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/01 13:20:48 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10


typedef struct s_args
{
	int		player_count;
	int		numbers[MAX_PLAYERS];
	int		dump_cycle;
	char	*filenames[MAX_PLAYERS];
}			t_args;

typedef struct s_champ
{
	int		magic;
	char	name[PROG_NAME_LENGTH];
	char	comment[COMMENT_LENGTH];
	int		code_size;
	char	code[CHAMP_MAX_SIZE];
	int		id;
}			t_champ;

typedef struct s_carriage
{
	int				id;
	int				carry;
	unsigned char	opcode;
	int 			last_live; //this will be TRUE or FALSE
	int 			remaining_cycles; // cycles before execution
	int 			position;
	int				bytes_to_cross;
	int 			registers[8];
}					t_carriage;

typedef struct s_vm
{
	t_args		args;
	t_champ		champs[MAX_PLAYERS];
	t_dynlist	carriages;
	int			alive_champ;
	int			cycles;
	int			cycles_to_die; //if cycles_to_ die > 0 
	int			checks;
	int			nb_of_live;
}				t_vm;



/* parse_args */
int	get_args(int argc, char **argv, t_vm *vm);
void verify_args(t_vm *vm);

/* set_player_order */
void set_player_order(t_vm *vm);

/* read_champs */
void	read_champs(t_vm *vm);

/* place_champs */
void	place_champs(unsigned char *arena, t_vm *vm);

/* init_carriages */
int		add_carriage(t_carriage *carriage, t_dynlist *alst);
void	init_carriages(t_vm *vm);


/* exit */
void error_exit(char *err_msg, t_vm *vm);

