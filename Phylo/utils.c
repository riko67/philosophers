/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <ddelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:13:24 by ddelacou          #+#    #+#             */
/*   Updated: 2023/09/11 16:01:18 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "philo.h"

void	prisefourchette(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(philo->print);
	ft_printf("%d %d has taken a fork\n",
				get_time_since_start(philo->global->program_start),
				philo->id);
	ft_printf("%d %d has taken a fork\n",
				get_time_since_start(philo->global->program_start),
				philo->id);
	pthread_mutex_unlock(philo->print);
}

void	mangeur(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	ft_printf("%d %d is eating\n",
				get_time_since_start(philo->global->program_start),
				philo->id);
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	gettimeofday(&philo->time_of_last_meal, NULL);
}
void	mort(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	ft_printf("%d %d died\n",
			get_time_since_start(philo->global->program_start), philo->id);
	pthread_mutex_unlock(philo->print);
	*(philo->program_should_stop) = 1;
	philo->global->program_should_stop = 1;
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	ft_printf("%d %d is sleeping\n",
				get_time_since_start(philo->global->program_start),
				philo->id);
	pthread_mutex_unlock(philo->print);
	ft_usleep(philo->time_to_sleep * 1000);
}

void	philonotalone(struct timeval now, t_philo *philo, int meals_eaten)
{
	while (1)
	{
		if (philo->id % 2 == 1)
			ft_usleep(50);
		prisefourchette(philo);
		gettimeofday(&now, NULL);
		if (((now.tv_sec - philo->time_of_last_meal.tv_sec) * 1000
				+ (now.tv_usec - philo->time_of_last_meal.tv_usec)
				/ 1000) >= philo->time_to_die)
		{
			mort(philo);
			ft_printf("hello");
			break ;
		}
		meals_eaten++;
		mangeur(philo);
		if (philo->meals_to_eat != -1 && meals_eaten == philo->meals_to_eat)
		{
			*(philo->program_should_stop) = 2;
			break ;
		}
		sleeping(philo);
		ft_printf("%d %d is thinking\n",
					get_time_since_start(philo->global->program_start),
					philo->id);
	}
}