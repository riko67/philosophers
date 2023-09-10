/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <ddelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:13:24 by ddelacou          #+#    #+#             */
/*   Updated: 2023/09/09 22:47:09 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void prisefourchette(t_philo *philo)
{
    pthread_mutex_lock(philo->stop);
    pthread_mutex_lock(philo->fork_left);
    printf("%d %d has taken a fork\n", get_time_since_start(philo->global->program_start), philo->id);
    pthread_mutex_lock(philo->fork_right);
    printf("%d %d has taken a fork\n", get_time_since_start(philo->global->program_start), philo->id);
}

void mangeur(t_philo *philo)
{
    printf("%d %d is eating\n", get_time_since_start(philo->global->program_start), philo->id);
    usleep(philo->time_to_eat * 1000);
    printf("meals_to_eat : %d\n", philo->meals_to_eat);
    gettimeofday(&philo->time_of_last_meal, NULL);
    pthread_mutex_unlock(philo->fork_left);
    pthread_mutex_unlock(philo->fork_right);
    pthread_mutex_unlock(philo->stop);
}
void mort(t_philo *philo)
{
     printf("%d %d died\n", get_time_since_start(philo->global->program_start), philo->id);
    *(philo->program_should_stop) = 1;
    philo->global->program_should_stop = 1;
}

void sleeping(t_philo *philo)
{
    printf("%d %d is sleeping\n", get_time_since_start(philo->global->program_start), philo->id);
    usleep(philo->time_to_sleep * 1000);
}
