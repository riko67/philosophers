/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realrealmain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelacou <ddelacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:23:13 by ddelacou          #+#    #+#             */
/*   Updated: 2023/09/09 20:42:23 by ddelacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_global global;
    int i;
    int *philosophers_done;
    int meals_end;
    pthread_t *threads;

    i = 0;
    philosophers_done = NULL;
    if (parser_arg(argv, argc) == -1)
        return(printf("Nombre d'arguments invalide.\n"));
    threads = malloc(global.nbrephilo * sizeof(pthread_t));
    philosophers_done = init_all(&global, argv, philosophers_done, threads);
    while(global.program_should_stop == 0)
    {
        meals_end = 0;
        i = 0;
        if (get_time_since_start(global.program_start) >= (global.philo[i].time_of_last_meal.tv_sec * 1000) + global.time_to_die)
        {
            global.program_should_stop = 1;
            printf("Un philosophe est mort, fin du programme\n");
            return(free_all(&global), 1);
        }
        while (i < global.nbrephilo)
        {
            if (philosophers_done[i] == 2)
                meals_end++;
            i++;
        } 
        if(meals_end == global.nbrephilo)
        {
            printf("tout les philosophers ont mangés, fin du programme\n");
            break;
        }
       //usleep(999);
    }
    free_all(&global);
}