/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:39:43 by bkandemi          #+#    #+#             */
/*   Updated: 2022/12/12 13:05:57 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/corewar.h"

/*
	* Set the new opcode if it is time
	* Reduce the remaining_cycles
	* Execute the opcode if it is time and update the position of the carriage
	* If the carriage executes live statement, set the carraige->last_live flag to TRUE
*/
void	run_carriages(t_vm *vm, unsigned char *arena)
{
	t_dblist	*cars;
	t_carriage	*the_car;

	cars = vm->carriages.head;
	while (cars != NULL)
	{
		the_car = cars->content;
		if (the_car->remaining_cycles < 0)
		{
			the_car->opcode = arena[the_car->position];
			/*get the new remaining cycles from the opcode
			if (arena[the_car->position] >= 0x01 && arena[the_car->position] <= 0x10)
				the_car->remaining_cycles = ???*/
		}
		if (the_car->remaining_cycles > 0)
			the_car->remaining_cycles--;
		if (the_car->remaining_cycles == 0)
		{
			/* Execute the opcode if it is time and update the position of the carriage */
			//if opcode is live, set carriage->last_live = TRUE
			the_car->remaining_cycles--;
		}
		cars = cars->next;
	}
}

/* 
	* Delete dead carriage
	* Reduce cycles_to_die value
	* If there are no carriages anymore, announce the winner
*/
void	check(t_vm *vm)
{
	t_dblist	*cars;
	t_carriage	*the_car;
	size_t		elem_count;
	t_dblist	*next_car;

	vm->checks++;
	cars = vm->carriages.head;
	elem_count = 0;
	while (cars)
	{
		the_car = cars->content;
		next_car = cars->next;
		if (the_car->last_live == FALSE || vm->cycles_to_die <= 0)
		{
			if (vm->carriages.size == 1)
				vm->winner = the_car->id;
			ft_dynlstdelelem(&vm->carriages, elem_count, del_fn);
		}
		else
		{
			the_car->last_live = FALSE;
			elem_count++;
		}
		cars = next_car;
	}
	if (vm->nb_of_live >= NBR_LIVE || vm->checks >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks = 0;
	}
	if (vm->carriages.size == 0)
		ft_printf("Player %d (%s) won\n",
			vm->winner, vm->champs[vm->winner - 1].name);
}

void	dump(unsigned char *arena) //hexadecimal format with 32 octets per line.
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	ft_printf("0x0000 :");
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 32 == 0)
		{
			row += 32;
			ft_printf("\n%#06x :", row);
		}
		ft_printf(" %02x", arena[i]); // we can color each player differently
		i++;
	}
	write(1, "\n", 1);
}

/*
	* Increment the cycle counter
	* Run carriages(execute the opcode or update the carriage struct)
	* Do the check-up
*/
void	the_cycle(t_vm *vm, unsigned char *arena)
{
	while (vm->carriages.size != 0)
	{
		if (vm->args.dump_flag == TRUE && vm->cycles == vm->args.dump_cycle)
		{
			dump(arena);
			return ;
		}
		vm->cycles++;
		run_carriages(vm, arena);
		if (vm->cycles % vm->cycles_to_die == 0 || vm->cycles_to_die <= 0)
			check(vm);
	}
}
