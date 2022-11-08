/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:26:01 by bkandemi          #+#    #+#             */
/*   Updated: 2022/11/04 13:54:47 by bkandemi         ###   ########.fr       */
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





