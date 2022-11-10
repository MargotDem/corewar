/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:26:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/10 15:36:07 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_PLAYERS				4
#define CYCLE_TO_DIE			1536

typedef struct s_args
{
	int		player_count;
	int		numbers[MAX_PLAYERS];
	int		dump_cycle;
	char	*filenames[MAX_PLAYERS];
}			t_args;


/* parse_args */
int	get_args(int argc, char **argv, t_args *args);
void verify_args(t_args *args);

/* set_player_order */
void set_player_order(t_args *args);


/* exit */
void error_exit(char *err_msg, t_args *args);

