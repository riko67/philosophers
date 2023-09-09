/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <ddelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:11:00 by ddelacou          #+#    #+#             */
/*   Updated: 2023/09/09 22:26:30 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int get_time_since_start(struct timeval program_start)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - program_start.tv_sec) * 1000 +
           (current_time.tv_usec - program_start.tv_usec) / 1000;
}
void *philosopher(void *arg) 
{
    t_philo *philo;
    int meals_eaten;
    int temps_attente;
    struct timeval now;

    philo = (t_philo *)arg;
    meals_eaten = 0;
    if (philo->global->nbrephilo == 1)
        philoalone(philo);
    else
    {
        while (1)
        {
            printf("%d %d is thinking\n", get_time_since_start(philo->global->program_start), philo->id);
            pthread_mutex_lock(philo->fork_left);
            printf("%d %d has taken a fork\n", get_time_since_start(philo->global->program_start), philo->id);
            pthread_mutex_lock(philo->fork_right);
            printf("%d %d has taken a fork\n", get_time_since_start(philo->global->program_start), philo->id);
            gettimeofday(&now, NULL);
            temps_attente = ((now.tv_sec - philo->time_of_last_meal.tv_sec) * 1000 + (now.tv_usec - philo->time_of_last_meal.tv_usec) / 1000);
            printf("%d\n", philo->time_to_die);
            if(temps_attente >= philo->time_to_die)
            {
                printf("%d %d died\n", get_time_since_start(philo->global->program_start), philo->id);
                *(philo->program_should_stop) = 1;
                philo->global->program_should_stop = 1;
                break;
            }
            meals_eaten++;
            printf("%d %d is eating\n", get_time_since_start(philo->global->program_start), philo->id);
            usleep(philo->time_to_eat * 1000);
            printf("meals_to_eat : %d\n", philo->meals_to_eat);
            gettimeofday(&philo->time_of_last_meal, NULL);
            pthread_mutex_unlock(philo->fork_left);
            pthread_mutex_unlock(philo->fork_right);
            if (philo->meals_to_eat != -1 && meals_eaten == philo->meals_to_eat) 
            {
                *(philo->program_should_stop) = 2;
                break;
            }
            printf("%d %d is sleeping\n", get_time_since_start(philo->global->program_start), philo->id);
            usleep(philo->time_to_sleep * 1000);
        }  
    } 
    return (NULL);
}

void free_all(t_global *global)
{
    int i;
    
    i = 0;
    free(global->philo);
    while(i < global->nbrephilo)
    {
        pthread_mutex_destroy(&global->fork_mutex[i]);
        i++;
    }
    free(global->fork_mutex);
}

void init_threads(t_global *global, pthread_t *threads)
{
    int i;
    
    i = 0;
    threads = malloc(global->nbrephilo * sizeof(pthread_t));
    while (i < global->nbrephilo)
    {
        pthread_create(&threads[i], NULL, philosopher, &global->philo[i]);
        pthread_detach(threads[i]);
        i++;
    }
}

void philoalone(t_philo *philo)
{
    printf("%d %d is thinking\n", get_time_since_start(philo->global->program_start), philo->id);
    pthread_mutex_lock(philo->fork_left);
    printf("%d %d has taken a fork\n", get_time_since_start(philo->global->program_start), philo->id);
    usleep(philo->time_to_die);
    printf("%d %d died\n", get_time_since_start(philo->global->program_start), philo->id);
    philo->global->program_should_stop = 1;
}