/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realrealmain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <ddelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:23:13 by ddelacou          #+#    #+#             */
/*   Updated: 2023/09/11 15:57:56 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "philo.h"
void ft_usleep(useconds_t microseconds)
{
	struct timeval now;
	int time;
	unsigned int currenttime;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	while (1)
	{
		gettimeofday(&now, NULL);
		currenttime = (now.tv_sec * 1000) + (now.tv_usec / 1000);
		if((time + microseconds / 1000) >= currenttime)
			break;
	}
}
int	main(int argc, char **argv)
{
	t_global global;
	int i;
	int *philosophers_done;
	int meals_end;
	pthread_t *threads;

	i = 0;
	philosophers_done = NULL;
	threads = NULL;
	if (parser_arg(argv, argc) == -1)
		return (ft_printf("Nombre d'arguments invalide.\n"));
	philosophers_done = init_all(&global, argv, philosophers_done, threads);
	while (global.program_should_stop == 0)
	{
		meals_end = 0;
		i = 0;
		if (get_time_since_start(global.program_start) >= (global.philo[i].time_of_last_meal.tv_sec
				* 1000) + global.time_to_die)
		{
			global.program_should_stop = 1;
			ft_printf("Un philosophe est mort, fin du programme\n");
			return (free_all(&global), 1);
		}
		while (i < global.nbrephilo)
		{
			if (philosophers_done[i] == 2)
				meals_end++;
			i++;
		}
		if (meals_end == global.nbrephilo)
		{
			ft_printf("tout les philosophers ont mangés, fin du programme\n");
			break ;
		}
	}
	free_all(&global);
}