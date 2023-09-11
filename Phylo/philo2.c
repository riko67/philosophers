/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <ddelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:11:00 by ddelacou          #+#    #+#             */
/*   Updated: 2023/09/11 16:02:04 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "ft_printf.h"

int	get_time_since_start(struct timeval program_start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec - program_start.tv_sec) * 1000 +
		(current_time.tv_usec - program_start.tv_usec) / 1000;
}
void	*philosopher(void *arg)
{
	t_philo			*philo;
	int				meals_eaten;
	struct timeval	now;

	philo = (t_philo *)arg;
	meals_eaten = 0;
	if (philo->global->nbrephilo == 1)
		philoalone(philo);
	else
	{
		gettimeofday(&now, NULL);
		philonotalone(now, philo, meals_eaten);
	}
	return (NULL);
}

void	free_all(t_global *global)
{
	int	i;

	i = 0;
	free(global->philo);
	while (i < global->nbrephilo)
	{
		pthread_mutex_destroy(&global->fork_mutex[i]);
		i++;
	}
	free(global->fork_mutex);
}

void	init_threads(t_global *global, pthread_t *threads)
{
	int	i;

	i = 0;
	threads = malloc(global->nbrephilo * sizeof(pthread_t));
	while (i < global->nbrephilo)
	{
		pthread_create(&threads[i], NULL, philosopher, &global->philo[i]);
		pthread_detach(threads[i]);
		i++;
	}
}

void	philoalone(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->print);
	ft_printf("%d %d has taken a fork\n",
			get_time_since_start(philo->global->program_start), philo->id);
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->time_to_die);
	pthread_mutex_lock(philo->print);
	ft_printf("%d %d died\n", get_time_since_start(philo->global->program_start),
			philo->id);
	pthread_mutex_unlock(philo->print);
	philo->global->program_should_stop = 1;
}