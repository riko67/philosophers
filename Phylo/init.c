/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <ddelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:13:24 by ddelacou          #+#    #+#             */
/*   Updated: 2023/09/09 21:05:35 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int init_mutex(t_global *global)
{
    int i;
    i = 0;
    global->fork_mutex = malloc(global->nbrephilo * sizeof(pthread_mutex_t));
    if (!global->fork_mutex)
    {
        printf("Erreur d'allocation de mémoire.\n");
        return (-1);
    }
    while (i < global->nbrephilo)
    {
        pthread_mutex_init(&global->fork_mutex[i], NULL);
        i++;
    }
    return (0);
}

int init_philo(t_global *global, int *philosophers_done)
{
    int i;

    i = 0;
    global->philo = malloc(sizeof(t_philo) * global->nbrephilo);
    if(!global->philo || !global->fork_mutex)
        return (-1);
    while (i < global->nbrephilo)
    {
        global->philo[i].global = global;
        global->philo[i].time_to_die = global->time_to_die;
        global->philo[i].id = i + 1;
        global->philo[i].program_should_stop = &philosophers_done[i];
        global->philo[i].time_of_last_meal.tv_sec = global->program_start.tv_sec;
        global->philo[i].time_of_last_meal.tv_usec = global->program_start.tv_usec;
        global->philo[i].meals_to_eat = global->meals_to_eat;
        global->philo[i].fork_left = &(global->fork_mutex[i]);
        if(global->nbrephilo != 1)
            global->philo[i].fork_right = &(global->fork_mutex[(i + 1) % global->nbrephilo]);
        i++;
    }
    return(0);
}

int *init_global(char **argv, t_global *global,int *philosophers_done)
{
    int i;

    i = 0;
    global->nbrephilo = atoi(argv[1]);
    philosophers_done = malloc(global->nbrephilo * sizeof(int));
    while(i < global->nbrephilo)
    {
        philosophers_done[i] = 0;
        i++;
    }
    global->time_to_die = atoi(argv[2]);
    global->time_to_eat = atoi(argv[3]);
    global->time_to_sleep = atoi(argv[4]);
    global->meals_to_eat = -1;
    global->program_should_stop = 0;
    if (argv[5])
        global->meals_to_eat = atoi(argv[5]);
    gettimeofday(&global->program_start, NULL);
    printf("program_start : %ld, %d", global->program_start.tv_sec, global->program_start.tv_usec);
    global->program_should_stop = 0;
    return (philosophers_done);
} 

int *init_all(t_global *global, char **argv, int *philosophers_done, pthread_t *threads)
{
    philosophers_done = init_global(argv, global, philosophers_done);
    init_mutex(global);
    init_philo(global, philosophers_done);
    init_threads(global, threads);
    return(philosophers_done);
}

int parser_arg(char **argv, int argc)
{
    int i;
    int j;

    j = 0;
    i = 1;
    if (argc < 4 || argc > 5)
        return(-1);
    while (i != argc - 1)
    {
        while(argv[i][j])
        {
            if((argv[i][j] > 'a' && argv[i][j] < 'z') || (argv[i][j] > 'A' && argv[i][j] < 'Z'))
                return(-1);
            j++;
        }   
        i++;
    }
    return(1);
}
